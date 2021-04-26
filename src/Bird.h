#pragma once

#include <iostream>

class Bird
{
public:
    enum class COLOR { RED, GREEN, BLUE, YELLOW, WHITE, BLACK, BROWN };

    Bird();
    Bird(COLOR color, bool is_migrating);
    virtual ~Bird();

    inline virtual COLOR GetColor() { return m_color; };
    inline virtual bool GetMigration() { return m_is_migrating; };

    virtual void BirdSound() const;
    virtual void Fly() const;
private:
    int m_weight;
    COLOR m_color;
    bool m_is_migrating;
};


