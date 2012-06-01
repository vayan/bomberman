//
// Niveau.cpp for  in /home/cao_y//c++/svn_bomberman
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Fri Apr 27 12:36:02 2012 yuguo cao
// Last update Fri Jun  1 11:38:18 2012 alexandre haulotte
//

#include "Level.hh"

Level::Level()
{
  srand(time(NULL));
}

Level::Level(std::map<int, std::map<int, char> > map)
{
  _map = map;
  _width = _map.size();
  _height = _map[0].size();
}

Level::~Level()
{

}

void					Level::setCase(int x, int y, char c)
{
  if (x > 0 && x < _height && y > 0 && y < _height)
    _map[x][y] = c;
}

char					Level::getCase(int x, int y)
{
  char c = 'w';
  if (x > 0 && x < _height && y > 0 && y < _height)
    c = _map[x][y];
  return (c);
}

void					Level::readMap(const std::string& path)
{
  char					c;
  std::ifstream				fmap;
  std::string				cPath;
  int					x = 0;
  int					y = 0;

  cPath = "./.level/" + path + ".map";
  fmap.open(&cPath[0]);
  if(!fmap)
    {
      std::cout << "Invalid file " << path << "." << std::endl;
      exit(0);
    }
  while(fmap.good())
  {
    fmap.get(c);
    if (c == '\n')
    {
     x = 0;
     y++;
   }
   else
   {
     _map[x][y] = c;
     x++;
   }
 }
 fmap.close();
 _width = _map.size();
 _height = _map[0].size();
 printMap(this);
}

void					Level::generateMap()
{
  int					x = 0;
  int					y = 0;
  Settings				_conf;
  int					width = _conf.GetMapx();
  int					height = _conf.GetMapY();
  int					nbPlayers = _conf.GetNbPlayers();
  int					nbIas = _conf.GetNb_AI();

  while (y < height)
  {
    if (x == width - 1)
    {
     _map[x][y] = 'w';
     x = 0;
     y++;
   }
   else
   {
     if (x == 0 || y == 0 || y == height - 1 || (!(x % 2) && !(y % 2)))
       _map[x][y] = 'w';
     else if (x != 0 && y != 0 && y != height - 1)
       _map[x][y] = 'd';
     else
       _map[x][y] = 'f';
     x++;
   }
 }
 _width = width;
 _height = height;
 placeHole();
 placePlayer(nbPlayers, nbIas);
 printMap(this);
}

void					Level::placePlayer(int nbPlayers, int nbIas)
{
  int					nbTot = nbPlayers + nbIas;
  int					per = (_height - 2) * 2 + (_width - 4) * 2;
  int					rep = per / nbTot;// + (nbPlayers >= _width / 2);
  int					i = 0;
  int					tmp_x = 1;
  int					tmp_y = 1;
  char					player = 'r';

  if (rep < 4)
    std::cout << "Pas jouable." << std::endl;
  //throw(new Errur("Too many players for this map."));
  std::cout << per << " " << rep << std::endl;
  while (nbTot > 0)
    {
      if (!(i % rep))
	{
	  if (i > _width - 4)
	    {
	      tmp_x = _width - 2;
	      tmp_y = i - (_width - 4);
	      if (i > (_width + _height) - 6)
		{
		  tmp_x = _width - (i - (_width + _height - 6)) - 2;
		  tmp_y = _height - 2;
		  if (i > (2 * _width + _height - 10))
		    {
		      tmp_x = 1;
		      tmp_y = _height - (i - ((2 * _width + _height - 10))) - 1;
		    }
		}
	    }
	  else
	    tmp_x = i + 1;
	  _map[tmp_x][tmp_y] = player;
	  std::cout << i << " " << tmp_x << " " << tmp_y << std::endl;
	  if (player == 'r' && nbPlayers == 2)
	    player = 'g';
	  else if (player == 'g' || nbPlayers == 1)
	    player = 'i';
	  (tmp_x + 1 < _height - 1) ? _map[tmp_x + 1][tmp_y] = 'f' : _map[0][0] = 'w';
	  (tmp_x - 1 > 0) ? _map[tmp_x - 1][tmp_y] = 'f' : _map[0][0] = 'w';
	  (tmp_y + 1 < _width - 1) ? _map[tmp_x][tmp_y + 1] = 'f' : _map[0][0] = 'w';
	  (tmp_y - 1 > 0) ? _map[tmp_x][tmp_y - 1] = 'f' : _map[0][0] = 'w';
	  nbTot--;
	}
      i++;
    }
}

void					Level::placeHole()
{
  int					x;
  int					y = 1;

  while (y < _height - 1)
  {
    x = 1;
    while (x < _width - 1)
    {
     if (rand() % 101 < 10)
     {
       _map[x][y] = 'f';
     }
     x++;
   }
   y++;
 }
}

void					Level::printMap(Level *lvl) const
{
  std::map<int, std::map<int, char> > _map = lvl->getMap();
  for (int i = 0; i < lvl->getHeight(); i++)
  {
    for (int j = 0; j < lvl->getWidth(); j++)
    {
     std::cout << _map[j][i] << " ";
   }
   std::cout << std::endl;
 }
}

void					Level::movePlayer(int x, int y, AObject *pl, char c)
{
  if (_map[x][y] == c)
    _map[x][y] = 'f';
  _map[pl->getX()][pl->getY()] = c;
}

std::string				Level::pack()
{
  int					x;
  int					y = 0;
  std::string				s;

  while (y < _height)
  {
    x = 0;
    while (x < _width)
    {
      if (_map[x][y] != '\n')
        s += _map[x][y];
     x++;
   }
   s += ';';
   y++;
 }
 return (s);
}

Level					*Level::unpack(const std::string& s)
{
  int					i = 0;
  int					x = 0;
  int					y = 0;
  std::map<int, std::map<int, char> >	map_;

  while (s[i])
  {
    if (s[i] == ';')
    {
     map_[x][y] = '\n';
     x = 0;
     y++;
   }
   else
   {
     map_[x][y] = s[i];
     x++;
   }
   i++;
 }
 return (new Level(map_));
}

std::map<int, std::map<int, char> >	Level::getMap() const
{
  return (_map);
}

int					Level::getHeight() const
{
  return (_height);
}

int					Level::getWidth() const
{
  return (_width);
}
