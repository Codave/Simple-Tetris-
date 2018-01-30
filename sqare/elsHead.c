
#include"elsHead.h"
//��������
char g_arrBackGround[20][10] = { 0 };
char g_arrSqare[2][4] = { 0 };
int g_nSqareID = -1;
int g_nLine = -1;
int g_nList = -1;
int g_nScore = 0;

void OnPaint(HDC hDc) {  //����ʵ��

	//����������DC(�ڴ�����
	HDC hMemDC = CreateCompatibleDC(hDc);
	//����������λͼ(һ��ֽ��
	HBITMAP hBitmapBack = CreateCompatibleBitmap(hDc, 500, 600);
	//��������
	SelectObject(hMemDC, hBitmapBack);

	//
	PaintSqare(hMemDC);
	ShowSqare2(hMemDC);
	
	//����
	ShowScore(hMemDC);
	BitBlt(hDc, 0, 0, 500, 600, hMemDC, 0, 0, SRCCOPY);

	//�ͷ�DC
	DeleteObject(hBitmapBack);
	DeleteDC(hMemDC);
}

void ShowScore(HDC hMemDC) {
	char strScore[10] = { 0 };
	Rectangle(hMemDC, 300, 0, 500, 600);
	itoa(g_nScore, strScore, 10);
	TextOut(hMemDC, 375, 20, "��Ϸ�÷�", strlen("��Ϸ�÷�"));
	TextOut(hMemDC, 400, 50, strScore, strlen(strScore));
	TextOut(hMemDC, 350, 100, "��ǰ��ң�������", strlen("��ǰ��ң�������"));
}

void OnCreate() {
	srand((unsigned int)time(NULL));
	CreateRandomSqare();
	CopySqareToBack();
}

void PaintSqare(HDC hMemDC) {
	int i = 0,j = 0;
	HBRUSH holdBrush;
	HBRUSH hNewBrush;
	//���󷽿�
	Rectangle(hMemDC, 0, 0, 300, 600);
	//ָ��һ�����黭����
	//g_arrBackGround[2][4] = 1;
	//g_arrBackGround[3][3] = 1;
	//g_arrBackGround[3][4] = 1;
	//g_arrBackGround[3][5] = 1;

	hNewBrush = CreateSolidBrush(RGB(63, 191, 49));
	holdBrush = SelectObject(hMemDC, hNewBrush);

	//����
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 10; j++) {
			if (g_arrBackGround[i][j] == 1) {
				//������
				Rectangle(hMemDC, j*30, i*30, j*30+30, i*30+30);
			}
		}
	}
	hNewBrush = SelectObject(hMemDC, holdBrush);
	DeleteObject(hNewBrush);
	
}

//���������
int CreateRandomSqare() {
	
	int nIndex = rand()%7;
	switch (nIndex) {
	case 0:
		g_arrSqare[0][0] = 1; g_arrSqare[0][1] = 1; g_arrSqare[0][2] = 0; g_arrSqare[0][3] = 0;
		g_arrSqare[1][0] = 0; g_arrSqare[1][1] = 1; g_arrSqare[1][2] = 1; g_arrSqare[1][3] = 0;
		g_nLine = 0;
		g_nList = 3;
		break;
	case 1:
		g_arrSqare[0][0] = 0; g_arrSqare[0][1] = 1; g_arrSqare[0][2] = 1; g_arrSqare[0][3] = 0;
		g_arrSqare[1][0] = 1; g_arrSqare[1][1] = 1; g_arrSqare[1][2] = 0; g_arrSqare[1][3] = 0;
		g_nLine = 0;
		g_nList = 3;
		break;
	case 2:
		g_arrSqare[0][0] = 1; g_arrSqare[0][1] = 0; g_arrSqare[0][2] = 0; g_arrSqare[0][3] = 0;
		g_arrSqare[1][0] = 1; g_arrSqare[1][1] = 1; g_arrSqare[1][2] = 1; g_arrSqare[1][3] = 0;
		g_nLine = 0;
		g_nList = 3;
		break;
	case 3:
		g_arrSqare[0][0] = 0; g_arrSqare[0][1] = 0; g_arrSqare[0][2] = 1; g_arrSqare[0][3] = 0;
		g_arrSqare[1][0] = 1; g_arrSqare[1][1] = 1; g_arrSqare[1][2] = 1; g_arrSqare[1][3] = 0;
		g_nLine = 0;
		g_nList = 3;
		break;
	case 4:
		g_arrSqare[0][0] = 0; g_arrSqare[0][1] = 1; g_arrSqare[0][2] = 0; g_arrSqare[0][3] = 0;
		g_arrSqare[1][0] = 1; g_arrSqare[1][1] = 1; g_arrSqare[1][2] = 1; g_arrSqare[1][3] = 0;
		g_nLine = 0;
		g_nList = 3;
		break;
	case 5:
		g_arrSqare[0][0] = 0; g_arrSqare[0][1] = 1; g_arrSqare[0][2] = 1; g_arrSqare[0][3] = 0;
		g_arrSqare[1][0] = 0; g_arrSqare[1][1] = 1; g_arrSqare[1][2] = 1; g_arrSqare[1][3] = 0;
		g_nLine = 0;
		g_nList = 4;
		break;
	case 6:
		g_arrSqare[0][0] = 1; g_arrSqare[0][1] = 1; g_arrSqare[0][2] = 1; g_arrSqare[0][3] = 1;
		g_arrSqare[1][0] = 0; g_arrSqare[1][1] = 0; g_arrSqare[1][2] = 0; g_arrSqare[1][3] = 0;
		g_nLine = 0;
		g_nList = 4;
		break;
	}
	g_nSqareID = nIndex; 
	return nIndex;
}

