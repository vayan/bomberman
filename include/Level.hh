//
// Niveau.hh for  in /home/cao_y//c++/svn_bomberman
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Fri Apr 27 12:37:47 2012 yuguo cao
// Last update Fri Jun  1 11:38:07 2012 alexandre haulotte
//

#ifndef		__LEVEL__
# define	__LEVEL__

#include	<map>
#include	<string>
#include	<iostream>
#include	<fstream>
#include	<ctime>
#include	<cstdlib>
#include	"Settings.hh"
#include	"AObject.hh"

class AObject;

enum direction
  {
    HAUT,
    BAS,
    GAUCHE,
    DROIT
  };

class Level
{
private:
  std::map<int, std::map<int, char> >	_map;
  int					_width;
  int					_height;

public:
  Level();
  Level(std::map<int, std::map<int, char> >);
  ~Level();

  void					readMap(const std::string& path);
  void					generateMap();
  void					movePlayer(int x, int y, AObject *pl, char c);
  void					placePlayer(int, int);
  void					placeHole();
  void					setCase(int x, int y, char c);
  // non const car operateur [][]
  char					getCase(int x, int y);
  std::string				pack();
  Level					*unpack(const std::string&);
  std::map<int, std::map<int, char> >	getMap() const;
  int					getHeight() const;
  int					getWidth() const;
  void					printMap(Level*) const;
};

#endif
