//
// BonusBox.cpp for BonusBox in /home/haulot_a//C++/Bomber-Man/svn_bomberman/gdl
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Wed May 23 10:19:26 2012 alexandre haulotte
// Last update Wed May 23 12:41:26 2012 alexandre haulotte
//

#include	"Object.hh"

void		BonusBox::initialize(void)
{}

void		BonusBox::update(gdl::GameClock const &, gdl::Input &)
{}

void		BonusBox::draw(void)
{
  float         offset = 0.4 / 2.0;

  this->tex_.bind();
  glBegin(GL_QUADS);
  drawSurface(x_, y_, z_ - offset, 0.4, 1);
  drawSurface(x_, y_, z_ + offset, 0.4, 1);
  drawSurface(x_ + offset, y_, z_, 0.4, 2);
  drawSurface(x_ - offset, y_, z_, 0.4, 2);
  drawSurface(x_, y_ + offset, z_, 0.4, 3);
  drawSurface(x_, y_ - offset, z_, 0.4, 3);
  glEnd();
}

void		BonusBox::drawSurface(float x, float y, float z,
				      float size, int mod)
{
  float         offset;

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

int		BonusBox::getX() const
{ return (x_); }

int		BonusBox::getY() const
{ return (y_); }

int             BonusBox::getType() const
{ return (ty); }

BonusBox::BonusBox(float x, float y, float z, gdl::Image tex, int ty_)
  :AObject(), x_(x), y_(y), z_(z), ty(ty_)
{
  this->x = x;
  this->y = y;
  _type = 5;
  tex_ = tex;
}

BonusBox::~BonusBox(void)
{}
