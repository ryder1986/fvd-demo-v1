#include "yuvwidget.h"
#include <QApplication>
#include "yuvrender.h"
#include <QPushButton>
#include <QWidget>
#include <QDialog>
#include "yuvfileplayer.h"
#include "load-cfg.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


//    mCamParam obj_mCamParam;
//    mCamDetectParam obj_mCamDetectParam;
//    mDetectDeviceConfig obj_mDetectDeviceConfig;
//    load_obj((unsigned char *) &obj_mCamParam, CLASS_mCamParam, 0);
//    load_obj((unsigned char *) &obj_mCamDetectParam, CLASS_mCamDetectParam, 0);
//    load_obj((unsigned char *) &obj_mDetectDeviceConfig, CLASS_mDetectDeviceConfig, 0);

//  //  qDebug("%d",obj_mCamDetectParam.detectlane.virtuallane[0].Front);
//    for (int i = 0; i < 16; i++)
//    {
//       qDebug("%d %d\n",(obj_mCamDetectParam.detectlane.virtuallane[i / 4].Front[i % 4].x, obj_mCamDetectParam.detectlane.virtuallane[i / 4].Front[i % 4].y));
//        //        graHandle_trans.DrawEllipse(RedPen, overlay_data.rear[i].X, overlay_data.rear[i].Y, 20, 20);
//       qDebug("%d %d\n",obj_mCamDetectParam.detectlane.virtuallane[i / 4].Rear[i % 4].x, obj_mCamDetectParam.detectlane.virtuallane[i / 4].Rear[i % 4].y);

//    }


    YuvFilePlayer p;
   // p.setWindowState(Qt::WindowMaximized);
    p.setGeometry(100,100,640,480);
    p.show();

    return a.exec();
}
