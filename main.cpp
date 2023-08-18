//I will I have to first read the input.
//vector of ints

//Check if the previous measurement is bigger than the current one.

#include"HydroThermalVentures.h"
#include "Puzzle6.h"
#include"Puzzle7.h"
#include<map>
#include<sstream>


int CalculateDepthMeasurementIncrease()
{
	//Open File
	std::ifstream fin("Input1.txt");
	std::string line;
	int oldValue = INT_MAX;
	int count = 0;
	while (std::getline(fin, line))
	{
		if ( line.size() > 0)
		{
			//convert str to integer
			int measurement = std::stoi(line);
			if ( measurement > oldValue )
				count++;
			oldValue = measurement;
		}
	}

	return count;
}

int CalculateDepthMeasurementIncreaseSlidingWindow()
{
	std::vector<int> input;

	//Open File
	std::ifstream fin("Input1.txt");
	std::string line;
	int oldSum = INT_MAX;
	int count = 0;
	//Insert all the values in the vector
	while (std::getline(fin, line))
	{
		if (line.size() > 0)
		{
			//convert str to integer
			int measurement = std::stoi(line);
			input.push_back(measurement);
		}
	}

	for ( int i = 0; i < input.size() - 2; i++ )
	{
		int sum = input[i] + input[i + 1] + input[i + 2];
		if ( sum > oldSum )
			count++;
		oldSum = sum;
	}

	return count;
}


//Day2
//Calculation of Final Horizontal and Final Depth position.
int CalculateHorizontalandDepthPoisition()
{
	std::map<std::string, int> directionMap;

	//Open File
	std::ifstream fin( "Input2.txt" );
	std::string line;
	int oldSum = INT_MAX;
	int horizontalPosition = 0;
	int depth = 0;
	int aim = 0;

	while ( std::getline( fin, line ) )
	{
		if ( line.size() > 0 )
		{
			//we get back forward 5.
			if ( line[0] == 'f' )
			{
				int value = std::atoi( &line.back() );
				horizontalPosition += value;
				if ( aim > 0 )
					depth += (aim * value);
			}
			else if ( line[0] == 'u' )
			{
				int value = std::atoi( &line.back() );
				aim -= value;
			}
			else if ( line[0] == 'd' )
			{
				int value = std::atoi( &line.back() );
				aim += value;
			}
		}
	}

	return horizontalPosition * depth;
	//wrong guess 1882100736
}

unsigned long long CaluculatePowerConsumption()
{
	std::map<int, int> MapOfZeroes;
	std::map<int, int> MapOfOnes;

	//OpenFile
	std::ifstream fin( "input3.txt" );
	std::string line;

	while ( std::getline( fin, line ) )
	{
		if ( line.size() > 0 )
		{
			for ( int i = 0; i < 12; i++ )
			{
				if ( line[i] == '0' )
					MapOfZeroes[i]++;
				else
					MapOfOnes[i]++;
			}

		}
	}
	std::string gammastr;
	std::string epsilonstr;
	for ( int i = 0; i < 12; i++ )
	{
		if ( MapOfZeroes[i] > MapOfOnes[i] )
		{
			gammastr += '0';
			epsilonstr += '1';
		}
		else
		{
			gammastr += '1';
			epsilonstr += '0';
		}
	}

	unsigned long long gamma = std::stoull( gammastr, nullptr, 2);
	unsigned long long epsilon = std::stoull( epsilonstr, nullptr, 2 );

	return gamma * epsilon;

}


