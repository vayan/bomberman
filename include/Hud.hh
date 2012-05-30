//
// Hud.hh for  in /home/cao_y//c++/plop/svn_bomberman/gdl
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Wed May 23 11:05:00 2012 yuguo cao
// Last update Wed May 30 15:27:05 2012 yuguo cao
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
  Player			*_player1;
  Player			*_player2;
  std::vector<gdl::Image>	_stats;
  gdl::Image			_back;
  gdl::Image			_back2;

public:
  Hud();
  ~Hud();

public:
  void		addPlayer(Player*);
  void		printStat(float, int, int);
  void		printPlayer();
  void		draw();
  void		drawImage(gdl::Image, int, int);
  void		mode2d();
  void		mode3d();
  void		deletePlayer(const int, const int);
};

#endif
