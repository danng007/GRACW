#pragma once
#include "DisplayableObject.h"
#include "DrawCube.h"
#include "Animation.h"
#include "GameManager.h"

class Lion :
	public DisplayableObject,
	public Animation
{
public:
	Lion(GameManager *gameManager);
	~Lion();

	void Display();
	void Update(const double& deltaTime);
private:
	bool legChange = false;
	bool tailChange = false;
	bool moveChange = true;
	void DrawLion();
	void DrawHead();
	void DrawBody();
	void DrawLeg();
	float leftLegAngle, moveStep, tailAngle;
	GameManager *gm;
	DrawCube *drawCube;
	void  DrawBox(float sx, float sy, float sz);
};