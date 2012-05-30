#ifndef __PAUSE_HH
#define __PAUSE_HH

#include <iostream>
#include <string>
#include "Bomberman.hh"
#include "Move.hh"
#include "Input.hpp"
#include "Level.hh"
#include "AObject.hh"
#include "IA.hh"
#include "Model.hpp"
#include "Menu.hh"
#include "UI.hh"
#include "Save.hh"

#define X_OFFSET 400
#define Y_OFFSET 200

#define PAUSE_BUTTON_SAVE  	x >= 419  && x <= 567 && y >= 600 && y <= 641
#define PAUSE_BUTTON_RESUME x >= 864  && x <= 1015 && y >= 600 && y <= 641
#define PAUSE_BUTTON_EXIT	x >= 1036  && x <= 1183 && y >= 544 && y <= 586

class Bomberman;
class Menu;
class Save;

class Pause : public UI, public AObject
{
public:
	Pause();
	~Pause();
	void      initialize(void);
	void      update(gdl::GameClock const &clock, gdl::Input &_input);
	void      draw(void);
	void 	restore_setting();
	virtual int			getX() const { return (0); }
	virtual int 		getY() const { return (0); }
	bool		is_active;
private:
	gdl::Image  Pause_img;
public:
	Save 	*svg;
	std::map<int, std::map<int, char> > __lvl;
	std::list<AObject*> __objects;

};

#endif