#include "Day17.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Animal.h"

void Day17()
{
    Iostream();

    CinProblem();
    CinProblem2();
    CinMethods();
    CinMethods2();
    CinMethods3();
    CinMethods4();
    CinMethods5();
    CinMethods6();

    CoutMethods();
    CoutMethods2();
    CoutMethods3();
    CoutMethods4();

    SetF();
    PrintF();
    OutputFormating();

    OpeningFiles();
    OpeningFilesWithFlags();
    BinaryFiles();
    Main();
}

void Iostream()
{
    int m_int;
    long m_long;
    double m_double;
    float m_float;
    unsigned int m_uint;

    std::cout << "Int: ";
    std::cin >> m_int;

    std::cout << "Long: ";
    std::cin >> m_long;

    std::cout << "Double: ";
    std::cin >> m_double;

    std::cout << "Float: ";
    std::cin >> m_float;

    std::cout << "Unsigned Int: ";
    std::cin >> m_uint;

    std::cout << "\n\nInt: " << m_int << std::endl;
    std::cout << "Long: " << m_long << std::endl;
    std::cout << "Double: " << m_double << std::endl;
    std::cout << "Float " << m_float << std::endl;
    std::cout << "Unsigned Int: " << m_uint << std::endl;

    char m_name[50];
    std::cout << "Write your name: ";
    std::cin >> m_name;
    std::cout << "Your name is: " << m_name;
}

void CinProblem()
{
    char yourName[50];
    std::cout << "\n\nSet your name: ";
    std::cin >> yourName;
    std::cout << "Your name is: " << yourName;
    
    std::cout << "\nSet your full name: ";
    std::cin >> yourName;
    std::cout << "Your full name is: " <<yourName;
}

void CinProblem2()
{
    int m_int;
    long m_long;
    double m_double;
    float m_float;
    char m_word[50];
    unsigned int m_uint;

    std::cout << "\n\nInt: ";
    std::cin >> m_int;

    std::cout << "Long: ";
    std::cin >> m_long;

    std::cout << "Double: ";
    std::cin >> m_double;

    std::cout << "Float: ";
    std::cin >> m_float;

    std::cout << "Word: ";
    std::cin >> m_word;

    std::cout << "Unsigned Int: ";
    std::cin >> m_uint;

    std::cout << "\n\nInt: " << m_int << std::endl;
    std::cout << "Long: " << m_long << std::endl;
    std::cout << "Double: " << m_double << std::endl;
    std::cout << "Float " << m_float << std::endl;
    std::cout << "Word " << m_word << std::endl;
    std::cout << "Unsigned Int: " << m_uint << std::endl;

    std::cout << "\n\nInt, Long, Double, Float, Word, Unsigned Int: ";
    std::cin >> m_int >> m_long >> m_double >> m_float >> m_word >> m_uint;

    std::cout << "\n\nInt: " << m_int << std::endl;
    std::cout << "Long: " << m_long << std::endl;
    std::cout << "Double: " << m_double << std::endl;
    std::cout << "Float " << m_float << std::endl;
    std::cout << "Word " << m_word << std::endl;
    std::cout << "Unsigned Int: " << m_uint << std::endl;
}

void CinMethods()
{
    // cin.get() without parameters
    char character;
    while ((character = std::cin.get()) != EOF)
    {
        std::cout << "Character is: " << character << std::endl;
    }
    // To end this program press Ctrl + Z
    std::cout << "End";
}

void CinMethods2()
{
    // cin.get() method with one parameter
    char a, b, c;
    std::cout << "\nInput three letters: ";
    std::cin.get(a).get(b).get(c);
    std::cout << "A: " << a << "\nB: " << b << "\nC: " << c << std::endl;
}

void CinMethods3()
{
    // cin.get() method with char array as a parameter
    char stringOne[256];
    char stringTwo[256];

    std::cout << "Input first string: ";
    std::cin.get(stringOne, 256);
    std::cout << "First string is: " << stringOne << std::endl;

    std::cout << "Input second string: ";
    std::cin >> stringTwo;
    std::cout << "Second string is: " << stringTwo << std::endl;
}

void CinMethods4()
{
    char firstString[256];
    char secondString[256];
    char thirdString[256];

    std::cout << "Input first string: ";
    std::cin.getline(firstString, 256);
    std::cout << "First string is: " << firstString << std::endl;

    std::cout << "Input second string: ";
    std::cin >> secondString;
    std::cout << "Second string is: " << secondString << std::endl;
    
    std::cout << "Input third string: ";
    std::cin.getline(thirdString, 256);
    std::cout << "Third string is: " << thirdString << std::endl;
}

