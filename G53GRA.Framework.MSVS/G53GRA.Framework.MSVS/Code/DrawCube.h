#pragma once
#include "DisplayableObject.h"

class DrawCube :
	public DisplayableObject
{
public:
	DrawCube();
	~DrawCube();

	void Display();
	void DrawBox(GLfloat size);
private:
	
	GLfloat v[8][3];
	GLint i;
	int texId;
	

};

