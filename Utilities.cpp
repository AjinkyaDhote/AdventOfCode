#include "Utilities.h"

std::vector<std::string> Utilities::SplitString( const std::string& str, const std::string& delimiter )
{
    std::vector<std::string> Tokens;

    size_t NextTokenStart = 0;
    
    while ( NextTokenStart < str.size() )
    {
        size_t DelimiterStart = str.find( delimiter, NextTokenStart );

        if ( DelimiterStart == std::string::npos )
        {
            DelimiterStart = str.size();
        }

        std::string Token = str.substr( NextTokenStart, DelimiterStart - NextTokenStart );
        Tokens.push_back( Token );

        NextTokenStart = DelimiterStart + delimiter.size();
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

std::ifstream& Utilities::OpenFile( std::string filePath )
{
	std::ifstream file( filePath );
	if ( file.is_open() )
	{
		return file;
	}

	HandleError();
}

void Utilities::CloseFile( std::ifstream &file )
{
	if ( file.is_open() )
	{
		file.close();
	}
}



void Utilities::HandleError()
{
	printf( "Value of errno: %d\n ", errno );
	perror( "Message from perror" );
	exit( EXIT_FAILURE );
}