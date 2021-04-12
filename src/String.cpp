#include "String.h"


String::String()
{
    m_string = new char[1];
    m_string[0] = '\0';
    m_length = NULL;
}

String::String(const char* const string)
{
    m_length = strlen(string);
    m_string = new char[m_length + 1];
    for (unsigned short i = 0; i < m_length; i++)
    {
        m_string[i] = string[i];
    }
    m_string[m_length] = '\0';
}

String::String(const String& string)
{
    m_length = string.GetLength();
    m_string = new char[m_length + 1];
    for (unsigned short i = 0; i < m_length; i++)
    {
        m_string[i] = string[i];
    }
    m_string[m_length] = '\0';
}

String::~String()
{
    delete[] m_string;
    m_length = 0;
}

char& String::operator[](unsigned short indentation)
{
    if (indentation > m_length)
        return m_string[m_length - 1];
    else
        return m_string[indentation];
}

char String::operator[](unsigned short indentation) const
{
    if (indentation > m_length)
        return m_string[m_length - 1];
    else
        return m_string[indentation];
}

String String::operator+(const String& string)
{
    unsigned short string_length = m_length + string.GetLength();
    String temp(string_length);
    unsigned short i;

    for (i = 0; i < m_length; i++)
    {
        temp[i] = m_string[i];
    }
    
    for (unsigned short j = 0; j < string.GetLength(); j++, i++)
    {
        temp[i] = string[j];
    }

    temp[string_length] = '\0';
    return temp;
}

void String::operator+=(const String& string)
{
    // stringA(3) += stringB(5);
    unsigned short string_length = string.GetLength();
    unsigned short new_length = m_length + string_length;

    String temp(new_length);

    unsigned short i;
    for (i = 0; i < m_length; i++)
    {
        temp[i] = m_string[i];
    }

    for (unsigned short j = 0; j < string_length; j++, i++)
    {
        temp[i] = string[i - m_length];
        //temp[i] = string[j];
    }

    temp[new_length] = '\0';
    *this = temp;
}

String& String::operator=(const String& string)
{
    if (this == &string)
        return *this;

    delete[] m_string;
    m_length = string.GetLength();
    m_string = new char[m_length+1];

    for (unsigned short i = 0; i < m_length; i++)
    {
        m_string[i] = string[i];
    }
    m_string[m_length] = '\0';
    return *this;
}

String::String(unsigned short length)
{
    m_string = new char[length + 1];
    for (unsigned short i = 0; i <= length; i++)
    {
        m_string[i] = '\0';
    }
    m_length = length;
}
