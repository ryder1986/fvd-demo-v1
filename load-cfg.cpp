
#include "load-cfg.h"

#define BUFSIZE 200
inline void log_file(char *fname, char *log)
{
//	char log_buf[BUFSIZE];
//	char filename[BUFSIZE];
//	char dirname[BUFSIZE] = { "log" };
//	char cmd_buf[BUFSIZE] = { };
//	//	if(dname!=NULL){
//	//		strcpy(dirname,dname);
//	//	}
//	FILE *fp = NULL;
//	if ((fp = fopen(dirname, "r")) == NULL) {
//		sprintf(cmd_buf, "mkdir %s", dirname);
////		system(cmd_buf);
//	} else
//		fclose(fp);
//	time_t timer;
//	struct tm *tblock;
//	/* gets time of day */
//	timer = time(NULL);
//	/* converts date/time to a structure */
//	tblock = localtime(&timer);
//	sprintf(filename, "%d_%d_%d", tblock->tm_year - 100 + 2000,
//			tblock->tm_mon + 1, tblock->tm_mday);
//	if (fname != NULL) {
//		strcpy(filename, fname);
//	}

//	strcat(dirname, "/");
//	strcat(dirname, filename);
//	fp = NULL;
//	fp = fopen(dirname, "a");
//	if (fp != NULL) {
//		//	fwrite(log, 1, strlen(log)+1, fp);
//		fwrite(log, 1, strlen(log), fp);
//		fclose(fp);
//	} else {
//		perror("file  open fail");
//		printf("file :%s\n", dirname);
//	}
}

