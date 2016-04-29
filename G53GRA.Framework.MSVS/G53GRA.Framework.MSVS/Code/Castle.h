#pragma once
#include "DisplayableObject.h"
#include "DrawCube.h"
#include "GameManager.h"
class Castle :
	public DisplayableObject
{
public:
	Castle();
	~Castle();

	void Display();

private:
	//GameManager *gm;
	DrawCube *drawCube;
	
	void DrawBox(float sx, float sy, float sz);
	void DrawTower();
	void DrawTowerSide(int doorType);
	void DrawDoor();
	void DrawLongWall();
	void DrawTowerWithWall();
	void BindTexture();
	int StongWallID, WoodID, HugeDoorID;
};

