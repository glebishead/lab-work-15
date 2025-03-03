#include <iostream> 

class MyVector {
    int _size;
    int _capacity;
    int* _data;
public:
    int size() {return _size;}

    int capacity(){return _capacity;}

    int& operator [] (int i) const {return _data[i];}

    void setValue(int i, int x) {
        if (i >= 0 && i < _size)
            _data[i] = x;
    }

    MyVector() {
        _size = 0;
        _capacity = 8;
        _data = new int[8];
    }

    MyVector(const MyVector& a) {
        _size = a._size;
        _capacity = a._capacity;
        _data = new int[_capacity];
        for (int i = 0; i < _size; i++)
            _data[i] = a[i];
    }

    MyVector(int n, int initialValue) {
        _capacity = 2 * n;
        _size = n;
        _data = new int[2 * n];
        for (int i = 0; i < n; i++)
            _data[i] = initialValue;
    }

    void print() {
        for (int i = 0; i < _size; i++)
            std::cout << _data[i] << " ";
        std::cout << std::endl;
    }

    MyVector& operator = (const MyVector& a) {
        _size = a._size;
        _capacity = a._capacity;
        _data = new int[_capacity];
        for (int i = 0; i < _size; i++)
            _data[i] = a[i];
        return *this;
    }

    ~MyVector() {
        delete[] _data;
    }

    int front() {
        return _data[0];
    }

    int back() {
        return _data[_size - 1];
    }

    void push_back(int x) {
        if (_size < _capacity) {
            _data[_size++] = x;
        }
        else {
            int* new_data = new int[_capacity + 5];
            for (int i = 0; i < _size; i++)
                new_data[i] = _data[i];
            new_data[_size] = x;
            delete[] _data;
            _data = new_data;
            _capacity += 5;
            _size++;
        }
    }
    
    friend MyVector operator + (const MyVector& a, const MyVector& b) {
        MyVector result;

        if (a._size == b._size) {
            for (int i = 0; i < a._size; i++)
                result.push_back(a._data[i] + b._data[i]);
        }
        return result;
    }

    friend MyVector operator - (const MyVector& a, const MyVector& b) {
        MyVector result;

        if (a._size == b._size) {
            for (int i = 0; i < a._size; i++)
                result.push_back(a._data[i] - b._data[i]);
        }
        return result;
    }

    friend int operator * (const MyVector& a, const MyVector& b) {
        int result = 0;

        if (a._size == b._size) {
            for (int i = 0; i < a._size; i++)
                result += a._data[i] * b._data[i];
        }
        return result;
    }

    friend MyVector operator * (const MyVector& a, int k) {
        MyVector result;

        for (int i = 0; i < a._size; i++)
            result.push_back(a._data[i] * k);
        return result;
    }
    
};

int main() {
    int p = 5;
    MyVector a(5, 1); 
    a.print();
    
    MyVector b(5, 2);
    b.print();
    
    MyVector c = a + b;
    std::cout << "Sum: " << std::endl;
    c.print();

    MyVector c1 = a - b;
    std::cout << "Difference: " << std::endl; 
    c1.print();

    int d  = a * b;
    std::cout << d << std::endl;

    MyVector c2 = a * p;
    c2.print();
        


    std::cout << a[3] << std::endl; 
    a.setValue(3, 50); 
    a.setValue(3, 100); 
    a.setValue(1, 200); 

    b.setValue(1, 777); 
    std::cout << a.front(); 
    
    return 0; 
}
