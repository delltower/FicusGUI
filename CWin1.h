#ifndef CWIN1_H
#define CWIN1_H
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
enum
{
	ID_BITMAP1 = 1,
	ID_START1,
	ID_STOP1,
	ID_OPEN1,
	ID_CLOSE1,
	ID_GROUP11
};
static const SRect RECT_Win1(150, 180, 445, 460);
static const SRect RECT_Group1_win1(165, 210, 430, 400);
static const SRect RECT_Bitmap_win1(235, 229, 356, 350);
static const SRect RECT_Start_win1(205, 360, 285, 385);
static const SRect RECT_Stop_win1(305, 360, 385, 385);

static const SRect RECT_Open_win1(175, 415, 285, 440);
static const SRect RECT_Close_win1(305, 415, 425, 440);

class CWin1 :public CWindow{
public:
	CWin1(const SWORD id = 1) :CWindow(RECT_Win1, "main window", id){
		addWidget(new CGroup("动画2", RECT_Group1_win1, ID_GROUP11));
		addWidget(new CBitmap("UnderSea.bmp", RECT_Bitmap_win1, ID_BITMAP1));
		addWidget(new CButton("start [S]", RECT_Start_win1, ID_START1));
		addWidget(new CButton("stop [T]", RECT_Stop_win1, ID_STOP1));

		addWidget(new CButton("open [O]", RECT_Open_win1, ID_OPEN1));
		addWidget(new CButton("close [C]", RECT_Close_win1, ID_CLOSE1));

		CBitmap* p = (CBitmap*)getWidgetById(ID_BITMAP1);
		p->addBitmap("UnderSea1.bmp");
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
		CBitmap* p = NULL;
		switch (id){
		case ID_START1:
			p = (CBitmap*)getWidgetById(ID_BITMAP1);
			if (p->isRun() == false){
				CAdaptor::getAdaptor()->registerTimer(p, 1000);
				sendNotice(ID_BITMAP1, 2);
			}
			break;
		case ID_STOP1:
			p = (CBitmap*)getWidgetById(ID_BITMAP1);
			if (p->isRun() == true){
				CAdaptor::getAdaptor()->stopTimer(p);
				sendNotice(ID_BITMAP1, 1);	//动画停止的通知
			}
			break;
		case ID_OPEN1:
			//CScreen::getScreen()->addWindow(new CWin1());
			break;
		case ID_CLOSE1:	//停止
			CScreen::getScreen()->removeWindow(this);
			//CScreen::getScreen()->addWindow(new CWin1());
		  break;
		default:
			break;
		} 
		
	}
private:
	//int mapIndex = 0;
};
#endif