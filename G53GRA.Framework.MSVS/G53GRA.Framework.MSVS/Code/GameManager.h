#pragma once
#include "DisplayableObject.h"
#include "Animation.h"
#include "Input.h"
class GameManager :
	public DisplayableObject,
	public Animation,
	public Input
{
public:
	GameManager();
	~GameManager();
	bool gameState = true;
	bool projection = true;
	Camera *currentCamera;
	void Update(const double& deltaTime);
	void Display();
	float lightIntensity = 0.0f;
	void HandleKey(unsigned char key, int state, int x, int y);
	bool lightOn = false;
private:
	bool lightChange = true;
	


};

