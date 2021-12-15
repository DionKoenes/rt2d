/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef CUBE_H
#define CUBE_H

#include <entity.h>

/// @brief The MyEntity class is the Entity implementation.
class Cube : public Entity
{
public:
	/// @brief Constructor
	Cube();
	/// @brief Destructor
	virtual ~Cube();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
};

#endif /* CUBE_H */
