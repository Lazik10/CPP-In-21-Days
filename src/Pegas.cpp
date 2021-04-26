#include "Pegas.h"

Pegas::Pegas()
{
    std::cout << "Pega's constructor...\n";
}

Pegas::Pegas(Horse::COLOR color, HEIGHT height, bool is_migrating, int num_of_followers) :
    Horse(color, height), Bird(Bird::COLOR::BLACK, is_migrating), m_number_of_followers(num_of_followers)
{
    std::cout << "Constructor Pegas...\n";
}

Pegas::~Pegas()
{
    std::cout << "Pega's destructor...\n";
}

void Pegas::BirdSound() const
{
    HorseSound();
}

void Pegas::Fly() const
{
    std::cout << "I can fly!\n";
}

void Pegas::Run() const
{
    std::cout << "Runing 10 metres\n";
}
