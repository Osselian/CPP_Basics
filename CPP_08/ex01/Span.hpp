#ifndef SPAN
#define SPAN

#include <vector>

typedef std::vector<int>::iterator iter;
class Span
{
	private:
		unsigned int _capacity;
		unsigned int _current;	
		std::vector<int> *_container;
		std::vector<int> getSpan() const;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &origin);
		const Span &operator=(const Span &other);
		~Span();
		void addNumber(int numb);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
		void fill_range(iter start, iter end);
};

#endif