void CopySqareToBack() {
	int i = 0, j = 0;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 4; j++) {
			g_arrBackGround[i][j + 3] = g_arrSqare[i][j];
		}
	}
}

void OnReturn(HWND hWnd) {
	//�򿪶�ʱ��
	SetTimer(hWnd, DEF_TIMER1, 500, NULL);
}

//����
void OnChangeSqare(HWND hWnd) {
	HDC hDc = GetDC(hWnd);
	switch(g_nSqareID){
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
		if (1 == CanSqareChangeShape()) {
			ChangeSqare();
		}
		else {
			return;
		}
		break;
	case 5://������

		return;
	case 6://����
		if (1 == CanLineSqareChange()) {
			ChangeLineSqare();
		}
		break;
	}
	OnPaint(hDc);
	ReleaseDC(hWnd,hDc);
}

void ChangeSqare() {
	int i = 0, j = 0;
	int nTemp = 2;
	char arrSqare[3][3];
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			arrSqare[i][j] = g_arrBackGround[g_nLine + i][g_nList + j];
		}
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			g_arrBackGround[g_nLine + i][g_nList + j] = arrSqare[nTemp][i];
			nTemp--;
		}
		nTemp = 2;
	}
}

int CanSqareChangeShape() {
	int i = 0, j = 0;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (2 == g_arrBackGround[g_nLine + i][g_nList + j]) {
				return 0;
			}
		}
	}
//	if (g_nList < 0 || g_nList + 2>9) {
//		return 0;
//	}
	if (g_nList < 0) {
		g_nList = 0;
	}
	else if (g_nList + 2 > 9) {
		g_nList = 7; 
	}
	return 1;
}

