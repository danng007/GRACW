#pragma once
#include "DisplayableObject.h"
#include "DrawCube.h"
class RecursionTree :
	public DisplayableObject
{
public:
	RecursionTree();
	~RecursionTree();

	void Display();
	void DrawBox(float sx, float sy, float sz);
private:

	DrawCube *drawCube;
	int texId;
	void DrawBranch(float heightBranch, float sizeBranch);
	void Branch(float height, float size);
	float branchHeight, branchSize;

};

