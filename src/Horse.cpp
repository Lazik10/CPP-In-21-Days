#include "Horse.h"

Horse::Horse() :
    m_age(0)
{
    std::cout << "Horse's constructor\n";
}

Horse::Horse(COLOR color, HEIGHT height) :
    m_age(0), m_color(color), m_height(height)
{
    std::cout << "Horse's constructor\n";
}

Horse::~Horse()
{
    std::cout << "Horse's destructor\n";
}

void Horse::HorseSound() const
{
    std::cout << "Ihahahaha!\n";
}

void Horse::Run() const
{
    std::cout << "Runing 5 metres\n";

}

