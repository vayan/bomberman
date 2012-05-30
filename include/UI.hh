#ifndef __UI___HH
#define __UI___HH

#include 	<string>
#include 	<iostream>
#include	"Game.hpp"
#include	"Window.hpp"
#include	"Clock.hpp"
#include	"Vector3f.hh"
#include	"Texture.hh"
#include	"AObject.hh"
#include	"Camera.hh"

class UI
{
public:
	static void 				glEnable2D();
	static void 				glDisable2D();
	static void					DrawImage(gdl::Image img, int x_off, int y_off);
};

#endif