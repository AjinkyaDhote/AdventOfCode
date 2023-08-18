
#include "../Header Files/Source.h"

int Advent::Solutions2023::CalorieCounting()
{
	printf("CountingCalories\n");

	std::ifstream file;
	file.open(R"(D:\AdventOfCode\Day1\CountingCalories.txt)");

	std::string line;
	long previousCalorieCount = 0;
	long currentCalorieCount = 0;

	if (file.is_open())
	{
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
	}

	std::cout << "The highest amount of calories carried by the elf are " << previousCalorieCount << std::endl;
	file.close();

	return 0;
}

