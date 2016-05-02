#include "Table.h"

Table::Table()
{
	glEnable(GL_TEXTURE_2D);
	drawCube = new DrawCube();
	BindTexture();
}

Table::~Table()
{
	
	glDisable(GL_TEXTURE_2D);
}

void Table::Display()
{
	
	glColor3f(1.0f, 1.0f, 1.0f );
	glPushMatrix();
	glScalef(20.0f, 20.0f, 20.0f);
	DrawTable();
	glTranslatef(1.8f, 2.1f, -0.8f);
	DrawLamp();
	glPopMatrix();
	
}

void Table::DrawTable()
{
	glPushMatrix();
	glTranslatef(0.0f, 1.9f, 0.0f);
	drawCube->SetTexture(5.0/ 2.5f, 3.0 / 2.5f);
	drawCube->SetTextureID(WoodID);
	DrawBox(5.0f, 0.2f, 3.0f);
	glPushMatrix();
	glTranslatef(-2.6f, -1.0f, 0.0f);
	DrawTableSide();
	glTranslatef(5.2f, 0.0f, 0.0f);
	DrawTableSide();
	glPopMatrix();
	glTranslatef(0.0f, -1.9f, 0.0f);
	drawCube->SetTexture(5.0 / 2.5f, 0.2 / 2.5f);
	DrawBox(5.0f, 0.2f, 0.2f);
	glPopMatrix();
}

void Table::DrawTableSide()
{
	glPushMatrix();
	drawCube->SetTexture(0.2 / 2.5f, 3.1 / 2.5f);
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
	drawCube->SetTexture(1.0f, 1.0f);
	drawCube->SetTextureID(MentalID);
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
	drawCube->SetTextureID(0);
	glPopMatrix();
}

void Table::DrawBox(float sx, float sy, float sz){
	glPushMatrix();
	glScalef(sx, sy, sz);                               // scale solid cube by size parameters
	drawCube->DrawBox(1.0f);
	glPopMatrix();
}

void Table::BindTexture()
{
	WoodID = Scene::GetTexture("./Wood2.bmp");
	MentalID = Scene::GetTexture("./tvBlack.bmp");
}
