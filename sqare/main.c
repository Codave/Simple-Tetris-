
#include"elsHead.h"
//#include"resource.h"  //iconͼ���Զ���
LRESULT CALLBACK PELouSi(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam);


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	//��ʼ��������
	WNDCLASSEX wc;
	HWND hWnd;
	MSG mSg;

	wc.cbClsExtra = 0;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW; //������ɫ
	wc.hCursor = NULL;  //TODO:����
	wc.hIcon = NULL;  //TODO:����
	wc.hIconSm = NULL;
	wc.hInstance = hInstance;
	wc.lpfnWndProc = PELouSi;  //�ص�������ַ
	wc.lpszClassName = "els";  //���ֲ�Ҫ�ظ�,������ϵͳ����
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	//ע�ᴰ�ڶ���
	if (0 == RegisterClassEx(&wc)) {
		int a = GetLastError();
		return 0;
	}

	//��������
	hWnd = CreateWindowEx(WS_EX_TOPMOST,"els","����˹����",WS_OVERLAPPEDWINDOW,100,30,520,645,NULL,NULL,hInstance,NULL);
	if (NULL == hWnd) {  //���ھ��:���ڵ�Ψһ��ʶ
		return 0;
	}

	//��ʾ����
	ShowWindow(hWnd, SW_SHOWNORMAL);  //����
	//������ʾ����0,������ʾ���ط�0

	//��Ϣѭ��
	while (GetMessage(&mSg, NULL, 0, 0)) {
		//
		TranslateMessage(&mSg);  //������Ϣ
		//
		DispatchMessage(&mSg);  //�ַ���Ϣ
	}

	//
	return 0;
}

LRESULT CALLBACK PELouSi(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT pt;
	HDC hDC;
	switch (nMsg) {
	case WM_CREATE:  //���ڴ�������ֻ����һ��
	//	GetLastError();//�Ż�
		//��ʼ������
		OnCreate();
		break;

	case WM_TIMER:
		OnTimer(hWnd);
		break;

	case WM_PAINT:
		hDC = BeginPaint(hWnd, &pt);//getDc
		//�������ϵ�����
		//����˹����  �ɻ���ս
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
	return DefWindowProc(hWnd, nMsg, wParam, lParam);  //����
}

