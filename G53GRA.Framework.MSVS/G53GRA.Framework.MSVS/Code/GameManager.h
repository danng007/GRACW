#pragma once
#include "DisplayableObject.h"

class GameManager :
	public DisplayableObject
{
public:
	GameManager();
	~GameManager();
	bool gameState = true;
	Camera *currentCamera;
	
	void Display();
private:




};

