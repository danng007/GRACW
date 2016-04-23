#pragma once

#include "DisplayableObject.h"
#include "Animation.h"
#include "Input.h"

class Camera;

class MultiLight :
	public DisplayableObject,
	public Animation,
	public Input
{
public:
	MultiLight();
	~MultiLight();

	void Display();
	void Update(const double& deltaTime);
	void HandleKey(unsigned char key, int state, int x, int y);

private:

	double t;
	double radius;

	// member variables for the reflectance model parameters for each of the light sources
	float position0[4], ambient0[4], diffuse0[4], specular0[4];
	float position1[4], ambient1[4], diffuse1[4], specular1[4];
	float position2[4], ambient2[4], diffuse2[4], specular2[4];
	float position3[4], ambient3[4], diffuse3[4], specular3[4];

	bool show0, show1, show2, show3;
};

