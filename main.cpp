#include <iostream>
#include <stdexcept>

using namespace std;

class Vec {
private:
    int* data = nullptr;
    int len = 0;
    int capacity = 0;
public:
    Vec(int);
//    ~Vec();
    void push_back(int);
    int operator[] (int);
};

Vec::Vec(int l)
{
    this->data = new int[l];
    this->capacity = l;
}

//Vec::~Vec()
//{
//    delete[] this->data;
//}

void Vec::push_back(int n)
{
    if (this->len < this->capacity)
    {
        this->data[this->len++] = n;
    }
}

int Vec::operator [](int pos)
{
    if (pos < 0 || pos > len - 1) throw out_of_range("index out of range");
    return this->data[pos];
}

int main(int argc, char *argv[])
{
    int size = 10;
    Vec my_vec(size);

    // push back loop
    for(int i = 0; i < size; i++)
    {
        my_vec.push_back(i);
    }

    // print loop
    for(int i = 0; i < size; i++)
    {
        cout << my_vec[i] << endl;
    }

    // example of accessing index out of range
    try {
        cout << my_vec[10] << endl;
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
