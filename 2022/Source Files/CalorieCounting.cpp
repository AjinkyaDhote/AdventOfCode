///--- Day 1: Calorie Counting ---

#include "../Header Files/Source.h"
#include "../../Utilities.h"

void Advent::Solutions2023::CalorieCounting()
{
	printf("CountingCalories\n");
	std::string inputFilePath = R"(..\AdventOfCode\2022\Input\CalorieCounting.txt)";

	std::ifstream file = Utilities::OpenFile( inputFilePath );
	
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

	// Only in case of set badbit we are sure that errno has been set in
	// the current context. Use perror() to print error details.
	if ( file.bad() )
	{
		perror( ("error while reading file " + inputFilePath).c_str() );
		exit( EXIT_FAILURE );
	}
		
	
	std::cout << "The highest amount of calories carried by the elf are " << previousCalorieCount << "\n";
	Utilities::CloseFile( file );
}

