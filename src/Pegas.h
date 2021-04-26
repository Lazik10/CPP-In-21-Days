#pragma once

#include "Horse.h"
#include "Bird.h"

class Pegas : public Bird, public Horse
{
public:
    Pegas();
    // It would be better to make new color.h file so I cna use the same colors for Horse and Birds
    // and pass them as a color for both
    Pegas(Horse::COLOR color, HEIGHT height, bool is_migrating, int num_of_followers);
    virtual ~Pegas();

    inline virtual int GetFollowers() { return m_number_of_followers; };
    inline Horse::COLOR GetColor() const override { return Horse::GetColor(); };

    virtual void BirdSound() const override;
    virtual void Fly() const override;
    virtual void Run() const override;
private:
    int m_number_of_followers;
};

