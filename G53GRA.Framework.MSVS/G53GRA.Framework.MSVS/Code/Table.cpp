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

}

void Table::DrawTable()
{

}

void Table::DrawBox(float sx, float sy, float sz){
	glPushMatrix();
	glScalef(sx, sy, sz);                               // scale solid cube by size parameters
	drawCube->DrawBox(1.0f);
	glPopMatrix();
}