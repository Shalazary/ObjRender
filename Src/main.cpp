#include <QCoreApplication>

#include "Viewport/viewport.h"
#include "Camera/camera.h"
#include "DrawableModel/drawablemodel.h"
#include "ObjReadingTools/objreadingtools.h"
#include "ModelGeometry/ModelGeometry/modelgeometry.h"

#include <QImage>
#include <QtDebug>
#include <QFile>
#include <QTextStream>
#include <QVector3D>

int main(int argc, char *argv[])
{
    QString errMsg;

    Camera camera(CameraMode::Orthographic);
    camera.setFov(M_PI / 6.0f);
    camera.setAspectRatio(1);
    camera.setPos({0, 0, 5});
    camera.setUp({0, 1, 0});

    Viewport viewport(&camera);
    viewport.setWidth(4096);
    viewport.setHight(4096);

    ModelGeometry geometry;
    QFile file("../obj/t1.obj");
    if(!file.open(QFile::ReadOnly)){
        qDebug() << "File" << file.fileName() << "not found";
        return -1;
    }
    QTextStream stream(&file);
    if(!ObjReadingTools::readModelGeometry(stream, geometry, errMsg)){
        qDebug() << errMsg << '\n';
        return -1;
    }

    DrawableModel model;
    model.setGeometry(geometry);

    viewport.addModel(&model);
    viewport.render().save("res.jpg");

    return 0;
}
