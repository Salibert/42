#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array {
private:
    unsigned int _size;
    T           *_array;

public:
    class OutOfSizeException : public std::exception {
    public:
        OutOfSizeException(void) { return; };
        virtual ~OutOfSizeException(void) throw() { return; };
        char const * message(void) const throw() { return ("Out of size array"); };

        OutOfSizeException &operator=(OutOfSizeException const & rhs) {
            (std::exception)*this = std::exception::operator=(rhs);
            return *this;
        }
    };

    Array<T>(Array<T> const &obj) { *this = obj; return; }

    Array<T>(unsigned int _size) : _size(_size), _array(new T[_size]) {}

    Array<T>(void) : _size(0), _array(NULL) {}

    virtual ~Array<T>(void) { delete [] this->_array; return; }

    unsigned int length(void) const { return this->_size; }

    Array<T> &operator=(Array<T> const &rhs) {
        delete [] this->_array;
        this->_size = rhs._size;
        this->_array = new T[this->_size];
        for (unsigned int i = 0; i < this->_size; i++)
            this->_array[i] = rhs._array[i];
        return *this;
    }

    T & operator[](unsigned int i) throw(Array::OutOfSizeException) {
        if (this->_array == NULL || i >= this->_size)
            throw Array::OutOfSizeException();
        return this->_array[i];
    }

};

template <class T>
std::ostream &operator<<(std::ostream &o, Array<T> const &rhs);

#endif