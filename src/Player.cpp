//
// Player.cpp for player in /home/haulot_a//C++/Bomber-Man/svn_bomberman/gdl/src
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Tue May 29 15:09:13 2012 alexandre haulotte
// Last update Thu May 31 12:12:56 2012 alexandre haulotte
//

#include		"Player.hh"
#include		"Utils.hh"
#include		"Move.hh"
#include		"Settings.hh"
#include		<iostream>

void      Player::qwertyorazerty()
{
  Settings Conf;

  switch (Conf.GetTypeKeyboard())
  {
    case 1:
    key_up = gdl::Keys::W;
    key_down = gdl::Keys::S;
    key_left = gdl::Keys::A;
    key_right = gdl::Keys::D;
    key_bombe = gdl::Keys::F;
    break;
    case 2:
    key_up = gdl::Keys::Z;
    key_down = gdl::Keys::S;
    key_left = gdl::Keys::Q;
    key_right = gdl::Keys::D;
    key_bombe = gdl::Keys::F;
    break;
  }
}

void			Player::actLvl(int _x, int _y, char c)
{
  lvl->setCase(_x, _y, c);
}

char			Player::getLvlCase(int _x, int _y) const
{
  return(lvl->getCase(_x, _y));
}

Player::Player()
:AObject()
{}

Player::Player(std::string _name, int _x, int _y, int _id, int _life, float _speed,
  int _power, int _nb_bomb, Level *_lvl, Bomberman* _game, int ty, Bonus *bo)
:AObject()
{
  Settings Conf;
  multiBombe = false;
  pierceBombe = false;
  bon = bo;
  this->_rotation = 0;
  _direction = 0;
  time_bombe = 0;
  time_mvt = 0;
  clock_bombe.play();
  clock_mvt.play();
  x 		= _x;
  y 		= _y;
  score		= 0;
  _speed = _speed;
  x_pix 	= x * 10;
  y_pix 	= y * 10;
  name 		= _name;
  id 		= _id;
  life 		= _life;
  speed 	= 5;
  power 	= _power;
  nb_bomb	= _nb_bomb;
  bomb_max	= nb_bomb;
  lvl		= _lvl;
  move		=  new Move();
  game		= _game;
  _IA		= NULL;
  is_dead	= false;
  this->ty = ty;
  if (_IA == NULL)
  {
    if (ty == 0)
    {
     key_up = gdl::Keys::Up;
     key_down = gdl::Keys::Down;
     key_left = gdl::Keys::Left;
     key_right = gdl::Keys::Right;
     key_bombe = gdl::Keys::Numpad0;
   }
   else if (ty == 1)
    qwertyorazerty();
  else
  {
   _IA = new IA(Conf.GetDifficulty(), this);
   key_up = gdl::Keys::A;
   key_down = gdl::Keys::A;
   key_left = gdl::Keys::A;
   key_right = gdl::Keys::A;
   key_bombe = gdl::Keys::A;
 }
}
_type = 2;
}

Player::~Player()
{
  if (!bombes.empty())
  {
    std::list<AObject*>::iterator itb = bombes.begin();
    while (itb != this->bombes.end())
    {
     (*itb)->_type = 4;
     itb++;
   }
 }
 game->deletePlayer(x, y);
}

void			Player::initialize(void)
{
  gdl::Color c(255, 255, 255);
  gdl::Color c2(0, 255, 255);
  this->model_ = gdl::Model::load("assets/marvin.fbx");
  this->model_.cut_animation(this->model_, "Take 001", 90, 130, "stop");
  this->model_.cut_animation(this->model_, "Take 001", 35, 55, "run");
  if (ty == 0)
    this->model_.set_default_model_color(c);
  if (ty == 1)
    this->model_.set_default_model_color(c2);
}

void	Player::die()
{
  is_dead = true;
}

bool	Player::isDie()
{
  return (is_dead);
}

void			Player::update(gdl::GameClock const &clock, gdl::Input &_input)
{
  input = &_input;
  ScanAllAction(lvl, game->getObj());
  if (bombes.size() > 0)
  {
    std::list<AObject*>::iterator itb = bombes.begin();
    while (!bombes.empty() && itb != this->bombes.end())
    {
     if (static_cast<Bombe*>((*itb))->time(false))
     {
       lvl->setCase((*itb)->getX(), (*itb)->getY(), 'f');
       static_cast<Bombe*>((*itb))->explose(this->game->getObj());
       game->deleteBombe(static_cast<Bombe*>(*itb));
       this->bombes.erase(itb);
       score += static_cast<Bombe*>(*itb)->scoring();
       delete (*itb);
       itb = this->bombes.begin();
     }
     if (!bombes.empty())
     {
       itb++;
     }
   }
 }
  //	printMap(lvl);
 nb_bomb = bomb_max - bombes.size();
 this->model_.update(clock);
}

