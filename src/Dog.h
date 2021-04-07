#pragma once

#include "Animal.h"
#include <string>

class Dog : public Animal
{
public:
	enum class Race
	{
		GOLDEN_RETRIEVER,
		LABRADOR,
		BASSET,
		POODLE,
		ALSATIAN
	};

	// Constructors
	Dog();
	Dog(int age, int weight, int height, Health health, Gender gender, Race race);
	// Destructor
	~Dog();
	// Copy constructor
	Dog(const Dog& dog);
	// Clone
	Dog* Clone() override;

	inline Race GetRace() const { return m_race; };
	inline void SetRace(Race race) { m_race = race; };

	void ShakeTail() const;
	void AskForFood() const;
	void MakeSound() const override;

private:
	Race m_race;
};