void ChangeLineSqare() {

	if (g_arrBackGround[g_nLine][g_nList-1]==1) {//����
		//����
		g_arrBackGround[g_nLine][g_nList - 1] = 0;
		g_arrBackGround[g_nLine][g_nList + 1] = 0;
		g_arrBackGround[g_nLine][g_nList + 2] = 0;
		if (2 == g_arrBackGround[g_nLine + 1][g_nList]) {
			//��ֵ
			g_arrBackGround[g_nLine - 1][g_nList] = 1;
			g_arrBackGround[g_nLine - 2][g_nList] = 1;
			g_arrBackGround[g_nLine - 3][g_nList] = 1;
		}
		else if(g_arrBackGround[g_nLine + 2][g_nList] == 2){
			//��ֵ
			g_arrBackGround[g_nLine + 1][g_nList] = 1;
			g_arrBackGround[g_nLine - 1][g_nList] = 1;
			g_arrBackGround[g_nLine - 2][g_nList] = 1;
		}
		else {
			//Ԫ�ظ�ֵ
			g_arrBackGround[g_nLine - 1][g_nList] = 1;
			g_arrBackGround[g_nLine + 1][g_nList] = 1;
			g_arrBackGround[g_nLine + 2][g_nList] = 1;
		}
	}
	else { //����
		//����
		g_arrBackGround[g_nLine - 1][g_nList] = 0;
		g_arrBackGround[g_nLine + 1][g_nList] = 0;
		g_arrBackGround[g_nLine + 2][g_nList] = 0;

		if (g_arrBackGround[g_nLine][g_nList + 1] == 2||9==g_nList) {
			//��ֵ
			g_arrBackGround[g_nLine][g_nList-1] = 1;
			g_arrBackGround[g_nLine][g_nList-2] = 1;
			g_arrBackGround[g_nLine][g_nList-3] = 1;
			//��Ǹı�
			g_nList = g_nList - 2;

		}
		else if (g_arrBackGround[g_nLine][g_nList + 2] == 2 || 8 == g_nList) {
			//��ֵ
			g_arrBackGround[g_nLine][g_nList + 1] = 1;
			g_arrBackGround[g_nLine][g_nList - 1] = 1;
			g_arrBackGround[g_nLine][g_nList - 2] = 1;
			//��Ǹı�
			g_nList = g_nList - 1;
		}
		else if(g_arrBackGround[g_nLine][g_nList - 1] == 2|| 0 == g_nList){
			//��ֵ
			g_arrBackGround[g_nLine][g_nList + 1] = 1;
			g_arrBackGround[g_nLine][g_nList + 2] = 1;
			g_arrBackGround[g_nLine][g_nList + 3] = 1;
			//��Ǹı�
			g_nList = g_nList + 1;
		}
		else {
			////����
			//g_arrBackGround[g_nLine - 1][g_nList] = 0;
			//g_arrBackGround[g_nLine + 1][g_nList + 1] = 0;
			//g_arrBackGround[g_nLine + 2][g_nList + 2] = 0;
			//Ԫ�ظ�ֵ
			g_arrBackGround[g_nLine][g_nList - 1] = 1;
			g_arrBackGround[g_nLine][g_nList + 1] = 1;
			g_arrBackGround[g_nLine][g_nList + 2] = 1;
		}
		
	}
}

int CanLineSqareChange() {
	int i = 0, j = 0;
	for (i = 1; i < 4; i++) {
		if (2 == g_arrBackGround[g_nLine][g_nList + i] || g_nList + i > 9) {
			break;
		}
	}
	for (j = 1; j < 4; j++) {
		if (2 == g_arrBackGround[g_nLine][g_nList - j] || g_nList -j < 0) {
			break;
		}
	}
	if ((i - 1 + j - 1) < 3) {
		return 0;
	}
	return 1;
}

//���¼���
void OnDown(HWND hWnd) {
	OnTimer(hWnd);
}

//��������
void SqareDown() {
	int i = 0, j = 0;
	for (i = 19; i >= 0; i--) {
		for (j = 0; j < 10; j++) {
			if (1 == g_arrBackGround[i][j]) {
				g_arrBackGround[i + 1][j] = g_arrBackGround[i][j];
				g_arrBackGround[i][j] = 0;
			}
		}
	}
}

//��ʱ����Ӧ����
void OnTimer(HWND hWnd) {
	HDC hDc = GetDC(hWnd); //�ں˶���
	if (1 == CanSqareDown()&&  1== CanSqareDown2()) {
		SqareDown();
		g_nLine++;
	}
	else {
		//1���2
		Change1To2();
		DestoryOneLineSqare();
		//
		if (0 == CanGameOver()) {
			//����
			KillTimer(hWnd, DEF_TIMER1);
			return 0;
		}
	
		//���������
		CreateRandomSqare();
		//���Ƶ�������
		CopySqareToBack();
	}
	
	//��ʾ����
	//PaintSqare(hDc);
	OnPaint(hDc);
	ReleaseDC(hWnd, hDc);
}

int CanGameOver() {
	int i = 0;
	for (i = 0; i < 10; i++) {
		if (2 == g_arrBackGround[0][i]) {
			//��Ϸ����
			MessageBox(NULL, "Game Over!", "��ʾ", MB_OK);
			return 0;
		}
	}
	return 1;
}

