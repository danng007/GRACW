#include "ClotheseCase.h"
#define SIZE 300.0f
ClotheseCase::ClotheseCase()
{
	glEnable(GL_TEXTURE_2D);
	drawCube = new DrawCube();
	BindTexture();
}

ClotheseCase::~ClotheseCase()
{
	glDisable(GL_TEXTURE_2D);
}

void ClotheseCase::Display()
{
	glColor3f(1.0f, 1.0f, 1.0f);
	glPushMatrix();
	glScalef(2.0f, 2.0f, 2.0f);
	//glcolor3f(1.0f, 0.0f, 1.0f);

	glTranslatef(0.0f, 21.0f, 0.0f);
	drawCube->SetTextureID(Wood1ID);
	DrawBox(40.0f, 1.0f, 10.0f); // 1

	glPushMatrix();
	drawCube->SetTextureID(Wood3ID);
	glTranslatef(-10.0f, -5.5f, 0.0f);
	//glcolor3f(1.0f, 0.0f, 0.5f);
	DrawBox(20.0f, 10.0f, 10.0f);  // 2
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 5.5f);
	glutSolidSphere(1.0f, 10, 10); // Door Knoc sphere
	glPopMatrix();
	glTranslatef(20.0f, 0.0f, 0.0f);
	//glcolor3f(1.0f, 0.5f, 0.5f);
	DrawBox(20.0f, 10.0f, 10.0f);  //3
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 5.5f);
	glutSolidSphere(1.0f, 10, 10); // Door Knoc sphere
	glPopMatrix();
	glTranslatef(0.0f, -10.0f, 0.0f);
	//glcolor3f(0.6f, 0.5f, 0.5f);
	DrawBox(20.0f, 10.0f, 10.0f);  //4
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 5.5f);
	glutSolidSphere(1.0f, 10, 10); // Door Knoc sphere
	glPopMatrix();
	glTranslatef(-20.0f, 0.0f, 0.0f);
	//glcolor3f(0.6f, 0.5f, 0.7f);
	DrawBox(20.0f, 10.0f, 10.0f);  //5
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 5.5f);
	glutSolidSphere(1.0f, 10, 10); // Door Knoc sphere
	glPopMatrix();
	drawCube->SetTextureID(0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 30.0f, 0.0f);
	glPushMatrix();
	glTranslatef(-10.0f, 0.0f, 0.0f);
	//glcolor3f(0.6f, 0.5f, 0.8f);
	drawCube->SetTextureID(WhiteWoodID);
	DrawBox(20.0f, 57.0f, 10.0f);  //6
	//glcolor3f(1.0f, 0.0f, 0.2f);
	glTranslatef(9.0f, 0.0f, 5.5f);
	glutSolidSphere(1.0f, 10, 10); // Door Knoc sphere
	glPopMatrix();
	glPushMatrix();
	glTranslatef(14.0f, 15.0f, 0.0);
	//glcolor3f(0.6f, 0.6f, 0.8f);
	DrawAroundSide();  // 7
	glTranslatef(0.0f, -11.0f, 0.0);
	//glcolor3f(0.8f, 0.6f, 0.8f);
	DrawAroundSide();  // 8
	glTranslatef(0.0f, -11.0f, 0.0);
	//glcolor3f(0.9f, 0.7f, 0.8f);
	DrawAroundSide();  // 9
	glTranslatef(0.0f, -11.0f, 0.0);
	//glcolor3f(1.0f, 0.2f, 0.8f);
	DrawAroundSide();  // 10
	glPopMatrix();
	glPushMatrix();
	glTranslatef(10.0f, 25.0f, 0.0f);
	drawCube->SetTexture(1.0f, 1.0f);
	drawCube->SetTextureID(MentalRedID);
	DrawBox(20.0f, 1.0f,1.0f); //11
	drawCube->SetTextureID(0);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	//glcolor3f(0.1f, 0.2f, 0.3f);
	drawCube->SetTexture(1.0f, 1.0f);
	drawCube->SetTextureID(Wood2ID);
	glTranslatef(0.0f, -21.0f, 0.0f);
	DrawBox(40.0f, 1.0f, 10.0f); //12
	glTranslatef(20.5f, 40.0f, 0.0f);
	DrawBox(1.0f, 81.0f, 10.0f); //13
	glTranslatef(-20.5f, 40.0f, 0.0f);
	DrawBox(40.0f, 1.0f, 10.0f); //14
	glTranslatef(-20.5f, -40.0f, 0.0f);
	DrawBox(1.0f, 81.0f, 10.0f); //15
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 19.0f, -5.0f);
	DrawBox(42.0f, 81.0f, 1.0f); //15 Back
	drawCube->SetTextureID(0);
	glPopMatrix();


	glPopMatrix();





}

void ClotheseCase::DrawBox(float sx, float sy, float sz)
{
	glPushMatrix();
	glScalef(sx, sy, sz);                               // scale solid cube by size parameters
	drawCube->DrawBox(1.0f);
	glPopMatrix();
}

void ClotheseCase::DrawAroundSide()
{
	drawCube->SetTexture(1.0f, 1.0f);
	drawCube->SetTextureID(WhiteWoodID);
	glPushMatrix();
	glTranslatef(0.0f, 5.0f, 0.0f);
	DrawBox(10.0f, 1.0f, 10.0f);
	glTranslatef(-5.0f, -5.0f, 0.0f);
	DrawBox(1.0f, 10.0f, 10.0f);
	glTranslatef(5.0f, -5.0f, 0.0f);
	DrawBox(10.0f, 1.0f, 10.0f);
	glTranslatef(5.0f, 5.0f, 0.0f);
	DrawBox(1.0f, 10.0f, 10.0f);
	glPopMatrix();
	drawCube->SetTextureID(0);
}

void ClotheseCase::BindTexture()
{
	Wood1ID = Scene::GetTexture("./Wood2.bmp");
	Wood2ID = Scene::GetTexture("./Wood3.bmp");
	MentalRedID = Scene::GetTexture("./MentalRed.bmp");
	WhiteWoodID = Scene::GetTexture("./WhiteWood.bmp");
	Wood3ID = Scene::GetTexture("./Wood4.bmp");
}