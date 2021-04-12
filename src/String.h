#pragma once

#include <iostream>
#include <string.h>

class String
{
public:
    // Constructors
    String();
    String(const char* const string);
    // Copy constr
    String(const String& string);
    // Destructor
    ~String();

    // Overloaded operators
    char& operator[](unsigned short indentation);
    char operator[](unsigned short indentation) const;
    String operator+(const String& string);
    void operator+=(const String & string);
    String& operator=(const String & string);

    // Public methods
    unsigned short GetLength() const { return m_length; };
    const char* GetString() const { return m_string; };
private:
    // Private constructor
    String(unsigned short lenght);

    char* m_string;
    unsigned short m_length;
};
