//
// Bombe.cpp for Bombe in /home/haulot_a//C++/Bomber-Man/svn_bomberman/src
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Wed May  2 12:29:56 2012 alexandre haulotte
// Last update Tue May 29 18:14:32 2012 alexandre haulotte
//

// 0 : Gauche
// 1 : Droite
// 2 : Haut
// 3 : Bas

#include	"Bombe.hh"
#include	"Utils.hh"

void		Bombe::initialize()
{

}

void		Bombe::update(gdl::GameClock const &clock, gdl::Input &_input)
{

}

void		Bombe::draw()
{

      glPushMatrix();
      glTranslatef(1 * x, 1 * y, 1);
      glScalef(0.002f, 0.002f, 0.002f);
      glRotatef(90, 1.0f, 0.0f, 0.0f);
      this->model_.draw();
      glPopMatrix();
      // //      std::list<AObject*>::iterator itb = this->obj.begin();
      // while (itb != this->obj.end())
      // 	{
      // 	  (*itb)->draw();
      // 	  itb++;
      // 	}
}

Bombe::Bombe(Player *j, Bonus *bon, Level *lvl)
  :AObject(), powa(j->getPower()), lvl(lvl), bonus(bon)
{

  x = j->getX();
  y = j->getY();
  _type = 3;
  timer = 150;
  this->model_ = gdl::Model::load("assets/bomb.fbx");
}

Bombe::Bombe(int &_x, int &_y, int &_powa)
  :AObject(), powa(_powa), lvl(NULL)
{
  x = _x;
  y = _y;
  _type = 3;
  timer = 150;
  this->model_ = gdl::Model::load("assets/bomb.fbx");
}

int	Bombe::getX() const
{
  return (x);
}

int	Bombe::getY() const
{
  return (y);
}

int	Bombe::getPowa() const
{
  return (powa);
}

int	Bombe::time(bool b)
{
  if (b == false)
    timer--;
  if (timer <= 0)
    {
      timer = -50;
      return (1);
    }
  if (b == true)
    timer = 0;
  return (0);
}

std::list<AObject*>::iterator Bombe::getObj(std::list<AObject*> &obj, int x_, int y_)
{
  std::list<AObject*>::iterator itb;
  for (itb = obj.begin(); itb != obj.end(); itb++)
    {
      if ((*itb)->getX() == x && (*itb)->getY() == y && (*itb)->_type != -1 && (*itb)->_type != 3 && (*itb)->_type != 4 && (*itb)->_type != 6)
	return (itb);
      if ((*itb)->getX() == x_ && (*itb)->getY() == y_ && (*itb)->_type != -1 && (*itb)->_type != 6)
	{
	  return (itb);
	}
    }
  return (obj.end());
}

bool	Bombe::bang(int dir, bool state, std::list<AObject*> &obj, int actBang)
{
  std::list<AObject*>::iterator	tmp;
  int		x_b, y_b, type;
  char	c;

  if (state)
    {
      tmp = obj.end();
      x_b = x;
      y_b = y;
      switch (dir)
	{
	case 0:
	  x_b -= actBang;
	  break;
	case 1:
	  x_b += actBang;
	  break;
	case 2:
	  y_b -= actBang;
	  break;
	case 3:
	  y_b += actBang;
	  break;
	default:
	  break;
	}
      tmp = getObj(obj, x_b, y_b);
      if (tmp == obj.end())
	{
	  return (true);
	}
      else
	{
	  if ((*tmp)->_type != 1)
	    {
	      type = (*tmp)->_type;
	      if ((*tmp)->_type != 2)
		{
		  if ((*tmp)->_type == 3 || (*tmp)->_type == 4)
		    {
		      static_cast<Bombe*>((*tmp))->time(true);
		    }
		  else
		    {
		      delete (*tmp);
		      obj.erase(tmp);
		    }
		}
	      else
		static_cast<Player*>((*tmp))->die();
	      lvl->setCase(x_b, y_b, 'f');
	      if (type != 0)
		return (true);
	      c = bonus->getBonus(x_b, y_b);
	      switch (c)
		{
		case 'n':
		  obj.push_back( bonus->createBonus(x_b, y_b, 1, 3));
		  break;
		case 'p':
		  obj.push_back( bonus->createBonus(x_b, y_b, 1, 1));
		  break;
		case 's':
		  obj.push_back( bonus->createBonus(x_b, y_b, 1, 2));
		  break;
		default:
		  break;
		}
	    }
	}
    }
  return (false);
}

void	Bombe::explose(std::list<AObject*> &obj)
{
  int	i = 1;
  bool	state[4];

  AObject *kaboom = new Explosion(checkPath(1 ,getPowa()),
				  checkPath(2 ,getPowa()),
				  checkPath(3 ,getPowa()),
				  checkPath(4 ,getPowa()), this->x, this->y);
  obj.push_back(kaboom);
  for (i = 0; i < 4; i++)
    state[i] = true;
  for (i = 1; i <= powa; i++)
    {
      for (int j = 0; j < 4; j++)
	{
	  state[j] = bang(j, state[j], obj, i);
	}
    }
}


std::string	Bombe::pack(Bombe* b)
{
  std::string	str;

  str = to_string(b->getX()) + ";"
    + to_string(b->getY()) + ";"
    + to_string(b->getPowa());
  return (str);
}

Bombe	*Bombe::unpack(std::string str)
{
  Bombe	*bom;
  int	x;
  int	y;
  int	pow;
  std::vector<std::string> toke = split_to_vec(str, ";");
  std::vector<std::string>::iterator it = toke.begin();

  x = to_number<int>(*(it++));
  y = to_number<int>(*(it++));
  pow = to_number<int>(*(it));
  bom = new Bombe(x, y, pow);
  return (bom);
}

int                   Bombe::checkPath(int direction, int power)
{
  int   x = this->x;
  int   y = this->y;
  int   go = -1;

  switch (direction)
    {
    case 1 :
      while (++go < power && ++y)
	{
	  if (this->lvl->getCase(x, y) == 'w')
	    return (go);
	  if (this->lvl->getCase(x, y) == 'd' )
	    return (go + 1);
	}
      break;
    case 2 :
      while (++go < power && --y)
	{
	  if (this->lvl->getCase(x, y) == 'w')
	    return (go);
	  if (this->lvl->getCase(x, y) == 'd' )
	    return (go + 1);
	}
      break;
    case 3 :
      while (++go < power && --x)
	{
	  if (this->lvl->getCase(x, y) == 'w')
	    return (go);
	  if (this->lvl->getCase(x, y) == 'd' )
	    return (go + 1);
	}
      break;
    case 4 :
      while (++go < power && ++x)
	{
	  if (this->lvl->getCase(x, y) == 'w')
	    return (go);
	  if (this->lvl->getCase(x, y) == 'd' )
	    return (go + 1);
	}
      break;
    default :
      return (0);
    }
  return (go);
}

Bombe::~Bombe()
{
  std::cout << "Bombe Détruite" << std::endl;
}

