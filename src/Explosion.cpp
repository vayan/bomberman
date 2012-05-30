#include	"Explosion.hh"

void Explosion::initialize(void)
{
}

void Explosion::update(gdl::GameClock const &, gdl::Input &)
{
  timer.update();
  time += timer.getElapsedTime();
  ti = time;
  if (time > 0.5)
    ti = time - 0.6;
}

void Explosion::draw(void)
{
  animExplose();
}

bool		Explosion::getTime() const
{
  if (time > 0.6)
    return (true);
  else
    return (false);
}

int             Explosion::getX() const
{
  return(this->x);
}

int             Explosion::getY() const
{
  return(this->y);
}

void          Explosion::drawSurface(float _x, float _y, float z, float size, int mod,  float x_size, float y_size)
{
  float         offset;

  offset = 0.5 / 2;
  switch (mod)
    {
    case 1:
      glTexCoord2d(1,1); glVertex3d(_x + offset + x_size, _y + offset + y_size, z);
      glTexCoord2d(1,0); glVertex3d(_x + offset + x_size, _y - offset - y_size, z);
      glTexCoord2d(0,0); glVertex3d(_x - offset - x_size, _y - offset - y_size, z);
      glTexCoord2d(0,1); glVertex3d(_x - offset - x_size, _y + offset + y_size, z);
      break;
    case 2:
      glTexCoord2d(1,1); glVertex3d(_x, _y + offset + y_size, z + offset);
      glTexCoord2d(0,1); glVertex3d(_x, _y - offset - y_size, z + offset);
      glTexCoord2d(0,0); glVertex3d(_x, _y - offset - y_size, z - offset);
      glTexCoord2d(1,0); glVertex3d(_x, _y + offset + y_size, z - offset);
      break;
    case 3 :
      glTexCoord2d(1,1); glVertex3d(_x + offset + x_size, _y, z + offset);
      glTexCoord2d(1,0); glVertex3d(_x + offset + x_size, _y, z - offset);
      glTexCoord2d(0,0); glVertex3d(_x - offset - x_size, _y, z - offset);
      glTexCoord2d(0,1); glVertex3d(_x - offset - x_size, _y, z + offset);
      break;
    }
}

void          Explosion::animExplose()
{
  drawAnimY(this->y + Down);
  drawAnimY(this->y - Up);
  drawAnimX(this->x + Right);
  drawAnimX(this->x - Left);
}

void           Explosion::drawAnimY(int _y)
{
  float         offset = 0.5 / 2.0;
  int		ry = y - _y;
  float		div = 0.9;

  this->texture_.bind();
  glBegin(GL_QUADS);
  if (ry < 0)
    {
      drawSurface(x, y - (Down * ti / 0.5) / 2, 1 - offset, 1, 1, 0, (Down * ti / div));
      drawSurface(x, y - (Down * ti / 0.5) / 2, 1 + offset, 1, 1, 0, (Down * ti / div));
      drawSurface(x + offset, y - (Down * ti / 0.5) / 2, 1, 1, 2, 0, (Down * ti / div));
      drawSurface(x - offset, y - (Down * ti / 0.5) / 2, 1, 1, 2, 0, (Down * ti / div));
      drawSurface(x, (y + offset) - (Down * ti / 0.5) / 2, 1, 1, 3, 0, (Down * ti / div));
      drawSurface(x, (y - offset) - (Down * ti / 0.5) / 2, 1, 1, 3, 0, (Down * ti / div));
    }
  else if (ry > 0)
    {
      drawSurface(x, y + (Up * ti / 0.5) / 2, 1 - offset, 1, 1, 0, (Up * ti / div));
      drawSurface(x, y + (Up * ti / 0.5) / 2, 1 + offset, 1, 1, 0, (Up * ti / div));
      drawSurface(x + offset, y + (Up * ti / 0.5) / 2, 1, 1, 2, 0, (Up * ti / div));
      drawSurface(x - offset, y + (Up * ti / 0.5) / 2, 1, 1, 2, 0, (Up * ti / div));
      drawSurface(x, (y + offset) + (Up * ti / 0.5) / 2, 1, 1, 3, 0, (Up * ti / div));
      drawSurface(x, (y - offset) + (Up * ti / 0.5) / 2, 1, 1, 3, 0, (Up * ti / div));
    }
  glEnd();
}

void          Explosion::drawAnimX(int _x)
{
  float         offset = 0.5 / 2.0;
  int		rx = x - _x;
  float		div = 0.9;

  this->texture_.bind();
  glBegin(GL_QUADS);
  if (rx < 0)
    {
      drawSurface(x + (Right * ti / 0.5) / 2, y, 1 - offset, 1, 1, (Right * ti / div), 0);
      drawSurface(x + (Right * ti / 0.5) / 2, y, 1 + offset, 1, 1, (Right * ti / div), 0);
      drawSurface(x + offset + (Right * ti / 0.5) / 2, y, 1, 1, 2, (Right * ti / div), 0);
      drawSurface(x - offset + (Right * ti / 0.5) / 2, y, 1, 1, 2, (Right * ti / div), 0);
      drawSurface(x + (Right * ti / 0.5) / 2, (y + offset), 1, 1, 3, (Right * ti / div), 0);
      drawSurface(x + (Right * ti / 0.5) / 2, (y - offset), 1, 1, 3, (Right * ti / div), 0);
    }
  else if (rx > 0)
    {
      drawSurface(x - (Left * ti / 0.5) / 2, y, 1 - offset, 1, 1, (Left * ti / div), 0);
      drawSurface(x - (Left * ti / 0.5) / 2, y, 1 + offset, 1, 1, (Left * ti / div), 0);
      drawSurface(x + offset - (Left * ti / 0.5) / 2, y, 1, 1, 2, (Left * ti / div), 0);
      drawSurface(x - offset - (Left * ti / 0.5) / 2, y, 1, 1, 2, (Left * ti / div), 0);
      drawSurface(x - (Left * ti / 0.5) / 2, (y + offset), 1, 1, 3, (Left * ti / div), 0);
      drawSurface(x - (Left * ti / 0.5) / 2, (y - offset), 1, 1, 3, (Left * ti / div), 0);
    }
  glEnd();
}

Explosion::Explosion(int up, int down, int left, int right, int x, int y)
  : AObject ()
{
  Texture	*texture = new Texture();
  timer.play();
  time = 0;
  this->x = x;
  this->y = y;
  this->_type = 6;
  this->Up = up;
  this->Down = down;
  this->Left = left;
  this->Right = right;
  this->texture_ = texture->Explode_;
}

Explosion::~Explosion()
{
}
