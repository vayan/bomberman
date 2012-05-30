//
// Camera.hh for  in /home/lyvet_r//tek2/C++/bomberman/sources
// 
// Made by randy lyvet
// Login   <lyvet_r@epitech.net>
// 
// Started on  Thu May  3 16:09:58 2012 randy lyvet
// Last update Wed May  9 16:25:04 2012 randy lyvet

#ifndef		CAMERA_HH_
# define	CAMERA_HH_

#include	<GL/gl.h>
#include	<GL/glu.h>
#include        <iostream>

#include	"GameClock.hpp"
#include	"Input.hpp"

#include	"Vector3f.hh"

class		Camera
{
public:
  void		initialize(void);
  void		update(gdl::GameClock const &, gdl::Input &);
  void          setPosition(float width, float height);
  Camera(void);

private:
  Vector3f	position_;
  Vector3f	target_;
};

#endif /* !CAMERA_HH_ */
