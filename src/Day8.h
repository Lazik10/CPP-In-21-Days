#pragma once
#include <string>

class Cat
{
public:
    Cat();
    Cat(std::string name);
    ~Cat();
    inline int GetAge() { return _age; };
    inline void SetAge(int age) { _age = age; };
    inline int GetHeight() { return this->_height; };
    inline void SetHeight(int height) { this->_height = height; };

private:
    int _age;
    int _height;
    std::string _name;
};

// Pointers
void Day8();
void AdressSymbolExample();
void PointerExample();
void PointersAndAdresses();
void NewAndDelete();
//void MemoryLeakExample();
void CreatingAndDeletingObjectsInJunkyard();
void AccessToDataMembers();
void ConstPointers();

void Exercise17();
