#include <vector>

#include "MutantStack.tpp"

void constructors_test()
{
	std::cout << "Constructors test:" << std:: endl;

	std::deque<int> mydeque (3,100);          // deque with 3 elements
	std::vector<int> myvector (2,200);        // vector with 2 elements

	MutantStack<int> first;                    // empty stack
	MutantStack<int> second (mydeque);         // stack initialized to copy of deque

	MutantStack<int,std::vector<int> > third;  // empty stack using vector
	MutantStack<int,std::vector<int> > fourth (myvector);

	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of second: " << second.size() << '\n';
	std::cout << "size of third: " << third.size() << '\n';
	std::cout << "size of fourth: " << fourth.size() << '\n';


	std::cout << std:: endl;
}

void empty_test()
{
	std::cout << "Empty test:" << std:: endl;

	MutantStack<int> mystack;
	int sum (0);

	for (int i=1;i<=10;i++) mystack.push(i);

	while (!mystack.empty())
	{
	   sum += mystack.top();
	   mystack.pop();
	}

	std::cout << "total: " << sum << '\n';
	std::cout << std:: endl;
}

void size_test()
{
	std::cout << "Size test:" << std:: endl;

	MutantStack<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';
	
	for (int i=0; i<5; i++) myints.push(i);
	std::cout << "1. size: " << myints.size() << '\n';
	
	myints.pop();
	std::cout << "2. size: " << myints.size() << '\n';

	std::cout << std:: endl;
}

void top_test()
{
	std::cout << "Top test:" << std:: endl;

	MutantStack<int> mystack;

	mystack.push(10);
	mystack.push(20);

	mystack.top() -= 5;

	std::cout << "mystack.top() is now " << mystack.top() << '\n';

	std::cout << std:: endl;
}

void push_pop_test()
{
	std::cout << "Push test:" << std:: endl;

	MutantStack<int> mystack;

	for (int i=0; i<5; ++i) mystack.push(i);

	std::cout << "Popping out elements...";
	while (!mystack.empty())
	{
	   std::cout << ' ' << mystack.top();
	   mystack.pop();
	}
	std::cout << '\n';

	std::cout << std:: endl;
}

void subject_test()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

int main() 
{
	constructors_test();
	empty_test();
	size_test();
	top_test();
	push_pop_test();
	subject_test();
}
