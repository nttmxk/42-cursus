#ifndef ARRAY_HPP

# define ARRAY_HPP
# include <exception>

template <typename T>
class Array {
private:
    unsigned int	_size;
    T*				arr;

public:
    Array() {
    	_size = 0;
    	arr = nullptr;
	}

    Array(unsigned int n) {
    	_size = n;
    	if (n != 0)
			arr = new T[n];
    	else
    		arr = nullptr;
	}

    Array(const Array &orig) {
		_size = orig._size;
		if (_size != 0)
			arr = new T[_size];
		for (unsigned int i = 0; i < _size; ++i)
			arr[i] = orig.arr[i];
	}

    Array& operator=(const Array &orig) {
		if (this != &orig) {
			if (arr != nullptr) {
				delete[] arr;
				arr = nullptr;
			}
			_size = orig._size;
			if (_size != 0)
				arr = new T[_size];
			for (unsigned int i = 0; i < _size; ++i) {
				arr[i] = orig.arr[i];
			}
		}
		return (*this);
	}

	~Array() {
    	if (arr != nullptr) {
    		delete[] arr;
    		arr = nullptr;
    	}
	}

	T& operator[](unsigned int i) {
		if (i >= _size)
			throw OutOfRangeException();
		return (arr[i]);
	}

	const T& operator[](unsigned int i) const {
		if (i >= _size)
			throw OutOfRangeException();
		return (arr[i]);
	}

    unsigned int size() const {
    	return (_size);
    }

class OutOfRangeException: public std::exception{
    public:
    	const char *what() const throw() {
    		return "Index Out of Range\n";
		}
    };
};

#endif