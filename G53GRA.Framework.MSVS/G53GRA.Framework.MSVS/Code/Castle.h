#pragma once
#include "DisplayableObject.h"
#include "DrawCube.h"
class Castle :
	public DisplayableObject
{
public:
	Castle();
	~Castle();

	void Display();

private:
	DrawCube *drawCube;
	int texId;
	void DrawBox(float sx, float sy, float sz);
	void DrawTower();
	void DrawTowerSide(int doorType);
	void DrawDoor();
	void DrawLongWall();
	void DrawTowerWithWall();
};

