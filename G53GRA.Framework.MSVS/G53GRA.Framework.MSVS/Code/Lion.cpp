#include "Lion.h"

Lion::Lion(GameManager *gameManager)
{
	gm = gameManager;
	drawCube = new DrawCube();
	leftLegAngle = 20.0f;
	tailAngle = 10.0f;
}

Lion::~Lion()
{

}
void Lion::Display()
{
	if (!gm->gameState)
	{
		glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);
		glTranslatef(pos[0] + moveStep, pos[1], pos[2]);
		if (moveChange)
		{
			glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
		}

		glScalef(150.0f, 150.0f, 150.0f);
		DrawLion();
		glPopAttrib();
		glPopMatrix();
	}
	
}

void Lion::DrawLion()
{
	DrawHead();
	glTranslatef(0.4f,0.0f, 0.0f);
	DrawBody();
}

void Lion::DrawHead()
{

	glPushMatrix();
	glColor3f(169.0f / 255.0f, 132.0f / 255.0f, 64.0f / 255.0f);
	DrawBox(0.4f, 1.0f, 1.0f); //face
	
	glPushMatrix(); //ear
	glColor3f(169.0f / 255.0f, 132.0f / 255.0f, 64.0f / 255.0f);
	glTranslatef(0.0f, 0.5f, 0.5f);
	DrawBox(0.2f, 0.2f, 0.2f);
	glTranslatef(0.0f, 0.0f, -1.0f);
	DrawBox(0.2f, 0.2f, 0.2f);
	glPopMatrix();
	
	glPushMatrix(); //eye
	glColor3f(15.0f / 255.0f, 11.0f / 255.0f, 12.0f / 255.0f);
	glTranslatef(-0.205f, 0.2f, 0.275f);
	DrawBox(0.01f, 0.1f, 0.15f);
	glTranslatef(0.0f, 0.0f, 0.15f);
	glColor3f(146.0f / 255.0f, 148.0f / 255.0f, 145.0f / 255.0f);
	DrawBox(0.01f, 0.1f, 0.15f);
	glTranslatef(0.0f, 0.0f, -0.7f);
	glColor3f(15.0f / 255.0f, 11.0f / 255.0f, 12.0f / 255.0f);
	DrawBox(0.01f, 0.1f, 0.15f);
	glTranslatef(0.0f, 0.0f, -0.15f);
	glColor3f(146.0f / 255.0f, 148.0f / 255.0f, 145.0f / 255.0f);
	DrawBox(0.01f, 0.1f, 0.15f);
	glPopMatrix();
	
	glPushMatrix(); //nose and mouse
	glTranslatef(-0.25f, -0.125f, 0.0f);
	glColor3f(47.0f / 255.0f, 47.0f / 255.0f, 47.0f / 255.0f);
	DrawBox(0.1f, 0.15f, 0.2f);
	glTranslatef(0.0f, -0.15f, 0.0f);
	glColor3f(147.0f / 255.0f, 147.0f / 255.0f, 147.0f / 255.0f);
	DrawBox(0.1f, 0.15f, 0.2f);
	glTranslatef(0.0f, -0.15f, 0.0f);
	glColor3f(199.0f / 255.0f, 186.0f / 255.0f, 167.0f / 255.0f);
	DrawBox(0.1f, 0.15f, 0.2f);
	glPopMatrix();

	glPopMatrix();
}

void Lion::DrawBody()
{
	glPushMatrix();
	glColor3f(132.0f / 255.0f, 90.0f / 255.0f, 50.0f / 255.0f);
	DrawBox(0.4f, 1.4f, 1.4f);//fure
	
	glPushMatrix();
	glTranslatef(0.7f, 0.0f, 0.0f);
	
	glPushMatrix(); 
	glColor3f(170.0f / 255.0f, 131.0f / 255.0f, 64.0f / 255.0f);
	DrawBox(1.0f, 1.0f, 1.0f); // front body
	glTranslatef(0.0f, -0.6f, 0.5f);
	glPushMatrix();
	glRotatef(leftLegAngle, 0.0f, 0.0f, 1.0f);
	DrawLeg();//front leg
	glPopMatrix();
	glTranslatef(0.0f, 0.0f, -1.0f);
	glRotatef(-leftLegAngle, 0.0f, 0.0f, 1.0f);
	DrawLeg();
	glPopMatrix();

	glTranslatef(1.0f, 0.0f, 0.0f);
	glPushMatrix();
	glColor3f(178.0f / 255.0f, 143.0f / 255.0f, 79.0f / 255.0f);
	DrawBox(1.0f, 0.8f, 0.8f); //back body
	glTranslatef(0.0f, -0.6f, 0.5f); //back leg
	glPushMatrix();
	glRotatef(leftLegAngle, 0.0f, 0.0f, 1.0f);
	DrawLeg();//front leg
	glPopMatrix();
	glTranslatef(0.0f, 0.0f, -1.0f);
	glRotatef(-leftLegAngle, 0.0f, 0.0f, 1.0f);
	DrawLeg();
	glPopMatrix();

	glTranslatef(0.525f, 0.0f, 0.0f); //tail
	glRotatef(tailAngle, 0.0f, 0.0f, 1.0f);
	glColor3f(191.0f/255.0f, 152.0f/255.0f, 83.0f/255.0f);
	DrawBox(0.5f, 0.1f, 0.1f);
	glTranslatef(0.25f, 0.0f, 0.0f);
	glColor3f(95.0f / 255.0f, 73.0f / 255.0f, 35.0f / 255.0f);
	glutSolidSphere(0.1f, 6, 6);
	glPopMatrix();
	glPopMatrix();
}

void Lion::DrawLeg()
{
	glPushMatrix();
	glColor3f(170.0f / 255.0f, 131.0f / 255.0f, 64.0f / 255.0f);
	DrawBox(0.3f, 1.0f, 0.3f);
	glTranslatef(0.0f, -0.55f, 0.0f);
	glColor3f(47.0f / 255.0f, 46.0f / 255.0f, 51.0f / 255.0f);
	DrawBox(0.3f, 0.1f, 0.3f);
	glPopMatrix();
}

void Lion::DrawBox(float sx, float sy, float sz)
{
	glPushMatrix();
	glScalef(sx, sy, sz);                               // scale solid cube by size parameters
	drawCube->DrawBox(1.0f);
	glPopMatrix();
}
void Lion::Update(const double& deltaTime)
{
	if (leftLegAngle >= 20.0f)
	{
		leftLegAngle = 20.0f;
		legChange = !legChange;
	}
	if (leftLegAngle <= -20.0f)
	{
		leftLegAngle = -20.0f;
		legChange = !legChange;
	}
	if (legChange )
	{
		leftLegAngle += 20.0f * deltaTime;
	}
	else
	{
		leftLegAngle -= 20.0f * deltaTime;
	}

	if (tailAngle >= 20.0f)
	{
		tailAngle = 20.0f;
		tailChange = !tailChange;
	}
	if (tailAngle <= -20.0f)
	{
		tailAngle = -20.0f;
		tailChange = !tailChange;
	}
	if (tailChange)
	{
		tailAngle += 10.0f * deltaTime;
	}
	else
	{
		tailAngle -= 10.0f * deltaTime;
	}

	if (moveStep >= 600.0f)
	{
		moveStep = 600.0f;
		moveChange = !moveChange;
		
	}
	if (moveStep <= -600.0f)
	{
		moveStep = -600.0f;
		moveChange = !moveChange;
		
	}
	if (moveChange)
	{
		moveStep += 50.0f * deltaTime;
	}
	else
	{
		moveStep -= 50.0f * deltaTime;
	}

}