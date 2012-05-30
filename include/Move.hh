#ifndef __MOVE_
#define __MOVE_

#include "Player.hh"
#include "Level.hh"
#include "Bomberman.hh"

class Player;

class Move {
public:
		Move();
		~Move();
bool	TryMove(int new_x, int new_y, Player*, Level*, std::list<AObject*>);
bool 	TryMoveY(int new_y, Level*, Player* );
bool 	TryMoveX(int new_x, Level*, Player* );
bool 	InMap(int new_x, int new_y, Player*, Level*);
};


#endif
