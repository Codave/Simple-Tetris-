
#include"elsHead.h"
//#include"resource.h"  //icon图标自定义
LRESULT CALLBACK PELouSi(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam);


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	//初始化窗口类
	WNDCLASSEX wc;
	HWND hWnd;
	MSG mSg;

	wc.cbClsExtra = 0;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW; //背景颜色
	wc.hCursor = NULL;  //TODO:测试
	wc.hIcon = NULL;  //TODO:测试
	wc.hIconSm = NULL;
	wc.hInstance = hInstance;
	wc.lpfnWndProc = PELouSi;  //回调函数地址
	wc.lpszClassName = "els";  //名字不要重复,给操作系统看的
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	//注册窗口对象
	if (0 == RegisterClassEx(&wc)) {
		int a = GetLastError();
		return 0;
	}

	//创建窗口
	hWnd = CreateWindowEx(WS_EX_TOPMOST,"els","俄罗斯方块",WS_OVERLAPPEDWINDOW,100,30,520,645,NULL,NULL,hInstance,NULL);
	if (NULL == hWnd) {  //窗口句柄:窗口的唯一标识
		return 0;
	}

	//显示窗口
	ShowWindow(hWnd, SW_SHOWNORMAL);  //测试
	//隐藏显示返回0,正常显示返回非0

	//消息循环
	while (GetMessage(&mSg, NULL, 0, 0)) {
		//
		TranslateMessage(&mSg);  //翻译消息
		//
		DispatchMessage(&mSg);  //分发消息
	}

	//
	return 0;
}

LRESULT CALLBACK PELouSi(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT pt;
	HDC hDC;
	switch (nMsg) {
	case WM_CREATE:  //窗口创建初期只产生一次
	//	GetLastError();//优化
		//初始化数据
		OnCreate();
		break;

	case WM_TIMER:
		OnTimer(hWnd);
		break;

	case WM_PAINT:
		hDC = BeginPaint(hWnd, &pt);//getDc
		//画窗口上的内容
		//俄罗斯方块  飞机大战
		OnPaint(hDC);
		EndPaint(hWnd, &pt);
		break;

	case WM_KEYDOWN:
		switch (wParam) {
		case VK_RETURN:
			OnReturn(hWnd);
			break;

		case VK_UP:
			OnChangeSqare(hWnd);
			break;

		case VK_DOWN:
			OnDown(hWnd);
			break;

		case VK_LEFT:
			OnLeft(hWnd);
			break;

		case VK_RIGHT:
			OnRight(hWnd);
			break;
		}
		break;

	case WM_DESTROY:
		KillTimer(hWnd, DEF_TIMER1);
		PostQuitMessage(0); 
		break;
	}
	return DefWindowProc(hWnd, nMsg, wParam, lParam);  //功能
}

