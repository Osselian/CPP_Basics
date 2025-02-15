#include "PmergeMeList.hpp"

PmergeMeList:: PmergeMeList()
{
}

PmergeMeList::PmergeMeList(const PmergeMeList &origin)
{
	_unordered = origin._unordered;
	_sorted = origin._sorted;
}

const PmergeMeList &PmergeMeList::operator=(const PmergeMeList &other)
{
	if (this != &other)
	{
		_unordered = other._unordered;
		_sorted = other._sorted;
	}
	return *this;
}

PmergeMeList::~PmergeMeList()
{
}

listi PmergeMeList:: sort(char **args)
{
	convert(args);
	listp nums = createDeqp();
	if (_unordered.size() == 1)
		return _unordered;
	listp result = mergeInsertionSort(nums);
	for (size_t i = 0; i < result.size(); i++)
	{
		int num = result.front().first; 
		_sorted.push_back(num);
	}
	return _sorted;
}

void PmergeMeList:: convert(char **args)
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

listp PmergeMeList:: createDeqp()
{
	listp result;
	listi::iterator it_b = _unordered.begin();
	listi::iterator it_e = _unordered.end();
	// for (size_t i = 0; i < _unordered.size(); i++)
	while (it_b != it_e)
	{
		pair item = std::make_pair(*it_b, 0);
		result.push_back(item);
		it_b++;
	}
	return result;
}

listp PmergeMeList:: mergeInsertionSort(listp & nums)
{
	size_t amount = nums.size() / 2;
	listp winners;
	listr losers;
	fillPairs(nums, amount, winners, losers);
	if (amount > 1)
		winners = mergeInsertionSort(winners);

	merge(winners, losers, nums);
	return winners;
}

void PmergeMeList:: fillPairs(listp & nums, size_t amount, listp & winners, listr & losers)
{
	listp::iterator it_f = nums.begin();
	listp::iterator it_s = ++nums.begin();
	for (size_t j = 0; j < amount; j++)
	{
		pair win;
		listi los(3);
		if (it_f->first > it_s->first)
		{
			win = std::make_pair(it_f->first, j) ;	
			los.push_back(it_s->first);
			los.push_back(it_s->second);
			los.push_back(it_f->second);
		}
		else
		{
			win = std::make_pair(it_s->first, j) ;	
			los.push_back(it_f->first);
			los.push_back(it_f->second);
			los.push_back(it_s->second);
		}
		winners.push_back(win);
		losers.push_back(los);
		std::advance(it_f, 2);
		std::advance(it_s, 2);
	}
}

void PmergeMeList::  merge(listp & winners, listr & losers, listp &nums)
{
	listp sorted_losers = restore(winners, losers);
	winners.push_front(sorted_losers.front());
	sorted_losers.pop_front();
	if (nums.size() % 2 == 1)
	{
		listp::reverse_iterator it = nums.rbegin();
		sorted_losers.push_back(*it);	
	}

	long rest = sorted_losers.size();
	int last = 0;
	int i = 1;
	int groupLen = pow(2, i);
	while (rest > 0)
	{
		listp toInsert = getInsertionGroup(groupLen, last, sorted_losers);
		binaryInsert(winners, toInsert);
		rest -= groupLen;
		i++;
		last += groupLen;
		groupLen = pow(2, i) - groupLen;
	}
}

listp PmergeMeList:: restore(listp &winners, listr & losers)
{
	listp losers_sorted(winners.size());
	listp::iterator it_b = winners.begin();
	for (size_t i = 0; i < winners.size(); i++)
	{
		int losInd = it_b->second;
		listr::iterator los_it = losers.begin();
		std::advance(los_it, losInd);
		listi triple =  *los_it;
		listi::iterator tr_it = triple.begin();
		int losNum = *tr_it;
		tr_it++;
		int losPrevInd = *tr_it;
		pair elem = std::make_pair(
			losNum, 
			losPrevInd); 
		losers_sorted.push_back(elem);	
		tr_it++;
		it_b->second = *tr_it;
	}
	return losers_sorted;
}

listp PmergeMeList:: getInsertionGroup(int groupLen, int start, listp  & nums)
{
	listp res;
	listp::iterator it_b = nums.begin();
	std::advance(it_b, start);
	listp::iterator it_e = nums.end();
	int rest = nums.size() - start;
	if (rest > groupLen)
	{
		it_e = nums.begin();
		std::advance(it_e, start + groupLen);
	}
	res = listp (it_b, it_e);
	return res;
}

void PmergeMeList:: binaryInsert(listp  & result, listp & group)
{
	size_t size = group.size();
	listp::iterator it_b = group.begin();
	listp::iterator it_e = group.end();
	
	while (it_e != it_b)
	{
		listp::iterator it_m = group.begin();
		std::advance(it_m, size / 2);
		list_it iters;
		iters.push_back(it_b);
		iters.push_back(it_e);
		iters.push_back(it_m);
		binsert(*it_e, result, iters, size);
		it_e--;
	}
}

void PmergeMeList:: binsert(pair item, listp & nums, list_it iters, size_t size)
{
	listp::iterator start = *iters.begin();
	listp::iterator end = *iters.end();
	listp::iterator targetIt = *iters.begin()++;
	int itemNum = item.first;
	int num = (*targetIt).first;
	if (itemNum >= num)
	{
		if (targetIt == end)
			nums.insert(targetIt, item);
		else
		{
			listp::iterator it_m = start;
			std::advance(it_m, size / 2);
			iters.clear();
			iters.push_back(targetIt++);
			iters.push_back(end);
			iters.push_back(it_m);
			binsert(item, nums, iters, size / 2);
		}
	}
	else
	{
		if (targetIt == start)
			nums.insert(targetIt, item);
		else
		{
			listp::iterator it_m = start;
			std::advance(it_m, size / 2);
			iters.clear();
			iters.push_back(start);
			iters.push_back(targetIt);
			iters.push_back(it_m);
			binsert(item, nums, iters, size / 2);
		}
	}
}