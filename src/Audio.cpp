//
// Audio.cpp for  in /home/cao_y//c++/plop/svn_bomberman/gdl
// 
// Made by yuguo cao
// Login   <cao_y@epitech.net>
// 
// Started on  Tue May 29 13:41:13 2012 yuguo cao
// Last update Tue May 29 16:27:22 2012 yuguo cao
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
  if (_bwin.LoadFromFile("assets/sound/win.wav"))
    _win.SetBuffer(_bwin);
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
      _die.Play();
      break;
    case (4):
      sleep(1);
      _win.Play();
      break;
    }
}
