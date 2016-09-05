#ifndef CGROUP_H
#define CGROUP_H
#include<iostream>
#include "CWidget.h"

class CGroup :public CWidget{
public:
	CGroup(const char* text,const SRect& rt,const SWORD id= 0) :CWidget(text, rt,id){}
	//void onDraw(IDrawInterface* pDraw)
	void onDraw(CAdaptor* pAda)
	{
		if (pAda){
			pAda->beginDraw(rect);
			CWidget::onDraw(pAda);
	
			int x = pAda->getTextWidth(getText());

			// 画边框
			SPoint p[6];
			p[0].y = p[1].y = p[4].y = p[5].y = rect.y1 + 6;
			p[0].x = rect.x1 + 16;
			p[1].x = p[2].x = rect.x1;
			p[2].y = p[3].y = rect.y2 - 1;
			p[3].x = p[4].x = rect.x2 - 1;
			p[5].x = rect.x1 + 20 + x;  //文字空隙20
			pAda->drawPolyLine(p,6,COLOR_DARKGRAY);  //外层灰线

			p[0].y = p[1].y = rect.y1 + 7;
			p[0].x = rect.x1 + 16;
			p[1].x = p[2].x = rect.x1 + 1;
			p[2].y = rect.y2 - 2;
			pAda->drawPolyLine(p,3, COLOR_WHITE); //向里一条白线

			p[0].y = p[1].y = rect.y2;
			p[0].x = rect.x1;
			p[1].x = p[2].x = rect.x2;
			p[2].y = rect.y1 + 6;
			pAda->drawPolyLine(p,3, COLOR_WHITE); //向外一条白线

			//最后一条白线在里
			pAda->line(rect.x1 + 20 + x, rect.y1 + 7, rect.x2 - 2, rect.y1 + 7, COLOR_WHITE);
			//只给文字留了18
			pAda->drawText(getText(), rect.x1 + 18, rect.y1 + 1, foreColor);

			pAda->endDraw();
		}
	}
	//不能得到焦点
	void setFocus(bool flag = false){
		focus = false;
	}
private:
	
};
#endif