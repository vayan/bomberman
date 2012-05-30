//
// Textures.hh for  in /home/lyvet_r//tek2/C++/bomberman/test
// 
// Made by randy lyvet
// Login   <lyvet_r@epitech.net>
// 
// Started on  Tue May  8 22:44:37 2012 randy lyvet
// Last update Wed May 30 13:32:05 2012 alexandre haulotte

#ifndef TEXTURES_HH_//
# define TEXTURES_HH_

#include        "Game.hpp"
#include        "Image.hpp"

class		Texture
{
public:
  Texture();
  ~Texture();
  gdl::Image    Floor_;
  gdl::Image    Cube_;
  gdl::Image    Wall_;
  gdl::Image    Explode_;
  gdl::Image    Po_;
  gdl::Image    Nb_;
  gdl::Image    Sp_;
  gdl::Image    Pod_;
  gdl::Image    Nbd_;
  gdl::Image    Spd_;
};

#endif /* !TEXTURES_HH_ */

