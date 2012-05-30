//
// IA.cpp for IA in /home/carlie_a//Bomberman
// 
// Made by anatole carlier
// Login   <carlie_a@epitech.net>
// 
// Started on  Mon May  7 10:03:08 2012 anatole carlier
// Last update Wed May 30 12:37:23 2012 anatole carlier
//

#include "IA.hh"
#include "Player.hh"
#include "Level.hh"

IA::IA(int level, Player* pl)
{
  this->_pl = pl;
  this->level = level;
  this->escape = 0;
  this->prev = 'l';
  this->allies = false;
  this->i = 0;
  switch (level)
    {
    case EASY:
      {
	std::cout << "Easy!";
	this->wait = 50;
	this->time_wait = 75;
      }
    case HARD:
      {
	std::cout << "Hard...";
	this->wait = 20;
	this->time_wait = 50;

      }
    case INFERNO:
      {
	std::cout << "Inferno!!!!!!!";
        this->wait = 0;
        this->time_wait = 20;
	this->allies = true;
      }
    }
}

IA::~IA() {}

void	IA::IA_moves(Level *lv, std::list<AObject*> all_object)
{
  std::map<int, std::map<int, char> > map;

  map = lv->getMap();
  this->object = all_object;
  this->x = _pl->getX();
  this->y = _pl->getY();
  if ( escape == 0 && search_bomb(map, lv) == 0 && this->wait != 0)
    {
      if (this->wait != 0)
	{
	  this->wait--;
	  return ;
	}
    }
  else if (this->escape == 1)
    {
      if (search_bomb(map, lv) == 0)
        {
          this->escape = 0;
	  this->wait = 150;
	}
      else
	{
	  if (i == _pl->getPower())
	    {
	      i = 0;
	      prev_move(map, lv);
	    }
	  if (i != 0)
	    {
	      i++;
	      prev_move(map, lv);
	    }
	}
    }
  else if (search_bomb(map, lv) == 0)
    {
      if (level != 0)
	{
	  if (map[x][y+1] == 'r' || map[x][y+2] == 'r' || map[x+1][y] == 'r' || map[x+2][y] == 'r' || map[x-1][y] == 'r' || map[x-2][y] == 'r')
	    {
	      _pl->ActionDropBomb(lv); escape = 1; 
	      return;
	    }
	  if (map[x][y+1] == 'g' || map[x][y+2] == 'g' || map[x+1][y] == 'g' || map[x+2][y] == 'g' || map[x-1][y] == 'g' || map[x-2][y] == 'g')
	    {
	      _pl->ActionDropBomb(lv); escape = 1; 
	      return;
	    }
	}
      if (x == 1)
	{
	  if (see_right(map, lv) != 0)
	    if (see_down(map, lv) != 0)
	      see_left(map, lv);
	}
      else if (y == (lv->getWidth() - 2) && x < 3)
	see_down(map, lv);
      else
	{
	  if (see_left(map, lv) != 0)
	    if (see_up(map, lv) != 0)
	      if (see_down(map, lv) != 0)
		see_right(map, lv);
	}
    }
}

int     IA::search_bomb(std::map<int, std::map<int, char> > map, Level *lv)
{
  if (map[x][y] == 'b')
    {
      this->escape = 1;
      if (see_left(map, lv) != 0)
	if (see_up(map, lv) != 0)
	  if (see_down(map, lv) != 0)
	    see_right(map, lv);
      return (1);
    }
  if (((y - 1) >= 0 && map[x][y-1] == 'b') || ((y - 2) >= 0 && map[x][y-2] == 'b') || ((y - 3) >= 0 &&  map[x][y-3] == 'b'))
    {
      this->escape = 1;
      if (see_right(map, lv) != 0)
	if (see_up(map, lv) != 0)
	  see_down(map, lv);
      return (1);
    }
  if (((x - 1) >= 0 && map[x-1][y] == 'b') || ((x - 2) >= 0 && map[x-2][y] == 'b') || ((x - 3) >= 0 &&  map[x-3][y] == 'b'))
    {
      this->escape = 1;
      if (see_right(map, lv) != 0)
	if (see_left(map, lv) != 0)
	  see_down(map, lv);
	return (1);
    }
  if (((y + 1) >= 0 && map[x][y+11] == 'b') || ((y + 2) >= 0 && map[x][y+2] == 'b') || ((y + 3) >= 0 &&  map[x][y+3] == 'b'))
    {
      this->escape = 1;
      if (see_down(map, lv) != 0)
	if (see_left(map, lv) != 0)
          see_up(map, lv);
	return (1);
    }
  if (((x + 1) >= 0 && map[x+1][y] == 'b') || ((x + 2) >= 0 && map[x+2][y] == 'b') || ((x + 3) >= 0 &&  map[x+3][y] == 'b'))
    {
      this->escape = 1;
      if (see_left(map, lv) != 0)
	if (see_right(map, lv) != 0)
          see_up(map, lv);
      return (1);
    }
  else
    return (0);
}