void CinMethods5()
{
    char firstString[256];
    char secondString[256];

    std::cout << "Input first string: ";
    std::cin.get(firstString, 256);
    std::cout << "First string is: " << firstString << std::endl;

    std::cout << "Input second string: ";
    std::cin.getline(secondString, 256);
    std::cout << "Second string is: " << secondString << std::endl << std::endl;

    std::cout << "Input first string: ";
    std::cin.get(firstString, 256);
    std::cout << "First string is: " << firstString << std::endl;
    std::cin.ignore(255, '\n');

    std::cout << "Input second string: ";
    std::cin.getline(secondString, 256);
    std::cout << "Second string is: " << secondString << std::endl;
}

void CinMethods6()
{
    char character;
    std::cout << "Enter your sentence: ";
    while (std::cin.get(character))
    {
        if (character == '!')
            std::cin.putback('@');
        else
            std::cout << character;

        if (std::cin.peek() == '#')
        {
            std::cin.ignore(1, '#');
        }
    }
}

void CoutMethods()
{
    std::cout.put('H').put('e').put('l').put('l').put('o');
    std::cout << std::endl;

    std::cout.put('H') << "ello";
}

void CoutMethods2()
{
    char firstString[] = "First word second word";

    int fullLength = strlen(firstString);
    int tooShortLength = fullLength - 4;
    int tooLongLength = fullLength + 6;

    std::cout.write(firstString, fullLength) << "\n";
    std::cout.write(firstString, tooShortLength) << "\n";
    std::cout.write(firstString, tooLongLength) << "\n";
}

void CoutMethods3()
{
    std::cout << "Begining >";
    std::cout.width(25);
    std::cout << 123 << "< End\n";

    std::cout << "Begining >";
    std::cout.width(25);
    std::cout << 123 << "< Next >" <<
        456 << "< End\n";

    std::cout << "Begining >";
    std::cout.width(4);
    std::cout << 123456 << "< End\n";
}

void CoutMethods4()
{
    std::cout << "Begining >";
    std::cout.width(25);
    std::cout << 123 << "< End\n";

    std::cout << "Begining >";
    std::cout.width(25);
    std::cout.fill('*');
    std::cout << 123 << "< End\n";
}

void SetF()
{
    const int number = 185;
    std::cout << "Number is: " << number << std::endl;

    // this std::hex flag will set the cout to hexadecimal outputs and we need to manually restore to default flag
    // otherwise it will persist until the end of the function
    std::cout << "Number is: " << std::hex << number << " " << number << std::endl;
    std::cout << number;

    const int number2 = 123;
    std::cout << number2;

    // with setf() method we can change the output formating
    std::cout.setf(std::ios::left | std::ios::internal | std::ios::hex | std::ios::showbase);
    std::cout << "\n" << number;
}

void PrintF()
{
    // %s - strings
    // %d - int numbers
    // %l - long int numbers
    // %ld - long double numbers
    // %f - float numbers
    const int age = 10;
    const float number = 180.1f;

    printf("%s", "Hello\n");
    printf("I am %d years old.\n", age);
    printf("Float number is: %20.5f", number);
}

void OutputFormating()
{
    /*
    \n - new line
    \r - cursor return
    \t - tab
    \\ - backslash
    \ddd - octal number (ASCI)
    \a - ring/bell/beep
    */

    // Manipulators without needing <iomanip>
    /*
    flush - empty output buffer
    endl - new line
    oct - sets output to octal numbers
    dec - sets output to decimal numbers
    hex - sets output to hexadecimal numbers
    */

    // Manipulators with need of <iomanip>
    /*
    setbase() - set base output (0 - decimal, 8 - octal, 10 - decimal, - 16 hexadecimal)
    setw() - sets minimal output width
    setfill() - sets fill sign
    setprecision() - sets precision for float numbers
    setiosflags() - sets one or more output flags
    resetiosflags() - resets one or more output flags

    // set/reset iosflags - FLAGS
    /*
    ios::left - sets output alignment to left
    ios::right - sets output alignment to right
    ios::internal - sign is alingment to left and value to right
    ios::hex - hexadecimal output
    ios::dec - decimal output
    ios::oct - octal output
    ios::showbase - adds 0x before hexadecimal number and 0 before octal number
    ios::showpoint - adds required zeros by specified precision
    ios::uppercase - hexadecimal numbers and scientific numbers use upper letters
    ios::showpos - shows plus before positive numbers
    ios::scientific - scientific number notation
    ios::fixed - floating number value is showed in base notation not scientific
    */
}

