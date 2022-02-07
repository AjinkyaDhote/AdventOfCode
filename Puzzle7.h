#pragma once

#include "Utilities.h"

class Puzzle7
{
public:
    std::vector<std::string> ReadInput( const std::string& FilePath );
    int CalculateLeastFuelPossible( std::string Input );
};