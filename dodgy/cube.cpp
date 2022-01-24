/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "cube.h"

Cube::Cube() : extraentity()
{
	this->addSprite("assets/Cube_Pink.tga");

	width = 64;
	height = 64;

	this->sprite()->size = Point2(width, height);



	ySpeed = 100;

}

Cube::~Cube()
{

}

void Cube::update(float deltaTime)
{
	position.y += ySpeed * deltaTime;
}
