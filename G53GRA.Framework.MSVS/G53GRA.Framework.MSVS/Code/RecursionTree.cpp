#include "RecursionTree.h"

RecursionTree::RecursionTree()
{
	drawCube = new DrawCube();
	branchHeight = 16.5f;
	branchSize = 0.8f;
}

RecursionTree::~RecursionTree()
{

}

void RecursionTree::Display()
{
	glPushMatrix();
	glScalef(5.0f, 5.0f, 5.0f);
	DrawBranch(branchHeight, branchSize);
	glPopMatrix();
}

void RecursionTree::DrawBranch(float heightBranch, float sizeBranch)
{
	if (heightBranch <= 0.0f)
	{
		glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);
		glTranslatef(0.0f, heightBranch + 1.8f, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glutSolidSphere(2.0f, 6, 6);
		glPopAttrib();
		glPopMatrix();
	}
	else
	{


		glPushMatrix();
		Branch(heightBranch, sizeBranch);
		glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);
		glTranslatef(0.0f, heightBranch + 1.8f, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glutSolidSphere(3.0f, 4, 4);
		glPopAttrib();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0f, heightBranch / 1.5, 0.0f);
		glRotatef(40.0f, 1.0f, 0.0f, 0.0f);
		glRotatef(-40.0f, 0.0f, 0.0f, 1.0f);
		DrawBranch(heightBranch - 4.0f, sizeBranch - 0.15f);
		Branch(heightBranch, sizeBranch);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0f, heightBranch / 1.5, 0.0f);
		glRotatef(40.0f, 1.0f, 0.0f, 0.0f);
		glRotatef(40.0f, 0.0f, 0.0f, 1.0f);
		DrawBranch(heightBranch - 4.0f, sizeBranch - 0.15f);
		Branch(heightBranch, sizeBranch);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0f, heightBranch / 1.5, 0.0f);
		glRotatef(-40.0f, 0.0f, 0.0f, 1.0f);
		glRotatef(-40.0f, 1.0f, 0.0f, 0.0f);
		DrawBranch(heightBranch - 4.0f, sizeBranch - 0.15f);
		Branch(heightBranch, sizeBranch);
		glPopMatrix();

		glPopMatrix();
	}
}

void RecursionTree::Branch(float height, float size )
{
	glColor3f(0.58f, 0.27f, 0.21f);
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

void RecursionTree::DrawBox(float sx, float sy, float sz){
	glPushMatrix();
	glScalef(sx, sy, sz);                               // scale solid cube by size parameters
	drawCube->DrawBox(1.0f);
	glPopMatrix();
}