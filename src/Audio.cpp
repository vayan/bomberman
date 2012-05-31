//
// Audio.cpp for  in /home/cao_y//c++/plop/svn_bomberman/gdl
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Tue May 29 13:41:13 2012 yuguo cao
// Last update Thu May 31 15:10:53 2012 yuguo cao
//


#include	"Audio.hh"

Audio::Audio()
{
  if (_bbackground.LoadFromFile("assets/sound/background.wav"))
    _background.SetBuffer(_bbackground);
  if (_bputBomb.LoadFromFile("assets/sound/putBomb.wav"))
    _putBomb.SetBuffer(_bputBomb);
  if (_bexplosion.LoadFromFile("assets/sound/explosion.wav"))
    _explosion.SetBuffer(_bexplosion);
  if (_bdie.LoadFromFile("assets/sound/die.wav"))
    _die.SetBuffer(_bdie);
  if (_bdie2.LoadFromFile("assets/sound/die2.wav"))
    _die2.SetBuffer(_bdie2);
  if (_bwin.LoadFromFile("assets/sound/win.wav"))
    _win.SetBuffer(_bwin);
  if (_blose.LoadFromFile("assets/sound/lose.wav"))
    _lose.SetBuffer(_blose);
  if (_bhit.LoadFromFile("assets/sound/hit.wav"))
    _hit.SetBuffer(_bhit);
  // if (!_click.LoadFromFile("loop.wav"))
  //   return EXIT_FAILURE;
}

Audio::~Audio()
{
  stopAll();
}

void		Audio::stopAll()
{
  _background.Stop();
  _putBomb.Stop();
  _explosion.Stop();
  _die.Stop();
  _win.Stop();
  _hit.Stop();
}

void		Audio::play(const int type)
{
  switch (type)
    {
    case (0):
      _background.SetLoop(true);
      _background.Play();
      break;
    case (1):
      _putBomb.Play();
      break;
    case (2):
      _explosion.Play();
      break;
    case (3):
      if (rand() % 2)
	_die.Play();
      else
	_die2.Play();
      break;
    case (4):
      sleep(1);
      _win.Play();
      break;
    case (5):
      sleep(1);
      _lose.Play();
      break;
    case (6):
      _hit.Play();
      break;
    }
}
