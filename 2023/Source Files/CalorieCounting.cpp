#include "../Header Files/Source.h"
#include "../../Utilities.h"

int Advent::Solutions2023::CalorieCounting()
{
	printf("CountingCalories\n");

	std::ifstream& file = Utilities::OpenFile( R"(..\AdventOfCode\2023\Input\CalorieCounting.txt)" );
	
	std::string line;
	long previousCalorieCount = 0;
	long currentCalorieCount = 0;

	while (std::getline(file, line))
	{
		if (line.empty() == true)
		{
			if (currentCalorieCount > previousCalorieCount)
			{
				previousCalorieCount = currentCalorieCount;
			}
	
			currentCalorieCount = 0;
		}
		else
		{
			currentCalorieCount += std::stoi(line);
		}
	}
	
	std::cout << "The highest amount of calories carried by the elf are " << previousCalorieCount << "\n";
	Utilities::CloseFile( file );


	return 0;
}

