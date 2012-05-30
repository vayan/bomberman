//
// Bomberman.hh for  in /home/lyvet_r//tek2/C++/bomberman/sources
// 
// Made by randy lyvet
// Login   <lyvet_r@epitech.net>
// 
// Started on  Thu May  3 17:26:16 2012 randy lyvet
// Last update Wed May 23 13:00:29 2012 alexandre haulotte

#ifndef BOMBERMAN_HH_//
# define BOMBERMAN_HH_

#include	<cstdlib>
#include	<list>
#include	<map>

#include	"Game.hpp"
#include	"Window.hpp"
#include	"Clock.hpp"

#include	"Vector3f.hh"
#include	"Texture.hh"
#include	"AObject.hh"
#include	"Camera.hh"
#include	"Object.hh"
#include	"Level.hh"
#include	"Player.hh"
#include	"Bombe.hh"
#include  	"Menu.hh"
#include	"Bonus.hh"

class Player;

class 		Bomberman : public gdl::Game
{
public:
  void					initialize(void);
  void					update(void);
  void					draw(void);
  void					unload(void);
  void					addBombe(Player* pl);
  std::list<AObject*>& getObj();
  Level					*level;

  Bomberman(Level *my_level);
  ~Bomberman();
private:
  int			sp;
  Camera		camera_;
  std::list<AObject*>	objects_;
  gdl::Clock	myClock;
  float		time;
  Bonus		*bonus;
};

#endif /* !BOMBERMAN_HH_ */
