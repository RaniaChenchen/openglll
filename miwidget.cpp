#include "miwidget.h"
#include <QOpenGLFunctions>
#include <QMatrix4x4>
#include <cmath>

miWidget::miWidget(QWidget *parent) : QOpenGLWidget(parent)
{
}

void miWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glEnable(GL_DEPTH_TEST); // Active la profondeur
}

void miWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -1.0, 1.0, 2.0, 10.0);  // Perspective
    glMatrixMode(GL_MODELVIEW);
}

void miWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Positionner la caméra
    glTranslatef(0.0, 0.0, -5.0); // Déplacer la scène pour mieux la voir

    // Appliquer les rotations
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    glRotatef(rotate_z, 0.0, 0.0, 1.0);

    // Dessiner l'étoile 3D
    drawStar();

    // Actualiser le rendu
    glFlush();
    this->makeCurrent();
}

void miWidget::drawStar()
{
    glBegin(GL_TRIANGLES);
    // Dessiner les triangles formant l'étoile
    for (int i = 0; i < 5; ++i) {
        double angle = 2 * M_PI * i / 5;
        double nextAngle = 2 * M_PI * (i + 1) / 5;

        glColor3f(1.0, 0.0, 0.0);  // Rouge
        glVertex3f(0.0f, 0.0f, 0.0f);  // Centre de l'étoile

        glColor3f(0.0, 1.0, 0.0);  // Vert
        glVertex3f(cos(angle) * 1.0, sin(angle) * 1.0, 0.0f);  // Pointe 1

        glColor3f(0.0, 0.0, 1.0);  // Bleu
        glVertex3f(cos(nextAngle) * 1.0, sin(nextAngle) * 1.0, 0.0f);  // Pointe 2
    }
    glEnd();
}
