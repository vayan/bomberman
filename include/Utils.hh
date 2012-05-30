#ifndef __UTILS_
#define __UTILS_

#include	<sstream>
#include	<iostream>
#include	<string>
#include	<algorithm>
#include	<iterator>
#include	<vector>

void				Tokenize(const std::string& str, std::vector<std::string>& tokens, const std::string& delimiters);
std::vector<std::string>	split_to_vec(std::string to_split, std::string delim);

template<typename T>
std::string to_string(const T & Value)
{
  std::ostringstream oss;
  oss << Value;
  return oss.str();
}

template<typename T>
T 	to_number(std::string val)
{
  T 	ret_val;

  std::istringstream iss(val);
  iss >> ret_val;
  return (ret_val);
}

#endif
