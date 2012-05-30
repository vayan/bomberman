#include "UI.hh"

void UI::glEnable2D()
{
	int vPort[4];

	glGetIntegerv(GL_VIEWPORT, vPort);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0, vPort[2], 0, vPort[3], -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
}

void UI::glDisable2D()
{
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();   
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();	
}

void 	UI::DrawImage(gdl::Image img, int x_off, int y_off)
{
	img.bind();
	glBegin(GL_QUADS);

	glTexCoord2f(0, 1); glVertex2d(x_off, y_off); //top left
	glTexCoord2f(1, 1); glVertex2d(img.getWidth() + x_off, y_off); //top right
	glTexCoord2f(1, 0); glVertex2d(img.getWidth() + x_off, img.getHeight() + y_off); //bottom right	
	glTexCoord2f(0, 0); glVertex2d(x_off, img.getHeight() + y_off); //bottom left

	glEnd();	
}