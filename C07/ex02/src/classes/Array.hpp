#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <string>
# include <iostream>
# include <cstdlib>

template<typename T>
class Array {

	public:
		Array() : _array(NULL), _size(0) {}
		Array(unsigned int n)
		{
			_array = new T[n];
			_size = n;
		}
		Array(const Array &cpy)
		{
			_array = NULL;
			_size = 0;
			*this = cpy;
		}

		~Array()
		{
			delete[] _array;
			_array = NULL;
			_size = 0;
		}

		Array &operator=(const Array &rhs)
		{
			delete[] _array;
			_array = new T[rhs._size];
			_size = rhs._size;
			for (int i = 0; i < _size; i++)
				_array[i] = rhs[i];
			return *this;
		}
		T &operator[](int index)
		{
			if (index >= _size)
				throw InvalidIndexException();
			return _array[index];
		}
		
		int getSize(void) { return _size;}

		class InvalidIndexException : public std::exception
		{
		public:
			virtual const char *what () const throw () {
				return "Array index is invalid";
			}
		};

	private:
		T *_array;
		int _size;

};

#endif