/*
 * Cube.cpp
 */
#include "Cube.h"

 void Cube::draw()  {
    glBegin(GL_TRIANGLES);

    Point p1, p2, p3, p4;

    for (float x = 0; x < m_segmentsX; ++x) {
        for (float y = 0; y < m_segmentsY; ++y) {

                    /* front face */
            p1 = Point(-0.5+x/m_segmentsX,-0.5+y/m_segmentsY,0.5);
            p2 = Point(-0.5+(x+1.0)/m_segmentsX,-0.5+y/m_segmentsY,0.5);
            p3 = Point(-0.5+x/m_segmentsX,-0.5+(y+1.0)/m_segmentsY,0.5);
            p4 = Point(-0.5+(x+1.0)/m_segmentsX,-0.5+(y+1.0)/m_segmentsY,0.5);

            glNormal3f(0,0,1);
            glVertex3f(p1[0], p1[1], p1[2]);
            glNormal3f(0,0,1);
            glVertex3f(p2[0], p2[1], p2[2]);
            glNormal3f(0,0,1);
            glVertex3f(p3[0], p3[1], p3[2]);

            glNormal3f(0,0,1);
            glVertex3f(p3[0], p3[1], p3[2]);
            glNormal3f(0,0,1);
            glVertex3f(p2[0], p2[1], p2[2]);
            glNormal3f(0,0,1);
            glVertex3f(p4[0], p4[1], p4[2]);

                    /* right face */
            p1 = Point(0.5,-0.5+y/m_segmentsY,0.5-x/m_segmentsX);
            p2 = Point(0.5,-0.5+y/m_segmentsY,0.5-(x+1.0)/m_segmentsX);
            p3 = Point(0.5,-0.5+(y+1.0)/m_segmentsY,0.5-x/m_segmentsX);
            p4 = Point(0.5,-0.5+(y+1.0)/m_segmentsY,0.5-(x+1.0)/m_segmentsX);

            glNormal3f(1, 0, 0);
            glVertex3f(p1[0], p1[1], p1[2]);
            glNormal3f(1, 0, 0);
            glVertex3f(p2[0], p2[1], p2[2]);
            glNormal3f(1, 0, 0);
            glVertex3f(p3[0], p3[1], p3[2]);

            glNormal3f(1, 0, 0);
            glVertex3f(p3[0], p3[1], p3[2]);
            glNormal3f(1, 0, 0);
            glVertex3f(p2[0], p2[1], p2[2]);
            glNormal3f(1, 0, 0);
            glVertex3f(p4[0], p4[1], p4[2]);

                    /* back face */
            p1 = Point(0.5-x/m_segmentsX,-0.5+y/m_segmentsY,-0.5);
            p2 = Point(0.5-(x+1.0)/m_segmentsX,-0.5+y/m_segmentsY,-0.5);
            p3 = Point(0.5-x/m_segmentsX,-0.5+(y+1.0)/m_segmentsY,-0.5);
            p4 = Point(0.5-(x+1.0)/m_segmentsX,-0.5+(y+1.0)/m_segmentsY,-0.5);

            glNormal3f(0, 0, -1);
            glVertex3f(p1[0], p1[1], p1[2]);
            glNormal3f(0, 0, -1);
            glVertex3f(p2[0], p2[1], p2[2]);
            glNormal3f(0, 0, -1);
            glVertex3f(p3[0], p3[1], p3[2]);

            glNormal3f(0, 0, -1);
            glVertex3f(p3[0], p3[1], p3[2]);
            glNormal3f(0, 0, -1);
            glVertex3f(p2[0], p2[1], p2[2]);
            glNormal3f(0, 0, -1);
            glVertex3f(p4[0], p4[1], p4[2]);                

                    /* left face */
            p1 = Point(-0.5,-0.5+y/m_segmentsY,-0.5+x/m_segmentsX);
            p2 = Point(-0.5,-0.5+y/m_segmentsY,-0.5+(x+1.0)/m_segmentsX);
            p3 = Point(-0.5,-0.5+(y+1.0)/m_segmentsY,-0.5+x/m_segmentsX);
            p4 = Point(-0.5,-0.5+(y+1.0)/m_segmentsY,-0.5+(x+1.0)/m_segmentsX);

            glNormal3f(-1, 0, 0);
            glVertex3f(p1[0], p1[1], p1[2]);
            glNormal3f(-1, 0, 0);
            glVertex3f(p2[0], p2[1], p2[2]);
            glNormal3f(-1, 0, 0);
            glVertex3f(p3[0], p3[1], p3[2]);

            glNormal3f(-1, 0, 0);
            glVertex3f(p3[0], p3[1], p3[2]);
            glNormal3f(-1, 0, 0);
            glVertex3f(p2[0], p2[1], p2[2]);
            glNormal3f(-1, 0, 0);
            glVertex3f(p4[0], p4[1], p4[2]);                

        }
        for (float z = 0; z < m_segmentsX; ++z) {

                    /* top face */
            p1 = Point(-0.5+x/m_segmentsX,0.5,0.5-z/m_segmentsX);
            p2 = Point(-0.5+x/m_segmentsX,0.5,0.5-(z+1.0)/m_segmentsX);
            p3 = Point(-0.5+(x+1.0)/m_segmentsX,0.5,0.5-z/m_segmentsX);
            p4 = Point(-0.5+(x+1.0)/m_segmentsX,0.5,0.5-(z+1.0)/m_segmentsX);

            glNormal3f(0, 1, 0);
            glVertex3f(p1[0], p1[1], p1[2]);
            glNormal3f(0, 1, 0);
            glVertex3f(p2[0], p2[1], p2[2]);
            glNormal3f(0, 1, 0);
            glVertex3f(p3[0], p3[1], p3[2]);

            glNormal3f(0, 1, 0);
            glVertex3f(p3[0], p3[1], p3[2]);
            glNormal3f(0, 1, 0);
            glVertex3f(p2[0], p2[1], p2[2]);
            glNormal3f(0, 1, 0);
            glVertex3f(p4[0], p4[1], p4[2]);                

                    /* bottom face */
            p1 = Point(-0.5+x/m_segmentsX,-0.5,-0.5+z/m_segmentsX);
            p2 = Point(-0.5+x/m_segmentsX,-0.5,-0.5+(z+1.0)/m_segmentsX);
            p3 = Point(-0.5+(x+1.0)/m_segmentsX,-0.5,-0.5+z/m_segmentsX);
            p4 = Point(-0.5+(x+1.0)/m_segmentsX,-0.5,-0.5+(z+1.0)/m_segmentsX);

            glNormal3f(0, -1, 0);
            glVertex3f(p1[0], p1[1], p1[2]);
            glNormal3f(0, -1, 0);
            glVertex3f(p2[0], p2[1], p2[2]);
            glNormal3f(0, -1, 0);
            glVertex3f(p3[0], p3[1], p3[2]);

            glNormal3f(0, -1, 0);
            glVertex3f(p3[0], p3[1], p3[2]);
            glNormal3f(0, -1, 0);
            glVertex3f(p2[0], p2[1], p2[2]);
            glNormal3f(0, -1, 0);
            glVertex3f(p4[0], p4[1], p4[2]);                

        }
    }

    glEnd();
}

