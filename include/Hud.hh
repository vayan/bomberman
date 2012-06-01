//
// Hud.hh for  in /home/cao_y//c++/plop/svn_bomberman/gdl
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Wed May 23 11:05:00 2012 yuguo cao
// Last update Fri Jun  1 11:39:21 2012 alexandre haulotte
//

#ifndef		__HUD__
# define	__HUD__

#include "GDL/Image.hpp"
#include "Bomberman.hh"

class Bomberman;

enum PSTATS
  {
    LIFE,
    SPEED,
    POWER,
    BOMBE
  };

class Hud
{
private:
  const Player			*_player1;
  const Player			*_player2;
  std::vector<gdl::Image>	_stats;
  gdl::Image			_back;
  gdl::Image			_back2;

public:
  Hud();
  ~Hud();

public:
  void		addPlayer(const Player*);
  void		printStat(float, int, int);
  void		printPlayer();
  void		draw();
  void		drawImage(gdl::Image&, int, int);
  void		mode2d();
  void		mode3d();
  void		deletePlayer(const int, const int);
};

#endif
