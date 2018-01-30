
#ifndef DEF_ELS_HEAD
#define DEF_ELS_HEAD

#include<windows.h>
#include<time.h>
#define DEF_TIMER1 1234

void OnCreate();

void OnPaint(HDC hDC);

//��ʾ����
void PaintSqare(HDC hMemDC);

//���������
int CreateRandomSqare();

//�������������
void CopySqareToBack();

//�س���
void OnReturn(HWND hWnd);

//����
void OnChangeSqare(HWND hWnd);

//���¼���
void OnDown(HWND hWnd);

//����
void OnLeft(HWND hWnd);

//����
void OnRight(HWND hWnd);

//��������
void SqareDown();
void SqareLeft();
void SqareRight();

//��ʱ����Ӧ����
void OnTimer(HWND hWnd);

//����ͣ�������  ����0���������䣬1��������
int CanSqareDown();
int CanSqareDown2();
int CanSqareLeft();
int CanSqareLeft2();
int CanSqareRight();
int CanSqareRight2();
int CanSqareChangeShape();
int CanLineSqareChange();
int CanGameOver();

//1���2
void Change1To2();
void ChangeSqare();
void ChangeLineSqare();
void DestoryOneLineSqare();

//��ʾ2
void ShowSqare2(HDC hMemDC);
void ShowScore(HDC hMemDC);


#endif