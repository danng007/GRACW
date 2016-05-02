#pragma once

#include "DisplayableObject.h"
#include "Input.h"
#include <iostream>
#include <fstream>
#include "ClotheseCase.h"
#include "DrawCube.h"
#include "Table.h"
#include "GameManager.h"
#include "Castle.h"
#include "SkyBox.h"
#include "LoadModel.h"
using namespace std;

class FirstRoom :
	public DisplayableObject,
	public Input
{
public:
	FirstRoom(GameManager *gameManager);
	~FirstRoom();

	void Display();
	//void Update(const double& deltaTime);
	void ReadFile();
	
private:
	
	Castle *castle;
	SkyBox *sky;
	ClotheseCase *clotheseCase;
	Table *table;
	DrawCube *drawCube;
	int mapWidth, mapHeight;
	char room[100][100];
	ifstream myfile;
	string fileString = "./file.txt";
	float xrot, yrot, zrot;
	float scale;
	GameManager *gm;
	void BindTexture();
	int floorID, wallID, ceillingID, wallpaperID, doorID, windowID;
	void DrawBox(float sx, float sy, float sz);
	LoadModel bed;
};

