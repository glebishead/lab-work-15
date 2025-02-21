#include <iostream>

using namespace std;

class MyVector
{
private:
    int _size;
    int _capacity;
    int * _data;

public:
    int size()
    {
        return _size;
    }

    int capacity()
    {
        return _capacity;
    }

    int& operator [] (int i) const
    {
        return _data[i];
    }

    void setValue(int i, int x)
    {
        if (i >= 0 && i < _size && x >= 0)
            _data[i] = x;
    }

    MyVector()
    {
        _size = 0;
        _capacity = 8;
        _data = new int [8];
    }

    MyVector(MyVector &v)
    {
        _size = v.size();
        _capacity = v.capacity();
        _data = new int [_capacity];
        for (int i = 0; i < _size; i++)
            _data[i] = v[i];
    }

    MyVector(int n, int initialValue)
    {
        _capacity = 2 * n;
        _size = n;

        _data = new int [2 * n];
        for (int i = 0; i < n; i++)
            _data[i] = initialValue;
    }

    void print()
    {
        for (int i = 0; i < _size; i++)
            cout << _data[i] << " ";
        cout << endl;
    }

    MyVector& operator = (MyVector &v)
    {
        _size = v.size();
        _capacity = v.capacity();
        _data = new int [_capacity];
        for (int i = 0; i < _size; i++)
            _data[i] = v[i];

        return *this;
    }

    ~MyVector()
    {
        delete [] _data;
    }

    int front()
    {
        return _data[0];
    }
    
    int back()
    {
        return _data[_size - 1];
    }
    
    int push_back(int x)
    {
        if (_size < _capacity) {
            _data[_size++] = x;
        }
        else {
            int * new_data = new int [_capacity + 5];
            for (int i = 0; i < _capacity; i++)
                new_data[i] = _data[i];
            new_data[_capacity] = x;
            delete [] _data;
            _data = new_data;
            _capacity += 5;
            _size++;
        }
};

int main()
{
    MyVector a(5, 29);
    a.print();

    cout << a[3] << endl;
    a.setValue(3, 50);

    a.setValue(3, 100);
    a.setValue(1, 200);

    a.print();

    MyVector b = a;

    b.print();

    b.setValue(1, 777);

    a.print();
    b.print();

    cout << a.front();
    

    return 0;
}
