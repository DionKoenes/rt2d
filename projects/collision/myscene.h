/**
 * This class describes MyScene behavior.
 *
 * Copyright 2019 Rik Teerling <rik@onandoffables.com>
 */

#ifndef MYSCENE_H
#define MYSCENE_H

#include <rt2d/scene.h>
#include "cube.h"
#include "shape.h"


class MyScene : public Scene
{
public:
	MyScene();
	virtual ~MyScene();

	virtual void update(float deltaTime);
	virtual void updateCubes(float deltaTime);

private:
	Shape* square1;
	Shape* square2;
	Shape* circle1;
	Shape* circle2;
};

Timer t;
std::vector<Cube*> cubes;
#endif /* MYSCENE_H */
