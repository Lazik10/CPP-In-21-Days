#include <iostream>

void Review();
void PartsListExmaple();

// ADT CLASS Parts
class Parts
{
public:
    Parts();
    Parts(int part_number);
    virtual ~Parts();

    inline int GetPartNumber() const { return m_partNumber; };
    virtual void Show() const = 0; // Need to be overriden

private:
    int m_partNumber;
};

// Car Parts
class CarParts : public Parts
{
public:
    CarParts();
    CarParts(int year, int part_number);
    ~CarParts();

    virtual void Show() const;
private:
    int m_year;
};

// Aeroplane Parts
class AeroplaneParts : public Parts
{
public:
    AeroplaneParts();
    AeroplaneParts(int engine_number, int part_number);
    ~AeroplaneParts();

    virtual void Show() const;
private:
    int m_engineNumber;
};

class NodeParts
{
public:
    NodeParts(Parts* p_parts);
    ~NodeParts();

    void AddNext(NodeParts* p_node);
    NodeParts* GetNext() const;
    Parts* GetParts() const;
private:
    Parts* m_parts;
    NodeParts* m_next;
};

// List of Parts
class PartsList
{
public:
    PartsList();
    ~PartsList();

    // We need copy constructor and equal operator

    Parts* Find(int& position, int part_number) const;
    inline int GetNumberOfParts() const { return m_number_of_parts; };
    Parts* GetFirst() const;
    void Insert(Parts* parts);
    void Iterrate() const;
    Parts* operator[](int offset) const;
private:
    NodeParts* m_p_head;
    int m_number_of_parts;
};

