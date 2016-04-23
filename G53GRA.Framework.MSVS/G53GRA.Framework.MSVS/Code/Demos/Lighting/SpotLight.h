#pragma once

#include "DisplayableObject.h"
#include "Animation.h"

class SpotLight :
	public DisplayableObject,
	public Animation
{
public:
	SpotLight(GLenum lightNum, int specialLightFlag);
	~SpotLight();
	
	void SetAmbient(float r, float g, float b, float a);
	void SetDiffuse(float r, float g, float b, float a);
	void SetSpecular(float r, float g, float b, float a);
	void SetAttenuation(float constant, float linear, float quadratic);
	void SetSpotDirection(float x, float y, float z);
	void SetSpotExponent(float e);
	void SetSpotCutOff(float d);

	void Display();
	void Update(const double& deltaTime);

private:

	GLenum lightNum;

	float ambient[4];
	float diffuse[4];
	float specular[4];
	float attenuation[3];
	float spotDir[4];
	float spotExponent;
	float spotCutOff;

	int flag, pmFlag;
};