void	IA::prev_move(std::map<int, std::map<int, char> > map, Level *lv)
{
  switch (prev)
    {
    case 'l':
      if (see_up(map, lv) != 0)
        if (see_down(map, lv) != 0)
          see_right(map, lv);
    case 'r':
      if (see_up(map, lv) != 0)
        if (see_down(map, lv) != 0)
          see_left(map, lv);
    case 'u':
      if (see_left(map, lv) != 0)
        if (see_right(map, lv) != 0)
          see_down(map, lv);
    case 'd':
      if (see_left(map, lv) != 0)
        if (see_right(map, lv) != 0)
          see_up(map, lv);
    default:
      return;
    }
}

int	IA::see_left(std::map<int, std::map<int, char> > map, Level *lv)
{
  wait = time_wait;
  switch (map[x][y-1])
    {
    case 'w':
      return (1); break;
    case 'd':
      _pl->ActionDropBomb(lv); escape = 1; return (1); break;
    case 'r':
      _pl->ActionDropBomb(lv);escape = 1; return (1); break;
    case 'g':
      _pl->ActionDropBomb(lv);escape = 1; return (1); break;
    case 'i':
      {
	if (this->allies == false)
	  _pl->ActionDropBomb(lv);escape = 1; return (1); break;
      }
    case 'f':
      if (map[x][y-2] != 'b' && map[x][y-3] != 'b')
    	{
    	  _pl->ActionLeft(lv, this->object); prev = 'l';
	  return (0);
    	  break;
    	}
      else
	{
	  return (1);
	  break;
	}
    }
  return (1);
}

int     IA::see_up(std::map<int, std::map<int, char> > map, Level *lv)
{
  wait = time_wait;
  switch (map[x-1][y])
    {
    case 'w':
      return (1); break;
    case 'd':
      {
	if (map[x][y-1] == 'f' && map[x][y+1] == 'f')
	  {
	    _pl->ActionDropBomb(lv); see_right(map, lv); escape = 1; 
	    return (1); break;
	  }
	else
	  this->wait = 10000; 
      }
    case 'r':
      _pl->ActionDropBomb(lv);escape = 1; return (1); break;
    case 'g':
      _pl->ActionDropBomb(lv);escape = 1; return (1); break;
    case 'i':
      {
	if (this->allies == false)
	  _pl->ActionDropBomb(lv);escape = 1; return (1); break;
      }
    case 'f':
      if (map[x-2][y] != 'b' && map[x-3][y] != 'b')
        {
          _pl->ActionUp(lv, this->object); prev = 'u';
          return (0);
          break;
        }
      else
        {
          return (1);
          break;
        }
    }
  return (1);
}

int     IA::see_right(std::map<int, std::map<int, char> > map, Level *lv)
{
  wait = time_wait;
  switch (map[x][y+1])
    {
    case 'w':
      return (1); break;
    case 'd':
      if (map[x][y-1] == 'f' && map[x][y+1] == 'f')
	{
	  _pl->ActionDropBomb(lv); see_right(map, lv); escape = 1;
	  return (1); break;
	}
    case 'r':
      _pl->ActionDropBomb(lv);escape = 1; return (1); break;
    case 'g':
      _pl->ActionDropBomb(lv);escape = 1; return (1); break;
    case 'i':
      {
	if (this->allies == false)
	  _pl->ActionDropBomb(lv);escape = 1; return (1); break;
      }
    case 'f':
      if (map[x][y+2] != 'b' && map[x][y+3] != 'b')
	{
          _pl->ActionRight(lv, this->object); prev = 'r';
	  return (0);
          break;
	}
      else
	{
	  return (1);
	  break;
	}
    }
  return (1);
}

int     IA::see_down(std::map<int, std::map<int, char> > map, Level *lv)
{
  wait = time_wait;
  switch (map[x+1][y])
    {
    case 'w':
      return (1); break;
    case 'd':
      _pl->ActionDropBomb(lv); escape = 1; return (1); break;
    case 'r':
      _pl->ActionDropBomb(lv);escape = 1; return (1); break;
    case 'g':
      _pl->ActionDropBomb(lv);escape = 1; return (1); break;
    case 'i':
      {
	if (this->allies == false)
	  _pl->ActionDropBomb(lv);escape = 1; return (1); break;
      }
    case 'f':
      if (map[x+2][y] != 'b' && map[x+3][y] != 'b')
        {
          _pl->ActionDown(lv, this->object); prev = 'd';
          return (0);
          break;
        }
      else
        {
          return (1);
          break;
        }
    }
  return (1);
}
