#include <iostream>

class MyVector {
    int _size;
    int _capacity;
	int* _data;
    
public:
    MyVector() {
		_size = 0;
		_capacity = 8;
		_data = nullptr;
	}
	int& operator [] (int i) {
	    return _data[i];
	}
	MyVector(int n, int initial) {
		_size = n;
		_capacity = 2 * n; 
		_data = new int[_capacity];
		for (int i = 0; i < _size; i++) _data[i] = initial;
	}
	MyVector(MyVector &v) {
	    this->_size = v.size();
	    this->_capacity = v.capacity();
	    this->_data = new int [v.capacity()];
	    for (int i = 0; i < this->_size; i++) this->_data[i] = v[i];
	}
	~MyVector() {
		delete[] _data;
		std::cout << "deleted " << this << std::endl;
	}
	void print() {
		for (int i = 0; i < _size; i++) {
			std::cout << _data[i] << " ";
		}
		std::cout << std::endl;
	}
	int size() {
	    return _size;
	}
	int capacity() {
	    return _capacity;
	}
	MyVector& operator = (MyVector& v) {
	    if (this != &v) {
	        this->_size = v.size();
	        this->_capacity = v.capacity();
	        this->_data = new int [v.capacity()];
	        for (int i = 0; i < this->_size; i++) this->_data[i] = v[i];
	    }
	    return *this;
	}
};

int main() {
	MyVector a(5, 29);
	MyVector b;
	MyVector c(a);
	MyVector d;
	d = a;
	a[1] = 1;
	a.print();
	b.print();
	c.print();
	d.print();
	return 0;
}
