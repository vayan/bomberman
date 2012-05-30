//
// main.cpp for  in /home/lyvet_r//tek2/C++/bomberman/sources
// 
// Made by randy lyvet
// Login   <lyvet_r@epitech.net>
// 
// Started on  Thu May  3 12:15:05 2012 randy lyvet
// Last update Fri May 25 15:53:42 2012 yuguo cao
//

#include	<map>
#include	<iostream>
#include	<cstdlib>

#include "Menu.hh"
#include	"Bomberman.hh"
#include "Settings.hh"
#include "Save.hh"

std::map<int,std::map<int,char> > genmap()
{
  int		x = 0;
  int		y = 0;
  std::map<int,std::map<int,char> >	map;

  while (y < 5)
  {
    x = 0;
    while (x++ < 5)
     map[x][y] = 'f';
   y++;
 }
 return (map);
}

int		main(int ac, char **av)
{
  while (11)
  {
    Level   *level = new Level();
    Menu    GUI;

    GUI.run();

    Settings conf;

    if (conf.GetSVG() == 1)
    {
      Save sv;
      std::cout << "Reload from save " << sv.GetLvl() << std::endl;
      level = level->unpack(sv.GetLvl());
    }
    else
    {
      std::cout << "new game " << std::endl;
      level->generateMap(conf);
    }
    Bomberman	*bomberman = new Bomberman(level);
    bomberman->run();

    delete bomberman;
    delete level;
  }
  return (EXIT_SUCCESS);
}
