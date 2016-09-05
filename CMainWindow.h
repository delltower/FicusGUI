#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H
#include "CAdaptor.h"
#include "SRect.h"
#include "CWindow.h"
#include "IObserver.h"
#include "CAdaptorWin32.h"
#include "CLabel.h"
#include "CButton.h"
#include "CRadioButton.h"
#include "CCheckBox.h"
#include "CGroup.h"
#include "CEdit.h"
#include "CBitmap.h"
#include "CWin1.h"

enum
{
	ID_RADIO1 = 1,
	ID_RADIO2,
	ID_RADIO3,
	ID_RADIO4,
	ID_RADIO5,
	ID_RADIO6,
	ID_EDIT1,
	ID_CHECK1,
	ID_CHECK2,
	ID_EDIT2,
	ID_OPEN,
	ID_FACTORY,
	ID_START,
	ID_STOP,
	ID_BITMAP,
	ID_GROUP1,
	ID_GROUP2,
	ID_GROUP3,
	ID_LABEL1
};
static const SRect RECT_MainWindow(30, 50, 640, 400);

static const SRect RECT_Group1(300, 80, 585, 200);
static const SRect RECT_Radio1(320, 100, 400, 120);
static const SRect RECT_Radio2(410, 100, 490, 120);
static const SRect RECT_Radio3(500, 100, 580, 120);
static const SRect RECT_Radio4(320, 125, 400, 145);
static const SRect RECT_Radio5(410, 125, 490, 145);
static const SRect RECT_Radio6(500, 125, 580, 145);
static const SRect RECT_Label1(350, 160, 400, 180);
static const SRect RECT_Edit1(450, 160, 560, 180);

static const SRect RECT_Group2(300, 220, 585, 320);
static const SRect RECT_Check1(340, 240, 430, 260);
static const SRect RECT_Check2(450, 240, 540, 260);
static const SRect RECT_Label2(350, 280, 400, 300);
static const SRect RECT_Edit2(450, 280, 560, 300);

static const SRect RECT_Open(320, 340, 455, 365);
static const SRect RECT_Factory(470, 340, 610, 365);

static const SRect RECT_Group3(65, 80, 285, 380);
static const SRect RECT_Bitmap(102, 140, 248, 275);
static const SRect RECT_Start(85, 315, 165, 340);
static const SRect RECT_Stop(185, 315, 265, 340);

class CMainWindow:public CWindow{
public:
	CMainWindow(const SWORD id= 0):CWindow(RECT_MainWindow,"main window",id){
		SWORD curId = id;
		////group
		//addWidget(new CGroup("Group 1", RECT_Group1, ID_GROUP1));
		//////radio button
		//CRadioButton* firstRadio = new CRadioButton("100 [A]", RECT_Radio1, NULL, ID_RADIO1);
		//addWidget(firstRadio);
		//addWidget(new CRadioButton("200 [B]", RECT_Radio2, firstRadio, ID_RADIO2));
		//addWidget(new CRadioButton("300 [C]", RECT_Radio3, firstRadio, ID_RADIO3));
		//addWidget(new CRadioButton("400 [D]", RECT_Radio4, firstRadio, ID_RADIO4));
		//addWidget(new CRadioButton("500 [E]", RECT_Radio5, firstRadio, ID_RADIO5));
		//addWidget(new CRadioButton("600 [F]", RECT_Radio6, firstRadio, ID_RADIO6));
		//edit1
		addWidget(new CLabel("edit input1:",RECT_Label1,ID_LABEL1));
		addWidget(new CEdit(RECT_Edit1, 15, ID_EDIT1));
		////gruop2 
		//addWidget(new CGroup("Group 2",RECT_Group2,++curId));
		////check box
		/*addWidget(new CCheckBox("ch 1[G]", RECT_Check1, ID_CHECK1));
		addWidget(new CCheckBox("ch 2[H]", RECT_Check2, ID_CHECK2));
		addWidget(new CLabel("edit input2:", RECT_Label2, ++curId));
		addWidget(new CEdit(RECT_Edit2,15,++curId));*/

		////button
		addWidget(new CButton("open window[O]", RECT_Open, ID_OPEN));
		addWidget(new CButton("rangle button[Y]", RECT_Factory, ID_FACTORY));
		//bitmap
	/*	addWidget(new CBitmap("baby30.bmp", RECT_Bitmap, ID_BITMAP, THIN_BORDER));
		addWidget(new CButton("start [S]", RECT_Start, ID_START));
		addWidget(new CButton("stop [T]", RECT_Stop, ID_STOP));


		CBitmap* p = (CBitmap*)getWidgetById(ID_BITMAP);
		p->addBitmap("baby31.bmp");
		p->addBitmap("baby32.bmp");*/
		//CAdaptor::getAdaptor()->registerTimer(p, 1000);
	}
	//处理通知
	void onNotify(SNotice& notice){
		switch (notice.type){
		case 0:
			onClick(notice.id);
			break;
		}
		
	}
private:
	void onClick(SWORD id){
		SNotice notice;
		switch (id){
		case ID_START:{
			CBitmap* p = (CBitmap*)getWidgetById(ID_BITMAP);
			if (p->isRun() == false){
				CAdaptor::getAdaptor()->registerTimer(p, 1000);
				sendNotice(ID_BITMAP, 2);
			}
				
		}
			break;
		case ID_STOP:{
			CBitmap* p = (CBitmap*)getWidgetById(ID_BITMAP);
			if (p->isRun() == true){
				CAdaptor::getAdaptor()->stopTimer(p);
				sendNotice(ID_BITMAP, 1);	//动画停止的通知
			}				
		}
			break;
		case ID_OPEN:{
			CScreen::getScreen()->addWindow(new CWin1(1));
		}
		}
	}
private:
	//int mapIndex = 0;
};
#endif