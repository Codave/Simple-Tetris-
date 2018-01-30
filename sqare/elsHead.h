
#ifndef DEF_ELS_HEAD
#define DEF_ELS_HEAD

#include<windows.h>
#include<time.h>
#define DEF_TIMER1 1234

void OnCreate();

void OnPaint(HDC hDC);

//显示方块
void PaintSqare(HDC hMemDC);

//产生随机块
int CreateRandomSqare();

//随机块贴进背景
void CopySqareToBack();

//回车键
void OnReturn(HWND hWnd);

//变形
void OnChangeSqare(HWND hWnd);

//向下加速
void OnDown(HWND hWnd);

//左移
void OnLeft(HWND hWnd);

//右移
void OnRight(HWND hWnd);

//方块下落
void SqareDown();
void SqareLeft();
void SqareRight();

//定时器响应函数
void OnTimer(HWND hWnd);

//方块停在最底下  返回0不可以下落，1可以下落
int CanSqareDown();
int CanSqareDown2();
int CanSqareLeft();
int CanSqareLeft2();
int CanSqareRight();
int CanSqareRight2();
int CanSqareChangeShape();
int CanLineSqareChange();
int CanGameOver();

//1变成2
void Change1To2();
void ChangeSqare();
void ChangeLineSqare();
void DestoryOneLineSqare();

//显示2
void ShowSqare2(HDC hMemDC);
void ShowScore(HDC hMemDC);


#endif