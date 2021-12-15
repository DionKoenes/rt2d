/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "myscene.h"


MyScene::MyScene() : Scene()
{
	// start the timer.
	t.start();

	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.
	myentity = new MyEntity();
	myentity->position = Point2(SWIDTH/2, SHEIGHT/1.05);

	background = new Background();
	background->position = Point2(SWIDTH / 2, SHEIGHT / 2);

	cube = new Cube();
	cube->position = Point2(SWIDTH / 2, SHEIGHT / 2);

	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(background);
	this->addChild(myentity);
	this->addChild(cube);
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(myentity);
	this->removeChild(background);
	this->removeChild(cube);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete cube;
	delete myentity;
	delete background;
}

void MyScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	/* ###############################################################
	// Spacebar scales myentity
	// ###############################################################
	if (input()->getKeyDown(KeyCode::Space)) {
		myentity->scale = Point(0.5f, 0.5f);
	}
	if (input()->getKeyUp(KeyCode::Space)) {
		myentity->scale = Point(1.0f, 1.0f);
	}*/

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
	if (input()->getKey(KeyCode::S)) {
		myentity->position.y += myentity->ydSpeed * deltaTime;
	}

	/* ###############################################################
	// Rotate Color
	// ###############################################################
	if (t.seconds() > 0.0333f) {
		RGBAColor color = myentity->sprite()->color;
		myentity->sprite()->color = Color::rotate(color, 0.01f);
		t.start();
	}*/
}