void FileLogicFunctions()
{
    // eof() - returns true if you reached end in iostream object
    // bad() - returns true if you try not accessible operation
    // fail() - returns true if everytime function bad() is true or some other operation fails
    // good() - returns true if all other functions return are fail

    // if(inputFile.fail()) is the same as if(!inputFile) and if(inputeFile.good()) is the same as if(inputFile)
}

void OpeningFiles()
{
    // Opening for output
    std::ofstream fout("file_name.cpp");

    // Opening for input
    std::ifstream fin("file_name.cpp");

    // Don't forget to close them when we finish working with them (to prevent data corruption and correct save)
    fout.close();
    fin.close();

    // Example:
    char fileName[80];
    char buffer[255];
    std::cout << "Set file name: ";
    std::cin >> fileName;

    std::ofstream outputFile(fileName);
    outputFile << "This line will be written into the file direfctly.\n";
    std::cout << "Insert your text: ";
    std::cin.ignore(1, '\n');
    std::cin.getline(buffer, 255);
    outputFile << buffer;
    outputFile.close();

    std::ifstream inputFile(fileName);
    std::cout << "This is input file content\n\n";
    char character;
    while (inputFile.get(character))
    {
        std::cout << character;
    }

    std::cout << "\nEnd of file";

    inputFile.close();
}

void OpeningFilesWithFlags()
{
    /*
    ios::app - adds content at the end of current content without deleting it
    ios::ate - 
    ios::trunc - default, content replaces the old content
    ios::nocreate - if specified file does not exists opening fails
    ios::noreplace - if specified file already exists opening fails

    By default when opening file it is created if it doesn't already exists and the
    content of that file is deleted if the file already exists, to avoid this default behaviour
    we can use these flags
    */

    char fileName[80];
    char buffer[255];
    std::string line;
    std::cout << "Type your file name: ";
    std::cin >> fileName;

    std::ifstream inputFile(fileName);
    if (inputFile) // check if it exists
    {
        std::cout << "Actual content of the file: \n";
        char character;
        while (inputFile.get(character))
        {
            std::cout << character;
        }

        // These two lines of code are required if we want to work with the file content again
        inputFile.close();
        inputFile.open(fileName);
        if (inputFile.is_open())
        {
            while (getline(inputFile, line))
            {
                std::cout << line;
            }
        }

        std::cout << "\nEnd of the actual file's content\n";
    }
    inputFile.close();

    std::cout << "Opening file " << fileName << " in add mode\n";

    // std::ios::app flag - append new text behind actual content of the file
    std::ofstream outputFile(fileName, std::ios::app);
    if (!outputFile)
    {
        std::cout << "Can't open specific file!\n";
        return;
    }

    std::cout << "Write your own text: ";
    std::cin.ignore(1, '\n');
    std::cin.getline(buffer, 255);
    outputFile << buffer << "\n";
    outputFile.close();

    // resets failure mode settings
    inputFile.clear();
    inputFile.open(fileName);
    if (!inputFile)
    {
        std::cout << "Can't open " << fileName << " file.\n";
        return;
    }

    std::cout << "This is " << fileName << "'s content:\n";

}

void BinaryFiles()
{
    char fileName[80];
    std::cout << "Enter your file name: ";
    std::cin >> fileName;

    std::ofstream fout(fileName, std::ios::binary);
    if (!fout)
    {
        std::cout << "Can't open " << fileName << " name.\n";
        return;
    }

    Animal animal(10, 100);
    // binary write - stores data structure of objects
    fout.write((char*)&animal, sizeof animal);
    fout.close();

    std::ifstream fin(fileName, std::ios::binary);
    if (!fin)
    {
        std::cout << "Can't read from " << fileName << " file.\n";
        return;
    }

    Animal animal2(20, 200);
    std::cout << "Animal's age is: " << animal2.GetAge() << "\n";
    std::cout << "Animal's weight is: " << animal2.GetWeight() << "\n";

    // binary read - can load data structure of objects
    fin.read((char*)&animal2, sizeof animal2);
    std::cout << "Animal's age is: " << animal2.GetAge() << "\n";
    std::cout << "Animal's weight is: " << animal2.GetWeight() << "\n";
    fin.close();
}

void Main()
{ 
    // More explanaiton and examples and research needed
    //int main(int argc, char* argv[])
    //{
    //    return 1;
    //}
}
