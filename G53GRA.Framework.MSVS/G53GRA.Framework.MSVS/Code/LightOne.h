#pragma once
#include "DisplayableObject.h"
#include "Animation.h"
#include "MyScene.h"
#include "GameManager.h"
class LightOne :
	public DisplayableObject,
	public Animation
{
public:
	LightOne(GameManager *gameManager);
	~LightOne();
	void Display();
	void Update(const double& deltaTime);
private:
	GameManager *gm;
	float* position;
	float* ambient;
	float* diffuse;
	float* specular;
	float* direction;

	float* amPosition;
	float* amAmbient;
	float* amDiffuse;
	float* amSpecular;
	
	Camera* currentCamera;

};

