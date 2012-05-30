//
// Vector3f.hh for  in /home/lyvet_r//tek2/C++/bomberman/sources
// 
// Made by randy lyvet
// Login   <lyvet_r@epitech.net>
// 
// Started on  Thu May  3 15:11:27 2012 randy lyvet
// Last update Tue May  8 13:39:44 2012 randy lyvet

#ifndef VECTOR3F_HH_//
# define VECTOR3F_HH_

struct		Vector3f
{
  float		x;
  float		y;
  float		z;

  Vector3f(void);
  Vector3f(float x, float y, float z);
  void	set3f(float x, float y, float z);
};

#endif /* !VECTOR3F_HH_ */
