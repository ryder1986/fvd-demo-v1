#ifndef YUVRENDER_H
#define YUVRENDER_H

#include <QGLWidget>

class YuvRender : public QGLWidget
{
    Q_OBJECT
public:
    explicit YuvRender(QWidget *parent = 0);
    void set_buf(char *);
signals:

public slots:
private:
    char yuv_buf[640*480*3/2];
    char rgb_buf[640*480*3];
    int video_width;
    int video_height;
    int pressed_x,pressed_y,pressed;

protected:
    void  initializeGL();
    void  resizeGL(int w, int h);
    void  paintEvent(QPaintEvent *);
 };

#endif // YUVRENDER_H
