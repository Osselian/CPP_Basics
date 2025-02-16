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
	listp::iterator it_b = result.begin();
	listp::iterator it_e = result.end();
	while (it_b != it_e)
	{
		int num = (*it_b).first; 
		_sorted.push_back(num);
		it_b++;
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
		listi los;
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
	size_t shift = pow(2, i + 1) - 1;;
	while (rest > 0)
	{
		if (shift > winners.size() - 1)
			shift = winners.size() - 1;
		listp toInsert = getInsertionGroup(groupLen, last, sorted_losers);
		listp::iterator end = winners.begin();
		std::advance(end, shift);
		int endNum = (*end).first;
		endNum+=0;
		binaryInsert(winners, toInsert, end);
		rest -= groupLen;
		i++;
		last += groupLen;
		groupLen = pow(2, i) - groupLen;
		shift = pow(2, i + 1) - 1;;
	}
}

listp PmergeMeList:: restore(listp &winners, listr & losers)
{
	listp losers_sorted;
	listp::iterator it_b = winners.begin();
	listp::iterator it_e = winners.end();
	while (it_b != it_e)
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
		it_b++;
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

void PmergeMeList:: binaryInsert(listp  & result, listp & group, listp::iterator end)
{
	size_t size = result.size();
	listp::reverse_iterator it_b = group.rbegin();
	listp::reverse_iterator it_e = group.rend();
	// listp::iterator it_res_e = result.end();
	// it_res_e--;
	while (it_b != it_e)
	{
		listp::iterator it_res_b = result.begin();
		int endNum = (*end).first;
		endNum+=0;
		listp::iterator it_res_m = result.begin();
		std::advance(it_res_m, size / 2);
		list_it iters;
		iters.push_back(it_res_b);
		iters.push_back(end);
		iters.push_back(it_res_m);
		pair item = *it_b;
		listp::iterator in_it = binsert(item, result, iters, size / 2);
		it_b++;
		if (in_it == end)
			end++;
		else
			end--;
	}
}

listp::iterator PmergeMeList:: binsert(pair item, listp & nums, list_it iters, size_t size)
{	
	int endNum;
	listp::iterator start = *iters.begin();
	listp::iterator end = *(++(iters.begin()));
	listp::iterator targetIt = *(--(iters.end()));
	int itemNum = item.first;
	int num = (*targetIt).first;
	if (itemNum >= num)
	{
		if (targetIt == end)
		{
			nums.insert(++targetIt, item);
			endNum = (*end).first;
			endNum += 0;
		}
		else
		{
			listp::iterator it_m = targetIt;
			if (size / 2 == 0)
				std::advance(it_m, 1);
			else
				std::advance(it_m, size / 2);
			iters.clear();
			targetIt++;
			iters.push_back(targetIt);
			iters.push_back(end);
			iters.push_back(it_m);
			end = binsert(item, nums, iters, size / 2);
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
			end = binsert(item, nums, iters, size / 2);
		}
	}
	return end;
}