void			Player::draw(void)
{
  glPushMatrix();
  glTranslatef(1 * this->x_pix / 10.0, 1 * this->y_pix / 10.0, 1);
  glRotatef(90, 1.0f, 0.0f, 0.0f);
  glRotatef(_rotation, 0.0f, 1.0f, 0.0f);
  glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
  glScalef(0.002f, 0.002f, 0.002f);
  this->model_.draw();
  glPopMatrix();
}

std::string &Player::pack()
{
  _pack = name + ';' +
  to_string(id) + ';' +
  to_string(life) + ';' +
  to_string(speed) + ';' +
  to_string(power) + ';' +
  to_string(x) + ';' +
  to_string(y) + ';' +
  to_string(x_pix) + ';' +
  to_string(y_pix) + ';' +
  to_string(_rotation) + ';' +
  to_string(awake) + ';' +
  to_string(action) + ';' +
  to_string(bomb_max) + ';' +
  to_string(time_bombe) + ';' +
  to_string(time_mvt) + ';' +
  to_string(ty) + ';' +
  to_string(getMultiBomb()) + ';' +
  to_string(getPierceBomb()) + ';' +
  to_string(nb_bomb);

  return (_pack);
}

Player			*Player::unpack(std::string& to_tokenize)
{
  std::vector<std::string> 		tokenize = split_to_vec(to_tokenize, ";");
  std::vector<std::string>::iterator	it = tokenize.begin();

  //std::cout << "le token " << to_tokenize << std::endl;

  std::string		_name = *(it++);
  int			_id = to_number<int>(*(it++));
  int			_life = to_number<int>(*(it++));
  float 	_speed = to_number<float>(*(it++));
  int			_power = to_number<int>(*(it++));
  int     _x = to_number<int>(*(it++));
  int     _y = to_number<int>(*(it++));
  int     _x_pix = to_number<int>(*(it++));
  int     _y_pix = to_number<int>(*(it++));
  int     _rotation = to_number<int>(*(it++));
  int     _awake = to_number<int>(*(it++));
  int     _action = to_number<int>(*(it++));
  int     _bomb_max = to_number<int>(*(it++));
  float   _time_bombe = to_number<float>(*(it++));
  float   _time_mvt = to_number<float>(*(it++));
  int     _ty = to_number<int>(*(it++));
  int     _multibomb = to_number<int>(*(it++));
  int     _piercebomb = to_number<int>(*(it++));
  int     _nb_bomb = to_number<int>(*(it++));

  Player 		*unpack_player = new Player(name, 1, 1, id, life, speed, power, nb_bomb, lvl, game, _ty, bon);

  unpack_player->setID(_id);
  unpack_player->setName(_name);
  unpack_player->setLife(_life);
  unpack_player->setSpeed(_speed);
  unpack_player->setPower(_power);
  unpack_player->setX(_x);
  unpack_player->setY(_y);
  unpack_player->setX_pix(_x_pix);
  unpack_player->setY_pix(_y_pix);
  unpack_player->setRotation(_rotation);
  unpack_player->setAwake(_awake);
  unpack_player->setAction(_action);
  unpack_player->setBombMax(_bomb_max);
  unpack_player->setTimeBomb(_time_bombe);
  unpack_player->setTime_mvt(_time_mvt);
  unpack_player->setBomb(_nb_bomb);
  unpack_player->setTy(_ty);
  unpack_player->setMultiBomb(_multibomb);
  unpack_player->setPierceBomb(_piercebomb);

  return (unpack_player);
}


int 			Player::ActionLeft(Level *lvl, std::list<AObject*> all_object)
{
  if ((input->isKeyDown(key_left) || _IA != NULL))
  {
    _direction = 2;
    this->_rotation = 0;
    this->awake = 0;
    this->action = 1;
    this->model_.play("run");
    this->model_.set_anim_speed("run", 6 - speed);
    if (move->TryMove(this->x, this->y - 1, this, lvl, all_object) || this->y_pix > this->y * 10)
    {
     if ((this->y_pix - 1 <= this->y * 10 - 7))
     {
       this->y -= 1;
     }
     this->y_pix -= 1;
   }
   return (0);
 }
 this->awake += 1;
 return (1);
}

