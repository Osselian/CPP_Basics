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
	deqp nums = createDeqp();
	deqp result = mergeInsertionSort(nums);
	for (size_t i = 0; i < result.size(); i++)
	{
		_sorted.push_back(result[i].first);
	}
	return _sorted;
}

void PmergeMe:: convert(char **args)
{
	while (*args)
	{
		char *end;
		errno = 0;
		long num = std::strtol(*args, &end, 10);	
		if (errno == ERANGE || *args == end || num < 0 || num > INT_MAX)
			throw std::exception();
		_unordered.push_back(static_cast<int>(num));
		args++;
	}	
}

deqp PmergeMe:: createDeqp()
{
	deqp result;
	for (size_t i = 0; i < _unordered.size(); i++)
	{
		pair item = std::make_pair(_unordered[i], 0);
		result.push_back(item);
	}
	return result;
}

deqp PmergeMe:: mergeInsertionSort(deqp & nums)
{
	size_t amount = nums.size() / 2;
	deqp winners;
	deqr losers;
	for (size_t i = 0; i < nums.size() - 1; i+=2)
	{
		pair win;
		deqi los(3);
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
		winners = mergeInsertionSort(winners);
	if (amount == 1)
	{
		pair first = std::make_pair(losers[0][0], losers[0][1]);
		winners[0].second = losers[0][2];
		winners.push_front(first);
		if (amount % 2 == 1)
		{
			pair item = nums[nums.size() - 1];
			int i;
			if (winners[0].first > item.first)
				i = 0;
			else if (winners[0].first < item.first && item.first < winners[0].first)
				i = 1;
			else
				i = 2;
			item.second = i;
			winners.insert(winners.begin() + i, item);
		}
		return winners;
	}

	deqp sorted_losers;
	if (amount != 1)
		sorted_losers = restore(winners, losers);
	winners.push_front(sorted_losers[0]);
	// result.push_back(winners[0]);
	if (amount % 2 == 1)
	{
		sorted_losers.push_back(nums[nums.size() - 1]);
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
		binaryInsert(winners, toInsert);
		rest -= groupLen;
		i++;
		groupLen = pow(2, i) - groupLen;
	}
	return winners;
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

void PmergeMe:: binaryInsert(deqp  & result, deqp & group)
{
	size_t size = group.size();
	
	for (int i = size -1; i > 0; i--)
	{
		binsert(group[i], result, result.begin(), result.end());
	}
}

void PmergeMe:: binsert(pair item, deqp & nums, deqp::iterator start, deqp::iterator end)
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
	for (size_t i = 0; i < winners.size(); i++)
	{
		int losInd = winners[i].second;
		deqi triple = losers[losInd];
		int losNum = triple[0];
		int losPrevInd = triple[1];
		pair elem = std::make_pair(
			losNum, 
			losPrevInd); 
		losers_sorted[i] = elem;	
		winners[i].second = losers[winners[i].second][2];
	}
	return losers_sorted;
}