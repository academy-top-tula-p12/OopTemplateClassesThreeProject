#include <iostream>
#include <string>

// Array

template <typename T, int size>
class Array
{
    T items[size]{};
public:
    T* GetArray();
    T& operator[](int);
    int Size();
};

template <typename T, int size>
T* Array<T, size>::GetArray() { return items; }

template <typename T, int size>
T& Array<T, size>::operator[](int index)
{
    return items[index];
}

template <typename T, int size>
int Array<T, size>::Size() { return size; }



// Storage


template <typename T>
class Storage
{
    T value;
public:
    Storage(T value) : value{ value } {}
    void Print() { std::cout << value << "\n"; }
    ~Storage() {}
};

template<>
void Storage<double>::Print()
{
    std::cout << std::scientific << value << "\n";
}

template<>
Storage<char*>::Storage(char* const value)
{
    if (!value)
        return;

    int size{ 0 };
    while (value[size] != '\0') size++;
    size++;

    this->value = new char[size];
    for (int i = 0; i < size; i++)
        this->value[i] = value[i];
}

template<>
Storage<char*>::~Storage()
{
    delete[] value;
}


template <typename T>
class Storage8
{
    T items[8];
public:
    void SetItem(int index, T value)
    {
        items[index] = value;
    }

    T GetItem(int index) const
    {
        return items[index];
    }
};

template<>
class Storage8<bool>
{
    uint8_t data{}; // unsigned char
public:
    void SetItem(int index, bool value)
    {
        auto mask = (1 << index);
        if (value)
            data = data | mask;
        else
            data = data & ~mask;
    }

    bool GetItem(int index) const
    {
        auto mask = (1 << index);
        return data & mask;
    }
};

int main()
{
    /*
    Array<int, 10> arr10;
    for (int i = 0; i < arr10.Size(); i++)
        arr10[i] = i + 1;
    for (int i = 0; i < arr10.Size(); i++)
        std::cout << arr10[i] << " ";
    std::cout << "\n";
    */

    /*
    Storage<int> intValue(100);
    Storage<double> dblValue(123.45);

    intValue.Print();
    dblValue.Print();

    std::string str = "Hello Bob";

    Storage<char*> chrValue(str.data());

    chrValue.Print();
    str.clear();
    chrValue.Print();
    */


    Storage8<int> int8;
    Storage8<bool> bool8;

    for (int i = 0; i < 8; i++)
        bool8.SetItem(i, i % 3);
    for (int i = 0; i < 8; i++)
        std::cout << std::boolalpha << bool8.GetItem(i) << "\n";


    // code
    /*float* fptr = new float;
    *fptr = 5.0;
    void* vptr = fptr;
    int* iptr = (int*)vptr;
    std::cout << *iptr;*/

    /*bool flag = true;
    std::cout << std::boolalpha << flag;*/

}