int 			Player::ActionRight(Level *lvl, std::list<AObject*> all_object)
{
  if ((input->isKeyDown(key_right) || _IA != NULL))
  {
    _direction = 3;
    this->_rotation = 180;
    this->awake = 0;
    this->action = 1;
    this->model_.play("run");
    this->model_.set_anim_speed("run", 6 - speed);
    if (move->TryMove(this->x, this->y + 1, this, lvl, all_object) || this->y_pix < this->y * 10)
    {
     if ((this->y_pix + 1 >= this->y * 10 + 3))
     {
       this->y += 1;
     }
     this->y_pix += 1;
   }
   return (0);
 }
 this->awake += 1;
 return (1);
}

int 			Player::ActionDown(Level *lvl, std::list<AObject*> all_object)
{
  if ((input->isKeyDown(key_down) || _IA != NULL))
  {
    _direction = 1;
    this->_rotation = 90;
    this->awake = 0;
    this->action = 1;
    this->model_.play("run");
    this->model_.set_anim_speed("run", 6 - speed);
    if (move->TryMove(this->x + 1, this->y, this, lvl, all_object) || this->x_pix < this->x * 10)
    {
     if ((this->x_pix + 1 >= this->x * 10 + 3))
     {
       this->x += 1;
     }
     this->x_pix += 1;
   }
   return (0);
 }
 this->awake += 1;
 return (1);
}

int 			Player::ActionUp(Level *lvl, std::list<AObject*> all_object)
{
  if ((input->isKeyDown(key_up) || _IA != NULL))
  {
    _direction = 0;
    this->_rotation = 270;
    this->model_.play("run");
    this->awake = 0;
    this->action = 1;
    this->model_.set_anim_speed("run", 6 - speed);
    if (move->TryMove(this->x - 1, this->y, this, lvl, all_object) || this->x_pix > this->x * 10)
    {
     if ((this->x_pix - 1 <= this->x * 10 - 7))
     {
       this->x -= 1;
     }
     this->x_pix -= 1;
   }
   return (0);
 }
 this->awake += 1;
 return (1);
}

void			Player::mBombe()
{
  int	xb = x;
  int	yb = y;
  int	dir;
  int	sx = x;
  int	sy = y;

  if (_direction > 1)
  {
    if (_direction == 2)
     dir = -1;
   else
     dir = 1;
   yb += dir;
   while (nb_bomb > 0 && lvl->getCase(xb, yb) == 'f')
   {
     x = xb;
     y = yb;
     Bombe *b = game->addBombe(&this[0]);
     lvl->setCase(xb, yb, 'b');
     nb_bomb--;
     bombes.push_back(b);
     yb += dir;
   }
 }
 else
 {
  if (_direction == 0)
   dir = -1;
 else
   dir = 1;
 xb += dir;
 while (nb_bomb > 0 && lvl->getCase(xb, yb) == 'f')
 {
   x = xb;
   y = yb;
   Bombe *b = game->addBombe(&this[0]);
   lvl->setCase(xb, yb, 'b');
   nb_bomb--;
   bombes.push_back(b);
   xb += dir;
 }
}
x = sx;
y = sy;
}

void			Player::ActionDropBomb(Level *lvl)
{
  clock_bombe.update();
  time_bombe += clock_bombe.getElapsedTime();
  if (time_bombe > 0.2 && (input->isKeyDown(key_bombe) || _IA != NULL) && nb_bomb > 0)
  {
    time_bombe = 0.0;
    if (lvl->getCase(x, y) == 'b' && multiBombe == true)
      mBombe();
    else
    {
     Bombe *b = game->addBombe(&this[0]);
     lvl->setCase(x, y, 'b');
     nb_bomb--;
     bombes.push_back(b);
   }
 }
}

std::list<AObject*>::iterator	Player::scanBonus(std::list<AObject*>& all)
{
  std::list<AObject*>::iterator it;

  if (bon->getBonus(x, y) != '.')
  {
    for (it = all.begin(); it != all.end(); it++)
    {
     if ((*it)->getX() == x && (*it)->getY() == y && (*it)->_type == 5)
     {
       return (it);
     }
   }
 }
 return (all.end());
}

