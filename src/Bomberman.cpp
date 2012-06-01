//
// Bomberman.cpp for  in /home/lyvet_r//tek2/C++/bomberman/sources
// 
// Made by randy lyvet
// Login   <lyvet_r@epitech.net>
// 
// Started on  Thu May  3 17:27:27 2012 randy lyvet
// Last update Fri Jun  1 11:19:15 2012 yuguo cao
//

#include	<iostream>
#include	"Window.hpp"
#include	"Input.hpp"
#include	"Bomberman.hh"
#include  	"Save.hh"
#include	"Explosion.hh"
#include	"Score.hh"

void    Bomberman::init_new(void)
{
  for (int y = 0 ; y < this->level->getHeight() ; y++)
    for (int x = 0; x < this->level->getWidth() ; x++)
    {
     switch (this->level->getMap()[x][y])
     {
       case 'w':
       {
         Cube *cube_w = new Cube(x, y, 1, texture_, 2);
         this->objects_.push_back(cube_w);
       }
       break;
       case 'd':
       {
         Cube *cube_f = new Cube(x, y, 1, texture_, 1);
         this->objects_.push_back(cube_f);
       }
       break;
       case 'r':
       {
         Player *pl = new Player("Lola", x, y, 1, 3, 2, 2, 1, this->level, this, 0, bonus);
         _hud->addPlayer(pl);
         this->objects_.push_back(pl);
       }
       break;
       case 'g':
       {
         Player *pl = new Player("Buba", x, y, 1, 3, 2, 2, 1, this->level, this, 1, bonus);
         _hud->addPlayer(pl);
         this->objects_.push_back(pl);
       }
       break;
       case 'i' :
       {
         Player *pl = new Player("IA", x, y, 1, 3, 2, 2, 1, this->level, this, 2, bonus);
         this->objects_.push_back(pl);
       }
       break;
       default :
       break;
     }
   }
 }

 void    Bomberman::init_from_svg(void)
 {
  Save sv;
  std::string buff = "";
  std::ifstream infile;

  for (int y = 0 ; y < this->level->getHeight() ; y++)
    for (int x = 0; x < this->level->getWidth() ; x++)
    {
     switch (this->level->getMap()[x][y])
     {
       case 'w':
       {
         Cube *cube_w = new Cube(x, y, 1, texture_, 2);
         this->objects_.push_back(cube_w);
       }
       break;
       case 'd':
       {
         Cube *cube_f = new Cube(x, y, 1, texture_, 1);
         this->objects_.push_back(cube_f);
       }
       break;
      case 'b':
       {
         Player *truc = new Player("Lola", x, y, 1, 3, 2, 2, 1, this->level, this, 0, bonus);
         Bombe *b = new Bombe(truc, bonus, level, truc->getPierceBomb());
         b->_type = 4;
         this->objects_.push_back(b);
       }
       break;
       default :
       break;
     }
   }

   infile.open((sv.GetFilename()).c_str());

   if (infile.good())
    getline(infile,buff);
  if (infile.good())
    getline(infile,buff);
  if (infile.good())
    getline(infile,buff);

  while (infile.good())
  {
    getline(infile,buff);
    if (infile.good() && buff != "")
    {
      Player *pl = new Player("null", 0, 0, 0, 0, 0, 0, 0, this->level, this, 0, bonus);
      pl = pl->unpack(buff);
      if (pl->getTy() <= 1)
       _hud->addPlayer(pl);
     this->objects_.push_back(pl);
   }
 }
}

void		Bomberman::initialize(void)
{
  texture_ = new Texture();
  Settings set;

  _audio->play(0);
  bonus = new Bonus(level->getHeight(), level, texture_);
  Surface		*Floor = new Surface(level->getHeight() / 2.0f, level->getHeight() / 2.0f, 1, level->getHeight() ,texture_);
  this->objects_.push_back(Floor);
  if (set.GetSVG() == 0)
    init_new();
  if (set.GetSVG() == 1)
    init_from_svg();

  std::list<AObject*>::iterator itb = this->objects_.begin();
  while (itb != this->objects_.end())
  {
    (*itb)->initialize();
    itb++;
  }
  time = 0;
  myClock.play();
}

void  Bomberman::refresh_setting()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(90, (double)1600/900, 1, 1000);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
  glEnable(GL_BLEND);
  glEnable(GL_POLYGON_SMOOTH);
  glHint(GL_POLYGON_SMOOTH, GL_NICEST);
  camera_.initialize();
  camera_.setPosition(this->level->getHeight(), this->level->getWidth());
}

void  Bomberman::update_all_obj(std::list<AObject*>::iterator itb)
{
  while (itb != this->objects_.end())
  {
    switch ((*itb)->_type)
    {
     case 2:
     {
       if (static_cast<Player*>((*itb))->isDie())
       {
        _audio->play(3);
        if (static_cast<Player*>((*itb))->getTy() < 2)
        {
          Score scr;
          scr.checkScore(static_cast<Player*>((*itb))->getScore());
          std::cout << "View Hight Score: " << "file:///HightScore.scr.html" << std::endl;
        }
        delete (*itb);
        this->objects_.erase(itb);
        itb = this->objects_.begin();
      }
      (*itb)->update(gameClock_, input_);
    }
    break;
    case 4:
    if (static_cast<Bombe*>((*itb))->time(false))
    {
     level->setCase((*itb)->getX(), (*itb)->getY(), 'f');
     static_cast<Bombe*>((*itb))->explose(this->objects_);
     delete (*itb);
     this->objects_.erase(itb);
     itb = this->objects_.begin();
   }
   break;
   case 6:
   (*itb)->update(gameClock_, input_);
   if (static_cast<Explosion*>((*itb))->getTime())
   {
     delete (*itb);
     this->objects_.erase(itb);
     itb = this->objects_.begin();
   }
   break;
   default:
   (*itb)->update(gameClock_, input_);
   break;
 }
 itb++;
}
}

