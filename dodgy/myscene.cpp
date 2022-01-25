/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "myscene.h"
#include "collider.h"


MyScene::MyScene() : Scene()
{
	// start the timer.
	spawntimer.start();
	scoretimer.start();
	srand(time(NULL));

	background = new Background();
	background->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	this->addChild(background);

	scoretext = new Text();
	scoretext->position.x = 50;
	scoretext->position.y = 75;
	score = 0;
	this->addChild(scoretext);

	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.
	myentity = new MyEntity();
	myentity->position = Point2(SWIDTH/2, SHEIGHT/1.05);

	myentity->position = Point2(400, 200);

	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(myentity);

}

void MyScene::spawnCubeRandom()
{
	int max = SWIDTH - 32;
	int min = 0 + 32;
	int random = rand() % (max - min) + min;

	if (spawntimer.seconds() >=  0.50)
	{
		spawnCube(random, 0 - 32);
		spawntimer.start();
	}
}

void MyScene::spawnCube(int xpos, int ypos)
{
	Cube* cube = new Cube();
	cube->position = Point2(xpos, ypos);
	cubes.push_back(cube);
	this->addChild(cube);
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(myentity);
	this->removeChild(background);
	this->removeChild(scoretext);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete myentity;
	delete background;
	delete scoretext;

	int sizeCubes = cubes.size();
	for (int i = 0; i < sizeCubes; i++)
	{
		this->removeChild(cubes[i]);
		delete cubes[i];
	}

}

void MyScene::updateCubes(float deltaTime)
{
	for (int i = cubes.size() - 1; i >= 0; i--) { // backwards!!!
		if (cubes[i]->position.y > SHEIGHT) {
			removeChild(cubes[i]);
			delete cubes[i]; // delete from the heap first
			cubes.erase(cubes.begin() + i); // then, remove from the list
		}
	}
}


void MyScene::update(float deltaTime)
{
	if (scoretimer.seconds() >= 0.1)
	{
		score += 2;
	}

	spawnCubeRandom();
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	int sizeCubes = cubes.size();
	for (int i = 0; i < sizeCubes; i++)
	{
		if (Collider::circle2rectangle(myentity, cubes[i])) {
			this->stop();
		}
	}


	updateCubes(deltaTime);

	//###############################################################
	// WASD Keys Movement Up-Left-Down-Right
	// ###############################################################
	if (input()->getKey(KeyCode::A)) {
		myentity->position.x -= myentity->xSpeed * deltaTime;
	}
	if (input()->getKey(KeyCode::D)) {
		myentity->position.x += myentity->xSpeed * deltaTime;
	}
	if (input()->getKey(KeyCode::W)) {
		myentity->position.y -= myentity->ySpeed * deltaTime;
	}
	{
		myentity->position.y += myentity->ydSpeed * deltaTime;
	}

	std::string st = "Score: ";
	st += std::to_string(score);
	scoretext->message(st);
}
