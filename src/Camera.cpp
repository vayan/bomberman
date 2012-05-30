//
// Camera.cpp for  in /home/lyvet_r//tek2/C++/bomberman/sources
// 
// Made by randy lyvet
// Login   <lyvet_r@epitech.net>
// 
// Started on  Thu May  3 16:11:33 2012 randy lyvet
// Last update Tue May 22 11:29:19 2012 yuguo cao
//

#include        <cstdlib>

#include	"Camera.hh"

void Camera::initialize(void)
{}

void Camera::update(gdl::GameClock const & gameClock, gdl::Input & input)
{
  if (input.isKeyDown(gdl::Keys::Escape) == true)
    exit(EXIT_SUCCESS);
}

void		Camera::setPosition(float height, float width)
{
  position_.x = 1 + (width / 2);
  position_.y = height / 2;
  position_.z = width;
  target_.x = width / 2;
  target_.y = height / 2;
  target_.z = 0;
  gluLookAt(position_.x, position_.y, position_.z, target_.x, target_.y, target_.z, 0, 0, 1);
}

Camera::Camera(void)
  : position_(5.0f, 5.0f, 10.0f), target_(5.0f, 5.0f, 0.0f)
{}
