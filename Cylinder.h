#ifndef CYLINDER_H
#define CYLINDER_H

#include "Shape.h"
#include "tess.h"

class Cylinder : public Shape {
public:

	void draw();
	void drawNormal();
};

#endif
