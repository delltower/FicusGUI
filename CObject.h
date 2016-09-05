#ifndef  COBJECT_H
#define  COBJECT_H
#include<stdlib.h>
#include "FCommon.h"
#include "CAdaptor.h"

//������Ļ���
class CObject{
public:
	//id,style
	CObject(const SWORD id = 0, const BORDERSTYLE style = NONE_BORDER){
		foreColor = COLOR_BLACK;
		bgColor = COLOR_GRAY;
		parent = NULL;
		this->id = id;
		borderStyle = style;
		//ifCanFocus = true;
	}
	//����,id,style
	CObject(const SRect& rt, const SWORD id = 0, const BORDERSTYLE style = NONE_BORDER) :CObject(id, style){
		rect = rt;
	}
	virtual ~CObject(){}  //Ϊɶ�麯��
	//set function
	 void setForeColor(COLORVAL color) //����ǰ��ɫ
	{
		foreColor = color;
	}
	 void setBgColor(COLORVAL color) //���ñ���ɫ
	{
		bgColor = color;
	}
	 void setRect(SRect& rt) //�ı����ھ��δ�С
	{
		rect = rt;
	}
	 void setBorderStyle(BORDERSTYLE style) //���ñ߿���
	{
		borderStyle = style;
	}
	 void setId(const WORD id) //����id��Ϊɶid�����������
	{
		this->id = id;
	}
	 void setParent(CObject* item) //���ø�Ԫ��
	{
		if (item)
			parent = item;
	//	else parent = NULL;
	}
	 void setFocus(bool flag = true) //���ý���
	{
		focus = flag;
	}
	//get function
	 COLORVAL getForeColor() //�õ�ǰ��ɫ
	{
		return foreColor;
	}
	 COLORVAL getBgColor() //�õ�����ɫ
	{
		return bgColor;
	}
	 virtual void getClientRect(SRect& rt) //�õ��ͻ������Σ���ͬ�������ͬ�Ľ��
	{
		rt = rect;
	}
	 BORDERSTYLE getBorderStyle() //�õ��߿���
	{
		return borderStyle;
	}
	 WORD getId() //�õ�id
	{
		return id;
	}
	 CObject* getParent() //�õ���Ԫ��
	{
		return parent;
	}
	 bool isFocus() //�Ƿ�Ϊ����
	{
		return focus;
	}
	 bool message(SMsg& msg) //��Ϣ�ַ�����
	{
		return true;
	}
	 bool isContains(const SPoint& p) //�ж������Ƿ��ڱ�Ԫ��
	{
		return rect.isContains(p.x, p.y);
	}
	
	//process function
	 virtual void msgProc(SMsg& msg);  //������Ϣ���麯��
	 virtual void onDraw(CAdaptor* pAda); ////�����ػ���Ϣ
	 virtual void onKey(SMsg& pMsg); //���������Ϣ
	 virtual void onMouseDown(SPoint& p);//���������Ϣ
	 virtual void onMouseUp(SPoint& p); //���������Ϣ
	 virtual void onDrawRequest(short idFlag);	//���������ػ���Ϣ
	 void onFocus(SMsg* pMsg);	//�������л���Ϣ
	 virtual void onNotify(SNotice& notice);//����֪ͨ
	 virtual void onTimer();//����ʱ����Ϣ
	 void requestDraw();//�����ػ���Ϣ��������
	
protected:
	 void drawBorder(CAdaptor* pAda, BORDERSTYLE style);	//���ݾ��δ�С�ͷ����Ʊ߿�
	 void notifyParent(SMsg& msg);//����֪ͨ��Ϣ��������
	 void onFocus(SMsg& msg); //�������л���Ϣ  Ϊɶ�����麯��
protected:
	COLORVAL foreColor;	//ǰ��ɫ
	COLORVAL bgColor;	//����ɫ
	SRect rect;	//Ԫ����������
	BORDERSTYLE borderStyle;	//�߿���
	SWORD id;	//Ԫ�ص�id
	CObject* parent;	//������Ԫ��
	bool focus;	//�Ƿ�Ϊ����

};
#endif