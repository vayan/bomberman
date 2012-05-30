//
// Score.hh for Score in /home/haulot_a//C++/Bomber-Man/svn_bomberman/bomberman-2015-haulot_a
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Wed May 30 11:52:59 2012 alexandre haulotte
// Last update Wed May 30 14:00:04 2012 randy lyvet
//

#ifndef	__SCORE_HH__
#define	__SCORE_HH__

#include 	<iostream>
#include 	<string>
#include 	<fstream>

class Score
{
private :
  int		Hscore;
  std::string	filename;

public:
  int		checkScore(int sc);

  Score();
  ~Score();
};

#endif
