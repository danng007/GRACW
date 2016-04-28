#include "Castle.h"
#define SIZE 300.0f
Castle::Castle()
{
	glEnable(GL_TEXTURE_2D);
	drawCube = new DrawCube();
	BindTexture();
}

Castle::~Castle()
{
	glDisable(GL_TEXTURE_2D);
}

void Castle::Display()
{
	glPushMatrix();
	glScalef(2.0f, 2.0f, 2.0f);
	DrawTowerWithWall();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(-2500.0f, 0.0f, 0.0f);
	DrawTowerWithWall();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(-2500.0f, 0.0f, 0.0f);
	DrawTowerWithWall();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(-2500.0f, 0.0f, 0.0f);
	DrawTowerWithWall();
	glPopMatrix();
}

void Castle::DrawTowerWithWall()
{
	glPushMatrix();
	glScalef(10.0f, 10.0f, 10.0f);
	DrawTower();
	glTranslatef(22.5f, 0.0f, 0.0f);
	DrawLongWall();
	glPopMatrix();
}

void Castle::DrawTower()
{
	glPushMatrix();
	DrawTowerSide(1);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	DrawTowerSide(2);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	DrawTowerSide(0);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	DrawTowerSide(0);
	glPopMatrix();
}

void Castle::DrawTowerSide(int doorType)
{
	switch (doorType)
	{
	case 0:
		glPushMatrix();
		glTranslatef(0.0f, 15.0f, 22.5f);
		drawCube->SetTexture(45.0 / 2.5f, 30.0 / 2.5f);
		drawCube->SetTextureID(StongWallID);
		DrawBox(45.0f, 30.0f, 2.0f);
		glTranslatef(0.0f, -10.0f, 1.0f);
		DrawDoor();
		glPopMatrix();
		break;
	case 1:
		glPushMatrix();
		glTranslatef(0.0f, 15.0f, 22.5f);
		drawCube->SetTexture(45.0 / 2.5f, 30.0 / 2.5f);
		drawCube->SetTextureID(StongWallID);
		DrawBox(45.0f, 30.0f, 2.0f);
		glTranslatef(0.0f, 5.0f, 1.0f);
		DrawDoor();
		glTranslatef(12.5f, -15.0f, 0.0f);
		DrawDoor();
		glPopMatrix();
		break;
	case 2:
		glPushMatrix();
		glTranslatef(0.0f, 15.0f, 22.5f);
		drawCube->SetTexture(45.0 / 2.5f, 30.0 / 2.5f);
		drawCube->SetTextureID(StongWallID);
		DrawBox(45.0f, 30.0f, 2.0f);
		glTranslatef(0.0f, 5.0f, 1.0f);
		DrawDoor();
		glTranslatef(-12.5f, -15.0f, 0.0f);
		DrawDoor();
		glPopMatrix();
		break;
	default:
		break;
	}
	glPushMatrix();
	//glColor3f(0.8f, 0.7f, 0.4f);
	glTranslatef(-25.0f, 37.5f, 24.0f);
	for (int i = 0; i < 5; i++)
	{
		drawCube->SetTexture(5.0 / 2.5f, 15.0 / 2.5f);
		drawCube->SetTextureID(StongWallID);
		DrawBox(5.0f, 15.0f, 5.0f);
		glTranslatef(5.0f, -2.5f, 0.0f);
		drawCube->SetTexture(5.0 / 2.5f, 10.0 / 2.5f);
		DrawBox(5.0f, 10.0f, 5.0f);
		glTranslatef(5.0f, 2.5f, 0.0f);
	}
	drawCube->SetTexture(5.0 / 2.5f, 15.0 / 2.5f);
	DrawBox(5.0f, 15.0f, 5.0f);
	drawCube->SetTextureID(0);
	glPopMatrix();
}

void Castle::DrawDoor()
{
	drawCube->SetTextureID(0);
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 0.0f);
	DrawBox(0.2f, 10.0f, 0.1f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(-2.55f, 0.0f, 0.0f);
	drawCube->SetTexture(1.0, 1.0);
	drawCube->SetTextureID(WoodID);
	DrawBox(4.9f, 10.0f, 0.1f);
	glTranslatef(5.1f, 0.0f, 0.0f);
	DrawBox(4.9f, 10.0f, 0.1f);
	glPopMatrix();
}

void Castle::DrawLongWall()
{
	glPushMatrix();
	//glColor3f(0.2f, 0.4f, 0.6f);
	glTranslatef(102.5f, 7.5f, 0.0f);
	drawCube->SetTexture(205.0 / 2.5f, 15.0 / 2.5f);
	drawCube->SetTextureID(StongWallID);
	DrawBox(205.0f, 15.0f, 12.0f); //Long Wall
	drawCube->SetTextureID(0);
	glTranslatef(0.0f, 0.0f, -6.0f);
	drawCube->SetTexture(1.0f, 1.0f);
	drawCube->SetTextureID(HugeDoorID);
	DrawBox(20.0f, 15.0f, 0.1f); //Wall door
	drawCube->SetTextureID(0);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(2.5f, 20.0f, -5.5f);
	//glColor3f(0.6f, 0.4f, 0.6f);
	for (size_t i = 0; i < 20; i++)
	{
		drawCube->SetTexture(1.0/0.5f, 10.0 /2.5f);
		drawCube->SetTextureID(StongWallID);
		DrawBox(5.0f, 10.0f, 1.0f); //Above wall, tall
		drawCube->SetTextureID(0);

		glTranslatef(5.0f, -2.5f, 0.0f);
		drawCube->SetTexture(1.0 / 0.5f, 5.0 / 2.5f);
		drawCube->SetTextureID(StongWallID);
		DrawBox(5.0f, 5.0f, 1.0f); //Above wall, low
		glTranslatef(5.0f, 2.5f, 0.0f);
	}
	drawCube->SetTexture(1.0 / 0.5f, 10.0 / 2.5f);
	DrawBox(5.0f, 10.0f, 1.0f);
	drawCube->SetTextureID(0);
	glPopMatrix();
}

void Castle::DrawBox(float sx, float sy, float sz){
	glPushMatrix();
	glScalef(sx, sy, sz);                               // scale solid cube by size parameters
	drawCube->DrawBox(1.0f);
	glPopMatrix();
}

void Castle::BindTexture()
{
	
	StongWallID = Scene::GetTexture("./StoneWall.bmp");
	WoodID = Scene::GetTexture("./Wood.bmp");
	HugeDoorID = Scene::GetTexture("./Door.bmp");
}