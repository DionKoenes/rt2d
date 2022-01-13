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
	t.start();

	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.
	myentity = new MyEntity();
	myentity->position = Point2(SWIDTH/2, SHEIGHT/1.05);

	myentity->position = Point2(400, 200);

	Line c1;
	c1.createCircle(64, 16);
	myentity->addLine(&c1);
	this->addChild(myentity);

	Line s2;
	s2.addPoint(-128, -60);
	s2.addPoint(128, -60);
	s2.addPoint(128, 90);
	s2.addPoint(-128, 90);
	s2.addPoint(-128, -60);
	myentity->addLine(&s2);
	this->addChild(myentity);

	background = new Background();
	background->position = Point2(SWIDTH / 2, SHEIGHT / 2);

	cube = new Cube();
	cube->position = Point2(SWIDTH / 2, SHEIGHT / 2);

	Line s1;
	s1.addPoint(-128, -128);
	s1.addPoint(128, -128);
	s1.addPoint(128, 128);
	s1.addPoint(-128, 128);
	s1.addPoint(-128, -128);
	cube->addLine(&s1);
	this->addChild(cube);

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

	Rectangle rect1 = Rectangle(cube->position.x, cube->position.y, 128*cube->scale.x, 128*cube->scale.y);
	Rectangle rect2 = Rectangle(myentity->position.x, myentity->position.y, 200*myentity->scale.x, -200*myentity->scale.y);

	Circle circ1 = Circle(myentity->position.x, myentity->position.y, 64*myentity->scale.y);

	if (Collider::rectangle2rectangle(rect1, rect2)) {
		cube->line()->color = RED;
		myentity->line()->color = RED;
	}
	else {
		cube->line()->color = GREEN;
		myentity->line()->color = GREEN;
	}

	if (Collider::circle2rectangle(circ1, rect1)) {
		myentity->line()->color = RED;
		cube->line()->color = RED;
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
