#include "People.h"
#include <iostream>
using namespace std;

/*
This class used to drawing the character and control the animation.
*/
People::People(GameManager *gameManager)
{
	gm = gameManager;
	
	drawCube = new DrawCube();
	currentCamera = Scene::GetCamera();
	
	armAngle = 30.0f;
	legAngle = 25.0f;
	rotation[0] = 0.0f;
	rotation[1] = 0.0f;
	rotation[2] = 0.0f;
	depth = 200.0f;

}

People::~People()
{
	
	
}

void People::Display()
{
	
		glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);
		//This translate make sure character always present at the front of camera
		glTranslatef(pos[0] + cameraRX * depth, pos[1] - 50.0f, pos[2] + cameraRZ * depth); 
		glRotatef(rotateX, 0.0f, 1.0f, 0.0f);
		glScalef(30.0f, 30.0f, 30.0f);
		DrawPeople();
		glPopAttrib();
		glPopMatrix();
}

void People::DrawPeople()
{
	DrawHead();
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, -1.6f, 0.0f);
	DrawBody();
}

void People::Update(const double& deltaTime)
{
	if (armAngle > 30.0f)
	{
		armChange = !armChange;
		armAngle = 30.0f;
	}
	if (armAngle < -30.0f)
	{
		armChange = !armChange;
		armAngle = -30.0f;
	}

	if (armChange)
	{
		armAngle += 40.0f * deltaTime;
	}
	else
	{
		armAngle -= 40.0f * deltaTime;
	}

	if (gm->lightOn)
	{
		leftArmAngle = -90.0f;
	}
	else
	{
		leftArmAngle = -armAngle;
	}

	if (legAngle > 30.0f )
	{
		legChange = !legChange;
		legAngle = 30.0f;
	}
	if (legAngle < -30.0f)
	{
		legChange = !legChange;
		legAngle = -30.0f;
	}
	if (legChange)
	{
		legAngle += 40.0f * deltaTime;
	}
	else
	{
		legAngle -= 40.0f * deltaTime;
	}
	
	currentCamera->GetEyePosition(pos[0], pos[1], pos[2]);
	currentCamera->GetViewDirection(cameraRX, cameraRY, cameraRZ);
	rotateX = asin (cameraRZ) / 3.1415926 * 180.0f + 90.0f;
	if (cameraRZ >= 0.0f)
	{
		rotateX = -rotateX;
	}
	
	

}
void People::DrawHead()
{

	glPushMatrix();
	glScalef(0.5f, 0.5f, 0.5f);
	glTranslatef(0.0f, 0.8f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	DrawBox(2.0f, 0.6f, 2.0f); //hair
	glTranslatef(0.0f, -0.8f, 0.0f);
	glColor3f(204.0f/255.0f, 132.0f/255.0f, 67.0f/255.0f);
	glutSolidSphere(1.0f, 20, 20); //head

	glPopMatrix();

}



void People::DrawBody()
{
	glPushMatrix();
	glColor3f(0.32f, 0.54f, 0.26f);
	DrawBox(1.5f, 2.0f, 0.3f);

	glPushMatrix(); //left arm
	glTranslatef(-1.0f, 0.5f, 0.0f);
	glRotatef(leftArmAngle, 1.0f, 0.0f, 0.0f);
	DrawArm(true);
	glPopMatrix();

	glPushMatrix(); //right arm
	glTranslatef(1.0f, 0.5f, 0.0f);
	glRotatef(armAngle, 1.0f, 0.0f, 0.0f);
	DrawArm(false);
	glPopMatrix();

	glPushMatrix(); //left leg
	glTranslatef(-0.25f, -1.75f, 0.0f);
	glRotatef(legAngle, 1.0f, 0.0f, 0.0f);
	DrawLeg(true);
	glPopMatrix();

	glPushMatrix(); //right leg
	glTranslatef(0.25f, -1.75f, 0.0f);
	glRotatef(-legAngle, 1.0f, 0.0f, 0.0f);
	DrawLeg(false);
	glPopMatrix();

	glPopMatrix();

}
void People::DrawArm(bool leftArm)
{
	glPushMatrix();
	glColor3f(0.32f, 0.54f, 0.26f);
	DrawBox(0.5f, 1.0f, 0.3f);
	glTranslatef(0.0f, -1.0f, 0.0f);
	DrawBox(0.5f, 1.0f, 0.3f);
	glTranslatef(0.0f, -0.6f, 0.0f);
	glColor3f(204.0f / 255.0f, 132.0f / 255.0f, 67.0f / 255.0f);
	glutSolidSphere(0.2, 3,3);
	glPopMatrix();
}
void People::DrawLeg(bool leftLeg)
{
	glPushMatrix();
	glColor3f(0.62f, 0.64f, 0.26f);
	DrawBox(0.5f, 1.5f, 0.3f);
	glTranslatef(0.0f, -1.25f, 0.0f);
	DrawBox(0.5f, 1.0f, 0.3f);
	glTranslatef(0.0f, -0.65f, 0.0f);
	glColor3f(0.62f, 0.14f, 0.26f);
	DrawBox(0.5f, 0.3f, 1.0f);
	glPopMatrix();
}
void People::DrawBox(float sx, float sy, float sz){
	glPushMatrix();
	glScalef(sx, sy, sz);                               // scale solid cube by size parameters
	drawCube->DrawBox(1.0f);
	glPopMatrix();
}