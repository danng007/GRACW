#include "Table.h"

Table::Table()
{
	drawCube = new DrawCube();
}

Table::~Table()
{

}

void Table::Display()
{
	glPushMatrix();
	glScalef(20.0f, 20.0f, 20.0f);
	DrawTable();
	glTranslatef(1.8f, 2.3f, -0.8f);
	DrawLamp();
	glPopMatrix();
	
}

void Table::DrawTable()
{
	glPushMatrix();
	glTranslatef(0.0f, 1.9f, 0.0f);
	DrawBox(5.0f, 0.2f, 3.0f);
	glPushMatrix();
	glTranslatef(-2.6f, -1.0f, 0.0f);
	DrawTableSide();
	glTranslatef(5.2f, 0.0f, 0.0f);
	DrawTableSide();
	glPopMatrix();
	glTranslatef(0.0f, -1.9f, 0.0f);
	DrawBox(5.0f, 0.2f, 0.2f);
	glPopMatrix();
}

void Table::DrawTableSide()
{
	glPushMatrix();
	glTranslatef(0.0f, 1.0f, 0.0f);
	DrawBox(0.2f, 0.3f, 3.1f);
	glTranslatef(0.0f, -1.0f, 1.45f);
	DrawBox(0.2f, 2.0f, 0.2f);
	glTranslatef(0.0f, -1.0f, -1.45f);
	DrawBox(0.2f, 0.3f, 3.1f);
	glTranslatef(0.0f, 1.0f, -1.45f);
	DrawBox(0.2f, 2.0f, 0.2f);
	glPopMatrix();
}

void Table::DrawLamp()
{
	glPushMatrix();
	DrawBox(1.0f, 0.2f, 0.5f);
	glTranslatef(-0.3f, 0.1f, 0.0f);
	glutSolidSphere(0.1f, 4, 4);
	glTranslatef(0.7f, 0.4f, 0.0f);
	glRotatef(-30.0f, 0.0f, 0.0f, 1.0f);
	DrawBox(0.1f, 1.0f, 0.1f);
	glRotatef(30.0f, 0.0f, 0.0f, 1.0f);
	glTranslatef(0.0f, 0.85f, 0.0f);
	glRotatef(30.0f, 0.0f, 0.0f, 1.0f);
	DrawBox(0.1f, 1.0f, 0.1f);
	glRotatef(-30.0f, 0.0f, 0.0f, 1.0f);
	glTranslatef(-0.5f, 0.5f, 0.0f);
	DrawBox(1.3f, 0.1f, 0.3f);
	glPopMatrix();
}

void Table::DrawBox(float sx, float sy, float sz){
	glPushMatrix();
	glScalef(sx, sy, sz);                               // scale solid cube by size parameters
	drawCube->DrawBox(1.0f);
	glPopMatrix();
}