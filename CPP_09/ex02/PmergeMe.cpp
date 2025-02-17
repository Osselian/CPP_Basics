#include "PmergeMe.hpp"
#include <ctime>

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

std::deque<int> PmergeMe:: sort(char **args)
{
	convert(args);
	deqp nums = createDeqp();
	if (_unordered.size() == 1)
		return _unordered;
	deqp result = mergeInsertionSort(nums);
	for (size_t i = 0; i < result.size(); i++)
		_sorted.push_back(result[i].first);
	return _sorted;
}

void PmergeMe:: convert(char **args)
{
	while (*args)
	{
		char *end;
		errno = 0;
		long num = std::strtol(*args, &end, 10);	
		if (errno == ERANGE || *args == end || *end != '\0' || num < 0 || num > INT_MAX)
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
	fillPairs(nums, amount, winners, losers);
	if (amount > 1)
		winners = mergeInsertionSort(winners);

	merge(winners, losers, nums);
	return winners;
}

void PmergeMe:: fillPairs(deqp & nums, size_t amount, deqp & winners, deqr & losers)
{
	for (size_t j = 0; j < amount; j++)
	{
		int ind = 2 * j;
		pair win;
		deqi los(3);
		if (nums[ind].first > nums[ind + 1].first)
		{
			win = std::make_pair(nums[ind].first, j) ;	
			los[0] = nums[ind + 1].first;
			los[1] = nums[ind + 1].second;
			los[2] = nums[ind].second;
		}
		else
		{
			win = std::make_pair(nums[ind + 1].first, j) ;	
			los[0] = nums[ind].first;
			los[1] = nums[ind].second;
			los[2] = nums[ind + 1].second;
		}
		winners.push_back(win);
		losers.push_back(los);
	}
}

void PmergeMe::  merge(deqp & winners, deqr & losers, deqp &nums)
{
	deqp sorted_losers = restore(winners, losers);
	winners.push_front(sorted_losers[0]);
	sorted_losers.pop_front();
	if (nums.size() % 2 == 1)
		sorted_losers.push_back(nums[nums.size() - 1]);

	long rest = sorted_losers.size();
	int last = 0;
	int i = 1;
	int groupLen = pow(2, i);
	size_t shift = pow(2, i + 1) - 1;
	while (rest > 0)
	{
		if (shift > winners.size() - 1)
			shift = winners.size() - 1;
		deqp toInsert = getInsertionGroup(groupLen, last, sorted_losers);
		deqp::iterator end = winners.begin();
		std::advance(end, shift);
		binaryInsert(winners, toInsert, shift);
		rest -= groupLen;
		i++;
		last += groupLen;
		groupLen = pow(2, i) - groupLen;
		shift = pow(2, i + 1) - 1;
	}
}


void PmergeMe:: binaryInsert(deqp  & result, deqp & group, size_t shift)
{
	size_t size = group.size();
	
	for (int i = size - 1; i >= 0; i--)
	{
		binsert(group[i], result, result.begin(), result.begin() + shift);
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
			nums.insert(++targetIt, item);
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