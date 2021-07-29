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
    QString objFilename = "../obj/african_head.obj";
    QString textureFilename = "../obj/african_head.tga";

    QString errMsg;

    Camera camera(CameraMode::Perspective);
    camera.setFov(M_PI / 6.0f);
    camera.setAspectRatio(1);
    camera.setPos({3, 0, 5});
    camera.setUp({0, 1, 0});

    Viewport viewport(&camera);
    viewport.setWidth(4096);
    viewport.setHight(4096);

    ModelGeometry geometry;
    QFile file(objFilename);
    if(!file.open(QFile::ReadOnly)){
        qDebug() << "File" << objFilename << "not found";
        return -1;
    }
    QTextStream stream(&file);
    if(!ObjReadingTools::readModelGeometry(stream, geometry, errMsg)){
        qDebug() << errMsg << '\n';
        return -1;
    }

    QImage texture;
    if(!texture.load(textureFilename)){
        qDebug() << "Fail to load" << textureFilename;
        return -1;
    }

    DrawableModel model;
    model.setGeometry(geometry);
    model.setTexture(texture);

    viewport.addObject(&model);
    viewport.render().save("res.jpg");

    return 0;
}
