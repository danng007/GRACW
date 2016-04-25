#pragma once
#include "DisplayableObject.h"
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include "DrawCube.h"
using namespace std;
class Tree :
	public DisplayableObject
{
public:
	Tree();
	~Tree();

	void Display();

private:
	DrawCube *drawCube;
	bool out = true;
	void setReplaceString(char flag, string str);
	int iter = 2;
	string init = "f";
	vector<string> change;
	vector<char> flags;
	float angle;
	string sequence;
	int texId;
	void Branch(float size);
	void Leaf();
	void LeafBranch();
	void GetSequence();
	void DrawBox(float sx, float sy, float sz);
};

