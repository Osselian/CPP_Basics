#ifndef WHATEVER
# define WHATEVER

template<class T>
void swap(T first, T second)
{
	T tmp;

	tmp = first;
	first = second;
	second = first;
}

template<class T>
T min(T first, T second)
{
	if (first < second)
		return first;
	return second;
}

template<class T>
T max(T first, T second)
{
	if (first > second)
		return first;
	return second;
}
#endif