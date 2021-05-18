#pragma once

#include <map>

void Day19();

void Template();
void TemplateArrays();
void TemplateStaticCount();

// STL - Standard Template Library

// <vector>
void Vector();
// <list>
void List();
// <deque>
void Deque();

// <stack> LIFO
void Stack();
// <queue> FIFO
void Queue();

//Asociative containers
// <map>
// map and multimap
void Map();
// <set>
// set and multiset
void Set();



template<class T, class A>
void ShowMap(const std::map<T, A>& map);

template<class T, class A>
void ShowMap(const std::map<T, A>& map)
{
    for (std::map<T, A>::const_iterator itr = map.begin(); itr != map.end(); ++itr)
    {
        std::cout << itr->first << ": " << itr->second << "\n";
    }

    std::cout << std::endl;
}

template<class T, class A>
void ShowMultimap(const std::multimap<T, A>& map);

template<class T, class A>
void ShowMultimap(const std::multimap<T, A>& map)
{
    for (std::map<T, A>::const_iterator itr = map.begin(); itr != map.end(); ++itr)
    {
        std::cout << itr->first << ": " << itr->second << "\n";
    }

    std::cout << std::endl;
}