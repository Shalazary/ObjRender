#include <QCoreApplication>

#include "Viewport/viewport.h"
#include "Camera/camera.h"
#include "DrawableModel/drawablemodel.h"
#include "ObjReadingTools/objreadingtools.h"

#include <QImage>
#include <QDebug>
#include <QFile>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QString errMsg;

    Camera camera;
    Viewport viewport(&camera);
    viewport.setWidth(4096);
    viewport.setHight(4096);
    DrawableModel model;
    QFile file("/home/shalazary/Testovye_modeli/african_head.obj");
    file.open(QFile::ReadOnly);
    QTextStream stream(&file);
    ObjReadingTools::readModel(stream, model, errMsg);
    viewport.addModel(&model);
    viewport.render().save("res.jpg");
}
