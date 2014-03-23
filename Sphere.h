#ifndef SPHERE_H
#define SPHERE_H

#include "Shape.h"
#include "tess.h"

class Sphere : public Shape {
public:
	void draw();
	void drawNormal();
};

#endif
