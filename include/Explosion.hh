//
// Explosion.hh for  in /home/lyvet_r//tek2/C++/bomberman/svn_bomberman/gdl
// 
// Made by randy lyvet
// Login   <lyvet_r@epitech.net>
// 
// Started on  Sat May 26 13:08:27 2012 randy lyvet
// Last update Wed May 30 11:55:46 2012 randy lyvet
//

#ifndef		_EXPLOSION_HH_
#define		_EXPLOSION_HH_

#include	"Player.hh"
#include	"AObject.hh"

class 		Explosion : public AObject
{
protected :
  int		Up;
  int		Down;
  int		Left;
  int		Right;
  gdl::Image	texture_;
  gdl::Clock	timer;
  float		time;
  float		ti;

public :
  void		initialize();
  void		update(gdl::GameClock const &, gdl::Input &);
  void		draw();
  int		getX() const;
  int		getY() const;
  bool		getTime() const;
  void         	drawSurface(float _x, float _y, float z, float size, int mod, float x_size, float y_size);
  //void		drawSurface(float x, float y, float z, float size);
  void		animExplose();
  void		drawAnimX(int _x);
  void		drawAnimY(int _y);

  Explosion(int up, int down, int left, int right, int x, int y);
  ~Explosion();
};

#endif
