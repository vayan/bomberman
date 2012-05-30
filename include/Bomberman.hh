//
// Bomberman.hh for  in /home/lyvet_r//tek2/C++/bomberman/sources
// 
// Made by randy lyvet
// Login   <lyvet_r@epitech.net>
// 
// Started on  Thu May  3 17:26:16 2012 randy lyvet
// Last update Wed May 30 11:45:58 2012 randy lyvet

#ifndef BOMBERMAN_HH_
# define BOMBERMAN_HH_

#include	<cstdlib>
#include	<list>
#include	<map>

#include	"Game.hpp"
#include	"Window.hpp"
#include	"Clock.hpp"

#include  	"Pause.hh"
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
#include	"Hud.hh"
#include	"EndGame.hh"
#include	"Bombe.hh"
#include	"Audio.hh"

class Player;
class Pause;
class Hud;
class Bombe;
class EndGame;

class 		Bomberman : public gdl::Game
{
public:
  std::list<AObject*>&			getObj();
  Bombe*				addBombe(Player* pl);

  void					initialize(void);
  void					update(void);
  void					draw(void);
  void					unload(void);
  void					deleteBombe(Bombe* b);
  void					refresh_setting();
  void					init_new(void);
  void					init_from_svg(void);
  void					update_all_obj(std::list<AObject*>::iterator itb);
  void					InputPause();
  void					deletePlayer(const int, const int);
  void          			InputEnd();

  int          				check_death();

  Bomberman(Level *my_level);
  ~Bomberman();
private:
  std::list<AObject*>			objects_;
  gdl::Clock				myClock;

  Pause					*_pause;
  EndGame				*_EndGame;
  Camera				camera_;
  float					time;
  Bonus					*bonus;
  Level					*level;
  Hud					*_hud;
  Texture				*texture_;
  Audio					*_audio;
  int					sp;
};

#endif /* !BOMBERMAN_HH_ */
