#include <iostream>

class MyVector {
public:
	int m_size;
	int* m_data;
    
    MyVector() {
		m_size = 0;
		m_data = nullptr;
	}
	MyVector(int n, int initial) {
		m_size = n;
		m_data = new int[m_size];
		for (int i = 0; i < m_size; i++) m_data[i] = initial;
	}
	MyVector(const MyVector &v) {
	    this->m_size = v.m_size;
	    this->m_data = new int [v.m_size];
	    for (int i = 0; i < this->m_size; i++) this->m_data[i] = v.m_data[i];
	}
	~MyVector() {
		delete[] m_data;
		std::cout << "deleted " << GET_VARIABLE_NAME(this) << std::endl;
	}
	void print() {
		for (int i = 0; i < m_size; i++) {
			std::cout << m_data[i] << " ";
		}
		std::cout << std::endl;
	}
	MyVector& operator=(const MyVector& v) {
	    if (this != &v) {
	        this->m_size = v.m_size;
	        this->m_data = new int [v.m_size];
	        for (int i = 0; i < this->m_size; i++) this->m_data[i] = v.m_data[i];
	    }
	    return *this;
	}
};

int main() {
	MyVector a(5, 29);
	a.m_data[1] = 100;
	a.m_data[2] = 3000;
	a.print();
	MyVector b = a;
	// MyVector b(a);
	b.m_size = 3;
	b.m_data[1] = 777;
	a.print();
	b.print();
	return 0;
}
