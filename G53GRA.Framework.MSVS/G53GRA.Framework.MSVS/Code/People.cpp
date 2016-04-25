#include "People.h"

People::People()
{
	drawCube = new DrawCube();
	currentCamera = Scene::GetCamera();
	
	armAngle = 30.0f;
	legAngle = 25.0f;
}

People::~People()
{
	
	
}

void People::Display()
{
	/*glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glColor3f(1.0f, 0.5f, 0.0f);
	currentCamera->GetEyePosition(pos[0], pos[1], pos[2]);
	glTranslatef(pos[0]+ 10.0f, pos[1], pos[2]);
	DrawBox(10.0f, 10.0f, 10.0f);
	glPopAttrib();
	glPopMatrix();*/
	currentCamera->GetEyePosition(pos[0], pos[1], pos[2]);
	glTranslatef(pos[0] , pos[1] - 120.0f, pos[2]);
	glScalef(100.0f, 100.0f, 100.0f);
	DrawPeople();
}

void People::DrawPeople()
{
	//DrawHead();
	//glTranslatef(0.0f, -1.6f, 0.0f);
	
	DrawBody();
}

void People::Update(const double& deltaTime)
{
	if (armAngle >= 60.0f || armAngle <= -60.0f)
	{
		armChange = !armChange;
	}
	if (armChange)
	{
		armAngle += 20.0f * deltaTime;
	}
	else
	{
		armAngle -= 20.0f * deltaTime;
	}

	if (legAngle >= 70.0f || legAngle <= -70.0f)
	{
		legChange = !legChange;
	}
	if (legChange)
	{
		legAngle += 20.0f * deltaTime;
	}
	else
	{
		legAngle -= 20.0f * deltaTime;
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
	glTranslatef(0.0f, 0.0f, 1.0f);
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