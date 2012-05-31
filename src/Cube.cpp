//
// Cube.cpp for  in /home/lyvet_r//tek2/C++/bomberman/sources
// 
// Made by randy lyvet
// Login   <lyvet_r@epitech.net>
// 
// Started on  Thu May  3 17:30:05 2012 randy lyvet
// Last update Thu May 31 12:40:17 2012 yuguo cao
//

#include		"Object.hh"

void			Cube::initialize()
{}

void			Cube::update(gdl::GameClock const & gameClock, gdl::Input & input)
{
  gameClock.getElapsedTime();
  input.getMousePositionX();
}

void			Cube::drawSurface(float x, float y, float z, float size, int mod)
{
  float		offset;

  offset = size / 2;
  switch (mod)
    {
    case 1:
      glTexCoord2d(1,1); glVertex3d(x + offset , y + offset, z);
      glTexCoord2d(1,0); glVertex3d(x + offset, y - offset, z);
      glTexCoord2d(0,0); glVertex3d(x - offset, y - offset, z);
      glTexCoord2d(0,1); glVertex3d(x - offset, y + offset, z);
      break;
    case 2:
      glTexCoord2d(1,1); glVertex3d(x, y + offset, z + offset);
      glTexCoord2d(0,1); glVertex3d(x, y - offset, z + offset);
      glTexCoord2d(0,0); glVertex3d(x, y - offset, z - offset);
      glTexCoord2d(1,0); glVertex3d(x, y + offset, z - offset);
      break;
    case 3 :
      glTexCoord2d(1,1); glVertex3d(x + offset, y, z + offset);
      glTexCoord2d(1,0); glVertex3d(x + offset, y, z - offset);
      glTexCoord2d(0,0); glVertex3d(x - offset, y, z - offset);
      glTexCoord2d(0,1); glVertex3d(x - offset, y, z + offset);
      break;
    }
}

void			Cube::draw()
{
  float		offset = 1 / 2.0;
  float		size = 1;

  // if (_type == 0)
  //   {
  //     offset = 0.4;
  //     size = 0.9;
  //   }
  this->texture_.bind();
  glBegin(GL_QUADS);
  drawSurface(position_.x, position_.y, position_.z - offset, size, 1);
  drawSurface(position_.x, position_.y, position_.z + offset, size, 1);
  drawSurface(position_.x + offset, position_.y, position_.z, size, 2);
  drawSurface(position_.x - offset, position_.y, position_.z, size, 2);
  drawSurface(position_.x, position_.y + offset, position_.z, size, 3);
  drawSurface(position_.x, position_.y - offset, position_.z, size, 3);
  glEnd();
}

Cube::Cube(float x, float y, float z, Texture *texture, int type)
  : AObject()
{
  _type = type - 1;
  this->x = x;
  this->y = y;
  position_.set3f(x, y, z);
  switch (type)
    {
    case 1 :
      texture_ = texture->Cube_;
      break;
    case 2 :
      texture_ = texture->Wall_;
      break;
    }
}

int   Cube::getX() const
{
  return (x);
}

int   Cube::getY() const
{
  return (y);
}

Cube::~Cube()
{}
