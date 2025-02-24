#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<easyx.h>
#include <conio.h>
#include <stdlib.h>
#include<graphics.h>
#include<mmsystem.h>

bool where;

struct Scoly   //定义 SCOLY 
{
	int speed;
	int dir;
	int reg;
	POINT coor;//坐标
}sco;

void INITScoly()
{
	sco.speed = 10;
	sco.coor.x = 447;
	sco.coor.y = 611;
}
void DrawScoly()
{
	BeginBatchDraw();
	IMAGE s1;
	loadimage(&s1, "Debug/photo/04.jpg",30 ,30);
	putimage(sco.coor.x, sco.coor.y, &s1);
	EndBatchDraw();
}
enum dirction { right, left, up, down ,stop};
void CONTROLScoly()
{
	void PlayScoly();
	if (_kbhit())
	{
		switch (_getch())
		{
		case'w':
		case'W':
		case'72':
			sco.dir = up;
			break;
		case's':
		case'S':
		case'80':
			sco.dir = down;
			break;
		case'a':
		case'A':
		case'75':
			sco.dir = left;
			break;
		case'd':
		case'D':
		case'77':
			sco.dir = right;
			break;
		case'e':
		case'E':
			sco.dir = stop;
			break;
		case'g':
		case'G':
			where = true;
			break;
		case'c':
		case'C':
			where = false;
			break;
		}
	}
}
void MOVEScoly()
{
	switch (sco.dir)
	{
	case up:
		sco.coor.y -= sco.speed;
		break;
	case down:
		sco.coor.y += sco.speed;
		break;
	case left:
		sco.coor.x -= sco.speed;
		break;
	case right:
		sco.coor.x += sco.speed;
		break;
	case stop:
		sco.coor.x = sco.coor.x;
		sco.coor.y = sco.coor.y;
		break;
	}
}
bool present;
void WhereScoly()
{
	IMAGE w1, w2, w3,w4,w5,w6,w7,w8,w9,w10,w11;
	if (sco.coor.x >= 430 - 90 && sco.coor.x <= 430 + 90 && sco.coor.y >= 420 - 45 && sco.coor.y <= 420 + 45)//  理工楼
	{
		loadimage(&w1, "Debug/photo/11.png", 1200, 700);
		putimage(0, 0, &w1); 
	}
	if (sco.coor.x >= 400 - 70 && sco.coor.x <= 400 + 70 && sco.coor.y >= 140 - 35 && sco.coor.y <= 140 + 35)//二综
	{
		loadimage(&w3, "Debug/photo/12.png", 1200, 700);
		putimage(0, 0, &w3);
	}
	if (sco.coor.x >= 218 - 70 && sco.coor.x <= 218 + 70 && sco.coor.y >= 132 - 35 && sco.coor.y <= 132 + 35)//一综
	{
		loadimage(&w4, "Debug/photo/05.png", 1200, 700);
		putimage(0, 0, &w4);
	}
	if (sco.coor.x >= 763 - 50 && sco.coor.x <= 763 + 50 && sco.coor.y >= 294 - 25 && sco.coor.y <= 294 + 20)//3号宿舍
	{
		loadimage(&w5, "Debug/photo/09.png", 1200, 700);
		putimage(0, 0, &w5);
	}
	if (sco.coor.x >=760 - 50&& sco.coor.x <= 760 + 50 && sco.coor.y >= 420 - 25 && sco.coor.y <= 420 + 25)//5号宿舍
	{
		loadimage(&w6, "Debug/photo/10.png", 1200, 700);
		putimage(0, 0, &w6);
	}
	if (sco.coor.x >=640 - 40 && sco.coor.x <= 640+ 30 && sco.coor.y >= 397 - 35 && sco.coor.y <= 397 + 25)//圣诞礼物
	{
		present = false;
	}
	if (sco.coor.x >= 574 - 20 && sco.coor.x <= 574 + 20 && sco.coor.y >= 276 - 20 && sco.coor.y <= 276 + 20)//岱园
	{
		loadimage(&w7, "Debug/photo/13.png", 1200, 700);
		putimage(0, 0, &w7);
	}
	if (sco.coor.x >= 651 - 30 && sco.coor.x <= 651+ 30 && sco.coor.y >= 310 - 20 && sco.coor.y <= 310 + 20)//岳园
	{
		loadimage(&w8, "Debug/photo/14.png", 1200, 700);
		putimage(0, 0, &w8);
	}
	if (sco.coor.x >= 971 - 50 && sco.coor.x <= 971 + 50 && sco.coor.y >= 426 - 25 && sco.coor.y <= 426 + 25)//xing园
	{
		loadimage(&w9, "Debug/photo/15.png", 1200, 700);
		putimage(0, 0, &w9);
	}
	if (sco.coor.x >= 227 - 50 && sco.coor.x <= 227 + 50 && sco.coor.y >= 378 - 40 && sco.coor.y <= 378 + 40)//tushuguan
	{
		loadimage(&w10, "Debug/photo/16.png", 1200, 700);
		putimage(0, 0, &w10);
	}
	if (sco.coor.x >= 791 - 46 && sco.coor.x <= 791 + 45 && sco.coor.y >= 335 - 15 && sco.coor.y <= 335 + 20)//tushuguan
	{
		loadimage(&w11, "Debug/photo/22.png", 1200, 700);
		putimage(0, 0, &w11);
	}
	else
		where = false;	
}
void PlayScoly()
{
	present = true;
	while (1)
	{
		IMAGE a1, a2, a3, a4;
		loadimage(&a2, "Debug/photo/06.jpeg", 1200, 700);
		putimage(0, 0, &a2);
		DrawScoly();
		CONTROLScoly();
		MOVEScoly();
		if (where == true)
		{
			WhereScoly();
			if ((sco.coor.x >= 430 - 90 && sco.coor.x <= 430 + 90 && sco.coor.y >= 420 - 45 && sco.coor.y <= 420 + 45) || (sco.coor.x >= 791 - 46 && sco.coor.x <= 791 + 45 && sco.coor.y >= 335 - 15 && sco.coor.y <= 335 + 20)|| (sco.coor.x >= 400 - 70 && sco.coor.x <= 400 + 70 && sco.coor.y >= 140 - 35 && sco.coor.y <= 140 + 35) || (sco.coor.x >= 218 - 70 && sco.coor.x <= 218 + 70 && sco.coor.y >= 132 - 35 && sco.coor.y <= 132 + 35) || (sco.coor.x >= 763 - 50 && sco.coor.x <= 763 + 50 && sco.coor.y >= 294 - 25 && sco.coor.y <= 294 + 25) || (sco.coor.x >= 760 - 50 && sco.coor.x <= 760 + 50 && sco.coor.y >= 420 - 25 && sco.coor.y <= 420 + 25) || (sco.coor.x >= 640 - 40 && sco.coor.x <= 640 + 30 && sco.coor.y >= 397 - 35 && sco.coor.y <= 397 + 25) || (sco.coor.x >= 574 - 20 && sco.coor.x <= 574 + 20 && sco.coor.y >= 276 - 20 && sco.coor.y <= 276 + 20) || (sco.coor.x >= 651 - 30 && sco.coor.x <= 651 + 30 && sco.coor.y >= 310 - 20 && sco.coor.y <= 310 + 20) || (sco.coor.x >= 971 - 50 && sco.coor.x <= 971 + 50 && sco.coor.y >= 426 - 25 && sco.coor.y <= 426 + 25) || (sco.coor.x >= 227 - 50 && sco.coor.x <= 227 + 50 && sco.coor.y >= 378 - 40 && sco.coor.y <= 378 + 40))
			{
				break;
			}
		}
		Sleep(100);
	}
}	
int main()//锐评  一坨答辩！
{
	initgraph(1200, 700);
	IMAGE a1, a2, a3, a4,a5;
	loadimage(&a1, "Debug/photo/20.png",1200,700);
	putimage(0, 0, &a1);
	char a;
	a = _getch();
	if (a=='f' || a == 'F')    //虽然现在看这代码像一坨答辩，我按任意键都能切换，但不妨碍它可以正常运行，无所谓了，能跑进行
	{
		loadimage(&a2, "Debug/photo/21.png", 1200, 700);
		putimage(0, 0, &a2);
		if (a == 'v' || a == 'V')
		{
			loadimage(&a2, "Debug/photo/06.jpeg", 1200, 700);
			putimage(0, 0, &a2);
		}
	}
	INITScoly();
	while (1)//woc，我好牛逼！！这个算法 实现了两个场景的随意切换！！好开心！！！用两个死循环嵌套！里面的break跳出来，但外面还有一个循环！
	{
		
		where = false;
		char back;
		back = _getch();
		if (back == 'v'||back=='V')
		{
			where = false;
			if (where == false)
			{
				PlayScoly();
			}
			if (present == false)
			{
				goto pos_1;
			}
		}
	}
pos_1:
	loadimage(&a3, "Debug/photo/08.jpeg", 1200, 700);
	putimage(0, 0, &a3);
	Sleep(1000);
	loadimage(&a4, "Debug/photo/18.png", 1200, 700);
	putimage(0, 0, &a4);
	char pick;
	pick = _getch();
	if (pick == 'p' || pick == 'P')
	{
		loadimage(&a5, "Debug/photo/17.jpg", 1200, 700);
		putimage(0, 0, &a5);
	}
	while(1)
	{
	}
	return 0;
}