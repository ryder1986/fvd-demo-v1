#ifndef YUVWIDGET_H
#define YUVWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "yuvrender.h"
class yuvWidget : public QWidget
{
    Q_OBJECT

public:

    yuvWidget(QWidget *parent = 0);
    ~yuvWidget();
protected slots:
    void update();

private:
     YuvRender *r;
};

#endif // YUVWIDGET_H
