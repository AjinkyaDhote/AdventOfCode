#include "Puzzle7.h"


std::vector<std::string> Puzzle7::ReadInput( const std::string& FilePath )
{
    std::vector<std::string> Input;

    std::ifstream fin( FilePath );
    std::string CurrentLine;
    while ( std::getline( fin, CurrentLine ) )
    {
        Input.push_back( CurrentLine );
    }

    return Input;
}

//4438332, 468826
int Puzzle7::CalculateLeastFuelPossible(std::string Input)
{
    std::vector<std::string> HorizontalPositionsstr = Utilities::ReadCommaSeperatedString( Input );
    std::vector<int>HorizontalPositions;
    for ( std::string HorizontalPosition : HorizontalPositionsstr )
    {
        HorizontalPositions.push_back( std::stoi( HorizontalPosition.c_str() ) );
    }

    std::sort( HorizontalPositions.begin(), HorizontalPositions.end() );
    double median = 0;
    size_t size = HorizontalPositions.size();
    if ( HorizontalPositions.size() % 2 != 0 )
        median = HorizontalPositions[size / 2];
    else
        median = (double)HorizontalPositions[(HorizontalPositions[(size - 1) / 2] + HorizontalPositions[size / 2]) / 2];
    


    int MinValue = *std::min_element( HorizontalPositions.begin(), HorizontalPositions.end() );
    int MaxValue = *std::max_element( HorizontalPositions.begin(), HorizontalPositions.end() );

    int SmallestPossibleFuelValue = INT_MIN;
    int SumOfDifferences = 0;
    for ( int i = 0; i < HorizontalPositions.size(); ++i )
    {
        int CurrentFuelValue = HorizontalPositions[i];

    }

    return 0;//SumOfDifferences;
}
