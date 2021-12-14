/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "background.h"

Background::Background() : Canvas()
{
	this->addSprite("assets/background.tga");

}

Background::~Background()
{

}

void Background::update(float deltaTime)
{

	/* ###############################################################
	// Rotate
	// ###############################################################
	this->rotation.z += HALF_PI * deltaTime; // 90 deg/sec
	if (this->rotation.z > TWO_PI) {
		this->rotation.z -= TWO_PI;
	}*/
}
