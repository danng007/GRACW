#pragma once
#include "DisplayableObject.h"
#include "DrawCube.h"
#include "GameManager.h"
class RecursionTree :
	public DisplayableObject
{
public:
	RecursionTree(GameManager *gameManager);
	~RecursionTree();

	void Display();
	void DrawBox(float sx, float sy, float sz);
private:
	int ycounter = 0, xcounter = 0;
	GameManager *gm;
	DrawCube *drawCube;
	int texId;
	void DrawBranch(float heightBranch, float sizeBranch);
	void Branch(float height, float size);
	float branchHeight, branchSize;

};

