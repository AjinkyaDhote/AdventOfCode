
#include "HydroThermalVentures.h"
#include "Utilities.h"

std::vector<std::string> HydroThermalVentures::ReadInput( const std::string& FilePath )
{
    std::ifstream fin( FilePath );

    std::string Line;
    std::vector<std::string> AllLines;

    while ( std::getline( fin, Line ) )
    {
        AllLines.push_back( Line );
    }

    return AllLines;

}

//5632
int HydroThermalVentures::ParseInput( std::vector<std::string> Input )
{
    size_t sz = Input.size();
    std::unordered_map<Point, int, KeyHasher> MapOfIntersection;
    for ( const std::string& CurrentLine : Input )
    {
        std::vector<std::string> CurrentLinePoints = Utilities::SplitString( CurrentLine, "->" );

        std::vector<std::string> FirstPoint = Utilities::SplitString( CurrentLinePoints[0], "," );
        std::vector<std::string> SecondPoint = Utilities::SplitString( CurrentLinePoints[1], "," );

        Point firstPoint;
        firstPoint.x  = std::stoi( FirstPoint[0].c_str() );
        firstPoint.y = std::stoi( FirstPoint[1].c_str() );

        Point secondPoint;
        secondPoint.x = std::stoi( SecondPoint[0].c_str() );
        secondPoint.y = std::stoi( SecondPoint[1].c_str() );

        if ( (firstPoint.x == secondPoint.x) || (firstPoint.y == secondPoint.y) )
        {
            if ( secondPoint.y < firstPoint.y )
                std::swap( firstPoint.y, secondPoint.y );

            if ( secondPoint.x < firstPoint.x )
                std::swap( firstPoint.x, secondPoint.x );

            if ( firstPoint.x == secondPoint.x )
            {
                while ( firstPoint.y <= secondPoint.y )
                {
                    
                    Point newPoint;
                    newPoint.x = firstPoint.x;
                    newPoint.y = firstPoint.y;
                    MapOfIntersection.try_emplace( newPoint, 0 );
                    ++MapOfIntersection[newPoint];
                    firstPoint.y += 1;
                }
            }
            else if ( firstPoint.y == secondPoint.y )
            {
                while ( firstPoint.x <= secondPoint.x )
                {
                    Point newPoint;
                    newPoint.x = firstPoint.x;
                    newPoint.y = firstPoint.y;
                    MapOfIntersection.try_emplace( newPoint, 0 );
                    ++MapOfIntersection[newPoint];
                    firstPoint.x += 1;
                }
            }
        }

        //Calculate Diagonal Intersection
         else if ( firstPoint.x > secondPoint.x )
         {
                if ( firstPoint.y > secondPoint.y )
                {
                    for ( int i = firstPoint.x; i >= secondPoint.x; --i )
                    {
                        Point newPoint;
                        newPoint.x = firstPoint.x;
                        newPoint.y = firstPoint.y;
                        MapOfIntersection.try_emplace( newPoint, 0 );
                        ++MapOfIntersection[newPoint];
                        --firstPoint.x;
                        --firstPoint.y;
                    }
                }
                else if ( firstPoint.y < secondPoint.y )
                {
                    for ( int i = firstPoint.y; i <= secondPoint.y; ++i )
                    {
                        Point newPoint;
                        newPoint.x = firstPoint.x;
                        newPoint.y = firstPoint.y;
                        MapOfIntersection.try_emplace( newPoint, 0 );
                        ++MapOfIntersection[newPoint];
                        --firstPoint.x;
                        ++firstPoint.y;
                    }
                }
         }
            
         else if ( firstPoint.x < secondPoint.x )
         {
                if ( firstPoint.y > secondPoint.y )
                {
                    for ( int i = firstPoint.x; i <= secondPoint.x; ++i )
                    {
                        Point newPoint;
                        newPoint.x = firstPoint.x;
                        newPoint.y = firstPoint.y;
                        MapOfIntersection.try_emplace( newPoint, 0 );
                        ++MapOfIntersection[newPoint];
                        ++firstPoint.x;
                        --firstPoint.y;
                    }
                }
                else if ( firstPoint.y < secondPoint.y )
                {
                    for ( int i = firstPoint.x; i <= secondPoint.x; ++i )
                    {
                        Point newPoint;
                        newPoint.x = firstPoint.x;
                        newPoint.y = firstPoint.y;
                        MapOfIntersection.try_emplace( newPoint, 0 );
                        ++MapOfIntersection[newPoint];
                        ++firstPoint.x;
                        ++firstPoint.y;
                    }
                }
         }



     }

     int Result = 0;
     for ( const auto& Intersection : MapOfIntersection )
     {
         int Value = Intersection.second;
         if ( Value >= 2 )
         {
             ++Result;
         }
     }

     return Result;
}