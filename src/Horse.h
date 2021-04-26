#pragma once

#include <iostream>

typedef int HEIGHT;

class Horse
{
public:
    enum class COLOR { RED, GREEN, BLUE, YELLOW, WHITE, BLACK, BROWN };

    Horse();
    Horse(COLOR color, HEIGHT height);
    virtual ~Horse();

    inline virtual HEIGHT GetHeight() const { return m_height; };
    inline virtual COLOR GetColor() const { return m_color; };
    inline virtual int GetAge() const { return m_age; };

    virtual void HorseSound() const;
    virtual void Run() const;
private:
    int m_age;
    COLOR m_color;
    HEIGHT m_height;
};