int CanSqareDown() {
	int i = 0;
	for (i = 0; i< 10; i++) {
		if (1 == g_arrBackGround[19][i]) {
			return 0;
		}
	}
	return 1;
}

//1���2
void Change1To2() {
	int i = 0, j = 0;
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 10; j++) {
			if (1 == g_arrBackGround[i][j]) {
				g_arrBackGround[i][j] = 2;
			}
		}
	}
}

//��ʾ2
void ShowSqare2(HDC hMemDC) {
	int i = 0, j = 0;
	HBRUSH holdBrush;
	HBRUSH hNewBrush = CreateSolidBrush(RGB(233, 27, 182));
	holdBrush = SelectObject(hMemDC, hNewBrush);
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 10; j++) {
			if (2 == g_arrBackGround[i][j]) {
				//������
				Rectangle(hMemDC, j * 30, i * 30, j * 30 + 30, i * 30 + 30);
			}
		}
	}
	hNewBrush = SelectObject(hMemDC, holdBrush);
	DeleteObject(hNewBrush);
}

int CanSqareDown2() {
	int i = 0, j = 0;
	for (i = 19; i >= 0; i--) {
		for (j = 0; j < 10; j++) {
			if (1 == g_arrBackGround[i][j]) {
				if (2 == g_arrBackGround[i + 1][j]) {
					return 0;
				}
			}
		}
	}
	return 1;
}

void OnLeft(HWND hWnd) {
	if (1 == CanSqareLeft()&& 1 == CanSqareLeft2()) {
		HDC hDc = GetDC(hWnd);
		//��������
		SqareLeft();
		g_nList--;
		//��ʾ����
		OnPaint(hDc);
		ReleaseDC(hWnd, hDc);
	}
}

void SqareLeft() {
	int i = 0, j = 0;
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 10; j++) {
			if (g_arrBackGround[i][j] == 1) {
				g_arrBackGround[i][j - 1] = g_arrBackGround[i][j];
				g_arrBackGround[i][j] = 0;
			}
		}
	}
}

int CanSqareLeft() {
	int i = 0;
	for (i = 0; i < 20; i++) {
		if (1 == g_arrBackGround[i][0]) {
			return 0;
		}
	}
	return 1;
}

int CanSqareLeft2() {
	int i = 0, j = 0;
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 10; j++) {
			if (1 == g_arrBackGround[i][j]) {
				if (2 == g_arrBackGround[i][j - 1]) {
					return 0;
				}
			}
		}
	}
	return 1;
}

void OnRight(HWND hWnd) {
	if (1 == CanSqareRight() && 1 == CanSqareRight2()) {
		HDC hDc = GetDC(hWnd);  
		//��������
		SqareRight();
		g_nList++;
		//��ʾ����
		OnPaint(hDc);
		ReleaseDC(hWnd, hDc);
	}
}

void SqareRight() {
	int i = 0, j = 0;
	for (i = 0; i < 20; i++) {
		for (j = 9; j >= 0; j--) {
			if (g_arrBackGround[i][j] == 1) {
				g_arrBackGround[i][j + 1] = g_arrBackGround[i][j];
				g_arrBackGround[i][j] = 0;
			}
		}
	}
}

int CanSqareRight() {
	int i = 0;
	for (i = 0; i < 20; i++) {
		if (1 == g_arrBackGround[i][9]) {
			return 0;
		}
	}
	return 1;
}

int CanSqareRight2() {
	int i = 0, j = 0;
	for (i = 0; i < 20; i++) {
		for (j = 9; j >= 0; j--) {
			if (1 == g_arrBackGround[i][j]) {
				if (2 == g_arrBackGround[i][j + 1]) {
					return 0;
				}
			}
		}
	}
	return 1;
}

void DestoryOneLineSqare() {
	int i = 0, j = 0;
	int nSum = 0;
	int nTempi = 0;
	for (i = 19; i >= 0; i--) {
		for (j = 0; j < 10; j++) {
			nSum += g_arrBackGround[i][j];
		}
		if (nSum == 20) {
			//����һ��
			for (nTempi = i - 1; nTempi >= 0; nTempi--) {
				for (j = 0; j < 10; j++) {
					g_arrBackGround[nTempi + 1][j] = g_arrBackGround[nTempi][j];
				}
			}
			//
			i = 20;
			g_nScore++;
		}
		nSum = 0;//����
	}
}