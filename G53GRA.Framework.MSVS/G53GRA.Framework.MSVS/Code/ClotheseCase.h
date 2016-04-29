#pragma once
#include "DisplayableObject.h"
#include "DrawCube.h"
class ClotheseCase :
	public DisplayableObject
{
public:
	ClotheseCase();
	~ClotheseCase();

	void Display();

private:
	DrawCube *drawCube;
	int texId;
	void DrawBox(float sx, float sy, float sz);
	void DrawAroundSide();
	void BindTexture();
	int Wood1ID, Wood2ID, MentalRedID, WhiteWoodID, Wood3ID;
};

