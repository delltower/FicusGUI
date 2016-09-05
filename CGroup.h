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

			// ���߿�
			SPoint p[6];
			p[0].y = p[1].y = p[4].y = p[5].y = rect.y1 + 6;
			p[0].x = rect.x1 + 16;
			p[1].x = p[2].x = rect.x1;
			p[2].y = p[3].y = rect.y2 - 1;
			p[3].x = p[4].x = rect.x2 - 1;
			p[5].x = rect.x1 + 20 + x;  //���ֿ�϶20
			pAda->drawPolyLine(p,6,COLOR_DARKGRAY);  //������

			p[0].y = p[1].y = rect.y1 + 7;
			p[0].x = rect.x1 + 16;
			p[1].x = p[2].x = rect.x1 + 1;
			p[2].y = rect.y2 - 2;
			pAda->drawPolyLine(p,3, COLOR_WHITE); //����һ������

			p[0].y = p[1].y = rect.y2;
			p[0].x = rect.x1;
			p[1].x = p[2].x = rect.x2;
			p[2].y = rect.y1 + 6;
			pAda->drawPolyLine(p,3, COLOR_WHITE); //����һ������

			//���һ����������
			pAda->line(rect.x1 + 20 + x, rect.y1 + 7, rect.x2 - 2, rect.y1 + 7, COLOR_WHITE);
			//ֻ����������18
			pAda->drawText(getText(), rect.x1 + 18, rect.y1 + 1, foreColor);

			pAda->endDraw();
		}
	}
	//���ܵõ�����
	void setFocus(bool flag = false){
		focus = false;
	}
private:
	
};
#endif