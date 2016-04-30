#pragma warning(disable:4996)
#pragma once
#include "DisplayableObject.h"
#include "Scene.h"
#include <sstream>
#include <fstream>
using namespace std;
class LoadModel : 
	public DisplayableObject
{
public:

	LoadModel(void);
	~LoadModel(void);
	void LoadOBJ(const char * path);
	void RenderModel();
	void Display();
	struct POINT3{
		double X;
		double Y;
		double Z;
	};
	struct Texture{
		double TU;
		double TV;
	};
	struct Normals{
		double NX;
		double NY;
		double NZ;
	};
	struct Face{
		int V[3];
		int T[3];
		int N[3];
	};
	struct Material{
		string filePath;
	};
	class PIC
	{
	public:
		vector<POINT3> V;
		vector<Texture>  VT;
		vector<Normals> VN;
		vector<Face> F;
		vector<Material> M;
		
	} m_pic;
	int faceCounter[1000], counter = -1, outCounter = 0;
	int textID;
	string filePaths[1000];
	string filePath;
	int textIDs[1000];
};