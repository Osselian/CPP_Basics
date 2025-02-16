#ifndef PMERGEMELIST
# define PMERGEMELIST

#include <cerrno>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <list>
#include <utility>

typedef std::list<int> listi;
typedef std::pair<int, int> pair;
typedef std::list<pair> listp;
typedef std::list<listi> listr;
typedef std::list<listp::iterator> list_it;

class PmergeMeList
{
	private:
		listi _unordered;
		listi _sorted;
		void convert(char **args);
		listp mergeInsertionSort(listp & nums);
		listp getInsertionGroup(int groupLen, int start, listp & nums);
		void binaryInsert(listp & nums, listp & group, listp::iterator end);
		listp::iterator binsert(pair item, listp & nums, list_it iters, size_t size);
		listp restore(listp & winners, listr & losers);
		listp createDeqp();
		void fillPairs(listp & nums, size_t amount, listp & winners, listr & losers);
		void merge(listp & winners, listr & losers, listp & nums);
	public:
		PmergeMeList();
		PmergeMeList(const PmergeMeList & origin);
		const PmergeMeList &operator=(const PmergeMeList &other);
		~PmergeMeList();

		listi sort(char **args);
};

#endif