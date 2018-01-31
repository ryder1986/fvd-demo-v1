#include "yuvalg.h"
#include "load-cfg.h"
RESULTMSG outbuf;
 m_args alg_arg;
 LANEINISTRUCT LaneIn;


 int lane_param_init(int curstatus, mDetectParam *tmpDetect,mCamDemarcateParam * tmpCamdem , LANEINISTRUCT *LaneIn)
 {
  //   print_alg("alg ctrl switch");

      LaneIn->uTransFactor=tmpDetect[curstatus].uTransFactor;
      LaneIn->uGraySubThreshold=tmpDetect[curstatus].uGraySubThreshold;
      LaneIn->uSpeedCounterChangedThreshold=tmpDetect[curstatus].uSpeedCounterChangedThreshold;
      LaneIn->uSpeedCounterChangedThreshold1=tmpDetect[curstatus].uSpeedCounterChangedThreshold1;
      LaneIn->uSpeedCounterChangedThreshold2=tmpDetect[curstatus].uSpeedCounterChangedThreshold2;
      LaneIn->uDayNightJudgeMinContiuFrame=tmpDetect[curstatus].uDayNightJudgeMinContiuFrame;
      LaneIn->uComprehensiveSens=tmpDetect[curstatus].uComprehensiveSens;
      LaneIn->uDetectSens1=tmpDetect[curstatus].uDetectSens1;
      LaneIn->uDetectSens2=tmpDetect[curstatus].uDetectSens2;
      LaneIn->uStatisticsSens1=tmpDetect[curstatus].uStatisticsSens1;
      LaneIn->uStatisticsSens2=tmpDetect[curstatus].uStatisticsSens2;
      LaneIn->uSobelThreshold=tmpDetect[curstatus].uSobelThreshold;

 //	memcpy(& LaneIn,\
 //			&tmpDetect[curstatus],\
 //			& LaneIn->uEnvironmentStatus-  \
 //			& LaneIn->uTransFactor);

      LaneIn->uEnvironment=  1;
      LaneIn->uEnvironmentStatus=  3;
      LaneIn->base_length = (float)tmpCamdem->baselinelen;
      LaneIn->near_point_length = (float)tmpCamdem->recent2stop;
     return 0;
 }
 int lane_pos_init(mChannelCoil *tmpcoil, mLine *tmpline,CPoint *m_ptEnd,int lanenum)
 {
     int i=0;
     for(i=0; i<lanenum; i++)
     {
         m_ptEnd[0+i*12].x = tmpline[i*2].startx;
         m_ptEnd[0+i*12].y = tmpline[i*2].starty;
         m_ptEnd[2+i*12].x = tmpline[i*2+1].startx;
         m_ptEnd[2+i*12].y = tmpline[i*2+1].starty;
         m_ptEnd[4+i*12].x = tmpcoil[i].Front[1].x;
         m_ptEnd[4+i*12].y = tmpcoil[i].Front[1].y;

         m_ptEnd[5+i*12].x = tmpcoil[i].Front[2].x;
         m_ptEnd[5+i*12].y = tmpcoil[i].Front[2].y;

         m_ptEnd[6+i*12].x = tmpcoil[i].Front[0].x;
         m_ptEnd[6+i*12].y = tmpcoil[i].Front[0].y;
         m_ptEnd[7+i*12].x = tmpcoil[i].Front[3].x;
         m_ptEnd[7+i*12].y = tmpcoil[i].Front[3].y;
         m_ptEnd[8+i*12].x = tmpcoil[i].Rear[1].x;
         m_ptEnd[8+i*12].y = tmpcoil[i].Rear[1].y;
         m_ptEnd[9+i*12].x = tmpcoil[i].Rear[2].x;
         m_ptEnd[9+i*12].y = tmpcoil[i].Rear[2].y;
         m_ptEnd[10+i*12].x = tmpcoil[i].Rear[0].x;
         m_ptEnd[10+i*12].y = tmpcoil[i].Rear[0].y;
         m_ptEnd[11+i*12].x = tmpcoil[i].Rear[3].x;
         m_ptEnd[11+i*12].y = tmpcoil[i].Rear[3].y;

         m_ptEnd[1+i*12].x = tmpline[i*2].endx;
         m_ptEnd[1+i*12].y = tmpline[i*2].endy;
         m_ptEnd[3+i*12].x = tmpline[i*2+1].endx;
         m_ptEnd[3+i*12].y = tmpline[i*2+1].endy;
     }
     return 0;
 }

