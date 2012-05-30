//
// Bonus.hh for Bonus in /home/haulot_a//C++/Bomber-Man/svn_bomberman/gdl
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Tue May 22 14:34:48 2012 alexandre haulotte
// Last update Wed May 30 11:46:28 2012 randy lyvet
//

#ifndef	__UU_HH__
#define	__UU_HH__

#include	"Level.hh"
#include	"AObject.hh"
#include	"Texture.hh"

class Bonus
{
  std::map<int, std::map<int, char> >   _map;
  Texture				*tex_;

public:
  char		getBonus(int x, int y);
  AObject*	createBonus(int x, int y, int z, int ty);

  Bonus(int size, Level *lvl, Texture *tex);
  ~Bonus();
};

#endif
