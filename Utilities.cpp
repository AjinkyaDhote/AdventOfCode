#include "Utilities.h"


std::vector<std::string> Utilities::SplitString( const std::string& String, const std::string& Delimiter )
{
    std::vector<std::string> Tokens;

    size_t NextTokenStart = 0;
    
    while ( NextTokenStart < String.size() )
    {
        size_t DelimiterStart = String.find( Delimiter, NextTokenStart );

        if ( DelimiterStart == std::string::npos )
        {
            DelimiterStart = String.size();
        }

        std::string Token = String.substr( NextTokenStart, DelimiterStart - NextTokenStart );
        Tokens.push_back( Token );

        NextTokenStart = DelimiterStart + Delimiter.size();
    }
    
    return Tokens;
}

std::vector<std::string> Utilities::ReadCommaSeperatedString( const std::string& string )
{
    std::vector<std::string> Tokens;
    std::stringstream ss (string);
    std::string token;
    while ( std::getline( ss, token, ',' ) )
    {
        Tokens.push_back( token );
    }

    return Tokens;
}
