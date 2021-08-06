#include <QCoreApplication>

#include "Viewport/viewport.h"
#include "Camera/camera.h"
#include "DrawableModel/drawablemodel.h"
#include "ObjReadingTools/objreadingtools.h"
#include "ModelGeometry/ModelGeometry/modelgeometry.h"
#include "RenderTools/render_tools.h"

#include <QImage>
#include <QtDebug>
#include <QFile>
#include <QTextStream>

int main()
{
    QString objFilename = "../obj/NeutralWrapped.obj";
    QString textureFilename = "../obj/NeutralWrapped.jpg";

    QString errMsg;
    Camera camera(CameraMode::Perspective);
    camera.setNear(1);
    camera.setFar(1000);
    camera.setFov(35.0f);
    camera.setAspectRatio(1);
    camera.setOrigin(0, 0, 102.4254379272461);
    camera.setRotation(0.8811194896697998, -0.27781587839126587, 0.3649716377258301, 0.11507517099380493);
    camera.setTarget(0, 0, 0);

    Viewport viewport(&camera);
    viewport.setWidth(4096);
    viewport.setHight(4096);
    viewport.setBackgroundColor(Qt::black);

    ModelGeometry geometry;
    QFile file(objFilename);
    if(!file.open(QFile::ReadOnly)){
        qDebug() << "Fail to load obj" << objFilename << "not found";
        return -1;
    }
    QTextStream stream(&file);
    if(!ObjReadingTools::readModelGeometry(stream, geometry, errMsg)){
        qDebug() << errMsg << '\n';
        return -1;
    }

    QImage texture;
    if(!texture.load(textureFilename)){
        qDebug() << "Fail to load texture" << textureFilename;
        return -1;
    }

    DrawableModel model;
    model.setGeometry(geometry);
    model.setTexture(texture);
    model.useLight = false;
    model.useTexture = true;

    viewport.addObject(&model);
    viewport.render().save("res.jpg");

    RenderTools::render(geometry, camera, {0, 0, -1}).save("static.jpg");

    return 0;
}
