#include "Day12.h"

void Day12()
{
    CreatingNewDog();
    CloneExample();

    Exercise20();
}

void CreatingNewDog()
{
    Dog fido;
    fido.ShakeTail();
    fido.MakeSound();
    std::cout << "Fido is " << fido.GetAge() << " year(s) old.\n";
    if (fido.GetRace() == Dog::Race::LABRADOR)
        std::cout << "Fido's race is labrador.\n";
    else
        std::cout << "Fido's race is something else.\n";
}

void CloneExample()
{
    const int number_of_classes = 3;
    Animal* array[number_of_classes]{};
    Animal* pointer = nullptr;

    int choice, i;
    for (i = 0; i < number_of_classes; i++)
    {
        std::cout << "(1) Dog, (2) Cat, (3) Animal: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            pointer = new Dog;
            break;
        case 2:
            pointer = new Cat;
            break;
        default:
            pointer = new Animal;
            break;
        }
        array[i] = pointer;
    }

    std::cout << std::endl;
    Animal* another_array[number_of_classes] { nullptr, nullptr, nullptr };
    for (i = 0; i < number_of_classes; i++)
    {
        array[i]->MakeSound();
        another_array[i] = array[i]->Clone();
    }

    std::cout << std::endl;
    for (i = 0; i < number_of_classes; i++)
    {
        another_array[i]->MakeSound();
    }
}

void Exercise20()
{
    Shape shape;
    Rectangle rectangle;
    Square square;

    shape.Draw();
    rectangle.Draw();
    square.Draw();

    Shape* p_shape = new Shape();
    Shape* p_rectangle = new Rectangle();
    Shape* p_square = new Square();

    p_shape->Draw();
    p_rectangle->Draw();
    p_square->Draw();

    delete p_shape;
    delete p_rectangle;
    delete p_square;


    std::cout << std::endl;
    Shape* p_new_shape = new Shape();
    Rectangle* p_new_rectangle = new Rectangle();
    p_new_shape = p_new_rectangle->Clone();

    p_new_shape->Draw();

    delete p_new_shape;
    delete p_new_rectangle;
}