inline void print_stacktrace()
{
	//	int size = 16;
	//	void * array[16];
	//	char tmp[BUFSIZE*2];
	//	int stack_num = backtrace(array, size);
	//	char ** stacktrace = backtrace_symbols(array, stack_num);
	//	if(stacktrace==NULL)
	//		return;
	//	log_file(NULL,"================dump stack begin===================\n");
	//	for (int i = 0; i < stack_num; ++i) {
	//		if(strlen( stacktrace[i])>100)
	//			continue;
	//	 	sprintf(tmp,"@@@@@@@@@@@%s@@@@@@@@@@@ \n", stacktrace[i]);
	//		log_file(NULL,tmp);
	//		printf("%s",tmp);
	//		fflush(NULL);
	//	}
	//	if(stacktrace!=NULL)
	//	free(stacktrace);
	//	log_file(NULL,"================dump stack done================\n");

}
inline void add_title(char *label, char *str, int line, char *src_file)
{
	char tmp_str[BUFSIZE] = { };
	char time_label[BUFSIZE] = { };
	char title_label[BUFSIZE] = { };
	char line_label[BUFSIZE] = { };

    struct tm *p_tm;
    time_t timer;
    /* gets time of day */
    timer = time(NULL);
    /* converts date/time to a structure */
    p_tm = localtime(&timer);
    sprintf(time_label, "[%d:%d:%d]", p_tm->tm_hour, p_tm->tm_min,
            p_tm->tm_sec);
    sprintf(title_label, "[%s]", label);
    sprintf(line_label, "(%s:%d)====>", src_file, line);
    //	if(strcmp(label,"cam_state")==0){
    //		print_stacktrace();
    //	}
#if defined( LOG_NONE)
	if(strcmp(label,"info---1")==0\
 ||strcmp(label,"err--1")==0
			||strcmp(label,"exit--1")==0
			||strcmp(label,"net---1")==0
			||strcmp(label,"in_loop---1")==0
			||strcmp(label,"config_change---1")==0
			||strcmp(label,"stack")==0
			||strcmp(label,"config---1")==0
			||strcmp(label,"cam_info---1")==0
			||strcmp(label,"check_setting--1")==0
			||strcmp(label,"check_client_cmd--1")==0
			||strcmp(label,"cam_state--1")==0
			||strcmp(label,"sig_state--1")==0
			||strcmp(label,"alg---1")==0
			||strcmp(label,"clients_msg---1")==0
			||strcmp(label,"camera_msg---1")==0
			||strcmp(label,"debug_sig----1")==0 )
#elif defined( LOG_LEVEL1)
	if(strcmp(label,"info---1")==0\
 ||strcmp(label,"err")==0
			||strcmp(label,"exit")==0
			||strcmp(label,"net---1")==0
			||strcmp(label,"in_loop---1")==0
			||strcmp(label,"config_change---1")==0
			||strcmp(label,"stack")==0
			||strcmp(label,"config---1")==0
			||strcmp(label,"cam_info---1")==0
			||strcmp(label,"check_setting--1")==0
			||strcmp(label,"check_client_cmd--1")==0
			||strcmp(label,"cam_state--1")==0
			||strcmp(label,"sig_state--1")==0
			||strcmp(label,"alg---1")==0
			||strcmp(label,"clients_msg")==0
			||strcmp(label,"camera_msg")==0
			||strcmp(label,"debug_sig----1")==0 )
#elif defined( LOG_LEVEL2)
	if(strcmp(label,"info")==0\
 ||strcmp(label,"err")==0
			||strcmp(label,"exit")==0
			||strcmp(label,"net")==0
			||strcmp(label,"in_loop---1")==0
			||strcmp(label,"config_change---1")==0
			||strcmp(label,"stack")==0
			||strcmp(label,"config---1")==0
			||strcmp(label,"cam_info---1")==0
			||strcmp(label,"check_setting--1")==0
			||strcmp(label,"check_client_cmd--1")==0
			||strcmp(label,"cam_state--1")==0
			||strcmp(label,"sig_state--1")==0
			||strcmp(label,"server")==0
			||strcmp(label,"alg---1")==0
			||strcmp(label,"clients_msg")==0
			||strcmp(label,"camera_msg")==0
			||strcmp(label,"debug_sig")==0 )
#else defined( LOG_LEVEL3)
	if (strcmp(label, "info") == 0\
 || strcmp(label, "err") == 0
			|| strcmp(label, "exit") == 0 || strcmp(label, "net---1") == 0
			|| strcmp(label, "in_loop---1") == 0
			|| strcmp(label, "config_change---1") == 0
			|| strcmp(label, "stack") == 0 || strcmp(label, "config---1") == 0
			|| strcmp(label, "cam_info---1") == 0
			|| strcmp(label, "check_setting--1") == 0
			|| strcmp(label, "check_client_cmd--1") == 0
			|| strcmp(label, "cam_state--1") == 0
			|| strcmp(label, "sig_state--1") == 0
			|| strcmp(label, "alg---1") == 0
			|| strcmp(label, "clients_msg") == 0
			|| strcmp(label, "camera_msg") == 0
			|| strcmp(label, "debug_sig----1") == 0)
#endif
					{
		strcpy(tmp_str, str);
		strcpy(str, time_label);
		strcat(str, title_label);
		strcat(str, line_label);
		strcat(str, tmp_str);

		strcat(str, "\n");
		if (!strcmp(label, "stack")) {
			print_stacktrace();
		}
	} else {
		memset(str, 0, BUFSIZE);
		//	sprintf(str, "ignoring unknown label [%s]\n", label);
	}

}
inline void print_str(char *str)
{
	printf("%s", str);
	fflush(NULL);
}
#define prt(label,... ) {\
		char tmp_string[BUFSIZE] ;	\
		sprintf(tmp_string,__VA_ARGS__);	\
		add_title(#label,tmp_string,__LINE__,__FILE__);  	\
		print_str(tmp_string);   \
		log_file(NULL,tmp_string);\
}
void save_buf(char *name, char *bf, int pos, int len)
{
	FILE *f = NULL;
	f = fopen(name, "rb+");
	if (f == NULL) {
		prt(info, "err in opne %s", name);
	} else {
		fseek(f, pos, SEEK_SET);
		fwrite(bf, len, 1, f);

		//	prt(info,"wirte file %s ok",name);
		fclose(f);
	}
}
void load_buf(char *name, char *bf, int pos, int len)
{
	FILE *f = NULL;
    f = fopen(name, "rb+");
	if (f == NULL) {
		prt(info, "err in opne %s", name);
	} else {
        prt(info, "ok in opne %s", name);
        fseek(f, pos, SEEK_SET);
        fread(bf, len, 1, f);
        //	prt(info,"read file %s ok",name);
        fclose(f);
	}
}
char cfg_dir[] = "./cfg/";
char *cfg_file_name(char *filename, int class_type)
{
	switch (class_type) {
	case CLASS_mCamParam:
        sprintf(filename, "./cfg/%s", "cam_param");
		break;
	case CLASS_mDetectDeviceConfig:
        sprintf(filename, "./cfg/%s", "dev_config");
		break;
	case CLASS_mCamDetectParam:
        sprintf(filename, "./cfg/%s", "det_param");
		break;

	default:
		prt(info, "unsupported save class %d", class_type)
		;
		break;
	}
	return filename;
}
void save_obj(unsigned char * p_obj, int class_type, int index)
{
	int pos = 0;
	char filename[FILE_NAME_LENGTH];
	int len = get_obj_len(class_type);
	if (class_type == CLASS_mDetectDeviceConfig) {
		pos = 0;
	} else {
		pos = index * len;
	}
	char *p_dst = NULL;
	switch (class_type) {
	case CLASS_mCamParam:
		//memcpy(&g_cam_cfg[index],p_obj,len);
		//	p_dst=(char *)&g_cam_cfg[index].cam_param;
		sprintf(filename, "./cfg/%s", "cam_param");
		break;
	case CLASS_mDetectDeviceConfig:
		//	p_dst=(char *)&g_dev_cfg;
		sprintf(filename, "./cfg/%s", "dev_config");
		break;
	case CLASS_mCamDetectParam:
		//	p_dst=(char *)&g_cam_cfg[index].det_param;
		sprintf(filename, "./cfg/%s", "det_param");
		//prt(info,"===11111>%d====>>> %d",g_cam_cfg[index].det_param.area.vircoordinate[2].x,((mCamDetectParam*)p_obj)->area.vircoordinate[2].x);
		break;

	default:
		prt(info, "unsupported save class %d", class_type)
		;
		break;
	}
	//	memcpy(p_dst,p_obj,len);
	save_buf(filename, (char *) p_obj, pos, len);
}

