#ifndef CFSCOMMON_H
#define CFSCOMMON_H
typedef unsigned short 	SWORD;
typedef unsigned long   DWORD;
typedef unsigned long   COLORVAL;

// color define
const COLORVAL COLOR_BLACK = 0x000000;         /*!< \brief��ɫ */
const COLORVAL COLOR_GRAY = 0xc0c0c0;         /*!< \brief��ɫ */
const COLORVAL COLOR_WHITE = 0xffffff;         /*!< \brief��ɫ */
const COLORVAL COLOR_DARKGRAY = 0x808080;         /*!< \brief���ɫ */
const COLORVAL COLOR_BLUE = 0xbf0000;         /*!< \briefǳ��ɫ */
const COLORVAL COLOR_BLUE1 = 0xff0000;         /*!< \brief��ɫ */
const COLORVAL COLOR_RED = 0x0000ff;         /*!< \brief��ɫ */

typedef enum { CENTER_ALIGN, LEFT_ALIGN, RIGHT_ALIGN } TEXTALIGN; //���뷽ʽ
typedef enum { EMBOSSING_BORDER, SUNKEN_BORDER, THIN_BORDER, NONE_BORDER } BORDERSTYLE; //border����ʽ��ͻ���³���ϸ�߿��ޱ߿�
//·������󳤶�
const int  MAX_PATHNAME = 500;
//��Ϣ���������
const int MAX_MSGNUM = 20; 
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
typedef enum{
	EMPTY_MSG,	//����Ϣ
	STARTUP_MSG, //ϵͳ������Ϣ
	HALT_MSG, //ϵͳֹͣ��Ϣ
	DRAW_MSG, //��Ļˢ�»򴰿�Ԫ���ػ���Ϣ
	KEY_MSG, //������Ϣ
	MOUSE_MSG, //�����Ϣ
	TIMER_MSG, //��ʱ����Ϣ
	SYS_MSG,
	DRAW_REQUEST_MSG,//�����ػ���Ϣ
	FOCUS_MSG,//�����л���Ϣ
	NOTIFY_MSG,	//֪ͨ��Ϣ
	UPDATE_VIEW_MSG,	//mvcģʽ����ͼ������Ϣ

	STOPTIMER_MSG,	//ֹͣ��ʱ��
	MOUSEUP_MSG, //��갴��
	MOUSEDOWN_MSG, //��갴��
}MSGTYPE; //��Ϣ������

const SWORD FVK_0 = 0x30;           /*!< \brief '0' */
const SWORD FVK_1 = 0x31;           /*!< \brief '1' */
const SWORD FVK_2 = 0x32;           /*!< \brief '2' */
const SWORD FVK_3 = 0x33;           /*!< \brief '3' */
const SWORD FVK_4 = 0x34;           /*!< \brief '4' */
const SWORD FVK_5 = 0x35;           /*!< \brief '5' */
const SWORD FVK_6 = 0x36;           /*!< \brief '6' */
const SWORD FVK_7 = 0x37;           /*!< \brief '7' */
const SWORD FVK_8 = 0x38;           /*!< \brief '8' */
const SWORD FVK_9 = 0x39;           /*!< \brief '9' */
const SWORD FVK_A = 0x41;           /*!< \brief 'A' */
// B.C.D......
const SWORD FVK_Z = 0x5a;           /*!< \brief 'Z' */

const SWORD FVK_ENTER = 0x8000;         /*!< \brief ENTER */
const SWORD FVK_DELETE = 0x8001;         /*!< \brief DELETE */
const SWORD FVK_LEFT = 0x8002;         /*!< \brief LEFT */
const SWORD FVK_RIGHT = 0x8003;         /*!< \brief RIGHT */
const SWORD FVK_TAB = 0x8004;         /*!< \brief TAB */
const SWORD FVK_BACK = 0x8005;         /*!< \brief BACKSPACE */
#endif