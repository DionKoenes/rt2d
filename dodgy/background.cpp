/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "myentity.h"

MyEntity::MyEntity() : Entity()
{
	this->addSprite("assets/dodgy.tga");

	scale.y = -0.40;
	scale.x = 0.40;

	xSpeed = 750;
	ySpeed = 500;
	ydSpeed = 250;
}

MyEntity::~MyEntity()
{

}

void MyEntity::update(float deltaTime)
{
	// ############################################################ //
	// BorderCheck													//
	// ############################################################ //
	if (this->position.x >= 1228) {
		position.x = 1228;
	}
	if (this->position.x <= 52) {
		position.x = 52;
	}
	if (this->position.y >= 695) {
		position.y = 695;
	}
	if (this->position.y <= 38) {
		position.y = 38;
	}
	/* ###############################################################
	// Rotate
	// ###############################################################
	this->rotation.z += HALF_PI * deltaTime; // 90 deg/sec
	if (this->rotation.z > TWO_PI) {
		this->rotation.z -= TWO_PI;
	}*/
}