void  Bomberman::InputPause()
{
  if (input_.isKeyDown(gdl::Keys::P) == true)
  {
    _pause->is_active = false;
    refresh_setting();
    usleep(500000);
  }
  else if (input_.isMouseButtonDown(gdl::Mouse::Left) == true)
  {
    int x = input_.getMousePositionX();
    int y = input_.getMousePositionY();

      //std::cout << " X " << x << " Y " << y << std::endl;
    if (PAUSE_BUTTON_SAVE)
     _pause->svg->SaveFile(level, objects_);
   if (PAUSE_BUTTON_RESUME)
   {
     _pause->is_active = false;
     refresh_setting();
   }
   if (PAUSE_BUTTON_EXIT)
    exit (EXIT_SUCCESS);
}
}

void  Bomberman::InputEnd()
{
  //usleep(500000);
  if (input_.isMouseButtonDown(gdl::Mouse::Left) == true)
  {
    int x = input_.getMousePositionX();
    int y = input_.getMousePositionY();

    //std::cout << " X " << x << " Y " << y << std::endl;
    if (END_BUTTON_EXIT)
      exit (EXIT_SUCCESS);
    if (END_BUTTON_RESTART)
    {
      // refresh_setting();
      // window_.close();
    }
  }
}

int    Bomberman::check_death()
{
  std::list<AObject*>::iterator itb;
  int nb_p1 = 0;
  int nb_p2 = 0;
  int nb_ia = 0;
  Settings conf;

  for (itb = this->objects_.begin(); itb != this->objects_.end(); itb++)
    {
      if (((*itb)->_type == 2))
	{
	  if (static_cast<Player*>(*itb)->getTy() == 0)
	    nb_p1 = 1;
	  if (static_cast<Player*>(*itb)->getTy() == 1)
	    nb_p2 = 1;
	  if (static_cast<Player*>(*itb)->getTy() > 1)
	    nb_ia++;
	  if ((nb_p1 == 1 || nb_p2 == 1) && (nb_ia >= 1))
	    return (0);
	}
    }
  if (nb_p1 == 1 && nb_ia == 0 && nb_p2 == 0)
    {
      _EndGame->state = 3;
      _audio->play(4);
    }
  else if (nb_p1 == 0 && nb_ia == 0 && nb_p2 == 1)
    {
      _EndGame->state = 4;
      _audio->play(4);
    }
  else if (nb_p1 == 0 && nb_p2 == 0)
    {
      _EndGame->state = 1;
      _audio->play(5);
    }
  else
    return (0);
  return (1);
}



void		Bomberman::update()
{
  myClock.update();
  time += myClock.getElapsedTime();

  if (time >= 1.0 / 100.0)
  {
    time = 0;
    sp = sp + 1;
    camera_.update(gameClock_, input_);
    std::list<AObject*>::iterator itb = this->objects_.begin();
    if (!_EndGame->state)
      check_death();
    if (_pause->is_active == true)
      InputPause();
    else if (_EndGame->state)
      InputEnd();
    else 
    {
      if (input_.isKeyDown(gdl::Keys::P) == true)
      {
        _pause->is_active = true;
        usleep(500000);
      }
      update_all_obj(itb);
    }
  }
  if (sp == 20)
    sp = 0;
}

Bombe*		Bomberman::addBombe(Player* pl)
{
  _audio->play(1);
  Bombe *b = new Bombe(pl, bonus, level, pl->getPierceBomb());
  this->objects_.push_back(b);
  return (b);
}

void		Bomberman::draw(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.74f, 0.84f, 95.0f, 1.0f);
  glClearDepth(1.0f);
  std::list<AObject*>::iterator itb = this->objects_.begin();
  if (_pause->is_active == true)
    _pause->draw();
  else if (_EndGame->state)
   _EndGame->draw();
 else
 {
  while (itb != this->objects_.end())
  {
    (*itb)->draw();
    itb++;
  }
}
this->_hud->draw();
this->window_.display();
}

void		Bomberman::unload(void)
{
}

Bomberman::Bomberman(Level *my_level)
{
  this->level = my_level;

  window_.setWidth(1600);
  window_.setHeight(900);
  window_.setTitle("Bomberman");
  window_.create();
  sp = 0;

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(90, (double)1600/900, 1, 1000);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_MULTISAMPLE);
  glDepthFunc(GL_LEQUAL);
  camera_.initialize();
  camera_.setPosition(this->level->getHeight(), this->level->getWidth());
  _pause = new Pause();
  _hud = new Hud();
  _EndGame = new EndGame();
  _audio = new Audio();
}

std::list<AObject*>&	Bomberman::getObj()
{
  return (objects_);
}

void			Bomberman::deletePlayer(const int x, const int y)
{
  _hud->deletePlayer(x, y);
}

void                    Bomberman::deleteBombe(Bombe* b)
{
  std::list<AObject*>::iterator itb;
  _audio->play(2);
  for (itb = objects_.begin(); itb != objects_.end(); itb++)
  {
    if ((*itb)->getX() == b->getX() && (*itb)->getY() == b->getY() && ((*itb)->_type == 3 || (*itb)->_type == 4))
    {
     objects_.erase(itb);
     break;
   }
 }
}

Bomberman::~Bomberman()
{}
