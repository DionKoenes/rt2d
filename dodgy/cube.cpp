/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "cube.h"

Cube::Cube() : Entity()
{
	this->addSprite("assets/Cube_Pink.tga");

}

Cube::~Cube()
{

}

void Cube::update(float deltaTime)
{

	/* ###############################################################
	// Rotate
	// ###############################################################
	this->rotation.z += HALF_PI * deltaTime; // 90 deg/sec
	if (this->rotation.z > TWO_PI) {
		this->rotation.z -= TWO_PI;
	}*/
}
