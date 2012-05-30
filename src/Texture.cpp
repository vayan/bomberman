//
// Texture.cpp for  in /home/lyvet_r//tek2/C++/bomberman/test
// 
// Made by randy lyvet
// Login   <lyvet_r@epitech.net>
// 
// Started on  Tue May  8 22:51:08 2012 randy lyvet
// Last update Wed May 30 14:03:55 2012 alexandre haulotte
//

#include	"Texture.hh"

Texture::Texture()
{
  Floor_ = gdl::Image::load("assets/texture/floor.jpg");
  Cube_ = gdl::Image::load("assets/texture/cube.jpg");
  Wall_ = gdl::Image::load("assets/texture/wall.jpg");
  Explode_ = gdl::Image::load("assets/texture/explode.jpg");
  Po_ = gdl::Image::load("assets/texture/power.png");
  Nb_ = gdl::Image::load("assets/texture/bombup.png");
  Sp_ = gdl::Image::load("assets/texture/speed.jpeg");
  Pod_ = gdl::Image::load("assets/texture/power-.png");
  Nbd_ = gdl::Image::load("assets/texture/bombdown.png");
  Spd_ = gdl::Image::load("assets/texture/speed-.jpeg");
  Line_ = gdl::Image::load("assets/texture/line.png");
}

Texture::~Texture()
{}