std::string CalculateOxygenGeneratorRating( std::vector<std::string> MapOfZeroes, std::vector<std::string> MapOfOnes )
{
	std::vector<std::string> ResultMap;

	if ( MapOfOnes.size() >= MapOfZeroes.size() )
		ResultMap = MapOfOnes;
	else
		ResultMap = MapOfZeroes;

	int j = 1;

	while ( ResultMap.size() != 1 )
	{
		MapOfZeroes.clear();
		MapOfOnes.clear();
		for (auto & i : ResultMap)
		{
			if ( i[j] == '0' )
				MapOfZeroes.push_back( i );
			else
				MapOfOnes.push_back( i );
		}

		ResultMap.clear();

		if ( MapOfOnes.size() >= MapOfZeroes.size() )
			ResultMap = MapOfOnes;
		else
			ResultMap = MapOfZeroes;
		j++;
	}

	return ResultMap[0];
}

std::string CalculateCO2ScrubberRating( std::vector<std::string> MapOfZeroes, std::vector<std::string> MapOfOnes )
{
	std::vector<std::string> ResultMap;

	if ( MapOfOnes.size() <= MapOfZeroes.size() )
		ResultMap = MapOfOnes;
	else
		ResultMap = MapOfZeroes;

	int j = 1;

	while ( ResultMap.size() != 1 )
	{
		MapOfZeroes.clear();
		MapOfOnes.clear();
		for (auto & i : ResultMap)
		{
			if ( i[j] == '0' )
				MapOfZeroes.push_back( i );
			else
				MapOfOnes.push_back( i );
		}

		ResultMap.clear();

		if ( MapOfZeroes.size() <= MapOfOnes.size() )
			ResultMap = MapOfZeroes;
		else
			ResultMap = MapOfOnes;
		j++;
	}

	return ResultMap[0];
}



unsigned long long CalculateLifeSupportRating()
{
	//Multiply Oxygen Generator Rating and CO2 scrubber Rating
	std::vector<std::string> MapOfZeroes;
	std::vector<std::string> MapOfOnes;

	std::map<int, std::string> ResultMap;

	//OpenFile
	std::ifstream fin( "input3.txt" );
	std::string line;

	int i = 0, j = 0;
	while ( std::getline( fin, line ) )
	{
		if ( line.empty() == false )
		{
			{
				if ( line[j] == '0' )
				{
					MapOfZeroes.push_back( line );
				}
				else
				{
					MapOfOnes.push_back( line );
				}

			}
			i++;

		}
	}


	std::string OxygenGeneratorRatingStr = CalculateOxygenGeneratorRating( MapOfZeroes, MapOfOnes );
	std::string CO2ScrubberRatingStr = CalculateCO2ScrubberRating( MapOfZeroes, MapOfOnes );
	

	unsigned long long OxygenGeneratorRating = std::stoull( OxygenGeneratorRatingStr, nullptr, 2 );
	unsigned long long CO2ScrubberRating = std::stoull( CO2ScrubberRatingStr, nullptr, 2 );

	return OxygenGeneratorRating * CO2ScrubberRating;
}


//Day 4: Giant Squid -------------------------------------------------

//unsigned long long CalculateBingoScore()
//{
//	//OpenFile and read input
//	std::ifstream fin( "input4.txt" );
//	std::string line;
//	std::vector<int> BingoInput;
//
//	struct arr
//	{
//
//		std::vector<int> BingoBoard;
//		int mat[5][5];
//		bool visited = false;
//		arr()
//		{
//			for ( int i = 0; i < 5; i++ )
//				for ( int j = 0; j < 5; j++ )
//					mat[i][j] = 0;
//		};
//	};
//	arr in;
//	std::vector<arr> vectorOfMatrices;
//
//	bool InputRead = false;
//	int i = 0, j = 0;
//
//	//Reading Input File
//	while ( std::getline( fin, line ) )
//	{
//		//Read first line which will be the input for Bingo and quit;
//		//parse the string and seperate values with commas.
//		std::istringstream iss( line );
//		if ( !InputRead )
//		{
//			while ( iss.good() )
//			{
//				std::string buf;
//				std::getline( iss, buf, ',' );
//
//				BingoInput.push_back( stoi(buf) );
//			}
//			InputRead = true;
//			continue;
//		}
//
//		//Read the matrices. If you encounter space that means we have new matrix values
//		if ( line == "" )
//			continue;
//
//		while ( iss.good() )
//		{
//			std::string buf;
//			std::getline( iss, buf, ' ' );
//			if ( buf != "" ) //Handle size 0 strings between the numbers as well. (If you notice the numbers are not evenly spaced out)
//			{
//				in.mat[i][j] = stoi( buf );
//				//in.BingoBoard.push_back( stoi( buf ) );
//				j++; //Column++
//			}
//			
//		}
//		i++; //Row++
//		j = 0;
//
//		if ( i == 5 )
//		{
//			i = 0, j = 0;
//			vectorOfMatrices.push_back( in ); //All the values for current matrix are now read and can be inserted into the vector.
//		}
//
//	}
//
//	//Now we start comparing Bingo Values.
//	int k = 0;
//	for (int i = 0; i < vectorOfMatrices.size(); i++ )
//	{
//		arr mat = vectorOfMatrices[i];
//
//		
//
//	}
//
//
//	return 0;
//}


