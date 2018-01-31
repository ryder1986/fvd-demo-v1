#ifndef LOADCFG_H
#define LOADCFG_H
#include <stdio.h>
#include <time.h>
//#include<unistd.h>
#include<string.h>
#define FILE_NAME_LENGTH 20
#define CAM_NUM_1 8
enum {
    CLASS_NULL,
    CLASS_char,
    CLASS_short,
    CLASS_int,
    CLASS_mCommand,
    CLASS_mDetectDeviceConfig,
    CLASS_mCamParam,
    CLASS_mCamDetectParam,
    CLASS_mChannelVirtualcoil,
    CLASS_mCamAttributes,
    CLASS_mCamDemarcateParam,
    CLASS_mCamDetectLane,
    CLASS_mChannelCoil,
    CLASS_mPoint,
    CLASS_mLine,
    CLASS_mVirtualLaneLine,
    CLASS_mStandardPoint,
    CLASS_mDemDetectArea,
    CLASS_mDetectParam,

};


int get_obj_len(int class_type);
#pragma pack(push)
#pragma pack(1)

#define  VERSION    0x01
#define  PROTTYPE    0x02


#define  SETCAMPARAM    0x0001
#define  GETCAMPARAM    0x0002
#define  REPCAMPARAM    0x0003

#define  SETDETECTDEVICE    0x0004
#define  GETDETECTDEVICE    0x0005
#define  REPDETECTDEVICE    0x0006

#define  SETCHECHPARAM    0x0007
#define  GETCHECHPARAM    0x0008
#define  REPCHECHPARAM    0x0009

#define  HEART    0x1000
#define  SHUTDOWN    0x1001
#define  REPHEART    0x1002

#define  REBOOTZEN   0x2001

#define  FORKEXIT    0x3001

#define   HEARTTIME     60

#define  USERNAMEMAX   20
#define  IPADDRMAX     16
#define  DEVNAMEMAX    50


#define Z_NONE 0x0
#define Z_NORTH 0x1
#define Z_NORTHEAST 0x2
#define Z_EAST 0x3
#define Z_SOUTHEAST 0x4
#define Z_SOUTH 0x5
#define Z_SOUTHWEST 0x6
#define Z_WEST 0x7
#define Z_NORTHWEST 0x8

#define  COILPOINTMAX       4
#define  DETECTLANENUMMAX   4
#define  LANELINEMAX         8
#define  STANDPOINT          8
#define  STANDARDVAULEMAX    4
#define  ALGMAX               2
#define  MAXSUBSYSTEM         4

//#define  CAMMERNUM           4

typedef struct Command {
    unsigned char version;
    unsigned char prottype;
    unsigned short objnumber;
    unsigned short objtype;
    unsigned int objlen;
} mCommand;

typedef struct {
    unsigned short x;
    unsigned short y;
} IVDPoint;

typedef struct {
    unsigned char state;
    unsigned char isCarInTail;
    unsigned short queueLength;
    unsigned int vehnum;
    //unsigned int    speed;
    unsigned short uActualDetectLength;
    unsigned short uActualTailLength;
    IVDPoint LineUp[2];
} mRealLaneInfo;

typedef struct {
    unsigned char flag;
    unsigned char laneNum;
    unsigned char curstatus;
    unsigned char fuzzyflag;
    unsigned char visibility;
    unsigned short uDegreePoint[20][2];
    //unsigned short 	uDegreePoint[4][2];
    mRealLaneInfo lane[DETECTLANENUMMAX];  //16
} mRealStaticInfo;

#if 0
//-----------------�����ȫ������------------------
typedef struct CammerControl {
    unsigned char start;                    //����������ñ�־   ����0x1 ������0x0
    unsigned char camdirect;//���������λ
    unsigned char cammerIp[IPADDRMAX];//���IP��ַ
}mCammerControl;

typedef struct DetectDeviceConfig {
    unsigned int detectport;
    unsigned char camnum;
    unsigned char detectip[IPADDRMAX];
    unsigned char detectname[DEVNAMEMAX];
    mCammerControl camcontrol[CAMMERNUM];
}mDetectDeviceConfig;   //������豸����,����4��������,
#endif

