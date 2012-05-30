//
// Object.hh for  in /home/lyvet_r//tek2/C++/bomberman/sources
// 
// Made by randy lyvet
// Login   <lyvet_r@epitech.net>
// 
// Started on  Thu May  3 17:23:25 2012 randy lyvet
// Last update Wed May 30 13:57:27 2012 randy lyvet

//-1 floor
// 0 destructible
// 1 industruc
// 2 joeuurs
// 3 bomb
// 5 bonus

#ifndef OBJECT_HH_
# define OBJECT_HH_

#include	"Image.hpp"

#include	"AObject.hh"
#include	"Bomberman.hh"

class		Cube : public AObject
{
public:
  void		initialize(void);
  void		update(gdl::GameClock const &, gdl::Input &);
  void		draw(void);
  void		drawSurface(float x, float y, float z, float size, int mod);
  virtual int	getX() const;
  virtual int	getY() const;
  gdl::Image	texture_;

  Cube(float x, float y, float z, Texture *texture, int type);
  ~Cube(void);
};

class		Surface : public AObject
{
  float			size;
public:
  void			initialize(void);
  void			update(gdl::GameClock const &, gdl::Input &);
  void			draw(void);
  void			drawSurface(float x, float y, float z, float size);
  virtual int	getX() const;
  virtual int	getY() const;
  gdl::Image		texture_;

  Surface(float x, float y, float z, float size, Texture *texture);
  ~Surface(void);
};

class		BonusBox : public AObject
{
  int			x_;
  int			y_;
  int			z_;
  gdl::Image		tex_;
  int			ty;

public:
  void			initialize(void);
  void			update(gdl::GameClock const &, gdl::Input &);
  void			draw(void);
  void			drawSurface(float x, float y, float z, float size, int mod);
  virtual int		getX() const;
  virtual int		getY() const;
  int			getType() const;

  BonusBox(float x, float y, float z, gdl::Image tex, int ty_);
  ~BonusBox(void);
};

#endif /* !OBJECT_HH_ */
