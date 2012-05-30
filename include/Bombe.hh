//
// Bombe.hh for bombe in /home/haulot_a//C++/Bomber-Man/svn_bomberman/include
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Wed May  2 12:30:19 2012 alexandre haulotte
// Last update Wed May 30 11:39:15 2012 alexandre haulotte
//

#ifndef	__BOMBE_HH__
#define	__BOMBE_HH__

#include	<string>

#include	"Model.hpp"

#include	"Player.hh"
#include	"Level.hh"
#include        "AObject.hh"
#include	"Bonus.hh"
#include	"Explosion.hh"

class Player;

class Bombe : public AObject
{
  int		powa;
  int		timer;
  Level	*lvl;
  Bonus	*bonus;
  int	score;
public:
  Bombe(Player *j, Bonus *bon, Level *lvl);
  Bombe(int &_x, int &_y, int &_powa);
  gdl::Model             model_;
  virtual int	getX() const;
  virtual int	getY() const;
  int	getPowa() const;
  int	time(bool b);
  void	explose(std::list<AObject*> &obj);
  bool	bang(int dir, bool state, std::list<AObject*> &obj, int actBang);
  std::list<AObject*>::iterator getObj(std::list<AObject*> &obj, int x_, int y_);
  ~Bombe();
  void		initialize(void);
  void		update(gdl::GameClock const &clock, gdl::Input &_input);
  void		draw(void);
  static std::string	pack(Bombe* b);
  static Bombe		*unpack(std::string str);
  void                  drawSurface(float x, float y, float z, float size, int mod);
  int			checkPath(int, int);
  int			scoring();
};

#endif
