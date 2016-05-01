#pragma once
#include "DisplayableObject.h"
#include "Input.h"
class GameManager :
	public DisplayableObject,
	public Input
{
public:
	GameManager();
	~GameManager();
	bool gameState = true;
	bool projection = true;
	Camera *currentCamera;
	
	void Display();
	void HandleKey(unsigned char key, int state, int x, int y);
private:




};

