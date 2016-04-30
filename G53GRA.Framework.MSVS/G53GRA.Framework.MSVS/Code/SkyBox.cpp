#include "SkyBox.h"

SkyBox::SkyBox()
{
	glEnable(GL_TEXTURE_2D);
	aroundID = Scene::GetTexture("./texture/skybox_around.bmp");
	upID = Scene::GetTexture("./texture/skybox_up.bmp");
	floorID = Scene::GetTexture("./texture/SnowFloor.bmp");
}
SkyBox::~SkyBox()
{
	glDisable(GL_TEXTURE_2D);
}

void SkyBox::Display()
{
	glPushMatrix();
	glScalef(10000.0f, 10000.0f, 10000.0f);
	glPushMatrix();
	
	//NEAR
	glBindTexture(GL_TEXTURE_2D, aroundID);
	DrawSurface();

	//RIGHT
	glRotatef(90, 0, 1, 0);
	DrawSurface();

	//BACK
	glRotatef(90, 0, 1, 0);
	DrawSurface();

	//LEFT
	glRotatef(90, 0, 1, 0);
	DrawSurface();
	glBindTexture(GL_TEXTURE_2D, 0);
	//UP
	glBindTexture(GL_TEXTURE_2D, upID);
	glRotatef(90, 0, 1, 0);
	glRotatef(-90, 1, 0, 0);
	DrawSurface();
	glBindTexture(GL_TEXTURE_2D, 0);

	//DOWN

	glPopMatrix();
	glTranslatef(0.0f, 0.965f, 0.0f);
	glBindTexture(GL_TEXTURE_2D, floorID);
	glRotatef(90, 1, 0, 0);
	DrawSurface();
	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();

	
}

void SkyBox::DrawSurface()
{
	glBegin(GL_QUADS);
	glTexCoord2d(0.0f, 0.0f);
	glVertex3f(1, -1, 1);
	glTexCoord2d(1.0f, 0.0f);
	glVertex3f(-1, -1, 1);
	glTexCoord2d(1.0f, 1.0f);
	glVertex3f(-1, 1, 1);
	glTexCoord2d(0.0f, 1.0);
	glVertex3f(1, 1, 1);
	glEnd();
}