void			Player::ScanAllAction(Level *_lvl, std::list<AObject*>& all_object)
{
  std::list<AObject*>::iterator it;
  int	o_x = x;
  int	o_y = y;

  (void) _lvl;
  //lvl->printMap(lvl);
  clock_mvt.update();
  time_mvt += clock_mvt.getElapsedTime();
  if (!_IA)
  {
    if (time_mvt * 100 > speed)
    {
     time_mvt = 0;
     ActionLeft(lvl, all_object);
     ActionRight(lvl, all_object);
     ActionUp(lvl, all_object);
     ActionDown(lvl, all_object);
   }
   if (this->awake > 30 &&
     this->action == 1)
   {
     this->model_.play("stop");
     this->awake = 0;
     this->action = 0;
     this->model_.set_anim_speed("stop", 7);
   }
   ActionDropBomb(lvl);
 }
 else
 {
  if (time_mvt * 100 > speed)
  {
   time_mvt = 0;
   _IA->IA_moves(lvl, all_object);
 }
}
if (o_x != x || o_y != y)
{
  if (_IA)
   lvl->movePlayer(o_x, o_y, this, 'i');
 else if (key_up == gdl::Keys::Up)
   lvl->movePlayer(o_x, o_y, this, 'r');
 else
   lvl->movePlayer(o_x, o_y, this, 'g');
}
it = scanBonus(all_object);
if (it != all_object.end())
{
  score += 5;
  switch (static_cast<BonusBox*>((*it))->getType())
  {
   case 0:
   power++;
   break;
   case 1:
   nb_bomb++;
   bomb_max++;
   break;
   case 2:
   if (speed > 1)
     speed--;
   break;
   case 4:
   if (power > 1)
     power--;
   break;
   case 5:
   if (bomb_max > 1)
     bomb_max--;
   break;
   case 3:
   speed++;
   break;
   case 6:
   multiBombe = true;
   break;
   case 7:
   pierceBombe = true;
   break;
   default:
   break;
 }
 delete ((*it));
 all_object.erase(it);
}
}

void 	Player::setID(int &_id) { id = _id; }
void	Player::setLife(int &_life) { life = _life; }
void	Player::setSpeed(float &_speed) { speed = _speed; }
void	Player::setName(std::string &_name) { name = _name; }

void 	Player::setBomb(int &_bomb) { nb_bomb += _bomb; }

void 	Player::setPower(int &_power) { power = _power; }
void 	Player::setBombMax(int &_bomb) { bomb_max = _bomb; }
int 	Player::getBombMax() const { return (bomb_max); }
int 	Player::getX() const { return (x); }
int 	Player::getY() const { return (y); }
int 	Player::getId() const { return (id); }
int 	Player::getPower() const { return (power); }
int		Player::getLife() const { return (life); }
int   Player::getTy() { return (ty); }
float 	Player::getSpeed() const { return (speed); }
std::string	Player::getName() const { return (name); } 
int		Player::getBomb() const { return (nb_bomb); }

int		Player::getMultiBomb() const
{
  if (multiBombe)
    return (1);
  return (0);
}

int		Player::getPierceBomb() const
{
  if (pierceBombe)
    return (1);
  return (0);
}

void    Player::setMultiBomb(int mult) 
{ 
  if (mult == 1) 
    multiBombe = true;
  if (mult == 0)
    multiBombe = false;
}

void    Player::setPierceBomb(int pirc) 
{  
  if (pirc == 1) 
    pierceBombe = true;
  if (pirc == 0)
    pierceBombe = false; 
}

IA    *Player::getIA(){ return (_IA); }
void Player::setX(int _x) { x = _x; }
void Player::setY(int _y) { y = _y; }
void Player::setX_pix(int _x) { x_pix = _x;}
void Player::setY_pix(int _y) { y_pix = _y;}
void Player::setRotation(int rotat) {_rotation = rotat;}
void Player::setAwake(int awk) {awake = awk;}
void Player::setAction(int act) {action = act;}
void Player::setTimeBomb(int timebomb) {time_bombe = timebomb;}
void Player::setTime_mvt(int tmvt) {time_mvt = tmvt;}
void Player::setTy(int ti) { ty = ti;}
double Player::getScore() const {return (score);}