//Answer : 72770, 13912
std::vector<int> CalculateBingoScore()
{
	std::ifstream ReadStream( "Input4.txt" );
	std::string CurrentLine;
	std::vector<std::string> AllLines;

	while ( std::getline( ReadStream, CurrentLine) )
	{
		AllLines.push_back( CurrentLine );
	}

	//Parse Bingo Input
	std::stringstream BingoInputStream( AllLines[0] );
	std::string CurrentInput;
	std::vector<int> BingoInput;

	while ( std::getline( BingoInputStream, CurrentInput, ',' ) )
	{
		BingoInput.push_back( atoi( CurrentInput.c_str() ) );
	}

	//BingoBoard Struct
	struct BingoBoard
	{

		std::vector<int> Numbers;
		std::vector<bool> Visited;

		int FinalScore = 0;
		int WinningTurn = 0;
		int BingoWinNumber = 0;
		int UnMarkedSumOfNumbers = 0;
		
		//Solve Bingo Board
		void SolveBoard( std::vector<int>& BingoInput )
		{
			//Check if the number is in the BingoBoard
			for ( int k = 0; k < BingoInput.size(); ++k )
			{
				int CurrentNumber = BingoInput[k];

				std::vector<int>::iterator it = std::find( Numbers.begin(), Numbers.end(), CurrentNumber );
				if ( it == Numbers.end() )
				{
					continue;
				}

				int CurrentNumberIndex = it - Numbers.begin();
				Visited[CurrentNumberIndex] = true;


				//Check if all the numbers in the row are visited.
				int CurrentRow = CurrentNumberIndex / 5;
				int RowStartIndex = CurrentRow * 5;
				bool bRowVisited = true;

				for ( int i = RowStartIndex; i < RowStartIndex + 5; ++i )
				{
					if ( !Visited[i] )
					{
						bRowVisited = false;
						break;
					}

				}

				//Check if all the numbers in the column are visited.
				int CurrentColumn = CurrentNumberIndex % 5;
				int ColumnStartIndex = CurrentColumn;
				bool bColumnVisited = true;
				for ( int i = ColumnStartIndex; i < Numbers.size(); i += 5 )
				{
					if ( !Visited[i] )
					{
						bColumnVisited = false;
						break;
					}

				}

				//Did we win?
				//We win if we have visited all the numbers in a row or column
				if ( bRowVisited || bColumnVisited )
				{
					BingoWinNumber = CurrentNumber;
					WinningTurn = k;
					int WinningTurn = k;
					int UnMarkedSum = 0;
					for ( int i = 0; i < Visited.size(); ++i )
					{
						if ( !Visited[i] )
						{
							UnMarkedSum += Numbers[i];
						}
					}
					UnMarkedSumOfNumbers = UnMarkedSum;
					FinalScore = UnMarkedSumOfNumbers * BingoWinNumber;
					break;
				}
			}
		}
	};


	//Parse BingoBoards	
	std::vector<BingoBoard> BingoBoards;
	
	int NextBingoBoardLine = 2;
	while ( NextBingoBoardLine + 5 <= AllLines.size() )
	{
		BingoBoard CurrentBoard;
		for ( int i = NextBingoBoardLine; i < NextBingoBoardLine + 5; ++i )
		{
			std::stringstream BingoBoardLineStream( AllLines[i] );
			for ( int j = 0; j < 5; ++j )
			{
				int CurrentNumber;
				BingoBoardLineStream >> CurrentNumber;
				CurrentBoard.Numbers.push_back( CurrentNumber );
				CurrentBoard.Visited.push_back( false );
				
			}
		}
		BingoBoards.push_back( CurrentBoard );
		NextBingoBoardLine += 6;
	}
	
	int FirstWinnerToReturn = 0;
	int LastWinnerToReturn = 0;
	int WinningTurn = INT_MAX;
	int LastWinningTurn = INT_MIN;

	for ( BingoBoard& CurrentBoard : BingoBoards )
	{
		CurrentBoard.SolveBoard( BingoInput );
		
		if ( CurrentBoard.WinningTurn <= WinningTurn )
		{
			WinningTurn = CurrentBoard.WinningTurn;
			FirstWinnerToReturn = CurrentBoard.FinalScore;
		}
			
		if ( CurrentBoard.WinningTurn >= LastWinningTurn )
		{
			LastWinningTurn = CurrentBoard.WinningTurn;
			LastWinnerToReturn = CurrentBoard.FinalScore;
		}

	}

	return { FirstWinnerToReturn, LastWinnerToReturn };
}




