#pragma once

#include "DisplayableObject.h"

class Room :
	public DisplayableObject
{
public:
	Room();
	~Room();

	void Display();

private:
	void DrawTessellatedWall();
};

