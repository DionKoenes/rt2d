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
	if (this->position.x >= SWIDTH - this->sprite()->width() /5 ) {
		position.x = SWIDTH - this->sprite()->width() /5;
	}
	if (this->position.x <= 0 + this->sprite()->width() /5 ) {
		position.x = 0 + this->sprite()->width() /5 ;
	}
	if (this->position.y >= SHEIGHT - this->sprite()->height() /7.25) {
		position.y = SHEIGHT - this->sprite()->height() /7.25;
	}
	if (this->position.y <= 0 + this->sprite()->height() /7.25) {
		position.y = 0 + this->sprite()->height() /7.25;
	}
	/* ###############################################################
	// Rotate
	// ###############################################################
	this->rotation.z += HALF_PI * deltaTime; // 90 deg/sec
	if (this->rotation.z > TWO_PI) {
		this->rotation.z -= TWO_PI;
	}*/
}
