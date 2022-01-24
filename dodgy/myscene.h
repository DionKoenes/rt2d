/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef MYSCENE_H
#define MYSCENE_H

#include <rt2d/scene.h>
#include <vector>
#include "myentity.h"
#include "background.h"
#include "cube.h"

/// @brief The MyScene class is the Scene implementation.
class MyScene : public Scene
{
public:
	/// @brief Constructor
	MyScene();
	/// @brief Destructor
	virtual ~MyScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	virtual void updateCubes(float deltaTime);

private:

	void spawnCube(int xpos, int ypos);
	void spawnCubeRandom();
	/// @brief the rotating square in the middle of the screen
	MyEntity* myentity;
	Background* background;
	/// @brief a Timer to rotate the color every n seconds
	Timer spawntimer;

	std::vector<Cube*> cubes;
};

#endif /* SCENE00_H */
