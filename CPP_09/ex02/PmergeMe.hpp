#ifndef PMERGEME
# define PMERGEME

#include <cerrno>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <utility>
#include <deque>

typedef std::deque<int> deqi;
typedef std::pair<int, int> pair;
typedef std::deque<pair> deqp;
typedef std::deque<deqi> deqr;

class PmergeMe
{
	private:
		deqi _unordered;
		deqi _sorted;
		void convert(char **args);
		deqp mergeInsertionSort(deqp & nums);
		deqp getInsertionGroup(int groupLen, int start, deqp & nums);
		void binaryInsert(deqp & nums, deqp & group, size_t shift);
		void binsert(pair item, deqp & nums, deqp::iterator start, deqp::iterator end);
		deqp restore(deqp & winners, deqr & losers);
		deqp createDeqp();
		void fillPairs(deqp & nums, size_t amount, deqp & winners, deqr & losers);
		void merge(deqp & winners, deqr & losers, deqp & nums);
	public:
		PmergeMe();
		PmergeMe(const PmergeMe & origin);
		const PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		deqi sort(char **args);
};

#endif