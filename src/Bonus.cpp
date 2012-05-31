//
// Bonus.cpp for Bonus in /home/haulot_a//C++/Bomber-Man/svn_bomberman/gdl
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Tue May 22 14:44:42 2012 alexandre haulotte
// Last update Thu May 31 11:48:51 2012 alexandre haulotte
//

#include	"Bonus.hh"
#include	"Object.hh"

Bonus::Bonus(int size, Level *lvl, Texture *tex)
{
  int	x = 1;
  int	y = 1;
  tex_ = tex;
  int	rnd;

  while (y < size - 1)
    {
      x = 1;
      while (x < size - 1)
	{
	  if (lvl->getCase(x, y) == 'd')
	    {
	      rnd = rand() % 20;
	      switch (rnd)
		{
		case 0:
		  _map[x][y] = 'n';
		  break;
		case 1:
		  _map[x][y] = 'p';
		  break;
		case 2:
		  _map[x][y] = 's';
		  break;
		case 6:
		  _map[x][y] = 'n';
		  break;
		case 7:
		  _map[x][y] = 'p';
		  break;
		case 8:
		  _map[x][y] = 's';
		  break;
		case 3:
		  _map[x][y] = 'o';
		  break;
		case 4:
		  _map[x][y] = 'q';
		  break;
		case 5:
		  _map[x][y] = 't';
		  break;
		case 9:
		  rnd = rand() % 3;
		  if (rnd == 0)
		    _map[x][y] = 'l';
		  else if (rnd == 1)
		    _map[x][y] = 'u';
		  else
		    _map[x][y] = '.';
		  break;
		default:
		  _map[x][y] = '.';
		}
	    }
	  x++;
	}
      y++;
    }
}

AObject*      Bonus::createBonus(int x, int y, int z, int ty)
{
  AObject*	obj;

  switch (ty)
    {
    case 1:
      obj = new BonusBox(x, y, z, tex_->Po_, 0);
      break;
    case 2:
      obj = new BonusBox(x, y, z, tex_->Nb_, 1);
      break;
    case 3:
      obj = new BonusBox(x, y, z, tex_->Sp_, 2);
      break;
    case 4:
      obj = new BonusBox(x, y, z, tex_->Pod_, 4);
      break;
    case 5:
      obj = new BonusBox(x, y, z, tex_->Nbd_, 5);
      break;
    case 6:
      obj = new BonusBox(x, y, z, tex_->Spd_, 3);
      break;
    case 7:
      obj = new BonusBox(x, y, z, tex_->Line_, 6);
      break;
    case 8:
      obj = new BonusBox(x, y, z, tex_->Pierce_, 7);
      break;
    }
  return (obj);
}

Bonus::~Bonus()
{}

char  Bonus::getBonus(int x, int y)
{
  return (_map[x][y]);
}
