#ifndef YUVFILEPLAYER_H
#define YUVFILEPLAYER_H

#include <QWidget>
#include "g_define.h"
#include "yuvrender.h"
#include <QHBoxLayout>
#include "yuvalg.h"
class YuvFilePlayer : public QWidget
{
    Q_OBJECT
public:
    explicit YuvFilePlayer(QWidget *parent = 0);

signals:

public slots:
    void frame_timeout();
private:
     QTimer *p_timer;
       int tick;
private:
     char yuv_buf[VIDEO_HEIGHT*VIDEO_WIDTH*3/2];
     YuvRender *render;
     QHBoxLayout *hlayout;
     YuvAlg *alg;
};

#endif // YUVFILEPLAYER_H
