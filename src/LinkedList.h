#pragma once

//This shows object oriented access to linked lists. 
//Node is abstract data type. There are 3 node data types.
//Head, Tail and nodes. Only nodes store data.

//Class Data is created as an object stored in linked list

#include <iostream>

enum { IS_LOWER, IS_HIGHER, IS_EQUAL };

class Data
{
public:
    Data(int value);
    ~Data();

    int Evaluate(const Data& data);
    inline void Show() { std::cout << m_value << std::endl; }

private:
    int m_value;
};

class Node;
class HeadNode;
class TailNode;
class InnerNode;

class Node
{
public:
    Node();
    virtual ~Node();
    virtual Node* Insert(Data* data) = 0;
    virtual void Show() = 0;

private:

};


class InnerNode : public Node
{
public:
    InnerNode(Data* data, Node* next);
    ~InnerNode();

    virtual Node* Insert(Data* data) override;
    // Delegate
    virtual void Show() override;

private:
    Node* m_next;
    Data* m_data;
};


class TailNode : public Node
{
public:
    TailNode();
    ~TailNode();

    virtual Node* Insert(Data* data) override;
    virtual void Show() override;

private:

};


class HeadNode : public Node
{
public:
    HeadNode();
    ~HeadNode();

    virtual Node* Insert(Data* data) override;
    virtual void Show() override;

private:
    Node* m_next;

};

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    void Insert(Data* data);
    void ShowAll();
private:
    HeadNode* m_head;
};
