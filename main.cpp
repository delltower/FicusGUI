#include<windows.h>
#include "CAdaptorWin32.h"
#include "CMyApp.h"
#define CRTDBG_MAP_ALLOC    
#include <stdlib.h>    
#include <crtdbg.h>    
//����ں����а��� _CrtDumpMemoryLeaks();    
//���ɼ�⵽�ڴ�й¶  

//���庯����  
inline void EnableMemLeakCheck()
{
	_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);
}
//�ú������Է���������������λ�ã�������ȷ�Ĵ����ڴ�й¶���  

CMyApp myApp;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE preHinstance, PSTR szCmdLine, int iCmdShow)
{
	//EnableMemLeakCheck();
	char Name[MAX_PATH + 1];
	GetModuleFileName(NULL, Name, MAX_PATH);
	for (WORD i = 0; i < strlen(Name); i++)
		Name[i] = toupper(Name[i]);

	char * pFishGUI = strstr(Name, "FICUSGUI");
	if (!pFishGUI)
	{
		MessageBox(NULL, "�Ҳ���λͼĿ¼'FicusGUI/Win32_Bmp'!\n", "����", MB_OK | MB_ICONSTOP);
		return 0;
	}
	
	char * pEnd = strstr(pFishGUI, "\\");
	if (!pEnd)
	{
		MessageBox(NULL, "�Ҳ���λͼĿ¼'FicusGUI/Win32_Bmp'!\n", "����", MB_OK | MB_ICONSTOP);
		return 0;
	}
	short length = pEnd - Name;

	CAdaptorWin32 * pAda = (CAdaptorWin32 *)CAdaptor::getAdaptor();
	pAda->setWin32Handle(hInstance, preHinstance, iCmdShow);
	//pAda->setBmpPath("D:\\vs\\FSGUItest3\\Debug\\Win32_Bmp");
	pAda->setBmpPath(Name);
	pAda->initInstance();  
	pAda->executeInstance();
	pAda->exitInstance();
	return 0;
}
