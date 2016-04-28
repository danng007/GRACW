#pragma once
#include "DisplayableObject.h"

class DrawCube :
	public DisplayableObject
{
public:
	DrawCube();
	~DrawCube();
	void SetTexture(float x, float y);
	void SetTextureID(int id);
	void Display();
	void DrawBox(GLfloat size);
	float textureX, textureY;
	int texID;
private:
	
	GLfloat v[8][3];
	GLint i;

	

};

