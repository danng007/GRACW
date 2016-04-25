#include "MyScene.h"

#include "Triangle.h"
#include "Triforce.h"
#include "Planet.h"
#include "Planet2.h"
#include "Lamp.h"
#include "Floor.h"
#include "Teapot.h"
#include "Light.h"
#include "MultiLight.h"
#include "Room.h"
#include "SpotLight.h"
#include "TexturedCube.h"
#include "Link.h"
#include "Water.h"
#include "SunLight.h"

#include "FirstRoom.h"
#include "Snow.h"
#include "Tree.h"
#include "People.h"
MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{

}

void MyScene::Initialise()
{
	glClearColor(0.f, 0.f, 0.f, 1.f);

	// DEMO 1
	//Triangle *t = new Triangle();
    //AddObjectToScene(t);

	// DEMO 2 (Demos / Triforce)
    //Triforce *t = new Triforce();
    // AddObjectToScene(t);
    
	// DEMO 3 (Demos/Solar System)
    // create and add a new triangle to the scene
    //Planet *sun = new Planet(30.0f, 0.0f, 12.0f, 0.0f);
    //sun->SetColour(255, 255, 0); //yellow
    //
    //Planet *mars = new Planet(6.0f, 60.0f, 150.0f, 50.0f);
    //mars->SetColour(255, 0, 0); //red
    //
    //Planet2 *earth = new Planet2(15.0f, 135.0f, 100.0f, 20.0f, 6.0f, 30.0, 100.0f, 8.0f );
    //earth->SetColour(0, 0, 255); //earth blue, moon grey
    //
    //AddObjectToScene(sun);
    //AddObjectToScene(mars);
    //AddObjectToScene(earth);

	// DEMO 4 (Demos/Animated Lamp)
	// Create and add a new lamp to the scene
	//Lamp *l = new Lamp();
	//l->size(6.f);
	//AddObjectToScene(l);

	// DEMO 5
	// Show floor and triangle
	//Floor *f = new Floor();
	//Triangle *t = new Triangle();
	//f->size(100.f);
    //t->size(0.5f);
	//AddObjectToScene(f);
	//AddObjectToScene(t);
	
	// DEMO 6 (LIGHTING)
	// Show teapot and lighting
	//Floor *f = new Floor();
	//f->size(100.f);

	//Teapot *t = new Teapot();
	//t->size(100.f);

	//Light *l = new Light();
	//
	//AddObjectToScene(l);
	//AddObjectToScene(t);
	//AddObjectToScene(f);

	// DEMO 7 (Multilights)
	//Floor *f = new Floor();
	//f->size(100.f);

	//Teapot *t = new Teapot();
	//t->size(100.f);

	//MultiLight *l = new MultiLight();

	//AddObjectToScene(l);
	//AddObjectToScene(t);
	//AddObjectToScene(f);

	// DEMO 8 (Spotlight)
	//Room *r = new Room();
	//r->size(150.f);
	//AddObjectToScene(r);

	//SpotLight *s0 = new SpotLight(GL_LIGHT0, 1);
	//s0->position(0.f, 1.f, 0.f);
	//s0->SetAmbient(0.5f, 0.0f, 0.0f, 1.0f);
	//s0->SetDiffuse(0.9f, 0.0f, 0.0f, 1.0f);
	//s0->SetSpecular(1.0f, 0.5f, 0.5f, 1.0f);
	//s0->SetAttenuation(1.0f, 0.0f, 0.0f);
	//s0->SetSpotDirection(0.0f, 0.0f, -1.0f);
	//s0->SetSpotExponent(6.0f);
	//s0->SetSpotCutOff(80.0f);
	//AddObjectToScene(s0);

	//// add a green spotlight that rotates
	//SpotLight *s1 = new SpotLight(GL_LIGHT1, 2);
	//s1->position(0.0f, -10.0f, 0.f);
	//s1->SetAmbient(0.0f, 0.5f, 0.0f, 1.0f);
	//s1->SetDiffuse(0.0f, 0.9f, 0.0f, 1.0f);
	//s1->SetSpecular(0.5f, 1.0f, 0.5f, 1.0f);
	//s1->SetAttenuation(1.0f, 0.0f, 0.000004f);
	//s1->SetSpotDirection(-1.0f, 0.0f, 0.0f);
	//s1->SetSpotExponent(10.0f);
	//s1->SetSpotCutOff(60.0f);
	//AddObjectToScene(s1);

	//// add a blue spotlight that rotates
	//SpotLight *s2 = new SpotLight(GL_LIGHT2, 3);
	//s2->position(0.0f, -30.0f, 0.f);
	//s2->SetAmbient(0.0f, 0.0f, 0.5f, 1.0f);
	//s2->SetDiffuse(0.0f, 0.0f, 0.9f, 1.0f);
	//s2->SetSpecular(0.5f, 0.5f, 1.0f, 1.0f);
	//s2->SetAttenuation(0.5f, 0.0f, 0.0f);
	//s2->SetSpotDirection(1.0f, 0.0f, 0.0f);
	//s2->SetSpotExponent(80.0f);
	//s2->SetSpotCutOff(20.0f);
	//AddObjectToScene(s2);

	//// add a white spotlight that is stationary
	//SpotLight *s3 = new SpotLight(GL_LIGHT3, 0);
	//s3->position(0.0f, 0.0f, 0.f);
	//s3->SetAmbient(0.5f, 0.5f, 0.5f, 1.0f);
	//s3->SetDiffuse(0.9f, 0.9f, 0.9f, 1.0f);
	//s3->SetSpecular(1.0f, 1.0f, 1.0f, 1.0f);
	//s3->SetAttenuation(1.0f, 0.0f, 0.0f);
	//s3->SetSpotDirection(1.0f, 1.0f, -1.0f);
	//s3->SetSpotExponent(30.0f);
	//s3->SetSpotCutOff(75.0f);
	//AddObjectToScene(s3);

	//// add a light that starts yellow and slowly gets more and less green
	//SpotLight *s4 = new SpotLight(GL_LIGHT4, 4);
	//s4->position(0.0f, -20.0f, 0.f);
	//s4->SetAmbient(0.5f, 0.5f, 0.0f, 1.0f);
	//s4->SetDiffuse(0.4f, 0.4f, 0.0f, 1.0f);
	//s4->SetSpecular(1.0f, 1.0f, 1.0f, 1.0f);
	//s4->SetAttenuation(1.0f, 0.0f, 0.0f);
	//s4->SetSpotDirection(-1.0f, -1.0f, -1.0f);
	//s4->SetSpotExponent(30.0f);
	//s4->SetSpotCutOff(60.0f);
	//AddObjectToScene(s4);

	//// add a light that gets more and less blue and rotates on all axis
	//SpotLight *s5 = new SpotLight(GL_LIGHT5, 5);
	//s5->position(0.0f, -40.0f, 0.f);
	//s5->SetAmbient(0.1f, 0.5f, 0.1f, 1.0f);
	//s5->SetDiffuse(0.2f, 0.9f, 0.2f, 1.0f);
	//s5->SetSpecular(1.0f, 1.0f, 1.0f, 1.0f);
	//s5->SetAttenuation(1.0f, 0.0f, 0.0f);
	//s5->SetSpotDirection(1.0f, -1.0f, -1.0f);
	//s5->SetSpotExponent(20.0f);
	//s5->SetSpotCutOff(80.0f);
	//AddObjectToScene(s5);

//	// DEMO 9 (TEXTURED CUBE)
//#ifdef __APPLE__
//    TexturedCube *txc = new TexturedCube("./batmanlogo.bmp");
//#else
//	TexturedCube *txc = new TexturedCube("./Code/Demos/Texturing/batmanlogo.bmp");
//#endif
//	txc->size(200.f);
//	//AddObjectToScene(txc);
//
	// DEMO 10 (Animated Texturing)
//#ifdef __APPLE__
//    Link *link = new Link(10.f, 25.f, "./linkSpriteSheet.bmp");
//#else
	//Link *link = new Link(10.f, 25.f, "./Code/Demos/Texturing/linkSpriteSheet.bmp");
//#endif
//	link->position(0.f, -99.9f, -100.f);
//	link->size(10.f);
//
//#ifdef __APPLE__
//    Water *water = new Water(20, 20, "./water.bmp");
//#else
//	Water *water = new Water(20, 20, "./Code/Demos/Texturing/water.bmp");
//#endif
//    
//	water->position(0.f, -99.9f, 100.f);
//	water->size(400.f);
//
//	Floor *floor = new Floor();
//	floor->size(100);
//
//	SunLight *sl = new SunLight();
//	sl->direction(-1.f, 1.f, 1.f);
//
//	AddObjectToScene(floor);
//	AddObjectToScene(water);
//	AddObjectToScene(link);
//	AddObjectToScene(sl);
//
	FirstRoom *fr = new FirstRoom();
	AddObjectToScene(fr);

	Snow *snow = new Snow();
	AddObjectToScene(snow);

	//Tree *t = new Tree();
	//AddObjectToScene(t);

	People *p = new People();
	AddObjectToScene(p);
}

void MyScene::Projection()
{
	gluPerspective(60.0, (GLdouble)windowWidth / (GLdouble)windowHeight, 1.0, 100000.0);
}