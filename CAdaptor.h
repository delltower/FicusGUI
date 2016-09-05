#ifndef CADAPTOR_H
#define CADAPTOR_H
#include<windows.h>
#include "IDrawInterface.h"
#include "IObserver.h"
class CTimerManger;
class CObject;

class CAdaptor:public IObserver{  
public: //�û�����ִ�����к���
	void run();	//����
	static CAdaptor* getAdaptor();	//���ظ��Ե�ƽ̨��adaptor
	//FG_OSMsgObserver* SetMsgObserver(word type, FG_OSMsgObserver* const pObserver); ע��ϵͳ��Ϣ�Ĺ۲���
	//void SendMsg(FG_Message* pMsg); //����ϵͳ��Ϣ��ע��Ĺ۲���
	virtual void beginDraw(SRect&);	//��ʼ��ͼ���ṩ��ͼ�ľ���
	virtual void endDraw() ; //������ͼ��������Դ
	virtual void fillRect(SRect&, COLORVAL foreColor, COLORVAL backgroundColor);//�����Σ��ṩǰ��ɫ������ɫ
	//��ֱ�ߣ��ṩ�����յ㣬����������ڻ����ģ�ʹ��ʱ�������ھ��ε����
	virtual void line(int, int, int, int, COLORVAL);
	//������,�ṩ���ݺ�λ�ã�������ɫ
	virtual void drawText(const char*, int, int, COLORVAL);
	//�õ��ı��Ŀ��
	virtual int getTextWidth(const char*);
	//�õ��ı��ĸ߶�
	virtual int getTextHeight(const char*);
	//��λͼ
	virtual void drawBitmap(const char*, int, int);
	//������,�ṩ������飬��ĸ�������ɫ
	virtual void drawPolyLine(SPoint*, int, COLORVAL);
	//�����߾��Σ��ṩ���δ�С�������ɫ
	virtual void drawDotRect(SRect&, COLORVAL);
	
	//��Ϣ
	IObserver* setObserver(IObserver*,MSGTYPE);//ע��۲���,�����ϴεĹ۲���
	static void sendMsg(SMsg&); //������Ϣ
	//ע�ᶨʱ��
	static bool registerTimer(CObject*, unsigned int);
	//ֹͣ��ʱ��
	static bool stopTimer(CObject* obj);

	//��Ϣ
	//virtual IObserver* setObserver(MSGTYPE) = 0;//ע��۲���,�����ϴεĹ۲���
	//virtual void sendMsg(SMsg&) = 0; //������Ϣ
	//virtual void processMessage(SMsg&) = 0;  //������Ϣ
	~CAdaptor(){}
protected: //��Щ������������protected���ԣ��û�����Ҫ������Щ����
	CAdaptor(){};//��ֹ������Ķ�����ô˺���
	virtual void initInstance() = 0;	//�����ʼ��
	virtual void executeInstance() = 0; //����ִ��
	virtual void exitInstance() = 0;//�����˳���������Դ
protected: //��̬�ĳ�ԱҪ������֮ǰ��ʼ����������ֻ����һ��adaptor���Ի�ò���ϵͳ�Ľӿ�
	//FG_OSMsgObserver* m_ppObserver[FG_MAX_SYS_MSG]; ��¼���е�ϵͳ��Ϣ�Ĺ۲��ߵ�����
	static IDrawInterface* pDraw;	//����ܻ�ͼ�Ľӿ�
	static CAdaptor* pAdaptor;	//��ò���ϵͳ��������
	static IObserver* allObserver[MAX_MSGNUM]; //������Ϣ�Ĺ۲��ߵ�ָ��
	static CTimerManger* timerManger;
};

#endif
/*ʹ��ʾ��
FG_Win32Adaptor * pAdp = (FG_Win32Adaptor *)FG_GetAdaptor(); //��ò���ϵͳ��adaptor
pAdp->SetBmpPath(Name, length); //����λͼ·��

pAdp->SetInst(hInstance);  //windows�����þ��
pAdp->SetPrevInst(hPrevInstance); //windows�����þ��
pAdp->SetCmdShow(nCmdShow); //windows�����þ��
pAdp->Run(); //�������У�����Ķ�����windows��wndProc�������趨
*/