void Cube::drawNormal()  {
    glBegin(GL_LINES);
    for (float x = 0; x < m_segmentsX; ++x) {
        for (float y = 0; y < m_segmentsY; ++y) {
                    /* front face */
            glVertex3f(-0.5+x/m_segmentsX,-0.5+y/m_segmentsY,0.5);
            glVertex3f(-0.5+x/m_segmentsX,-0.5+y/m_segmentsY,0.6);
                    /* right face */
            glVertex3f(0.5,-0.5+y/m_segmentsY,0.5-x/m_segmentsX);
            glVertex3f(0.6,-0.5+y/m_segmentsY,0.5-x/m_segmentsX);
                    /* back face */
            glVertex3f(0.5-x/m_segmentsX,-0.5+y/m_segmentsY,-0.5);
            glVertex3f(0.5-x/m_segmentsX,-0.5+y/m_segmentsY,-0.6);
                    /* left face */
            glVertex3f(-0.5,-0.5+y/m_segmentsY,-0.5+x/m_segmentsX);
            glVertex3f(-0.6,-0.5+y/m_segmentsY,-0.5+x/m_segmentsX);
        }
        for (float z = 0; z < m_segmentsX; ++z) {
                    /* top face */
            glVertex3f(-0.5+x/m_segmentsX,0.5,0.5-z/m_segmentsX);
            glVertex3f(-0.5+x/m_segmentsX,0.6,0.5-z/m_segmentsX);
                    /* bottom face */
            glVertex3f(-0.5+x/m_segmentsX,-0.5,-0.5+z/m_segmentsX);
            glVertex3f(-0.5+x/m_segmentsX,-0.6,-0.5+z/m_segmentsX);
        }
    }
    glEnd();
}


