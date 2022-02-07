#pragma once

#include "Utilities.h"

class Puzzle6
{
public:
    std::vector<std::string> ReadInput( const std::string& FilePath );
    //Do not use this. Use the Optimal version
    int64_t CountLanternFish( std::vector<std::string> Input, size_t days ); //Not Optimal
    int64_t CountLanternFishOptimal( std::vector<std::string> Input, size_t days );
};