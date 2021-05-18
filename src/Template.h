#pragma once
#include <iostream>
#include "Animal.h"
#include "Cat.h"

const int defaultvalue = 10;

// Template definition
template <class T>
class Array
{
public:
    Array(int length = defaultvalue);
    Array(const Array& array);
    ~Array() { delete[] p_type; m_count--; }

    void ArrayFunction(Array<T>& array, Array<int>& array1);

    Array& operator=(const Array& array);
    T& operator[](int indent) { return p_type[indent]; }
    const T& operator[](int indent) const { return p_type[indent]; }

    inline int GetLength() const { return m_length; }

    static int GetArrayCount() { return m_count; }

    // Friendship in templates
    friend void Invade(Array<int> array);

    // when implementing friend template function we need to remember to also put the template specification here
    template <typename U>
    friend std::ostream& operator<<(std::ostream& output, Array<U>& arr);

private:
    T* p_type;
    int m_length;
    static int m_count;
};

// static member initialization
template <class T>
int Array<T>::m_count = 0;

template<class T>
Array<T>::Array(int length) :
    m_length(length)
{
    p_type = new T[length];
    for (int i = 0; i < length; i++)
    {
        p_type[i] = 0;
    }

    m_count++;
}

template<class T>
Array<T>::Array(const Array& array)
{
    m_length = array.m_length;
    p_type = new T[m_length];

    for (int i = 0; i < array.m_length; i++)
    {
        p_type[i] = array[i];
    }

    m_count++;
}

template<class T>
inline void Array<T>::ArrayFunction(Array<T>& array, Array<int>& array1)
{
    // example of template function which takes array of different types of objects
    // as a first argument and array of ints as a second
}

template<class T>
Array<T>& Array<T>::operator=(const Array& array)
{
    if (this == &array)
        return;

    delete[] p_type;
    m_length = array.m_length;
    p_type = new T[m_length];

    for (int i = 0; i < m_length; i++)
    {
        p_type[i] = array[i];
    }
    return *this;
}

template <typename U>
std::ostream& operator<<(std::ostream& output, Array<U>& arr)
{
    for (int i = 0; i < arr.GetLength(); i++)
    {
        output << "[" << i << "]" << arr[i] << std::endl;
    }
    return output;
}

Array<Animal>::Array(int length) :
    m_length(length)
{
    p_type = new Animal[length];
    std::cout << "Specialized consturctor call\n";

    m_count++;
}

void FunctionFillingArrayOfNumbers(Array<int>& array);
void FunctionFillingArrayOfAnimals(Array<Animal>& array);

void Invade(Array<int> array)
{
    std::cout << "\n*** Invade ***\n";

    for (int i = 0; i < array.GetLength(); i++)
    {
        std::cout << "i: " << array.p_type[i] << std::endl;
    }
    std::cout << std::endl;
}

void FunctionFillingArrayOfNumbers(Array<int>& array)
{
    bool stop = false;
    int indentation, value;

    while (!stop)
    {
        std::cout << "Please insert your indentation (0-2) and value: ";
        std::cout << "(-1) for exit: ";
        std::cin >> indentation >> value;

        if (indentation < 0)
            break;
        if (indentation > 2)
        {
            std::cout << "*** Please insert number between 0 and 2. ***\n";
            continue;
        }
        array[indentation] = value;
    }
}

void FunctionFillingArrayOfAnimals(Array<Animal>& array)
{
    Animal* p_animal;
    for (int i = 0; i < array.GetLength(); i++)
    {
        p_animal = new Animal(i * 10);
        array[i] = *p_animal;
        delete p_animal;
    }
}