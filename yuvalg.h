#ifndef YUVALG_H
#define YUVALG_H
#include "alg/m_arith.h"
class YuvAlg
{
public:
    YuvAlg();
    void handle_frame(unsigned char *yuv_buf);
};

#endif // YUVALG_H
