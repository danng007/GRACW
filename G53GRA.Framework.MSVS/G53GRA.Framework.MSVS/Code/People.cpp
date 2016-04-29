#include "People.h"
#include <iostream>
using namespace std;
People::People()
{
	
	drawCube = new DrawCube();
	currentCamera = Scene::GetCamera();
	
	armAngle = 30.0f;
	legAngle = 25.0f;
	rotation[0] = 0.0f;
	rotation[1] = 0.0f;
	rotation[2] = 0.0f;
	depth = 400.0f;
}

People::~People()
{
	
	
}

void People::Display()
{
		glPushMatrix();
		glTranslatef(pos[0] + cameraRX * depth, pos[1], pos[2] + cameraRZ * depth);

		glRotatef(rotateX, 0.0f, 1.0f, 0.0f);
		glScalef(40.0f, 40.0f, 40.0f);
		DrawPeople();
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
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glColor3f(0.3f, 0.4f, 0.02f);
	glutSolidSphere(1.0f, 20, 20); //head
	glTranslatef(0.0f, 0.0f, -1.0f);
	glColor3f(0.3f, 0.4f, 0.32f);
	glutSolidSphere(0.1f, 5, 5); //nose
	glTranslatef(-0.25f, 0.25f, 0.0f);
	glColor3f(0.3f, 0.6f, 0.02f);
	glutSolidSphere(0.1f, 5, 5); //left eye
	glTranslatef(0.5f, 0.0f, 0.0f);
	glColor3f(0.6f, 0.4f, 0.02f);
	glutSolidSphere(0.1f, 5, 5); // right eye
	glTranslatef(-0.25f, -0.5f, 0.0f);
	glColor3f(0.3f, 0.4f, 0.72f);
	DrawBox(0.3f, 0.1f, 0.1f); // mosue
	glPopAttrib();
	glPopMatrix();
	glTranslatef(0.0f, -0.6f, 0.0f);
	//glColor3f(0.3f, 0.4f, 0.02f);
	DrawNeck(0.5f, 1.0f);
	glPopMatrix();
}

void People::DrawNeck(float size, float height)
{
	float res = 0.1f * 3.1415926;                  // resolution (in radians: equivalent to 18 degrees)
	float r = size;                        // ratio of radius to height
	float x = r, z = 0.f;                   // initialise x and z on right of cylinder centre
	float t = 0.f;                          // initialise angle as 0

	do{                                     // create branch with multiple QUADS
		glBegin(GL_QUADS);
		// Create first points
		glVertex3f(x, 0.f, z);          // bottom
		glVertex3f(x, height, z);          // top
		// Iterate around circle
		t += res;                       // add increment to angle
		x = r*cos(t);                   // move x and z around circle
		z = r*sin(t);
		// Close quad
		glVertex3f(x, height, z);          // top
		glVertex3f(x, 0.f, z);          // bottom
		glEnd();
	} while (t <= 2 * 3.1415926);                // full rotation around circle

	glTranslatef(0.f, 1.f, 0.f);            // translate to top of branch
}

void People::DrawBody()
{
	glPushMatrix();
	DrawBox(1.5f, 2.0f, 0.3f);

	glPushMatrix(); //left arm
	glTranslatef(-1.0f, 0.5f, 0.0f);
	glRotatef(armAngle, 1.0f, 0.0f, 0.0f);
	DrawArm(true);
	glPopMatrix();

	glPushMatrix(); //right arm
	glTranslatef(1.0f, 0.5f, 0.0f);
	glRotatef(-armAngle, 1.0f, 0.0f, 0.0f);
	DrawArm(false);
	glPopMatrix();

	glPushMatrix(); //left leg
	glTranslatef(-0.25f, -1.75f, 0.0f);
	glRotatef(-legAngle, 1.0f, 0.0f, 0.0f);
	DrawLeg(true);
	glPopMatrix();

	glPushMatrix(); //right leg
	glTranslatef(0.25f, -1.75f, 0.0f);
	glRotatef(legAngle, 1.0f, 0.0f, 0.0f);
	DrawLeg(false);
	glPopMatrix();

	glPopMatrix();

}
void People::DrawArm(bool leftArm)
{
	glPushMatrix();
	DrawBox(0.5f, 1.0f, 0.3f);
	glTranslatef(0.0f, -1.0f, 0.0f);
	glRotatef(handAngle, 1.0f, 0.0f, 0.0f);
	DrawBox(0.5f, 1.0f, 0.3f);
	glTranslatef(0.0f, -0.6f, 0.0f);
	glutSolidSphere(0.2, 3,3);
	glPopMatrix();
}
void People::DrawLeg(bool leftLeg)
{
	glPushMatrix();
	DrawBox(0.5f, 1.5f, 0.3f);
	glTranslatef(0.0f, -1.25f, 0.0f);
	glRotatef(footAngle, 1.0f, 0.0f, 0.0f);
	DrawBox(0.5f, 1.0f, 0.3f);
	glTranslatef(0.0f, -0.65f, 0.0f);
	DrawBox(0.5f, 0.3f, 1.0f);
	glPopMatrix();
}
void People::DrawBox(float sx, float sy, float sz){
	glPushMatrix();
	glScalef(sx, sy, sz);                               // scale solid cube by size parameters
	drawCube->DrawBox(1.0f);
	glPopMatrix();
}