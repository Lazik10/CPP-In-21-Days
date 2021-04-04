#include "Day10.h"

void Day10()
{
    OverloadedFunctionExample();
    DrawingExamples();
    DeepCopyExample();
    OverloadingOperatorsExamples();

    Exercise19();
}

void OverloadedFunctionExample()
{
    Rectangle rec(10, 5);
    std::cout << "DrawRectangle(): \n";
    rec.DrawRectangle();
    std::cout << "DrawRectangle(50,50): \n";
    rec.DrawRectangle(5, 10);
}

void DrawingExamples()
{
    Rectangle rec(3, 5);
    std::cout << "Draw rectangle(0,0,true): \n";
    rec.DrawRectangle(0, 0, true);
    std::cout << "Draw rectangle(10,2): \n";
    rec.DrawRectangle(10, 2);
}

void DeepCopyExample()
{
    Cat* maya = new Cat;
    maya->SetKittens(5);

    Cat snowflake(*maya);
    delete maya;

    std::cout << "Snowflake has " << snowflake.GetKittens() << " kittens \n";
}

void OverloadingOperatorsExamples()
{
    // declaration of 2 objects of the same class
    Cat maya(7, 3);
    Cat micka(5, 10);
    Cat result(0, 0);

    // assign operator for objects is overloaded by default
    micka = maya;
    std::cout << "\nMicka is " << micka.GetAge() << " years old. \n";

    // incrementation
    ++maya;
    std::cout << "\nMaya is " << maya.GetAge() << " years old. \n";
    maya++;
    std::cout << "\nMaya is " << maya.GetAge() << " years old. \n";

    // decrementation
    --maya;
    std::cout << "\nMaya is " << maya.GetAge() << " years old. \n";
    maya--;
    std::cout << "\nMaya is " << maya.GetAge() << " years old. \n";

    // adding
    result = maya + micka;
    std::cout << "\nNew cat is " << result.GetAge() << " years old. \n";

    // substract
    result = maya - micka;
    std::cout << "\nNew cat  is " << result.GetAge() << " years old. \n";

    // divide
    result = maya / micka;
    std::cout << "\nNew cat  is " << result.GetAge() << " years old. \n";

    // multiply
    result = maya * micka;
    std::cout << "\nNew cat  is " << result.GetAge() << " years old. \n";

    // comparsion
    bool is_equal;
    is_equal = maya == micka;
    if (is_equal)
        std::cout << "\nMaya and Micka are same years old. \n";
    else
        std::cout << "\nMaya and Micka are different years old. \n";

    Cat mourek = 1;
    std::cout << "Mourek age: " << mourek.GetAge() << "\n";

    // type conversion from short int to object Cat
    // for that we need to have constructor with that type as the only argument
    // but if we define the only argument as int and we pass char, the compilator will 
    // convert this char to int to create our object!!! Be careful with that, example below
    char var = 'A';
    Cat cat = var;
    // since A has int value of 65 in ASCI table, our cat will be 65 years old
    std::cout << "Cat is " << cat.GetAge() << " years old. \n";
    // the other way around to convert class Cat to unsigned short int we cna do this
    unsigned short age;
    age = cat;
    std::cout << "Cat is " << cat.GetAge() << " years old. \n";
}

void Exercise19()
{
    Circle a;
    Circle b(9);

    a++;
    b++;

    std::cout << "First circle has radius: " << a.GetRadius() << " and second circle has radius: " << b.GetRadius();
    a = b;
    std::cout << "\nFirst circle has radius: " << a.GetRadius();

}
