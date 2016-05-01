#pragma once

#include "Scene.h"
#include "GameManager.h";
class MyScene :
	public Scene
{
public:
	MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight);
	~MyScene(){};
	GameManager *gm;
private:

	void Initialise();
	void Projection();

};