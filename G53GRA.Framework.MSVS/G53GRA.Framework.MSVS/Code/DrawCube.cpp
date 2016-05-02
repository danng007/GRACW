#include "DrawCube.h"
#include <iostream>
#define SIZE 300.0f
using namespace std;

/*
Rewrite the glutsolidcube function.
Now it included texture part.
SetTexture will define the texture size in each part.
*/

DrawCube::DrawCube()
{
	glEnable(GL_TEXTURE_2D);
}

DrawCube::~DrawCube()
{
	glDisable(GL_TEXTURE_2D);
}

void DrawCube::Display()
{

}


void DrawCube::SetTexture(float x, float y)
{
	textureX = x;
	textureY = y;
}

void DrawCube::DrawBox(GLfloat size){
	
	static GLfloat n[6][3] =
	{
		{ -1.0, 0.0, 0.0 },
		{ 0.0, 1.0, 0.0 },
		{ 1.0, 0.0, 0.0 },
		{ 0.0, -1.0, 0.0 },
		{ 0.0, 0.0, 1.0 },
		{ 0.0, 0.0, -1.0 }
	};
	static GLint faces[6][4] =
	{
		{ 0, 1, 2, 3 },
		{ 3, 2, 6, 7 },
		{ 7, 6, 5, 4 },
		{ 4, 5, 1, 0 },
		{ 5, 6, 2, 1 },
		{ 7, 4, 0, 3 }
	};
	v[0][0] = v[1][0] = v[2][0] = v[3][0] = -size / 2;
	v[4][0] = v[5][0] = v[6][0] = v[7][0] = size / 2;
	v[0][1] = v[1][1] = v[4][1] = v[5][1] = -size / 2;
	v[2][1] = v[3][1] = v[6][1] = v[7][1] = size / 2;
	v[0][2] = v[3][2] = v[4][2] = v[7][2] = -size / 2;
	v[1][2] = v[2][2] = v[5][2] = v[6][2] = size / 2;

	glBindTexture(GL_TEXTURE_2D, texID);
	for (i = 5; i >= 0; i--) {
		glBegin(GL_QUADS);
		glNormal3fv(&n[i][0]);
		glTexCoord2d(0.0f, 0.0f);
		glVertex3fv(&v[faces[i][0]][0]);
		glTexCoord2d(0.0f, textureY);
		glVertex3fv(&v[faces[i][1]][0]);
		glTexCoord2d(textureX, textureY);
		glVertex3fv(&v[faces[i][2]][0]);
		glTexCoord2d(textureX, 0);
		glVertex3fv(&v[faces[i][3]][0]);
		glEnd();
		
	}
	glBindTexture(GL_TEXTURE_2D, 0);
}

void DrawCube::SetTextureID(int id)
{
	texID = id;
	//cout << texID << endl;
}