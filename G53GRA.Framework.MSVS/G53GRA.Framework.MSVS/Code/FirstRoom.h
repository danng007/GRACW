#pragma once

#include "DisplayableObject.h"
#include "Input.h"
#include <iostream>
#include <fstream>
#include "ClotheseCase.h"
#include "DrawCube.h"
#include "Castle.h"
#include "Table.h"
using namespace std;

class FirstRoom :
	public DisplayableObject,
	public Input
{
public:
	FirstRoom();
	~FirstRoom();

	void Display();
	//void Update(const double& deltaTime);
	void ReadFile();

private:
	ClotheseCase *clotheseCase;
	Castle *castle;
	Table *table;
	DrawCube *drawCube;
	int mapWidth, mapHeight;
	char room[100][100];
	ifstream myfile;
	string fileString = "./file.txt";
	float xrot, yrot, zrot;
	float scale;
	void DrawSingleFloor(int x, int z);
	void FirstRoom::DrawMapCube(int x, int z ,float y, float wallHeight,  float length);
	
};

