#include <QCoreApplication>

#include "Viewport/viewport.h"
#include "Camera/camera.h"
#include "DrawableModel/drawablemodel.h"
#include "ObjReadingTools/objreadingtools.h"

#include <QImage>
#include <QtDebug>
#include <QFile>
#include <QTextStream>
#include <QVector3D>

int main(int argc, char *argv[])
{
    QString errMsg;

    Camera camera(2 * M_PI / 3, 1, 1, 2);
    camera.setPos({0, 0, 1.5});
    camera.setUp({0, 1, 0});
    Viewport viewport(&camera);
    viewport.setWidth(4096);
    viewport.setHight(4096);
    DrawableModel model;
    QFile file("../ObjRender/obj/african_head.obj");
    if(!file.open(QFile::ReadOnly)){
        qDebug() << "File " << file.fileName() << "not found  \n";
        return -1;
    }
    QTextStream stream(&file);
    if(!ObjReadingTools::readModel(stream, model, errMsg)){
        qDebug() << errMsg << '\n';
        return -1;
    }
    viewport.addModel(&model);
    viewport.render().save("res.jpg");

    return 0;
}
