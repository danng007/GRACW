#pragma once
#include "DisplayableObject.h"
#include "DrawCube.h"
#include "Animation.h"
class People :
	public DisplayableObject,
	public Animation
{
public:
	People();
	~People();
	float positions[3];
	void Display();
	void DrawBox(GLfloat size);
	void Update(const double& deltaTime);
private:
	bool armChange = true;
	bool legChange = true;
	void DrawHead();
	void DrawNeck(float size, float height);
	void DrawBody();
	void DrawPeople();
	void DrawArm(bool leftArm);
	void DrawLeg(bool leftLeg);
	float armAngle, legAngle, handAngle, footAngle;
	Camera * currentCamera;
	DrawCube *drawCube;
	void DrawBox(float sx, float sy, float sz);
	int texId;


};

