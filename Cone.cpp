/*
 * Cone.cpp
 */
#include "Cone.h"

void Cone::draw() {
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
    }
    for (float y = 0; y < m_segmentsY; ++y) {
        float lowerY = 0.5 - y / m_segmentsY;
        float upperY = 0.5 - (y+1.0) / m_segmentsY;
        float lowerR = transverseSliceRadiusCone(0.5,1.0,lowerY+0.5);
        float upperR = transverseSliceRadiusCone(0.5,1.0,upperY+0.5);
        for (int i = 0; i < m_segmentsX; ++i) {

            float lowerXL = ithSliceXComponent(lowerR,i,m_segmentsX);
            float upperXL = ithSliceXComponent(lowerR,i+1,m_segmentsX);
            float lowerZL = ithSliceZComponent(lowerR,i,m_segmentsX);
            float upperZL = ithSliceZComponent(lowerR,i+1,m_segmentsX);

            float lowerXU = ithSliceXComponent(upperR,i,m_segmentsX);
            float upperXU = ithSliceXComponent(upperR,i+1,m_segmentsX);
            float lowerZU = ithSliceZComponent(upperR,i,m_segmentsX);
            float upperZU = ithSliceZComponent(upperR,i+1,m_segmentsX);

            Vector norm((ithSliceXComponent(0.5,i,m_segmentsX) + 
                ithSliceXComponent(0.5,i+1,m_segmentsX))/2,
            0.25,
            (ithSliceZComponent(0.5,i,m_segmentsX) +
                ithSliceZComponent(0.5,i+1,m_segmentsX))/2);
            norm.normalize();

            glNormal3f(norm[0],norm[1],norm[2]);
            glVertex3f(lowerXL,lowerY,lowerZL);
            glNormal3f(norm[0],norm[1],norm[2]);
            glVertex3f(upperXL,lowerY,upperZL);
            glNormal3f(norm[0],norm[1],norm[2]);
            glVertex3f(lowerXU,upperY,lowerZU);

            glNormal3f(norm[0],norm[1],norm[2]);
            glVertex3f(lowerXU,upperY,lowerZU);
            glNormal3f(norm[0],norm[1],norm[2]);
            glVertex3f(upperXL,lowerY,upperZL);
            glNormal3f(norm[0],norm[1],norm[2]);
            glVertex3f(upperXU,upperY,upperZU);
        }
    }
    glEnd();
}

void Cone::drawNormal()  {
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
    }
    for (float y = 0; y < m_segmentsY; ++y) {
        float lowerY = 0.5 - y / m_segmentsY;
        float upperY = 0.5 - (y+1.0) / m_segmentsY;
        float lowerR = transverseSliceRadiusCone(0.5,1.0,lowerY+0.5);
        float upperR = transverseSliceRadiusCone(0.5,1.0,upperY+0.5);
        for (int i = 0; i < m_segmentsX; ++i) {

            float lowerXL = ithSliceXComponent(lowerR,i,m_segmentsX);
            float upperXL = ithSliceXComponent(lowerR,i+1,m_segmentsX);
            float lowerZL = ithSliceZComponent(lowerR,i,m_segmentsX);
            float upperZL = ithSliceZComponent(lowerR,i+1,m_segmentsX);

            float lowerXU = ithSliceXComponent(upperR,i,m_segmentsX);
            float upperXU = ithSliceXComponent(upperR,i+1,m_segmentsX);
            float lowerZU = ithSliceZComponent(upperR,i,m_segmentsX);
            float upperZU = ithSliceZComponent(upperR,i+1,m_segmentsX);

            Vector norm((ithSliceXComponent(0.5,i,m_segmentsX) + 
                ithSliceXComponent(0.5,i+1,m_segmentsX))/2,
            0.25,
            (ithSliceZComponent(0.5,i,m_segmentsX) +
                ithSliceZComponent(0.5,i+1,m_segmentsX))/2);
            norm.normalize();

            glNormal3f(norm[0],norm[1],norm[2]);
            glVertex3f(lowerXL,lowerY,lowerZL);
            glVertex3f(upperXL,lowerY,upperZL);
            glVertex3f(lowerXU,upperY,lowerZU);

            glNormal3f(norm[0],norm[1],norm[2]);
            glVertex3f(lowerXU,upperY,lowerZU);
            glVertex3f(upperXL,lowerY,upperZL);
            glVertex3f(upperXU,upperY,upperZU);
        }
    }
    glEnd();
}

double Cone::Intersect(Point eyePointP, Vector rayV, Matrix transformMatrix) {
    return 0;
}
Vector Cone::findIsectNormal(Point eyePoint, Vector ray, double dist) {
    return Vector();
}
