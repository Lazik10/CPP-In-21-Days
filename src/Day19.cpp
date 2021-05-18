#include "Day19.h"
#include "Template.h"
#include "Cat.h"

#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <set>

void Day19()
{
    Template();
    TemplateArrays();
    TemplateStaticCount();

    Vector();
    List();
    Map();
}

void Template()
{
    Array<int> arrayOfNumbers;
    Array<Cat> arrayOfCats;
    Cat* p_cat;

    for (int i = 0; i < arrayOfNumbers.GetLength(); i++)
    {
        arrayOfNumbers[i] = i * 2;
        p_cat = new Cat(i);
        arrayOfCats[i] = *p_cat;
        delete p_cat;
    }

    for (int i = 0; i < arrayOfNumbers.GetLength(); i++)
    {
        std::cout << arrayOfNumbers[i] << std::endl;
    }

    for (int i = 0; i < arrayOfCats.GetLength(); i++)
    {
        std::cout << arrayOfCats[i].GetAge() << std::endl;
    }

    // Friend function example
    Invade(arrayOfNumbers);

    // General friend classes and template functions
    bool stop = false;
    int indentation, value;

    while (!stop)
    {
        std::cout << "Set indentation (0-9): ";
        std::cout << "and value. (-1 for exit): ";
        std::cin >> indentation >> value;

        if (indentation < 0)
            break;

        if (indentation > 9)
        {
            std::cout << "Please use numbes between 0-9.";
            continue;
        }

        arrayOfNumbers[indentation] = value;
    }

    std::cout << "\nHere is whole array: \n";
    std::cout << arrayOfNumbers << std::endl;
}

void TemplateArrays()
{
    Array<int> arrayOfNumbers2;
    Array<Animal> arrayOfAnimals2;
    
    FunctionFillingArrayOfNumbers(arrayOfNumbers2);
    FunctionFillingArrayOfAnimals(arrayOfAnimals2);

    std::cout << "\n array of numbers: \n" << arrayOfNumbers2;
    std::cout << "\n array of animals: \n" << arrayOfAnimals2;
}

void TemplateStaticCount()
{
    std::cout << "Get total number of templated arrays for int: " << Array<int>::GetArrayCount() << "\n";
    std::cout << "Get total number of templated arrays for Animal: " << Array<Animal>::GetArrayCount() << "\n";

    Array<int> arrayOfNumbers;
    Array<Animal> arrayOfAnimals;

    std::cout << "Get total number of templated arrays for int: " << Array<int>::GetArrayCount() << "\n";
    std::cout << "Get total number of templated arrays for Animal: " << Array<Animal>::GetArrayCount() << "\n";

    Array<int>* p_intArray = new Array<int>;
    std::cout << "Get total number of templated arrays for int: " << Array<int>::GetArrayCount() << "\n";
    delete p_intArray;
    std::cout << "Get total number of templated arrays for int: " << Array<int>::GetArrayCount() << "\n";
}

void Vector()
{
    std::vector<int> vector1;
    std::vector<Animal> vector2(50);
    // capacity() - tells us how many elements this vector can take before expanding its own capacity
    std::cout << "Vector2 has: " << vector2.capacity() << " elements." << std::endl;
    // size() - tells exact size of vector (number of elements)
    std::cout << "Vector2 has: " << vector2.size() << " elements." << std::endl;
    // empty() - returns true if vector is empty
    std::cout << "Vector1 is empty: ";
    if (vector1.empty())
        std::cout << "TRUE\n";
    else
        std::cout << "FALSE\n";
    // [] index option
    Animal maya(1000);
    vector2[10] = maya;
    std::cout << "Maya's age is: " << vector2[10] << std::endl;
    std::cout << "Maya's age is: " << vector2[10].GetAge() << std::endl;
    // push_back() - puts new element at the end of the vector
    vector2.push_back(maya);
    std::cout << "Vector2 has: " << vector2.size() << " elements." << std::endl;
    // pop_back() - removes last element in the vector
    vector2.pop_back();
    std::cout << "Vector2 has: " << vector2.size() << " elements." << std::endl;
    // max_size() - returns max size of vecotr of current data type
    std::cout << "Vector1 can have max: " << vector1.max_size() << " number of elements\n";
    std::cout << "Vector2 can have max: " << vector2.max_size() << " number of elements\n";
    typedef std::vector<Animal> zoo;
    zoo zoo1;
    zoo1.push_back(maya);
    vector2[0] = maya;
    // front() - returns first element
    std::cout << "Age of first Cat in vector is: " << vector2.front() << "\n";
    // back() - returns last element
    std::cout << "Age of last Cat in vector is: " << vector2.back() << "\n";
    // at() - it is safer than index number, because it checks for range - with error message/exception out_of_range
    std::cout << "Age of Cat at position .at(x) in vector is: " << vector2.at(49) << "\n";
    // insert() - inserts element at nth position
    vector2.insert(vector2.begin() + 15, maya);
    std::cout << "Age of Cat in 15th position in vector is: " << vector2.at(15) << "\n";
    std::cout << "Vector2 has: " << vector2.size() << " elements." << std::endl;
    // erase() - erases nth element or range of elements
    if (vector1.size() > 6)
        vector1.erase(vector1.begin() + 5);
    if (vector1.size() > 4)
        vector1.erase(vector1.begin(), vector1.begin() + 3);
    // remove() - removes one or more elements from vector with specific value or condition
    // it will reorder the vector but the size stays the same, so if we delete for example 5 elements
    // last 5 elements will have random numbers after the remove function
    vector1 = { 3,3,3,10 };
    std::remove(vector1.begin(), vector1.end(), 3);
    std::cout << "Vector1 has: " << vector1.size() << " elements." << std::endl;
    for (int i = 0; i < vector1.size(); i++)
        std::cout << vector1[i] << " ";
}

void List()
{
    std::list<int> list { 1,2,3,4,5,6,7,8,9,10 };
    std::list<int>::const_iterator itr = list.begin();
    // list has all the same methods as vector, but it also has 2 more
    // push_front() - adds element at first position
    list.push_front(0);
    for (itr; itr != list.end(); ++itr) 
        std::cout << *itr << " ";
    std::cout << std::endl;
    // pop_front() - removes element from first position
    list.pop_front();
    itr = list.begin();
    for (itr; itr != list.end(); ++itr)
        std::cout << *itr << " ";
    // end() - points one node after the end of the container, we can never reach that point with our iterator
    // that is why our for loop ends if itr!=list.end()
}

void Deque()
{
    // similar to vector
    std::deque<int> deque;
}

void Stack()
{
    // <stack> LIFO
}

void Queue()
{
    // <queue> FIFO
}

typedef std::map<int, Animal> Map_of_animals;

void Map()
{
    // Map
    Map_of_animals animals;

    Animal cat(10);
    Animal dog(15);
    Animal parrot(20);
    Animal bird(10);
    Animal snake(40);
    animals[0] = cat;
    animals[1] = dog;
    animals[2] = parrot;
    animals[3] = snake;
    animals[2] = bird;

    ShowMap(animals);

    // Multimap
    std::multimap<int,Animal> animals1;

    animals1.insert(std::pair <int, Animal> (0, cat));
    animals1.insert(std::pair <int, Animal>(1, dog));
    animals1.insert(std::pair <int, Animal>(2, parrot));
    animals1.insert(std::pair <int, Animal>(3, snake));
    animals1.insert(std::pair <int, Animal>(2, bird));

    ShowMultimap(animals1);
}

void Set()
{
    // <set>
}
