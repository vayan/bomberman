
#ifndef _PLAYER_HH
#define _PLAYER_HH

#include 		<iostream>
#include 		<string>

#include       		"Clock.hpp"
#include 		"Bomberman.hh"
#include 		"Move.hh"
#include 		"Input.hpp"
#include 		"Level.hh"
#include 		"AObject.hh"
#include 		"IA.hh"
#include 		"Model.hpp"
#include        	"Vector3f.hh"
#include		"Bonus.hh"
class			Move;
class			Bomberman;
class			IA;

class			Player : public AObject {
public:
  int 			getId() const;
  int			getLife() const;
  float			getSpeed() const;
  std::string		getName() const;
  int			getBomb() const;
  int 			getPower() const;
  int 			getBombMax() const;
  virtual int		getX() const;
  virtual int		getY() const;
  IA        *getIA();
  int       getTy();
  char			getLvlCase(int _x, int _y) const;
  void			actLvl(int _x, int _y, char c);
  void 			setBombMax(int&);
  void 			setPower(int&);
  void 			setID(int&);
  void			setLife(int&);
  void			setSpeed(float&);
  void			setName(std::string&);
  void 			setBomb(int&);
  void setX(int _x);
  void setY(int _y);
  void setX_pix(int _x);
  void setY_pix(int _y);
  void setRotation(int rotat);
  void setAwake(int awk);
  void setAction(int act);
  void setTimeBomb(int timebomb) ;
  void setTy(int t);
  void setTime_mvt(int tmvt);
  void setNbBomb(int nbb) { nb_bomb = nbb;}
  int 			ActionLeft(Level *lvl, std::list<AObject*>);
  int 			ActionRight(Level *lvl, std::list<AObject*>);
  int 			ActionUp(Level *lvl, std::list<AObject*>);
  int 			ActionDown(Level *lvl, std::list<AObject*>);
  void			ActionDropBomb(Level *lvl);
  void			ScanAllAction(Level *lvl, std::list<AObject*>& all_object);
  void			initialize(void);
  void  		update(gdl::GameClock const &clock, gdl::Input &_input);
  void	 		draw(void);
  std::list<AObject*>::iterator   scanBonus(std::list<AObject*>& all);
  void			die();
  bool			isDie();
  ////////POUR LES SAUVEGARDES////////////////
  std::string		&pack();
  Player		    *unpack(std::string&);
  ////////////////////////////////////////////

  Player();
  Player(std::string, int, int, int, int, float, int ,int, Level*, Bomberman*, int, Bonus*);
  virtual ~Player();

private:
  bool			is_dead;
  gdl::Input		 *input;
  gdl::Model		 model_;
  gdl::Keys::Key 	key_up;
  gdl::Keys::Key 	key_down;
  gdl::Keys::Key	key_left;
  gdl::Keys::Key	key_right;
  gdl::Keys::Key	key_bombe;

  std::string 		_pack;
  std::string		name;

  int			_rotation;

  std::list<AObject*>	bombes;
  int			  awake;
  int			  action;
  int			  x_pix;
  int			  y_pix;
  int 			id;
  int			  life;
  float			speed;
  int			  power;
  int 			nb_bomb;
  int 			bomb_max;
  float			time_bombe;
  gdl::Clock		clock_bombe;
  float			time_mvt;
  gdl::Clock		clock_mvt;
  Move    		*move;
  Level     		*lvl;
  Bomberman		*game;
  IA			*_IA;
  Bonus			*bon;
  int ty;
};

#endif
