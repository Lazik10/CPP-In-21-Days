#include "Day14.h"

void Day14()
{
    Ranch();
    PegasTest();
    CreatingPegas();
}

void Ranch()
{
    const int num_horses = 5;

    Horse* ranch[num_horses];
    Horse* p_horse;

    int choice, i;

    for (i = 0; i < num_horses; i++)
    {
        std::cout << "(1) Horse, (2) Pegas: ";
        std::cin >> choice;

        if (choice == 2)
            p_horse = new Pegas;
        else
            p_horse = new Horse;

        ranch[i] = p_horse;
    }

    std::cout << "\n";

    for (i = 0; i < num_horses; i++)
    {
        Pegas* p_pegas = dynamic_cast<Pegas*> (ranch[i]);
        if (p_pegas)
            p_pegas->Fly();
        else
            std::cout << "It is only a horse!\n";
        delete ranch[i];
    }
}

void PegasTest()
{
    const int magic_number = 2;
    Horse* ranch[magic_number];
    Bird* cage[magic_number];
    Horse* p_horse;
    Bird* p_bird;

    int choice, i;

    for (i = 0; i < magic_number; i++)
    {
        std::cout << "\n(1) Pegas, (2) Horse: ";
        std::cin >> choice;

        if (choice == 1)
            p_horse = new Pegas;
        else
            p_horse = new Horse;

        ranch[i] = p_horse;
    }

    for (i = 0; i < magic_number; i++)
    {
        std::cout << "\n(1) Pegas, (2) Bird: ";
        std::cin >> choice;

        if (choice == 1)
            p_bird = new Pegas;
        else
            p_bird = new Bird;

        cage[i] = p_bird;
    }

    std::cout << "\n";

    for (i = 0; i < magic_number; i++)
    {
        std::cout << "\nRanch[" << i << "]: ";
        ranch[i]->HorseSound();
        delete ranch[i];
    }

    std::cout << "\n";

    for (i = 0; i < magic_number; i++)
    {
        std::cout << "\nRanch[" << i << "]: ";
        cage[i]->BirdSound();
        cage[i]->Fly();
        delete cage[i];
    }
}

void CreatingPegas()
{
    Pegas* p_pegas = new Pegas(Horse::COLOR::RED, 5, true, 10);
    p_pegas->Fly();
    p_pegas->HorseSound();

    std::cout << "\nYour Pegas is " << p_pegas->GetHeight() << " meters tall and ";
    if (p_pegas->GetMigration())
        std::cout << "is migrating.\n";
    else
        std::cout << "is not migrating\n";

    std::cout << "There is " << p_pegas->GetFollowers() << " people believing that pegas is a real creature\n";

    delete p_pegas;
}