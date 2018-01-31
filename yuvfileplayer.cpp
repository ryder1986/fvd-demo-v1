#include "yuvfileplayer.h"
#include "yuvrender.h"
#include "common_routine.h"
#include <QFile>
#include <QTimer>
#include "load-cfg.h"
#include <QPushButton>
QPoint pt[16];
QPoint pt_rear[16];
    YuvFilePlayer::YuvFilePlayer(QWidget *parent) :
    QWidget(parent)
{

    mCamParam obj_mCamParam;
    mCamDetectParam obj_mCamDetectParam;
    mDetectDeviceConfig obj_mDetectDeviceConfig;
    load_obj((unsigned char *) &obj_mCamParam, CLASS_mCamParam, 0);
    load_obj((unsigned char *) &obj_mCamDetectParam, CLASS_mCamDetectParam, 0);
    load_obj((unsigned char *) &obj_mDetectDeviceConfig, CLASS_mDetectDeviceConfig, 0);

  //  qDebug("%d",obj_mCamDetectParam.detectlane.virtuallane[0].Front);

    for (int i = 0; i < 16; i++)
    {
       qDebug("%d %d\n",(obj_mCamDetectParam.detectlane.virtuallane[i / 4].Front[i % 4].x, obj_mCamDetectParam.detectlane.virtuallane[i / 4].Front[i % 4].y));
       pt[i].setX(obj_mCamDetectParam.detectlane.virtuallane[i / 4].Front[i % 4].x);
       pt[i].setY(obj_mCamDetectParam.detectlane.virtuallane[i / 4].Front[i % 4].y);
        //        graHandle_trans.DrawEllipse(RedPen, overlay_data.rear[i].X, overlay_data.rear[i].Y, 20, 20);
       qDebug("%d %d\n",obj_mCamDetectParam.detectlane.virtuallane[i / 4].Rear[i % 4].x, obj_mCamDetectParam.detectlane.virtuallane[i / 4].Rear[i % 4].y);

       pt_rear[i].setX(obj_mCamDetectParam.detectlane.virtuallane[i / 4].Rear[i % 4].x);
       pt_rear[i].setY(obj_mCamDetectParam.detectlane.virtuallane[i / 4].Rear[i % 4].y);
    }




    alg=new YuvAlg();
    p_timer=new QTimer();
    render=new YuvRender();
    hlayout= new QHBoxLayout();

    hlayout->addWidget(render);

    this->setLayout(hlayout);
    connect(p_timer,SIGNAL(timeout()),this,SLOT(frame_timeout()));
    p_timer->start(40);
}

void YuvFilePlayer::frame_timeout()
{
 // qDebug("1");
    common_routine::read_yuv_file(yuv_buf,VIDEO_WIDTH,VIDEO_HEIGHT,tick++%200,"./200frame.yuv");
    render->set_buf(yuv_buf);
    alg->handle_frame((unsigned char *)yuv_buf);
    render->update();
}
