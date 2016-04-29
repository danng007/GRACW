#pragma once
#include "DisplayableObject.h"
#include "DrawCube.h"

class Table :
	public DisplayableObject
{
public:
	Table();
	~Table();

	void Display();
	void DrawBox(float sx, float sy, float sz);
private:
	void DrawTable();
	void DrawTableSide();
	void DrawLamp();
	DrawCube *drawCube;
	int WoodID, MentalID;
	void BindTexture();

};

