//
// Audio.hh for  in /home/cao_y//c++/plop/svn_bomberman/gdl
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Tue May 29 13:41:28 2012 yuguo cao
// Last update Thu May 31 15:09:58 2012 yuguo cao
//

#ifndef		__AUDIO__
# define	__AUDIO__

#include <iostream>
#include <SFML/Audio.hpp>

enum AUDIO
  {
    BACKGROUND,
    PUTBOMB,
    EXPLOSION,
    DIE,
    WIN,
    LOSE,
    CLICK
  };

class Audio
{
private:
  sf::SoundBuffer	_bbackground;
  sf::SoundBuffer	_bputBomb;
  sf::SoundBuffer	_bexplosion;
  sf::SoundBuffer	_bdie;
  sf::SoundBuffer	_bdie2;
  sf::SoundBuffer	_bwin;
  sf::SoundBuffer	_blose;
  sf::SoundBuffer	_bhit;
  sf::SoundBuffer	_bclick;
  sf::Sound		_background;
  sf::Sound		_putBomb;
  sf::Sound		_explosion;
  sf::Sound		_die;
  sf::Sound		_die2;
  sf::Sound		_win;
  sf::Sound		_lose;
  sf::Sound		_hit;
  sf::Sound		_click;

public:
  Audio();
  ~Audio();

  void			stopAll();
  void			play(const int);
};

#endif
