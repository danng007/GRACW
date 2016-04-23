#include "Room.h"

#define TESSELATION_LEVEL 100
#define QUAD_STEP_SIZE 2.f/TESSELATION_LEVEL

Room::Room()
{
}


Room::~Room()
{
}

void Room::Display()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glDisable(GL_COLOR_MATERIAL);						// Stop/disable glColor3 calls from affecting the colour of the surface

	GLfloat mat_ambient[] = { 0.3, 0.3, 0.3, 1.0 };     // Define the ambient material colour property K_a
	GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };     // Define the diffuse material colour property K_d
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };    // Define the specular material colour property K_s
	GLfloat mat_shininess[] = { 100.0 };                // Define the shininess/specular exponent factor n ( capped between 0.0 and 128.0 )

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);    // Pass the matrial properties into openGL implementation of the Phong reflectance model
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glPushMatrix();
		glTranslatef(pos[0], pos[1], pos[2]);
		glScalef(scale[0], scale[1], scale[2]);

		// draw back face
		glPushMatrix();
			glTranslatef(0.0f, 0.0f, -1.0f);
			DrawTessellatedWall();
		glPopMatrix();

		// draw front face
		glPushMatrix();
			glTranslatef(0.0f, 0.0f, 1.0f);
			glRotatef(180, 0.0f, 1.0f, 0.0f);
			DrawTessellatedWall();
		glPopMatrix();

		// draw left face
		glPushMatrix();
			glTranslatef(-1.0f, 0.0f, 0.0f);
			glRotatef(90, 0.0f, 1.0f, 0.0f);
			DrawTessellatedWall();
		glPopMatrix();

		// draw right face
		glPushMatrix();
			glTranslatef(1.0f, 0.0f, 0.0f);
			glRotatef(-90, 0.0f, 1.0f, 0.0f);
			DrawTessellatedWall();
		glPopMatrix();

		// draw bottom face
		glPushMatrix();
			glTranslatef(0.0f, -1.0f, 0.0f);
			glRotatef(-90, 1.0f, 0.0f, 0.0f);
			DrawTessellatedWall();
		glPopMatrix();

		// draw top face
		glPushMatrix();
			glTranslatef(0.0f, 1.0f, 0.0f);
			glRotatef(90, 1.0f, 0.0f, 0.0f);
			DrawTessellatedWall();
		glPopMatrix();

	glPopMatrix();

	glEnable(GL_COLOR_MATERIAL);
	glPopAttrib();
}

void Room::DrawTessellatedWall()
{
	glNormal3f(0.f, 0.f, 1.f);

	glBegin(GL_QUADS);
	for (int j = 0; j < TESSELATION_LEVEL; j++)
	{
		for (int i = 0; i < TESSELATION_LEVEL; i++)
		{
			glVertex3f(-1.0f + i*QUAD_STEP_SIZE, -1.0f + (j + 1)*QUAD_STEP_SIZE, 0.0f);
			glVertex3f(-1.0f + i*QUAD_STEP_SIZE, -1.0f + j*QUAD_STEP_SIZE, 0.0f);
			glVertex3f(-1.0f + (i + 1)*QUAD_STEP_SIZE, -1.0f + j*QUAD_STEP_SIZE, 0.0f);
			glVertex3f(-1.0f + (i + 1)*QUAD_STEP_SIZE, -1.0f + (j + 1)*QUAD_STEP_SIZE, 0.0f);
		}
	}
	glEnd();
}