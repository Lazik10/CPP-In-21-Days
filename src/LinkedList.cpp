#include "LinkedList.h"

// DATA

Data::Data(int value) :
    m_value(value)
{

}

Data::~Data()
{
}

int Data::Evaluate(const Data& data)
{
    if (m_value < data.m_value)
        return IS_LOWER;
    else if (m_value > data.m_value)
        return IS_HIGHER;
    else
        return IS_EQUAL;
}

// NODE

Node::Node()
{
}

Node::~Node()
{
}

InnerNode::InnerNode(Data* data, Node* next) :
    m_data(data), m_next(next)
{

}

InnerNode::~InnerNode()
{
    delete m_next;
    delete m_data;
}

Node* InnerNode::Insert(Data* data)
{
    int result = m_data->Evaluate(*data);

    switch (result)
    {
    case IS_EQUAL:
    case IS_HIGHER:
    {
        InnerNode* data_node = new InnerNode(data, this);
        return data_node;
    }
    case IS_LOWER:
        m_next = m_next->Insert(data);
        return this;
    default:
        break;
    }
    return this;


    return nullptr;
}

void InnerNode::Show()
{
    m_data->Show();
    m_next->Show();
}

TailNode::TailNode()
{
}

TailNode::~TailNode()
{
}

Node* TailNode::Insert(Data* data)
{
    InnerNode* data_node = new InnerNode(data, this);
    return data_node;
}

void TailNode::Show()
{
}

// When creating Head we also need to create Tail as well
HeadNode::HeadNode()
{
    m_next = new TailNode;
}

HeadNode::~HeadNode()
{
    delete m_next;
}

Node* HeadNode::Insert(Data* data)
{
    m_next = m_next->Insert(data);
    return this;
}

void HeadNode::Show()
{
    m_next->Show();
}


// LINKED LIST

LinkedList::LinkedList()
{
    m_head = new HeadNode;
}

LinkedList::~LinkedList()
{
    delete m_head;
}

void LinkedList::Insert(Data* data)
{
    m_head->Insert(data);
}

void LinkedList::ShowAll()
{
    m_head->Show();
}
