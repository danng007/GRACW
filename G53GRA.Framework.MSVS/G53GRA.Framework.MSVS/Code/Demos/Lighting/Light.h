#pragma once
#include "DisplayableObject.h"
#include "Animation.h"

class Camera;

class Light :
	public DisplayableObject,
	public Animation
{
public:
	Light();
	~Light();

	void Display();	// If wanting to represent light with sphere (optional)
	void Update(const double& deltaTime);

private:
	double t;       // member variable to remember how long program has been running

	double radius;  // member variable for radius of rotation
	
	float ambient[4], diffuse[4], specular[4]; // reflectance model parameters of LIGHT

	float positionalLight;
};


