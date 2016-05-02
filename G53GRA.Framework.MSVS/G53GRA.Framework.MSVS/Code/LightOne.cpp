#include "LightOne.h"


LightOne::LightOne(GameManager *gameManager)
{
	glEnable(GL_LIGHTING);
	
	gm = gameManager;
	// Get the camera
	currentCamera = Scene::GetCamera();

	// Initialise the lighting attributes
	position = new float[4]{ 0.f, 0.f, 0.f, 1.f };
	ambient = new float[4] {0.0, 0.0, 0.0, 1.0};
	diffuse = new float[4]{ 1.0, 1.0, 1.0, 1.0};
	specular = new float[4]{ 1.0, 1.0, 0.0, 1.0 };
	direction = new float[3]{ 0.0, 0.0, 0.0 };

	glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, specular);
	// Concentrated the light
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 0.1f);
	// Define the Range
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 22.5f);



	amPosition = new float[4]{ 1000.0f, 0.f, 0.f, 0.f };
	amAmbient = new float[4] {0.1f, 0.0f, 0.2f, 1.0};
	amDiffuse = new float[4]{ 0.4f, 0.4f, 0.7f, 1.0};
	amSpecular = new float[4]{ 0.1f, 0.1f, 0.4f, 1.0 };

	glLightfv(GL_LIGHT2, GL_POSITION, amPosition);
	glLightfv(GL_LIGHT2, GL_AMBIENT, amAmbient);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, amDiffuse);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, amSpecular);

}


LightOne::~LightOne()
{
	delete[] position;
	delete[] ambient;
	delete[] specular;
	delete[] diffuse;
	delete[] direction;

	delete[] amPosition;
	delete[] amAmbient;
	delete[] amSpecular;
	delete[] amDiffuse;
	
}

void LightOne::Display() {


}

void LightOne::Update(const double& deltaTime) {
	if (gm->lightOn)
	{
		glEnable(GL_LIGHT1);
	}
	else
	{
		glDisable(GL_LIGHT1);
	}
	

	if (!gm->gameState)
	{
		glEnable(GL_LIGHT2);
		// update character's spot light postion and direction
		currentCamera->GetViewDirection(direction[0], direction[1], direction[2]);
		currentCamera->GetEyePosition(position[0], position[1], position[2]);
		position[0] += direction[0] * 200.0f;
		position[2] += direction[2] * 200.0f;

		glLightfv(GL_LIGHT1, GL_POSITION, position);
		glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, direction);
	}
	else
	{
		glDisable(GL_LIGHT2);
	}
	
}