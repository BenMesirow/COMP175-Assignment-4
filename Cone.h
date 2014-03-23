#ifndef CONE_H
#define CONE_H

#include "Shape.h"
#include "tess.h"

class Cone : public Shape {
public:
	void draw();
	void drawNormal();
};

#endif
