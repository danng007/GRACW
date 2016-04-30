#pragma once
#include "DisplayableObject.h"

class SkyBox :
	public DisplayableObject
{
public:
	SkyBox();
	~SkyBox();

	void Display();

private:
	void DrawSurface();
	int aroundID, upID, floorID;
};