YuvAlg::YuvAlg()
{


    mCamParam obj_mCamParam;
    mCamDetectParam obj_mCamDetectParam;
    mDetectDeviceConfig obj_mDetectDeviceConfig;
    load_obj((unsigned char *) &obj_mCamParam, CLASS_mCamParam, 0);
    load_obj((unsigned char *) &obj_mCamDetectParam, CLASS_mCamDetectParam, 0);
    load_obj((unsigned char *) &obj_mDetectDeviceConfig, CLASS_mDetectDeviceConfig, 0);





    memset(alg_arg.m_ptEnd, 0, sizeof(alg_arg.m_ptEnd));
    memset(alg_arg.ptimage, 0, sizeof(alg_arg.ptimage));
    memset(&LaneIn,0,sizeof(LaneIn));
//    LaneIn.uTransFactor=1;
//    LaneIn.uGraySubThreshold=1;
//    LaneIn.uSpeedCounterChangedThreshold=1;
//    LaneIn.uSpeedCounterChangedThreshold1=1;
//    LaneIn.uSpeedCounterChangedThreshold2=1;
//    LaneIn.uDayNightJudgeMinContiuFrame=1;
//    LaneIn.uComprehensiveSens=11;
//    LaneIn.uDetectSens1=11;
//    LaneIn.uDetectSens2=12;
//    LaneIn.uStatisticsSens1=1;
//    LaneIn.uStatisticsSens2=1;
//    LaneIn.uSobelThreshold=1;

////	memcpy(& LaneIn,\
////			&tmpDetect[curstatus],\
////			& LaneIn.uEnvironmentStatus-  \
////			& LaneIn.uTransFactor);

//    LaneIn.uEnvironment=  1;
//    LaneIn.uEnvironmentStatus=  1;
//    LaneIn.base_length = (float)1;
//    LaneIn.near_point_length = (float)1;


    lane_param_init(0,&obj_mCamDetectParam.detectparam[1],&obj_mCamParam.camdem,&LaneIn);
    lane_pos_init(obj_mCamDetectParam.detectlane.virtuallane,
            obj_mCamDetectParam.laneline.laneline, alg_arg.m_ptEnd,obj_mCamDetectParam.detectlane.lanenum);
  //  mDemDetectArea *tmpArea = &p_camdetectparam->area;



    int i;
    for(i=0; i<6; i++){
       alg_arg.ptimage[i].x =100;
        alg_arg.ptimage[i].y =100;
    }
   transform_init_DSP_VC(1, 3,LaneIn,&outbuf,&alg_arg);
}
#include <QDebug>
#include <QPoint>
QPoint p1;
QPoint p2;
QPoint p3;
void YuvAlg::handle_frame(unsigned char *yuv_buf)
{
  transform_Proc_DSP_VC(yuv_buf,yuv_buf+640*480/4*1,yuv_buf+640*480/4*2,640,480,0,&outbuf,&alg_arg);
    qDebug("%d",alg_arg.p_outbuf->LineUp[0][1].y);
    p1.setX(alg_arg.p_outbuf->LineUp[0][1].x);
    p1.setY(alg_arg.p_outbuf->LineUp[0][1].y);

    p2.setX(alg_arg.p_outbuf->LineUp[1][1].x);
    p2.setY(alg_arg.p_outbuf->LineUp[1][1].y);

    p3.setX(alg_arg.p_outbuf->LineUp[2][1].x);
    p3.setY(alg_arg.p_outbuf->LineUp[2][1].y);
      //   return1 ret;
}
