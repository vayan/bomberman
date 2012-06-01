//
// Bonus.hh for Bonus in /home/haulot_a//C++/Bomber-Man/svn_bomberman/gdl
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Tue May 22 14:34:48 2012 alexandre haulotte
// Last update Fri Jun  1 11:46:10 2012 alexandre haulotte
//

#ifndef	__UU_HH__
#define	__UU_HH__

#include	"Level.hh"
#include	"AObject.hh"
#include	"Texture.hh"

class Bonus
{
  std::map<int, std::map<int, char> >   _map;
  const Texture				*tex_;

public:
  // non const car operateur [][]
  char		getBonus(int x, int y);
  AObject*	createBonus(int x, int y, int z, int ty);

  Bonus(int size, Level *lvl, const Texture *tex);
  ~Bonus();
};

#endif
