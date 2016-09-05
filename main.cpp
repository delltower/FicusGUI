#include<windows.h>
#include "CAdaptorWin32.h"
#include "CMyApp.h"
#define CRTDBG_MAP_ALLOC    
#include <stdlib.h>    
#include <crtdbg.h>    
//在入口函数中包含 _CrtDumpMemoryLeaks();    
//即可检测到内存泄露  

//定义函数：  
inline void EnableMemLeakCheck()
{
	_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);
}
//该函数可以放在主函数的任意位置，都能正确的触发内存泄露输出  

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
		MessageBox(NULL, "找不到位图目录'FicusGUI/Win32_Bmp'!\n", "错误", MB_OK | MB_ICONSTOP);
		return 0;
	}
	
	char * pEnd = strstr(pFishGUI, "\\");
	if (!pEnd)
	{
		MessageBox(NULL, "找不到位图目录'FicusGUI/Win32_Bmp'!\n", "错误", MB_OK | MB_ICONSTOP);
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
