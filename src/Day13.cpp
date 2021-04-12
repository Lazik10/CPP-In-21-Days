#include "Day13.h"
#include "String.h"

#include <limits>

void Day13()
{
    Array();
    BastetOfCats();
    CatFamily();
    CatFamilyAtHeap();
    ArrayOfChars();
    StrCopy();
    StringClassTest();
    LinkedListTest();
    Exercise21();
}

void Array()
{
    // Array initializaton
    int array[5] = { 10, 20, 30, 40, 50 };
    // we don't have to specify how large the array is going to be
    int array1[] = { 10, 20, 30, 40, 50 };
    
    // to get an array lenght we can use sizeof method
    // it will take the saze of the whole array and divide it by size of an element of that array
    const int array_lenght = sizeof(array1) / sizeof(array1[0]);
    std::cout << "Array1 has " << array_lenght << " elements.\n\n";

    std::string array_days[WEEK] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
    for (int i = 0; i < WEEK; i++)
    {
        std::cout << array_days[i] << std::endl;
    }
}

void BastetOfCats()
{
    Cat array[5];
    for (int i = 0; i < 5; i++)
    {
        array[i].SetAge(2 * i + 1);
        std::cout << "Cat number: " << i + 1 << ": ";
        std::cout << array[i].GetAge() << std::endl;
    }
}

void Array2D()
{
    // 2D initialization
    int array[4][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13, 14, 15, 16} };
    // it is also possible to initialize as this
    int array1[4][4] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
    // it will automatically asign each value to correct index 


    // we can't intialize the array after with the same syntax, because in that case we are accessing specific index of [4][4]
    // array[4][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13, 14, 15, 16} };
    // and at that specific index we have only one int number
}

void CatFamily()
{
    const int number_of_cats = 50;
    Cat* family[number_of_cats] {};
    Cat* p_cat = nullptr;

    for (int i = 0; i < number_of_cats; i++)
    {
        p_cat = new Cat;
        p_cat->SetAge(2 * i + 1);
        family[i] = p_cat;

        std::cout << "Cat number " << i + 1 << ": ";
        std::cout << family[i]->GetAge() << std::endl;
    }

    delete p_cat;
    std::cout << std::endl << std::endl;
}

void CatFamilyAtHeap()
{
    const int number_of_cats = 50;
    Cat* family = new Cat[number_of_cats];
    Cat* p_cat = nullptr;

    for (int i = 0; i < number_of_cats; i++)
    {
        p_cat = new Cat;
        p_cat->SetAge(2 * i + 1);
        family[i] = *p_cat;

        std::cout << "Cat number " << i + 1 << ": ";
        std::cout << family[i].GetAge() << std::endl;
    }

    delete[] family;
}

void ArrayOfChars()
{
    // Two possible initializations
    char greetings[] = { 'H','e','l','l','o','\0' };
    char greetingsOne[] = "Hello";

    // Or don't initialize at all
    char buffer[100];
    std::cout << "Please insert your message: ";
    std::cin >> buffer;
    std::cout << "Here is what you wrote: " << buffer << std::endl;
    // Problem with this code is that cin only takes test untill it finds first space
    // to fix this we can use cin.get(buffer, 79); takes input of 79 chars or until new line

    // also first we need to clear the input buffer, because there is still the remaining text
    // if we don't do this the next cin.get function will not ask user for input, but automatically 
    // uses the leftover to fill the buffer!!!
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cin.get(buffer, 79);
    std::cout << "Here is what you wrote: " << buffer << std::endl;
}

void StrCopy()
{
    char string_one[] = "This is my sentence!\nHello\n";
    char string_two[100];

    // The problem with strcpy is that it takes tagret variable and source variable and if the source is longer than target
    // it would start writing after the target variable, which could lead to errors
    strcpy(string_two, string_one);
    std::cout << string_two;

    // For that case we have function strncpy()
    const int lenght = 80;
    char string_three[] = "My another sentence!\nHello\n";
    char string_four[lenght+1]; // Plus one is for \0 character

    strncpy(string_four, string_three, lenght);
    std::cout << string_four;
}

void StringClassTest()
{
    String s1("Initial test sentence");
    std::cout << "S1: \t" << s1.GetString() << std::endl;

    char* temp = "Hello World";
    s1 = temp;
    std::cout << "S1: \t" << s1.GetString() << std::endl;

    char temp1[20];
    strcpy(temp1, "-----");
    s1 += temp1;

    std::cout << "temp1:\t " << temp1 << std::endl;
    std::cout << "s1: \t " << s1.GetString() << std::endl;

    std::cout << "s1[4]: \t" << s1[4] << std::endl;
    s1[4] = 'x';
    std::cout << "s1: \t" << s1.GetString() << std::endl;

    std::cout << "s1[999]: \t" << s1[999] << std::endl;

    String s2("Another sentence");
    String s3;
    s3 = s1 + s2;
    std::cout << "S3: \t" << s3.GetString() << std::endl;

    String s4;
    s4 = "Why this works?";
    std::cout << "S4: \t" << s4.GetString() << std::endl;
}

void LinkedListTest()
{
    Data* p_data;
    int value;

    LinkedList list;
    for (;;)
    {
        std::cout << "Insert value. For Exit insert value 0: ";
        std::cin >> value;

        if (!value)
            break;

        p_data = new Data(value);
        list.Insert(p_data);
    }

    list.ShowAll();
}

void Exercise21()
{
    int tic_tac_toe[3][3];
    // Or
    int tic_tac_toe1[3][3] = { 0,0,0,0,0,0,0,0,0 };
    int tic_tac_toe2[3][3] = { {0,0,0}, {0,0,0}, {0,0,0} };

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tic_tac_toe[i][j] = 2;
            tic_tac_toe1[i][j] = 2;
            tic_tac_toe2[i][j] = 2;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << tic_tac_toe[i][j] << std::endl;
            std::cout << tic_tac_toe1[i][j] << std::endl;
            std::cout << tic_tac_toe2[i][j] << std::endl;
        }
    }
}