int get_obj_len(int class_type)
{
	int len = 0;
	switch (class_type) {
	case CLASS_NULL:
		break;
	case CLASS_char:
		break;
	case CLASS_short:
		len = 2;
		break;
	case CLASS_int:
		len = 4;
		break;
	case CLASS_mCommand:
		len = sizeof(mCommand);
		break;
	case CLASS_mDetectDeviceConfig:
		len = sizeof(mDetectDeviceConfig);
		break;
	case CLASS_mCamParam:
		len = sizeof(mCamParam);
		break;
	case CLASS_mCamAttributes:
		len = sizeof(mCamAttributes);
		break;

	case CLASS_mCamDemarcateParam:
		len = sizeof(mCamDemarcateParam);
		break;
	case CLASS_mChannelVirtualcoil:
		len = sizeof(mChannelVirtualcoil);
		break;
	case CLASS_mCamDetectParam:
		len = sizeof(mCamDetectParam);

		break;

	case CLASS_mCamDetectLane:
		len = sizeof(mCamDetectLane);
		break;
	case CLASS_mChannelCoil:
		len = sizeof(mChannelCoil);
		break;
	case CLASS_mPoint:
		len = sizeof(mPoint);
		break;
	case CLASS_mLine:
		len = sizeof(mLine);
		break;
	case CLASS_mVirtualLaneLine:
		len = sizeof(mVirtualLaneLine);
		break;
	case CLASS_mStandardPoint:
		len = sizeof(mStandardPoint);
		break;
	case CLASS_mDemDetectArea:
		len = sizeof(mDemDetectArea);
		break;
	case CLASS_mDetectParam:
		len = sizeof(mDetectParam);
		break;
	default:
		prt(info, "not recognize")
		;
		break;
	}
	return len;
}
void load_obj(unsigned char * p_obj, int class_type, int index)
{
	int pos = 0;
	char filename[FILE_NAME_LENGTH];
	int len = get_obj_len(class_type);
	if (class_type == CLASS_mDetectDeviceConfig) {
		pos = 0;
	} else {
		pos = index * len;
	}


	char *p_dst = NULL;
	switch (class_type) {
	case CLASS_mCamParam:
		//memcpy(&g_cam_cfg[index],p_obj,len);
		//	p_dst=(char *)&g_cam_cfg[index].cam_param;
        sprintf(filename, "./cfg/%s", "cam_param");
		break;
	case CLASS_mDetectDeviceConfig:
		//	p_dst=(char *)&g_dev_cfg;
		sprintf(filename, "./cfg/%s", "dev_config");
		break;
	case CLASS_mCamDetectParam:
		//	p_dst=(char *)&g_cam_cfg[index].det_param;
		sprintf(filename, "./cfg/%s", "det_param");
		//prt(info,"===11111>%d====>>> %d",g_cam_cfg[index].det_param.area.vircoordinate[2].x,((mCamDetectParam*)p_obj)->area.vircoordinate[2].x);
		break;

	default:
		prt(info, "unsupported save class %d", class_type)
		;
		break;
	}
	//	memcpy(p_dst,p_obj,len);
	load_buf(filename, (char *) p_obj, pos, len);
}
//#include "t.h"
//int main()
//{
// 	mCamParam obj_mCamParam;
//
// 	load_obj((unsigned char *) &obj_mCamParam, CLASS_mCamParam, 0);
//	return 0;
//}
