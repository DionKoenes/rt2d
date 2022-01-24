/**
 * This class describes Collider behavior.
 *
 * Copyright 2019 Rik Teerling <rik@onandoffables.com>
 */

#ifndef COLLIDER_H
#define COLLIDER_H

#include <algorithm> // std::min + std::max
#include <rt2d/pointx.h> // Point2
#include "extraentity.h"

class Collider
{
public:

	// https://yal.cc/rectangle-circle-intersection-test/
	static bool circle2rectangle(const extraentity* circle, const extraentity* rect) {
		float mx = std::max(rect->position.x, std::min(circle->position.x, rect->position.x + rect->width));
		float my = std::max(rect->position.y, std::min(circle->position.y, rect->position.y + rect->height));
		float dx = circle->position.x - mx;
		float dy = circle->position.y - my;
		return (dx * dx + dy * dy) < (circle->radius * circle->radius);
	}

private:
	// Disallow creating an instance of this object
	Collider() {}
};

#endif /* COLLIDER_H */
