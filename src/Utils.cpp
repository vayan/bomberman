//
// Utils.hpp for Crome in /home/haulot_a//C++/Bomber-Man/svn_bomberman/gdl
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Fri May 11 11:21:42 2012 alexandre haulotte
// Last update Fri May 11 11:21:45 2012 alexandre haulotte
//

#include <sstream>  
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include "Utils.hh"

void Tokenize(const std::string& str, std::vector<std::string>& tokens, const std::string& delimiters)
{
	std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	std::string::size_type pos     = str.find_first_of(delimiters, lastPos);

	while (std::string::npos != pos || std::string::npos != lastPos)
	{
		tokens.push_back(str.substr(lastPos, pos - lastPos));
		lastPos = str.find_first_not_of(delimiters, pos);
		pos = str.find_first_of(delimiters, lastPos);
	}
}

std::vector<std::string> split_to_vec(std::string to_split, std::string delim)
{
	std::vector<std::string> tokens;

	Tokenize(to_split, tokens, delim);
	copy(tokens.begin(), tokens.end(), std::ostream_iterator<std::string>(std::cout, ", "));
	std::cout << std::endl;
	return (tokens);
}