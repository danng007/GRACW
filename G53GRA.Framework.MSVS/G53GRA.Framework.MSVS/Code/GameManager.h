#pragma once
#include "DisplayableObject.h"

class GameManager :
	public DisplayableObject
{
public:
	GameManager();
	~GameManager();
	bool gameState = false;
	Camera *currentCamera;
	
	void Display();
private:




};

