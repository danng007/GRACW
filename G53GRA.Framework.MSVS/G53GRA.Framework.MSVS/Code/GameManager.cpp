#include "GameManager.h"
using namespace std;
GameManager::GameManager()
{
	glEnable(GL_TEXTURE_2D);
	currentCamera = Scene::GetCamera();
}
GameManager::~GameManager()
{
	glDisable(GL_TEXTURE_2D);
}
void GameManager::Display()
{
	currentCamera->GetEyePosition(pos[0], pos[1], pos[2]);
	currentCamera->GetViewDirection(rotation[0], rotation[1], rotation[2]);
	pos[0] += rotation[0] * 200.0f;
	pos[2] += rotation[2] * 200.0f;
	
	if (gameState)
	{
		if (pos[0] >= 950.0f && pos[0] <= 1100.0f && pos[2] >= 1000.0f && pos[2] <= 1100.0f)
		{
			gameState = false;
			currentCamera->Reset();
			currentCamera->SetState(false);
		}
	}
	else
	{
		if (pos[0] >= 1950.0f && pos[0] <= 2050.0f && pos[2] >= 1950.0f && pos[2] <= 2050.0f)
		{
			gameState = true;
			currentCamera->Reset();
			currentCamera->SetState(true);
		}
	}

}

void GameManager::HandleKey(unsigned char key, int state, int x, int y)
{
	if (key == 't' && state == 0)
	{
		lightOn = !lightOn;
	}
}

void GameManager::Update(const double& deltaTime)
{

	if (lightIntensity > 1.0f)
	{
		lightChange = !lightChange;
		lightIntensity = 0.999f;
	}
	if (lightIntensity < 0.0f)
	{
		lightChange = !lightChange;
		lightIntensity = 0.001f;
	}

	if (lightChange)
	{
		lightIntensity += 0.1f * deltaTime;
	}
	else
	{
		lightIntensity -= 0.1f * deltaTime;
	}
	
}
