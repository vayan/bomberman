#ifndef __MENU__HH
#define __MENU__HH

#include 	<string>
#include 	<iostream>
#include	"Game.hpp"
#include	"Window.hpp"
#include	"Clock.hpp"

#include	"Vector3f.hh"
#include	"Texture.hh"
#include	"AObject.hh"
#include	"Camera.hh"
#include	"Object.hh"
#include	"Level.hh"
#include	"Player.hh"
#include	"Bombe.hh"
#include 	"Settings.hh"
#include 	"Pause.hh"
#include 	"UI.hh"

#define SINGLE_PLAYER_BUTTON		x >= 53  && x <= 283 && y >= 346 && y <= 413
#define TWO_PLAYER_BUTTON 		x >= 500 && x <= 730 && y >= 345 && y <= 410
#define SETTING_BUTTON 			x >= 52  && x <= 280 && y >= 477 && y <= 540
#define EXIT_BUTTON 			x >= 500 && x <= 727 && y >= 477 && y <= 544
#define CANCEL_BUTTON 			x >= 462 && x <= 610 && y >= 531 && y <= 577
#define PLUS_BUTTON 			x >= 350 && x <= 370 && y >= 350 && y <= 373
#define MINUS_BUTTON 			x >= 318 && x <= 338 && y >= 355 && y <= 373
#define EASY_BUTTON 			x >= 328 && x <= 428 && y >= 400 && y <= 425
#define HARD_BUTTON 			x >= 446 && x <= 548 && y >= 400 && y <= 425
#define INFERNO_BUTTON 			x >= 566 && x <= 666 && y >= 400 && y <= 425
#define SAVE_BUTTON 			x >= 624 && x <= 773 && y >= 532 && y <= 575
#define SMALL_BUTTON			x >= 325 && x <= 428 && y >= 444 && y <= 470
#define MEDIUM_BUTTON			x >= 448 && x <= 547 && y >= 444 && y <= 470
#define BIG_BUTTON			x >= 568 && x <= 667 && y >= 444 && y <= 470
#define SET_QWERTY      x >= 326 && x <= 427 && y >= 486 && y <= 513
#define SET_AZERTY      x >= 447 && x <= 545 && y >= 486 && y <= 513

class Pause;

class Menu : public gdl::Game
{
public:
  virtual int			getX() const { return (0); }
  virtual int 			getY() const { return (0); }

  void 				MainMenu();
  void 				MainMenu_input();
  void 				SettingMenu();
  void 				SettingMenu_input();
  void      			initialize(void);
  void     	 		draw(void);
  void				unload(void);
  void				update(void);
  void				PutSelect_difficulty();
  void 				PutSelect_size();
  void     		   	PutSelect_keyboard();
  void 				DrawAIicon();
  void 				save();

  Menu();
  ~Menu();

private:
  Settings 			conf;
  Camera			camera_;
  int				sp;
  int 				nb_icon_ai;
  int 				diff_select;
  int 				menu_select;
  int 				size_select;
  float				time;
  int       type_k;

  gdl::Image  			MainMenu_img;
  gdl::Image  			SettingMenu_img;
  gdl::Image 			AI_img;
  gdl::Image			Select_img;
  gdl::Clock			myClock;
};

#endif
