#ifndef MIWIDGET_H
#define MIWIDGET_H
#include <QOpenGLFramebufferObject>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class miWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
public:
    explicit miWidget(QWidget *parent = 0);
protected:
    void initializeGL() Q_DECL_OVERRIDE;
    void resizeGL(int w, int h) Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
    void graficarEtoile();

public:
    double rotate_x = 0;
    double rotate_y = 0;
    double rotate_z = 0;

private:
    void drawStar();
};

#endif // MIWIDGET_H
