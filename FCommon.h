#ifndef CFSCOMMON_H
#define CFSCOMMON_H
typedef unsigned short 	SWORD;
typedef unsigned long   DWORD;
typedef unsigned long   COLORVAL;

// color define
const COLORVAL COLOR_BLACK = 0x000000;         /*!< \brief黑色 */
const COLORVAL COLOR_GRAY = 0xc0c0c0;         /*!< \brief灰色 */
const COLORVAL COLOR_WHITE = 0xffffff;         /*!< \brief白色 */
const COLORVAL COLOR_DARKGRAY = 0x808080;         /*!< \brief深灰色 */
const COLORVAL COLOR_BLUE = 0xbf0000;         /*!< \brief浅蓝色 */
const COLORVAL COLOR_BLUE1 = 0xff0000;         /*!< \brief蓝色 */
const COLORVAL COLOR_RED = 0x0000ff;         /*!< \brief红色 */

typedef enum { CENTER_ALIGN, LEFT_ALIGN, RIGHT_ALIGN } TEXTALIGN; //对齐方式
typedef enum { EMBOSSING_BORDER, SUNKEN_BORDER, THIN_BORDER, NONE_BORDER } BORDERSTYLE; //border的样式，突起，下沉，细边框，无边框
//路径的最大长度
const int  MAX_PATHNAME = 500;
//消息的最大条数
const int MAX_MSGNUM = 20; 
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
typedef enum{
	EMPTY_MSG,	//空消息
	STARTUP_MSG, //系统启动消息
	HALT_MSG, //系统停止消息
	DRAW_MSG, //屏幕刷新或窗口元素重画消息
	KEY_MSG, //键盘消息
	MOUSE_MSG, //鼠标消息
	TIMER_MSG, //定时器消息
	SYS_MSG,
	DRAW_REQUEST_MSG,//请求重画消息
	FOCUS_MSG,//焦点切换消息
	NOTIFY_MSG,	//通知消息
	UPDATE_VIEW_MSG,	//mvc模式的视图更新消息

	STOPTIMER_MSG,	//停止计时器
	MOUSEUP_MSG, //鼠标按下
	MOUSEDOWN_MSG, //鼠标按起
}MSGTYPE; //消息的种类

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