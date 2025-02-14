#include "PmergeMe.hpp"
#include <cerrno>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <utility>

PmergeMe:: PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &origin)
{
	_unordered = origin._unordered;
	_sorted = origin._sorted;
}

const PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_unordered = other._unordered;
		_sorted = other._sorted;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}

std::deque<int> &PmergeMe:: sort(char **args)
{
	convert(args);
	mergeInsertionSort(_unordered);
	return _sorted;
}

void PmergeMe:: convert(char **args)
{
	while (*args)
	{
		char *end;
		errno = 0;
		long num = std::strtol(*args, &end, 10);	
		if (errno == ERANGE || num < 0 || num > INT_MAX)
			throw std::exception();
		_unordered.push_back(static_cast<int>(num));
		args++;
	}	
}

deqp &PmergeMe:: mergeInsertionSort(deqp & nums)
{
	size_t amount = nums.size() / 2;
	deqp winners;
	deqr losers;
	for (size_t i = 0; i < nums.size(); i+=2)
	{
		pair win;
		int los[3];
		if (nums[i].first > nums[i + 1].first)
		{
			win = std::make_pair(nums[i].first, i) ;	
			los[0] = nums[i + 1].first;
			los[1] = nums[i + 1].second;
			los[2] = nums[i].second;
		}
		else
		{
			win = std::make_pair(nums[i + 1].first, i) ;	
			los[0] = nums[i].first;
			los[1] = nums[i].second;
			los[2] = nums[i + 1].second;
		}
		winners.push_back(win);
		losers.push_back(los);
	}
	if (amount > 1)
		mergeInsertionSort(winners);
	deqp sorted_losers = restore(winners, losers);
	deqp result;
	result.push_back(sorted_losers[0]);
	result.push_back(winners[0]);

	if (amount % 2 == 1)
	{
		winners.push_back(nums[nums.size() - 1]);
		amount++;
	}
	// int resAmount = nums.size();
	int rest = amount - 1;
	int last = 0;
	int i = 1;
	int groupLen = pow(2, i);
	while (rest > 0)
	{
		deqp toInsert = getInsertionGroup(groupLen, last, sorted_losers);
		binaryInsert(result, toInsert);
	}

	for (int i = 1; i < amount; i++)
	{

		result.push_back(winners[i][0]);
	}
	for (int i = 0; i < winners.size() - 1; i++)
	{
	}
}

deqp PmergeMe:: getInsertionGroup(int groupLen, int start, deqp  & nums)
{
	deqp res;
	deqp::iterator it_b = nums.begin() + start;
	deqp::iterator it_e = nums.end();
	if (it_e - it_b < groupLen)
		res = deqp (it_b, it_e);
	else
		res = deqp (it_b, it_b + groupLen);
	return res;
}

deqp PmergeMe:: binaryInsert(deqp  & result, deqp & group)
{
	size_t size = group.size();
	
	for (int i = size -1; i > 0; i--)
	{
		binsert(group[i], result, result.begin(), result.end());
	}
}

deqp PmergeMe:: binsert(pair item, deqp & nums, deqp::iterator start, deqp::iterator end)
{
	deqp::iterator targetIt = start + (end - start) / 2;
	int itemNum = item.first;
	int num = (*targetIt).first;
	if (itemNum >= num)
	{
		if (targetIt == end)
			nums.insert(targetIt, item);
		else
			binsert(item, nums, targetIt + 1, end);
	}
	else
	{
		if (targetIt == start)
			nums.insert(targetIt, item);
		else
			binsert(item, nums, start, targetIt);
	}
}

deqp PmergeMe:: restore(deqp &winners, deqr & losers)
{
	deqp losers_sorted(winners.size());
	for (int i = 0; i < winners.size(); i++)
	{
		pair elem = std::make_pair(
			losers[winners[i].second][0], 
			losers[winners[i].second][1]); 
		losers_sorted[i] = elem;	
		winners[i].second = losers[winners[i].second][2];
	}
	return losers_sorted;
}