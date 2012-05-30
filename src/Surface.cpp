//
// Surface.cpp for  in /home/lyvet_r//tek2/C++/bomberman/test
// 
// Made by randy lyvet
// Login   <lyvet_r@epitech.net>
// 
// Started on  Tue May  8 19:07:53 2012 randy lyvet
// Last update Tue May 29 18:12:47 2012 alexandre haulotte
//

#include		"Object.hh"

void			Surface::initialize()
{
}

void			Surface::update(gdl::GameClock const & gameClock, gdl::Input & input)
{}

void                    Surface::drawSurface(float x, float y, float z, float size)
{
  float         offset = size / 2;

  glTexCoord2d(1,1); glVertex3d(x + offset , y + offset, z);
  glTexCoord2d(1,0); glVertex3d(x + offset, y - offset, z);
  glTexCoord2d(0,0); glVertex3d(x - offset, y - offset, z);
  glTexCoord2d(0,1); glVertex3d(x - offset, y + offset, z);
}

void			Surface::draw()
{
  float         offset = 1 / 2.0;

  this->texture_.bind();
  glBegin(GL_QUADS);
  drawSurface(position_.x, position_.y, position_.z - offset, size);
  glEnd();
}

Surface::Surface(float x, float y, float z, float size, Texture *texture)
  : AObject()
{
  _type = -1;
  this->size = size;
  this->x = x;
  this->y = y;
  position_.set3f(x, y, z);
  this->texture_ = texture->Floor_;
}

int   Surface::getX() const
{
  return (x);
}

int   Surface::getY() const
{
  return (y);
}

Surface::~Surface()
{}
