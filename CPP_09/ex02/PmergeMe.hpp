#ifndef PMERGEME
# define PMERGEME

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
		void binaryInsert(deqp & nums, deqp & group);
		void binsert(pair item, deqp & nums, deqp::iterator start, deqp::iterator end);
		deqp restore(deqp & winners, deqr & losers);
		deqp createDeqp();
	public:
		PmergeMe();
		PmergeMe(const PmergeMe & origin);
		const PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		deqi &sort(char **args);
};

#endif