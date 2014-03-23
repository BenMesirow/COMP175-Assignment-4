#ifndef TORUS_H
#define TORUS_H

#include "Shape.h"
#include "tess.h"

class Torus : public Shape {
public:
	Torus();
	Torus(float R, float r);
	void draw();
	void drawNormal();

private:
	float r;
	float R;
};

#endif
