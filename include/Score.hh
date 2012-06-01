//
// Score.hh for Score in /home/haulot_a//C++/Bomber-Man/svn_bomberman/bomberman-2015-haulot_a
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Wed May 30 11:52:59 2012 alexandre haulotte
// Last update Fri Jun  1 12:13:19 2012 alexandre haulotte
//

#ifndef	__SCORE_HH__
#define	__SCORE_HH__

#include 	<iostream>
#include 	<string>
#include 	<fstream>

class Score
{
private :
  int		H1score;
  int		H2score;
  int		H3score;
  std::string	filename;

public:
  int		checkScore(int sc);

  Score();
  ~Score();
};

#endif
