/*
 * Cylinder.cpp
 */

#include "Cylinder.h"

void Cylinder::draw() {
    glBegin(GL_TRIANGLES);      

    for (int i = 0; i < m_segmentsX; ++i) {

        float lowerX = ithSliceXComponent(0.5,i,m_segmentsX);
        float upperX = ithSliceXComponent(0.5,i+1,m_segmentsX);
        float lowerZ = ithSliceZComponent(0.5,i,m_segmentsX);
        float upperZ = ithSliceZComponent(0.5,i+1,m_segmentsX);

            /* bottom base */
        glNormal3f(0, -1, 0);
        glVertex3f(0.0, -0.5, 0.0);
        glNormal3f(0, -1, 0);
        glVertex3f(upperX,-0.5,upperZ);
        glNormal3f(0, -1, 0);
        glVertex3f(lowerX,-0.5,lowerZ);

        for (float y = 0.0; y < m_segmentsY; ++y) {

            float lowerY = -0.5 + y / m_segmentsY;
            float upperY = -0.5 + (y + 1.0) / m_segmentsY; 

            Vector norm((lowerX+upperX)/2, 0, (lowerZ+upperZ)/2);
            norm.normalize();

            glNormal3f(norm[0],norm[1],norm[2]);
            glVertex3f(lowerX,lowerY,lowerZ);
            glNormal3f(norm[0],norm[1],norm[2]);
            glVertex3f(upperX,lowerY,upperZ);
            glNormal3f(norm[0],norm[1],norm[2]);
            glVertex3f(lowerX,upperY,lowerZ);

            glNormal3f(norm[0],norm[1],norm[2]);
            glVertex3f(lowerX,upperY,lowerZ);
            glNormal3f(norm[0],norm[1],norm[2]);
            glVertex3f(upperX,lowerY,upperZ);
            glNormal3f(norm[0],norm[1],norm[2]);
            glVertex3f(upperX,upperY,upperZ);
        }           

            /* top base */
        glNormal3f(0, 1, 0);
        glVertex3f(0.0, 0.5, 0.0);
        glNormal3f(0, 1, 0);
        glVertex3f(lowerX,0.5,lowerZ);
        glNormal3f(0, 1, 0);
        glVertex3f(upperX,0.5,upperZ);
    }
    glEnd();
}

void Cylinder::drawNormal()  {
    glBegin(GL_TRIANGLES);      

    for (int i = 0; i < m_segmentsX; ++i) {

        float lowerX = ithSliceXComponent(0.5,i,m_segmentsX);
        float upperX = ithSliceXComponent(0.5,i+1,m_segmentsX);
        float lowerZ = ithSliceZComponent(0.5,i,m_segmentsX);
        float upperZ = ithSliceZComponent(0.5,i+1,m_segmentsX);

            /* bottom base */
        glNormal3f(0, -1, 0);
        glVertex3f(0.0, -0.5, 0.0);
        glVertex3f(upperX,-0.5,upperZ);
        glVertex3f(lowerX,-0.5,lowerZ);

        for (float y = 0.0; y < m_segmentsY; ++y) {

            float lowerY = -0.5 + y / m_segmentsY;
            float upperY = -0.5 + (y + 1.0) / m_segmentsY; 

            Vector norm((lowerX+upperX)/2, 0, (lowerZ+upperZ)/2);
            norm.normalize();

            glNormal3f(norm[0],norm[1],norm[2]);
            glVertex3f(lowerX,lowerY,lowerZ);
            glVertex3f(upperX,lowerY,upperZ);
            glVertex3f(lowerX,upperY,lowerZ);

            glNormal3f(norm[0],norm[1],norm[2]);
            glVertex3f(lowerX,upperY,lowerZ);
            glVertex3f(upperX,lowerY,upperZ);
            glVertex3f(upperX,upperY,upperZ);
        }           

            /* top base */
        glNormal3f(0, 1, 0);
        glVertex3f(0.0, 0.5, 0.0);
        glVertex3f(lowerX,0.5,lowerZ);
        glVertex3f(upperX,0.5,upperZ);
    }
    glEnd();
}

double Cylinder::Intersect(Point eyePointP, Vector rayV, Matrix transformMatrix) {
    return 0;
}
Vector Cylinder::findIsectNormal(Point eyePoint, Vector ray, double dist) {
    return Vector();
}
