//
// Hud.cpp for  in /home/cao_y//c++/plop/svn_bomberman/gdl
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Wed May 23 11:03:56 2012 yuguo cao
// Last update Wed May 30 11:43:23 2012 yuguo cao
//

#include "Hud.hh"
#include "Settings.hh"

Hud::Hud()
{
  _player1 = NULL;
  _player2 = NULL;
  _stats.push_back(gdl::Image::load("assets/img/life.png"));
  _stats.push_back(gdl::Image::load("assets/img/speed.png"));
  _stats.push_back(gdl::Image::load("assets/img/power.png"));
  _stats.push_back(gdl::Image::load("assets/img/bombe.png"));
  _back = gdl::Image::load("assets/img/player1_hud.png");
  _back2 = gdl::Image::load("assets/img/player2_hud.png");
}

    Hud::~Hud()
    {}

void		Hud::draw()
{
  Settings conf;

  mode2d();
  drawImage(_back, 0, 0);
  if (conf.GetNbPlayers() == 2)
    drawImage(_back2, 1315, 0);
  printPlayer();
  mode3d();
}

void		Hud::printStat(float nb, int player, int line)
{
  int		i = 0;
  int		margin;

  if (line == 1)
    nb = 6 - nb;
  switch (line)
    {
    case 0:
      margin = 225;
      break;
    case 1:
      margin = 510;
      break;
    case 2:
      margin = 315;
      break;
    case 3:
      margin = 405;
      break;
    default:
      margin = line;
    }
  if (player == 0)
    {
      while (i < nb && i < 20)
	{
	  drawImage(_stats[line], 8 + i * 27 - (i / 10) * 27 * 10, 850 - (i / 10) * 27 - margin);
	  i++;
	}
    }
  else if (player == 1)
    {
      while (i < nb)
	{
	  drawImage(_stats[line], 1574 - 8 - i * 27 + (i / 10) * 27 * 10, 850 - (i / 10) * 27 - margin);
	  i++;
	}
    }
}

void		Hud::printPlayer()
{
  if (_player1)
    {
      //_player1->getName();
      printStat(_player1->getLife(), 0, 0);
      printStat(_player1->getSpeed(), 0, 1);
      printStat(_player1->getPower(), 0, 2);
      printStat(_player1->getBombMax(), 0, 3);
    }
  if (_player2)
    {
      //_player1->getName();
      printStat(_player2->getLife(), 1, 0);
      printStat(_player2->getSpeed(), 1, 1);
      printStat(_player2->getPower(), 1, 2);
      printStat(_player2->getBombMax(), 1, 3);
    }
}

  void		Hud::addPlayer(Player *player)
  {
    if (!_player1)
      _player1 = player;
    else
      _player2 = player;
  }

  void		Hud::drawImage(gdl::Image img, int x, int y)
  {
    glAlphaFunc(GL_GREATER, 0);
    glEnable(GL_ALPHA_TEST);
    img.bind();
    glBegin(GL_QUADS);
    glTexCoord2f(0, 1); glVertex2d(x, y);
    glTexCoord2f(1, 1); glVertex2d(img.getWidth() + x, y);
    glTexCoord2f(1, 0); glVertex2d(img.getWidth() + x, img.getHeight() + y);
    glTexCoord2f(0, 0); glVertex2d(x, img.getHeight() + y);
    glEnd();
  }

  void		Hud::mode2d()
  {
    glDisable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0.0, 1600, 0.0, 900);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
  }

  void		Hud::mode3d()
  {
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glEnable(GL_DEPTH_TEST);
  }

  void		Hud::deletePlayer(const int x, const int y)
  {
    if (_player1 && _player1->getX() == x && _player1->getY() == y)
      _player1 = NULL;
    else if (_player2 && _player2->getX() == x && _player2->getY() == y)
      _player2 = NULL;
  }
