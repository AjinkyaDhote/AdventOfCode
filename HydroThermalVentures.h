#pragma once
#include <iostream>
#include <string>
#include<vector>
#include<fstream>
#include <sstream>
#include<array>
#include<map>

class HydroThermalVentures
{
public:
    std::vector<std::string> ReadInput( const std::string& FilePath );
    int ParseInput( std::vector<std::string> Input );

    struct Point
    {
        int x = 0;
        int y = 0;

        bool operator==( const Point& other ) const 
        {
            return (x == other.x) && (y == other.y);
        }
    };


    struct KeyHasher
    {
        std::size_t operator()( const HydroThermalVentures::Point& point ) const
        {
            return (std::hash<int>()(point.x) ^ std::hash<int>()(point.y << 1));
        }
    };
};



