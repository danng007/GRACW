#include "SunLight.h"


SunLight::SunLight()
{
	ambient[0] = 0.4f;    // Set the ambient colour of the light
	ambient[1] = 0.4f;
	ambient[2] = 0.4f;
	ambient[3] = 1.f;

	diffuse[0] = 0.8f;    // Set the diffuse colour of the light
	diffuse[1] = 0.8f;
	diffuse[2] = 0.6f;
	diffuse[3] = 1.f;

	specular[0] = 1.f;   // Set the specular colour of the light
	specular[1] = 1.f;
	specular[2] = 1.f;
	specular[3] = 1.f;
}


SunLight::~SunLight()
{
}

void SunLight::Update(const double& deltaTime)
{
	// turn lighting on
	glEnable(GL_LIGHTING);


	// pass openGL the lighting model parameters for the Phong reflection model
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.05);

	float ldirection[] = { pos[0], pos[1], pos[2], 0.f };
	glLightfv(GL_LIGHT0, GL_POSITION, ldirection);

	// enable light 0
	glEnable(GL_LIGHT0);
}