#ifndef MUTANT_STACK
# define MUTANT_STACK

#include <stack>
#include <vector>

template <typename DataType, typename Container = std::vector<DataType>>
class MutantStack
{
	private:
		std::stack<DataType, Container> *_stack;	
	public:
		MutantStack();
};

#endif