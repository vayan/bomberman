//
// AObject.hh for  in /home/lyvet_r//tek2/C++/bomberman/sources
// 
// Made by randy lyvet
// Login   <lyvet_r@epitech.net>
// 
// Started on  Thu May  3 14:29:57 2012 randy lyvet
// Last update Wed May 30 11:41:02 2012 randy lyvet

#ifndef AOBJECT_HH_//
# define AOBJECT_HH_

#include	<GL/gl.h>
#include	<GL/glu.h>

#include	"Game.hpp"
#include	"Vector3f.hh"

class		AObject
{
public:
  int			_type;

  virtual void		initialize(void) = 0;
  virtual void		update(gdl::GameClock const &, gdl::Input &) = 0;
  virtual void		draw(void) = 0;
  virtual int		getX() const = 0;
  virtual int		getY() const = 0;

  AObject(void)
    : _type(0), position_(0, 0, 0), rotation_(0, 0, 0)
  {}

  virtual ~AObject() {}

protected:
  Vector3f		position_;
  Vector3f		rotation_;
  int			x;
  int			y;
};

#endif /* !AOBJECT_HH_ */
