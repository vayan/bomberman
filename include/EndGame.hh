#ifndef __ENDGAME__
#define __ENDGAME__

#include <iostream>
#include <string>
#include "Bomberman.hh"
#include "Move.hh"
#include "Level.hh"
#include "AObject.hh"
#include "IA.hh"
#include "Menu.hh"
#include "UI.hh"
#include "Save.hh"

#include "Input.hpp"
#include "Model.hpp"

#define X_OFFSET 400
#define Y_OFFSET 200

#define END_BUTTON_EXIT x >= 840  && x <= 1072 && y >= 529 && y <= 593
#define END_BUTTON_RESTART x >= 575  && x <= 802 && y >= 529 && y <= 593

class EndGame : public UI, public AObject {
public:
  virtual int		getX() const { return (0); }
  virtual int 		getY() const { return (0); }

  int			state;

  void			initialize(void);
  void			update(gdl::GameClock const &clock, gdl::Input &_input);
  void			draw(void);

  EndGame();
  ~EndGame();

private:
  gdl::Image		img_EndScreen;
  gdl::Image		img_P1Win;
  gdl::Image		img_P2Win;
  gdl::Image		img_ULoose;
  gdl::Image		img_UWin;

};



#endif
