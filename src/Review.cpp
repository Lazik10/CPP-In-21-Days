#include "Review.h"

void Review()
{
    PartsListExmaple();
}

void PartsListExmaple()
{
    PartsList pl;
    Parts* p_part = nullptr;

    int parts_id;
    int value;
    int choice;

    while (true)
    { 
        std::cout << "(0) Exit\n (1) Car\n (2) Airplane\n";
        std::cin >> choice;

        if (!choice)
            break;

        std::cout << "New parts ID?: ";
        std::cin >> parts_id;

        if (choice == 1)
        {
            std::cout << "Model year? ";
            std::cin >> value;
            p_part = new CarParts(value, parts_id);
        }
        else if (choice == 2)
        {
            std::cout << "Engine number? ";
            std::cin >> value;
            p_part = new AeroplaneParts(value, parts_id);
        }

        pl.Insert(p_part);
    }
    pl.Iterrate();
}


// Parts

Parts::Parts() :
    m_partNumber(1)
{
}

Parts::Parts(int part_number) :
    m_partNumber(part_number)
{
}

Parts::~Parts()
{
}

void Parts::Show() const
{
    std::cout << "\n Part number: " << m_partNumber << std::endl;
}


// Car Parts

CarParts::CarParts() :
    m_year(94)
{

}

CarParts::CarParts(int year, int part_number) :
    Parts(part_number), m_year(year)
{

}

CarParts::~CarParts()
{
}

void CarParts::Show() const
{
    Parts::Show();
    std::cout << "Model year is: " << m_year << std::endl;
}


// Aeroplane Parts

AeroplaneParts::AeroplaneParts() :
    m_engineNumber(1)
{
}

AeroplaneParts::AeroplaneParts(int engine_number, int part_number) :
    Parts(part_number), m_engineNumber(engine_number)
{

}

AeroplaneParts::~AeroplaneParts()
{
}

void AeroplaneParts::Show() const
{
    Parts::Show();
    std::cout << "Engine number is: " << m_engineNumber << std::endl;
}


// Node Parts

NodeParts::NodeParts(Parts* parts)
{
    m_parts = parts;
    m_next = nullptr;
}

NodeParts::~NodeParts()
{
    delete m_parts;
    m_parts = nullptr;
    delete m_next;
    m_next = nullptr;
}

void NodeParts::AddNext(NodeParts* node)
{
    m_next = node;
}

NodeParts* NodeParts::GetNext() const
{
    return m_next;
}

Parts* NodeParts::GetParts() const
{
    if (m_parts)
        return m_parts;
    else
        return NULL;
}

// Parts List


PartsList::PartsList() :
    m_p_head(nullptr), m_number_of_parts(NULL)
{
}

PartsList::~PartsList()
{
    delete m_p_head;
    m_p_head = nullptr;
}

Parts* PartsList::Find(int& position, int part_number) const
{
    NodeParts* p_node = nullptr;
    for (p_node = m_p_head, position = 0; p_node != nullptr; p_node = p_node->GetNext(), position++)
    {
        if (p_node->GetParts()->GetPartNumber() == part_number)
            break;
    }

    if (p_node == nullptr)
        return nullptr;
    else 
        return p_node->GetParts();
}

Parts* PartsList::GetFirst() const
{
    if (m_p_head)
        return m_p_head->GetParts();
    else 
        return nullptr;
}

void PartsList::Insert(Parts* p_parts)
{
    NodeParts* p_node = new NodeParts(p_parts);
    NodeParts* p_actuall = m_p_head;
    NodeParts* p_next = nullptr;

    int new_id = p_parts->GetPartNumber();
    int next_id = NULL;
    m_number_of_parts++;

    if (!m_p_head)
    {
        m_p_head = p_node;
        return;
    }

    // If this parts has lower number then it is our new head
    if (m_p_head->GetParts()->GetPartNumber() > new_id)
    {
        p_node->AddNext(m_p_head);
        m_p_head = p_node;
        return;
    }

    for (;;)
    {
        // if there is no next, add this one
        if (!p_actuall->GetNext())
        {
            p_actuall->AddNext(p_node);
            return;
        }

        // if it belongs behind this, but before next then insert it here, otherwise go to next one
        p_next = p_actuall->GetNext();
        next_id = p_next->GetParts()->GetPartNumber();

        if (next_id > new_id)
        {
            p_actuall->AddNext(p_node);
            p_node->AddNext(p_next);
            return;
        }
        p_actuall = p_next;
    }
}

void PartsList::Iterrate() const
{
    if (!m_p_head)
        return;
    
    NodeParts* p_node = m_p_head;
    
    do
    {
        p_node->GetParts()->Show();
    } while (p_node = p_node->GetNext());
}

Parts* PartsList::operator[](int offset) const
{
    NodeParts* p_node = m_p_head;

    if (!m_p_head)
        return nullptr;

    if (offset > m_number_of_parts)
        return nullptr;

    for (int i = 0; i < offset; i++)
    {
        p_node = p_node->GetNext();
    }

    return p_node->GetParts();
}