double Cube::Intersect(Point eyePointP, Vector rayV, Matrix transformMatrix) {

    Vector P = transformMatrix * Vector(eyePointP[0],eyePointP[1],eyePointP[2]);
    Vector d = transformMatrix * rayV;

    double min_t = 0;
    double t;
    Point isect;

    /* right face */
    t = (0.5 - P[0]) / d[0];
    isect = Point(P[0],P[1],P[2]) + t * d;
    if (isect[1] < 0.5 && isect[1] > -0.5 && 
        isect[2] < 0.5 && isect[2] > -0.5) {
        min_t = fmin(t, min_t);
    }

    /* top face */
    t = (0.5 - P[1]) / d[1];
    isect = Point(P[0],P[1],P[2]) + t * d;
    if (isect[0] < 0.5 && isect[0] > -0.5 && 
        isect[2] < 0.5 && isect[2] > -0.5) {
        min_t = fmin(t, min_t);
    }
    /* front face */
    t = (0.5 - P[2]) / d[2];
    isect = Point(P[0],P[1],P[2]) + t * d;
    if (isect[0] < 0.5 && isect[0] > -0.5 && 
        isect[1] < 0.5 && isect[1] > -0.5) {
        min_t = fmin(t, min_t);
    }

    /* left face */
    t = (-0.5 - P[0]) / d[0];
    isect = Point(P[0],P[1],P[2]) + t * d;
    if (isect[1] < 0.5 && isect[1] > -0.5 && 
        isect[2] < 0.5 && isect[2] > -0.5) {
        min_t = fmin(t, min_t);
    }

    /* bottom face */
    t = (-0.5 - P[1]) / d[1];
    isect = Point(P[0],P[1],P[2]) + t * d;
    if (isect[0] < 0.5 && isect[0] > -0.5 && 
        isect[2] < 0.5 && isect[2] > -0.5) {
        min_t = fmin(t, min_t);
    }
    /* back face */
    t = (-0.5 - P[2]) / d[2];
    isect = Point(P[0],P[1],P[2]) + t * d;
    if (isect[0] < 0.5 && isect[0] > -0.5 && 
        isect[1] < 0.5 && isect[1] > -0.5) {
        min_t = fmin(t, min_t);
    }
    return min_t;

}
Vector Cube::findIsectNormal(Point eyePoint, Vector ray, double dist) {
    Point isect = eyePoint + dist * ray;
    for (int i = 0; i < 3; ++i) {
        float v[3] = {0, 0, 0};
        if (isect[i] == 0.5) {
            v[i] = 1;
            return Vector(v[0],v[1],v[2]);
        } else if (isect[i] == -0.5) {
            v[i] = -1;
            return Vector(v[0],v[1],v[2]);
        }
    }
    return Vector();
}
