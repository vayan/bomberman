//
// Vector3f.cpp for  in /home/lyvet_r//tek2/C++/bomberman/sources
// 
// Made by randy lyvet
// Login   <lyvet_r@epitech.net>
// 
// Started on  Thu May  3 15:13:40 2012 randy lyvet
// Last update Tue May  8 13:41:25 2012 randy lyvet
//

#include	"Vector3f.hh"

void		Vector3f::set3f(float x, float y, float z)
{
  this->x = x;
  this->y = y;
  this->z = z;
}

Vector3f::Vector3f(void)
  : x(1.5), y(1.5), z(5)
{}

Vector3f::Vector3f(float x, float y, float z)
  : x(x), y(y), z(z)
{}
