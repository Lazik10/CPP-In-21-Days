#include "Bird.h"

Bird::Bird():
    m_weight(0)
{
    std::cout << "Bird's constructor!\n";
}

Bird::Bird(COLOR color, bool is_migrating) :
    m_weight(1), m_color(color), m_is_migrating(is_migrating)
{

}

Bird::~Bird()
{
    std::cout << "Bird's destructor\n";
}

void Bird::BirdSound() const
{
    std::cout << "Pip,pip,pip!\n";
}

void Bird::Fly() const
{
    std::cout << "I can fly...\n";
}

