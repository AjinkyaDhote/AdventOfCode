#include "Puzzle6.h"


std::vector<std::string> Puzzle6::ReadInput( const std::string& FilePath )
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
//362639 //Inefficient solution. //Due to fishes growing exponentially we cannot keep 
// track of every fish. Instead of that we should loop over Total Number of Days
// and update the count of fishes accordingly.
int64_t Puzzle6::CountLanternFish( std::vector<std::string> Input, size_t days )
{
    std::vector<int> Fishes;
    for ( const std::string& CurrentLine : Input )
    {
        std::vector<std::string> FishString = Utilities::SplitString( CurrentLine, "," );

        for ( const std::string& FishNumber : FishString )
            Fishes.push_back( std::stoi( FishNumber.c_str() ) );
    }
    int CurrentDayCount = 0;
    bool FishCreatedToday = false;
    int FishCreated = 0;
    while ( CurrentDayCount <= days )
    {
        for ( int i = 0; i < Fishes.size(); ++i )
        {
            if ( Fishes[i] == 0 && CurrentDayCount < days )
            {
                Fishes[i] = 6;
                Fishes.push_back( 8 );
                FishCreated++;
            }
            else if ( Fishes[i] == 8 && (i >= Fishes.size() - FishCreated) )
                continue;
            else
                --Fishes[i];
        }
        ++CurrentDayCount;
        FishCreated = 0;
    }

    return Fishes.size();
}

//3,4,3,1,2
int64_t Puzzle6::CountLanternFishOptimal( std::vector<std::string> Input, size_t days )
{
    std::vector<int> Fishes;
    for ( const std::string& CurrentLine : Input )
    {
        std::vector<std::string> FishString = Utilities::SplitString( CurrentLine, "," );

        for ( const std::string& FishNumber : FishString )
            Fishes.push_back( std::stoi( FishNumber.c_str() ) );
    }

    std::array<int64_t, 9> CurrentFish{};

    for ( int DaysRemainingForFish : Fishes )
    {
        ++CurrentFish[DaysRemainingForFish];
    }


    for ( int i = 0; i < days; ++i )
    {
        std::array<int64_t, 9> NextFish{};
        NextFish[6] = CurrentFish[0];
        NextFish[8] = CurrentFish[0];

        for ( int j = 1; j < CurrentFish.size(); ++j )
        {
            NextFish[j - 1] += CurrentFish[j];
        }

        CurrentFish = NextFish;
    }


    return std::accumulate( CurrentFish.begin(), CurrentFish.end(), static_cast<int64_t> (0) );

}
