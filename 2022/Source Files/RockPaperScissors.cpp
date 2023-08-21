///--- Day 2: Rock Paper Scissors ---

#include "../Header Files/Source.h"
#include "../../Utilities.h"


int CalculateResult( const char* input, const char* output );

void Advent::Solutions2022::RockPaperScissors()
{
	printf( "RockPaperScissors\n" );
	std::string inputFilePath = R"(..\AdventOfCode\2022\Input\RockPaperScissors.txt)";

	std::ifstream file = Utilities::OpenFile( inputFilePath );

	std::string line;
	int sum = 0;

	while ( std::getline( file, line ) )
	{
		std::vector<std::string> vec = Utilities::SplitString( line, " ");
		const char* input = vec[0].c_str();
		const char* output = vec[1].c_str();

		int result = CalculateResult( input,  output );
		sum += result;
	}

	// Only in case of set badbit we are sure that errno has been set in
	// the current context. Use perror() to print error details.
	if ( file.bad() )
	{
		perror( ("error while reading file " + inputFilePath).c_str() );
		exit( EXIT_FAILURE );
	}


	std::cout << "The total score according to the strategy guide is " << sum << "\n";
	Utilities::CloseFile( file );
}

int CalculateResult( const char *input, const char* output )
{
	int result = 0;

	if ( *input == 'A' ) //Input is Rock
	{
		if ( *output == 'X' ) //Output is Rock
		{
			result += 1;
			result += 3;
		}
		else if ( *output == 'Y' ) //Output is Paper
		{
			result += 2;
			result += 6;
		}
		else //Output is Scissor
		{
			result += 3;
		}
	}

	else if ( *input == 'B' ) //Input is Paper
	{
		if ( *output == 'X' ) //Output is Rock
		{
			result += 1;
		}
		else if ( *output == 'Y' ) //Output is Paper
		{
			result += 2;
			result += 3;
		}
		else //Output is Scissor
		{
			result += 3;
			result += 6;
		}
	}

	else //Input is "C" Scissor
	{
		if ( *output == 'X' ) //Output is Rock
		{
			result += 1;
			result += 6;
		}
		else if ( *output == 'Y' ) //Output is Paper
		{
			result += 2;
		}
		else //Output is Scissor
		{
			result += 3;
			result += 3;
		}
	}

	return result;
}