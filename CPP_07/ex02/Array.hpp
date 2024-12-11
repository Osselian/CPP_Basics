#ifndef ARRAY
# define ARRAY

#include <exception>

template <class T>
class Array 
{
	private:
		T *arr;
		unsigned int len;
	public:
		Array()
		{
			arr = new T[0];
			len = 0;
		}

		Array(unsigned int n)
		{
			arr = new T[n];
			len = n;
		}

		Array(const Array<T> &origin)
		{
			arr = new T[origin.len];
			len = origin.len;
			for (unsigned int i = 0; i < len; i++)
			{
				arr[i] = origin[i];
			}
		}

		const Array<T> &operator=(const Array<T> &other)
		{
			delete [] arr;
			arr = new T[other.len];
			len = other.len;
			for (unsigned int i = 0; i < len; i++)
			{
				arr[i] = other[i];
			}
			return *this;
		}

		~Array()
		{
			delete [] arr;
		}

		T &operator[](unsigned int index) const
		{
			if (index >= len)
				throw std::exception();
			return arr[index];
		}

		unsigned int size() const 
		{
			return len;
		}
};

#endif