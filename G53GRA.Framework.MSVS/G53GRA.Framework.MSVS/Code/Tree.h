#pragma once
#include "DisplayableObject.h"
#include <cmath>
#include <string>
#include <vector>
using namespace std;
class Tree :
	public DisplayableObject
{
public:
	Tree();
	~Tree();

	void Display();

private:
	void addReplaceString(char flag, string str);
	void setReplaceString(char flag, string str);
	int iter = 2;
	string init = "f";
	vector<string> change;
	vector<char> flags;
	float angle;
	string sequence;
	int texId;
	void Branch();
	void GetSequence();
};