#define CAM_CLOSED_STATUS 0
#define CAM_OPENED_STATUS 1
typedef struct caminfo {

    unsigned char camstatus;
    unsigned char camdirect;
    unsigned char cammerIp[IPADDRMAX];
} m_caminfo;

typedef struct DetectDeviceConfig {
    unsigned int deviceID;
    unsigned int detectport;
    unsigned char camnum;
    unsigned char detectip[IPADDRMAX];
    unsigned char detectname[DEVNAMEMAX];
    m_caminfo cam_info[CAM_NUM_1];

} mDetectDeviceConfig;
typedef struct CamAttributes {
    unsigned char direction;
    unsigned int camID;
    unsigned int cammerport;
    unsigned int adjustport;
    unsigned int signalport;
    unsigned char urlname[USERNAMEMAX];
    unsigned char username[USERNAMEMAX];
    unsigned char passwd[USERNAMEMAX];
    unsigned char cammerIp[IPADDRMAX];
    unsigned char adjustIp[IPADDRMAX];
    unsigned char signalIp[IPADDRMAX];
} mCamAttributes;
typedef struct CamDemarcateParam {
    unsigned short cam2stop;
    unsigned short camheight;
    unsigned short lannum;
    unsigned short number;
    unsigned short baselinelen;
    unsigned short farth2stop;
    unsigned short recent2stop;
} mCamDemarcateParam;
typedef struct ChannelVirtualcoil {
    unsigned short number;
    unsigned short farthCoillen;
    unsigned short recentCoillen;
} mChannelVirtualcoil;
typedef struct CamParam {
    unsigned char coilnum;
    mCamAttributes camattr;
    mCamDemarcateParam camdem;
    mChannelVirtualcoil channelcoil[DETECTLANENUMMAX];
} mCamParam;
typedef struct Point {
    unsigned short x;
    unsigned short y;
} mPoint;
typedef struct Line {
    unsigned short startx;
    unsigned short starty;
    unsigned short endx;
    unsigned short endy;
} mLine;
typedef struct RearCoil {
    mPoint Rear[COILPOINTMAX];
    mPoint Front[COILPOINTMAX];
} mChannelCoil;

typedef struct CamDetectLane
{
    unsigned char lanenum;
    mChannelCoil virtuallane[DETECTLANENUMMAX];
} mCamDetectLane;

typedef struct VirtualLaneLine {
    unsigned char lanelinenum;         //
    mLine laneline[LANELINEMAX];
} mVirtualLaneLine;

typedef struct StandardPoint {
    mPoint coordinate;
    unsigned short value;
} mStandardPoint;

typedef struct DemDetectArea {
    mPoint vircoordinate[STANDPOINT];
    mPoint realcoordinate[STANDPOINT];
} mDemDetectArea;

typedef struct DetectParam {
    unsigned short uTransFactor;
    unsigned int uGraySubThreshold;
    unsigned int uSpeedCounterChangedThreshold;
    unsigned int uSpeedCounterChangedThreshold1;
    unsigned int uSpeedCounterChangedThreshold2;
    unsigned short uDayNightJudgeMinContiuFrame;
    unsigned short uComprehensiveSens;
    unsigned short uDetectSens1;
    unsigned short uDetectSens2;
    unsigned short uStatisticsSens1;
    unsigned short uStatisticsSens2;
    unsigned short uSobelThreshold;
    unsigned short shutterMax;        // 1 2 3 4 5 6 7 8
    unsigned short shutterMin;        // 1 2 3 4 5 6 7 8
} mDetectParam;

typedef struct CamDetectParam {
    unsigned int timep[4];
    mCamDetectLane detectlane;
    mVirtualLaneLine laneline;
    mStandardPoint standpoint[STANDARDVAULEMAX];
    mDemDetectArea area;
    mDetectParam detectparam[ALGMAX];
} mCamDetectParam;

void load_obj(unsigned char * p_obj, int class_type, int index);
#endif // LOADCFG_H