//int main()
//{
//	//Fill the vector by reading the file
//	//int answer = CalculateDepthMeasurementIncrease();
//	//int answerSlidingWindow = CalculateDepthMeasurementIncreaseSlidingWindow();
//	//int answerHorizontalAndDepth = CalculateHorizontalandDepthPoisition();
//	//unsigned long long powerConsumption = CaluculatePowerConsumption();
//	//unsigned long long lifeSupportRating = CalculateLifeSupportRating();
//	//std::vector<int>BingoScores = CalculateBingoScore();
//	//std::cout << answer << std::endl;
//	//std::cout << answerSlidingWindow << std::endl;
//	//std::cout << answerHorizontalAndDepth << std::endl;
//	//std::cout << powerConsumption << std::endl;
//	//std::cout << "lifeSupportRating -> " << lifeSupportRating << std::endl;
//	//std::cout << "BingoScoreFirstPuzzle -> " << BingoScores[0] << std::endl;
//	//std::cout << "BingoScoreSecondPuzzle -> " << BingoScores[1] << std::endl;
//
//	//HydroThermalVentures hydro;
//	//std::vector<std::string> Input = hydro.ReadInput("Input5.txt");
//	//hydro.ParseInput(Input);
//
//	//Puzzle6 puzzle6;
//	//std::vector<std::string> Input = puzzle6.ReadInput( "Input6.txt" );
//	//size_t NumberOfDays = 256;
//	//int64_t Fishes = puzzle6.CountLanternFishOptimal(Input, NumberOfDays);
//	//std::cout << "-------------Solution for Puzzle 6-----------------\n\n";
//	//std::cout << "Puzzle 1\n";
//	//std::cout << "Total number of fishes after " << NumberOfDays << " Days" << " - " << Fishes << "\n";
//
//	//Puzzle 7 -------------------------------------------------------
//	Puzzle7 puzzle7;
//	std::vector<std::string> Input = puzzle7.ReadInput( "Input7.txt" );
//	int LeaseFuelPossible = puzzle7.CalculateLeastFuelPossible( Input[0]);
//	//print LeastFuelPossible
//
//	return 0;
//}

#include "2023/Header Files/Source.h"

int main()
{
	Advent::Solutions2023::CalorieCounting();
	return 0;
}