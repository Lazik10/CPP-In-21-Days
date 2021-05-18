SET(SC_DAYS
	Day1.h
	Day1.cpp
	Day2.h
	Day2.cpp
	Day3.h
	Day3.cpp
	Day4.h
	Day4.cpp
	Day5.h
	Day5.cpp
	Day6.h
	Day6.cpp
	Day7.h
	Day7.cpp
	Day8.h
	Day8.cpp
	Day9.h
	Day9.cpp
	Day10.h
	Day10.cpp
	Day11.h
	Day11.cpp
	Day12.h
	Day12.cpp
	Day13.h
	Day13.cpp
	Day14.h
	Day14.cpp
	Day15.h
	Day15.cpp
	Day16.h
	Day16.cpp
	Day17.h
	Day17.cpp
	Day18.h
	Day18.cpp
	Day19.h
	Day19.cpp
	Day20.h
	Day20.cpp
	Day21.h
	Day21.cpp)
	
SOURCE_GROUP(Days FILES ${SC_DAYS})

MESSAGE("  -> Prepared: Days")

# Another option how to include all files
#FILE(GLOB_RECURSE days Days/*.cpp Days/*.h)
#SOURCE_GROUP(Days FILES ${days})

SET(SC_CLASSES
	Animal.h
	Animal.cpp
	Bird.h
	Bird.cpp
	Cat.h
	Cat.cpp
	Dog.h
	Dog.cpp
	Employee.h
	Employee.cpp
	Geometry.h
	Geometry.cpp
	Horse.h
	Horse.cpp
	LinkedList.h
	LinkedList.cpp
	Pegas.h
	Pegas.cpp
	Review.h
	Review.cpp
	String.h
	String.cpp
	Template.h
	Template.cpp
	)

SOURCE_GROUP(Classes FILES ${SC_CLASSES})

MESSAGE("  -> Prepared: Classes")

ADD_EXECUTABLE( 21Days main.cpp ${SC_DAYS} ${SC_CLASSES})