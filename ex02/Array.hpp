#ifndef ARRAY_HPP

# define ARRAY_HPP
# include <exception>

template <typename T>
class Array {
private:
    unsigned int	size;
    T*				arr;

public:
    Array() {
    	size = 0;
    	arr = nullptr;
	}

    Array(unsigned int n) {
    	size = n;
    	if (n != 0)
			arr = new T[n];
    	else
    		arr = nullptr;
	}

    Array(const Array &orig) {
		size = orig.size;
		if (size != 0)
			arr = new T[size];
		for (unsigned int i = 0; i < size; ++i)
			arr[i] = orig.arr[i];
	}

    Array& operator=(const Array &orig) {
		if (this != &orig) {
			if (arr != nullptr) {
				delete[] arr;
				arr = nullptr;
			}
			size = orig.size;
			if (size != 0)
				arr = new T[size];
			for (unsigned int i = 0; i < size; ++i) {
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
    	if (i >= size)
    		throw OutOfRangeException();
    	return (arr[i]);
    }

    unsigned int size() const {
    	return (size);
    }

class OutOfRangeException: public std::exception{
    public:
    	const char *what() const throw() {
    		return "Index Out of Range\n";
		}
    };
};

#endif