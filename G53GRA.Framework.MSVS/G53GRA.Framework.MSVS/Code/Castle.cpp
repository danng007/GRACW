#include "Castle.h"
#define SIZE 300.0f
Castle::Castle()
{
	drawCube = new DrawCube();
}

Castle::~Castle()
{

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
		glColor3f(0.5f, 0.7f, 0.1f);
		DrawBox(45.0f, 30.0f, 2.0f);
		glTranslatef(0.0f, -10.0f, 1.0f);
		DrawDoor();
		glPopMatrix();
		break;
	case 1:
		glPushMatrix();
		glTranslatef(0.0f, 15.0f, 22.5f);
		glColor3f(0.5f, 0.7f, 0.1f);
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
		glColor3f(0.5f, 0.7f, 0.1f);
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
	glColor3f(0.8f, 0.7f, 0.4f);
	glTranslatef(-25.0f, 37.5f, 24.0f);
	for (int i = 0; i < 5; i++)
	{

		DrawBox(5.0f, 15.0f, 5.0f);
		glTranslatef(5.0f, -2.5f, 0.0f);
		DrawBox(5.0f, 10.0f, 5.0f);
		glTranslatef(5.0f, 2.5f, 0.0f);
	}
	DrawBox(5.0f, 15.0f, 5.0f);
	glPopMatrix();
}

void Castle::DrawDoor()
{
	glPushMatrix();
	glColor3f(1.0f,1.0f,1.0f);
	DrawBox(0.2f, 10.0f, 0.1f);
	glTranslatef(-2.55f, 0.0f, 0.0f);
	glColor3f(1.0f, 0.6f, 0.6f);
	DrawBox(4.9f, 10.0f, 0.1f);
	glTranslatef(5.1f, 0.0f, 0.0f);
	DrawBox(4.9f, 10.0f, 0.1f);
	glPopMatrix();
}

void Castle::DrawLongWall()
{
	glPushMatrix();
	glColor3f(0.2f, 0.4f, 0.6f);
	glTranslatef(102.5f, 7.5f, 0.0f);
	DrawBox(205.0f, 15.0f, 12.0f); //Long Wall
	glTranslatef(0.0f, 0.0f, -6.0f);
	glColor3f(0.1f, 0.9f, 0.6f);
	DrawBox(20.0f, 15.0f, 0.1f); //Wall door
	glPopMatrix();
	glPushMatrix();
	glTranslatef(2.5f, 20.0f, -5.5f);
	glColor3f(0.6f, 0.4f, 0.6f);
	for (size_t i = 0; i < 20; i++)
	{
		DrawBox(5.0f, 10.0f, 1.0f); //Above wall, tall
		glTranslatef(5.0f, -2.5f, 0.0f);
		DrawBox(5.0f, 5.0f, 1.0f); //Above wall, low
		glTranslatef(5.0f, 2.5f, 0.0f);
	}
	DrawBox(5.0f, 10.0f, 1.0f);
	glPopMatrix();
}

void Castle::DrawBox(float sx, float sy, float sz){
	glPushMatrix();
	glScalef(sx, sy, sz);                               // scale solid cube by size parameters
	drawCube->DrawBox(1.0f);
	glPopMatrix();
}