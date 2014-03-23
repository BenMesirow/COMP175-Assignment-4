
#ifndef SHAPE_H
#define SHAPE_H

#include <GL/glui.h>
#include "Algebra.h"

class Shape {
public:

	void setSegments(int x, int y);

	virtual void draw() {};
	virtual void drawNormal() {};

protected:
	void normalizeNormal (float x, float y, float z);
	void normalizeNormal (Vector v);

	int m_segmentsX, m_segmentsY;
};

#endif
