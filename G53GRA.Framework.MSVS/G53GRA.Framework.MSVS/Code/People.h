#pragma once
#include "DisplayableObject.h"
#include "DrawCube.h"
#include "Animation.h"
#include "GameManager.h"

class People :
	public DisplayableObject,
	public Animation
{
public:
	People(GameManager *gameManager);
	~People();
	float positions[3];
	void Display();
	void DrawBox(GLfloat size);
	void Update(const double& deltaTime);
private:
	GameManager *gm;
	float* lightPosition;
	float* ambient;
	float* diffuse;
	float* specular;
	float* direction;
	bool oldState = true;
	
	bool armChange = true;
	bool legChange = true;
	void DrawHead();
	void DrawBody();
	void DrawPeople();
	void DrawArm(bool leftArm);
	void DrawLeg(bool leftLeg);
	float armAngle, legAngle, leftArmAngle;
	Camera * currentCamera;
	DrawCube *drawCube;
	void DrawBox(float sx, float sy, float sz);
	int texId;
	float rotateX, rotateZ;
	float XTranslate, ZTranslate, depth;
	float cameraRX, cameraRY, cameraRZ;

};

