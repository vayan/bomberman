//
// Score.hh for Score in /home/haulot_a//C++/Bomber-Man/svn_bomberman/bomberman-2015-haulot_a
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Wed May 30 11:52:59 2012 alexandre haulotte
// Last update Wed May 30 11:56:44 2012 alexandre haulotte
//

#ifndef	__SCORE_HH__
#define	__SCORE_HH__

#include <iostream>
#include <string>
#include <fstream>

class Score
{
  int	Hscore;
  std::string	filename;
public:
  Score();
  int	checkScore(int sc);
  ~Score();
};

#endif
