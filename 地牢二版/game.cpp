#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <ctime>
#include "game.h"
#include "tools.h"
#include "monster.h"
using namespace std;
void Gamestart()
{
	SetWindowSize(49, 49);//设置窗口大小
						  //SetColor(64);//设置开始动画颜色
						  //SetBackColor();
						  //SetCursorPosition(1,1);
						  //Sleep(2000);
	int orderx[49 * 49], ordery[49 * 49];
	int order = 0;
	for (int i = 1; i <= 25; ++i)
	{
		for (int j = 1; j <= 51 - 2 * i; ++j)
		{
			orderx[order] = i + j - 2;
			ordery[order] = i - 1;
			++order;
		}
		for (int j = 1; j <= 50 - 2 * i; ++j)
		{
			orderx[order] = 49 - i;
			ordery[order] = i + j - 1;
			++order;
		}
		for (int j = 1; j <= 50 - 2 * i; ++j)
		{
			orderx[order] = 49 - i - j;
			ordery[order] = 49 - i;
			++order;
		}
		for (int j = 1; j <= 49 - 2 * i; ++j)
		{
			orderx[order] = i - 1;
			ordery[order] = 49 - i - j;
			++order;
		}
	}


	for (int i = 49 * 49 - 100; i < 49 * 49; ++i)
	{
		SetColor(192);
		SetCursorPosition(orderx[i], ordery[i]);
		printf("  ");
		if (i >= 10)
		{
			SetColor(64);
			SetCursorPosition(orderx[i - 10], ordery[i - 10]);
			printf("  ");
		}
		if (i >= 20)
		{
			SetColor(0);
			SetCursorPosition(orderx[i - 20], ordery[i - 20]);
			printf("  ");
		}
		Sleep(5);
	}
	for (int i = 49 * 49 - 10; i < 49 * 49; ++i)
	{
		SetColor(64);
		SetCursorPosition(orderx[i], ordery[i]);
		printf("  ");
		SetColor(0);
		SetCursorPosition(orderx[i - 10], ordery[i - 10]);
		printf("  ");
		Sleep(5);
	}
	for (int i = 49 * 49 - 10; i < 49 * 49; ++i)
	{
		SetColor(0);
		SetCursorPosition(orderx[i], ordery[i]);
		printf("  ");
		Sleep(5);
	}


	for (int i = 49 * 49 - 1; i >= 49 * 49 - 24; --i)
	{
		SetColor(192);
		SetCursorPosition(orderx[i], ordery[i]);
		printf("  ");
		Sleep(10);
	}
	//打出眼睛
	SetCursorPosition(0, 0);
	Sleep(250);
	SetColor(240);
	SetCursorPosition(24, 24);
	printf("  ");
	SetCursorPosition(24, 23);
	printf("  ");
	SetCursorPosition(26, 24);
	printf("  ");
	SetCursorPosition(26, 23);
	printf("  ");
	SetCursorPosition(0, 0);
	Sleep(1000);
	//眨眼
	for (int i = 1; i <= 2; ++i)
	{
		SetColor(192);
		SetCursorPosition(24, 24);
		printf("  ");
		SetCursorPosition(24, 23);
		printf("  ");
		SetCursorPosition(26, 24);
		printf("  ");
		SetCursorPosition(26, 23);
		printf("  ");
		SetCursorPosition(0, 0);
		Sleep(50);

		SetColor(240);
		SetCursorPosition(24, 24);
		printf("  ");
		SetCursorPosition(24, 23);
		printf("  ");
		SetCursorPosition(26, 24);
		printf("  ");
		SetCursorPosition(26, 23);
		printf("  ");
		SetCursorPosition(0, 0);
		Sleep(500);
	}

	bool dungon[7][49] = {
		0,0,0,0,1,1,1,1,1,0,0,1,1,0,0,1,1,0,1,1,0,0,1,1,0,0,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,0,0,1,1,0,0,0,0,
		0,0,0,0,1,1,0,1,1,1,0,1,1,0,0,1,1,0,1,1,0,0,1,1,0,1,1,0,0,0,0,0,1,1,0,0,1,1,0,1,1,0,0,1,1,0,0,0,0,
		0,0,0,0,1,1,0,0,1,1,0,1,1,0,0,1,1,0,1,1,1,0,1,1,0,1,1,0,0,0,0,0,1,1,0,0,1,1,0,1,1,1,0,1,1,0,0,0,0,
		0,0,0,0,1,1,0,0,1,1,0,1,1,0,0,1,1,0,1,1,0,1,1,1,0,1,1,0,1,1,1,0,1,1,0,0,1,1,0,1,1,0,1,1,1,0,0,0,0,
		0,0,0,0,1,1,0,0,1,1,0,1,1,0,0,1,1,0,1,1,0,0,1,1,0,1,1,0,0,1,1,0,1,1,0,0,1,1,0,1,1,0,0,1,1,0,0,0,0,
		0,0,0,0,1,1,0,1,1,1,0,1,1,0,0,1,1,0,1,1,0,0,1,1,0,1,1,0,0,1,1,0,1,1,0,0,1,1,0,1,1,0,0,1,1,0,0,0,0,
		0,0,0,0,1,1,1,1,1,0,0,0,1,1,1,1,0,0,1,1,0,0,1,1,0,0,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,0,0,1,1,0,0,0,0
	};

	bool expedition[5][49] = {
		1,1,1,1,0,1,0,0,1,0,1,1,1,0,0,1,1,1,1,0,1,1,1,0,0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,0,0,1,
		1,0,0,0,0,1,0,0,1,0,1,0,0,1,0,1,0,0,0,0,1,0,0,1,0,0,1,1,0,0,0,1,1,0,0,0,1,1,0,0,1,0,0,1,0,1,1,0,1,
		1,1,1,0,0,0,1,1,0,0,1,0,0,1,0,1,1,1,0,0,1,0,0,1,0,0,1,1,0,0,0,1,1,0,0,0,1,1,0,0,1,0,0,1,0,1,0,1,1,
		1,0,0,0,0,1,0,0,1,0,1,1,1,0,0,1,0,0,0,0,1,0,0,1,0,0,1,1,0,0,0,1,1,0,0,0,1,1,0,0,1,0,0,1,0,1,0,0,1,
		1,1,1,1,0,1,0,0,1,0,1,0,0,0,0,1,1,1,1,0,1,1,1,0,0,1,1,1,1,0,0,1,1,0,0,1,1,1,1,0,1,1,1,1,0,1,0,0,1,
	};
	SetCursorPosition(0, 3);
	for (int i = 0; i < 7; ++i)
	{
		for (int j = 0; j < 49; ++j)
		{
			if (dungon[i][j]) SetColor(192);
			else SetColor(0);
			printf("  ");
			Sleep(1);
		}
		printf("\n");
	}
	SetCursorPosition(0, 14);
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 49; ++j)
		{
			if (expedition[i][j]) SetColor(192);
			else SetColor(0);
			printf("  ");
			Sleep(1);
		}
		printf("\n");
	}
	SetColor(12);
	SetCursorPosition(21, 30);
	while (_kbhit())
	{
		_getch();
	}
	printf("请按任意键继续");
	while (!_kbhit());
	while (_kbhit())//清除键盘缓存
	{
		_getch();
	}
}

void Shop()
{
	int o;//按键
	int temp;//购买数量
	int maxlife, attack,defense,speed,critical_p,critical_a, penetration,bloodsuck,attack_m,maxpower,defense_m,penetration_m,bloodsuck_m,money;//角色属性
	ifstream rolefile("role.txt");
	rolefile >> maxlife>>attack>>defense>>speed>>critical_p>>critical_a>>penetration>>bloodsuck>>attack_m>>maxpower>>defense_m>>penetration_m>>bloodsuck_m>>money;
	rolefile.close();
	while (1)
	{
		SetColor(14);
		system("cls");
		cout << "当前总金币数量为" << endl << endl;
		cout << "A 当前最大生命为                " << "每1点最大生命需要金币1" << endl << endl;
		cout << "B 当前物理攻击为                " << "每1点物理攻击需要金币12" << endl << endl;
		cout << "C 当前物理防御为                " << "每1点物理防御需要金币6" << endl << endl;
		cout << "D 当前攻击速度为                " << "每1点攻击速度需要金币3" << endl << endl;
		cout << "E 当前暴击几率为                " << "每1%暴击几率需要金币40" << endl << endl;
		cout << "F 当前暴击效果为                " << "每1%点暴击效果需要金币10" << endl << endl;
		cout << "G 当前物理穿透为                " << "每1点物理穿透需要金币7" << endl << endl;
		cout << "H 当前物理吸血为                " << "每1%物理吸血需要金币36" << endl << endl;
		cout << "I 当前法术攻击为                " << "每1点法术攻击需要金币8" << endl << endl;
		cout << "J 当前最大法力为                " << "每10点最大法力需要金币7" << endl << endl;
		cout << "K 当前法术防御为                " << "每1点法术防御需要金币6" << endl << endl;
		cout << "L 当前法术穿透为                " << "每1点法术穿透需要金币7" << endl << endl;
		cout << "M 当前法术吸血为                " << "每1%法术吸血需要金币27" << endl << endl;
		SetCursorPosition(11, 0);
		cout << money;
		SetCursorPosition(11, 2);
		cout << maxlife;
		SetCursorPosition(11, 4);
		cout << attack;
		SetCursorPosition(11, 6);
		cout << defense;
		SetCursorPosition(11, 8);
		cout << speed;
		SetCursorPosition(11, 10);
		cout << critical_p;
		SetCursorPosition(11, 12);
		cout << critical_a;
		SetCursorPosition(11, 14);
		cout << penetration;
		SetCursorPosition(11, 16);
		cout << bloodsuck;
		SetCursorPosition(11, 18);
		cout << attack_m;
		SetCursorPosition(11, 20);
		cout << maxpower;
		SetCursorPosition(11, 22);
		cout << defense_m;
		SetCursorPosition(11, 24);
		cout << penetration_m;
		SetCursorPosition(11, 26);
		cout << bloodsuck_m;
		while (_kbhit())
		{
			_getch();
		}
		
		o = _getch();
		_getch();
		if (o == 97)
		{
			SetColor(15);
			SetCursorPosition(20, 22);
			printf(" +--------------+ ");
			SetCursorPosition(20, 23);
			printf(" |请输入购买数量| ");
			SetCursorPosition(20, 24);
			printf(" |              | ");
			SetCursorPosition(20, 25);
			printf(" |Enter 确定    | ");
			SetCursorPosition(20, 26);
			printf(" +--------------+ ");

			SetCursorPosition(21, 24);
			cin >> temp;

			if (1 * temp <= money)
			{
				maxlife += temp;
				money -= 1 * temp;
				ofstream rolefile("role.txt");
				rolefile << maxlife << '\n' << attack << '\n' << defense << '\n' << speed << '\n' << critical_p << '\n' << critical_a << '\n' << penetration << '\n' << bloodsuck << '\n' << attack_m << '\n' << maxpower << '\n' << defense_m << '\n' << penetration_m << '\n' << bloodsuck_m << '\n' << money << '\n';
				rolefile.close();
			}
			else
			{
				while (true)
				{
					SetColor(15);
					SetCursorPosition(20, 22);
					printf(" +--------------+ ");
					SetCursorPosition(20, 23);
					printf(" |金币不足      | ");
					SetCursorPosition(20, 24);
					printf(" |              | ");
					SetCursorPosition(20, 25);
					printf(" |Enter 确定    | ");
					SetCursorPosition(20, 26);
					printf(" +--------------+ ");

					SetCursorPosition(21, 24);
					cin >> temp;

					if (1 * temp <= money)
					{
						maxlife += temp;
						money -= 1 * temp;
						ofstream rolefile("role.txt");
						rolefile << maxlife << '\n' << attack << '\n' << defense << '\n' << speed << '\n' << critical_p << '\n' << critical_a << '\n' << penetration << '\n' << bloodsuck << '\n' << attack_m << '\n' << maxpower << '\n' << defense_m << '\n' << penetration_m << '\n' << bloodsuck_m << '\n' << money << '\n';
						rolefile.close();
						break;
					}
				}
			}
		}

		else if (o == 98)
		{
			SetColor(15);
			SetCursorPosition(20, 22);
			printf(" +--------------+ ");
			SetCursorPosition(20, 23);
			printf(" |请输入购买数量| ");
			SetCursorPosition(20, 24);
			printf(" |              | ");
			SetCursorPosition(20, 25);
			printf(" |Enter 确定    | ");
			SetCursorPosition(20, 26);
			printf(" +--------------+ ");

			SetCursorPosition(21, 24);
			cin >> temp;

			if (12 * temp <= money)
			{
				attack += temp;
				money -= 12 * temp;
				ofstream rolefile("role.txt");
				rolefile << maxlife << '\n' << attack << '\n' << defense << '\n' << speed << '\n' << critical_p << '\n' << critical_a << '\n' << penetration << '\n' << bloodsuck << '\n' << attack_m << '\n' << maxpower << '\n' << defense_m << '\n' << penetration_m << '\n' << bloodsuck_m << '\n' << money << '\n';
				rolefile.close();
			}
			else
			{
				while (true)
				{
					SetColor(15);
					SetCursorPosition(20, 22);
					printf(" +--------------+ ");
					SetCursorPosition(20, 23);
					printf(" |金币不足      | ");
					SetCursorPosition(20, 24);
					printf(" |              | ");
					SetCursorPosition(20, 25);
					printf(" |Enter 确定    | ");
					SetCursorPosition(20, 26);
					printf(" +--------------+ ");

					SetCursorPosition(21, 24);
					cin >> temp;

					if (12 * temp <= money)
					{
						attack += temp;
						money -= 12 * temp;
						ofstream rolefile("role.txt");
						rolefile << maxlife << '\n' << attack << '\n' << defense << '\n' << speed << '\n' << critical_p << '\n' << critical_a << '\n' << penetration << '\n' << bloodsuck << '\n' << attack_m << '\n' << maxpower << '\n' << defense_m << '\n' << penetration_m << '\n' << bloodsuck_m << '\n' << money << '\n';
						rolefile.close();
						break;
					}
				}
			}
		}

		else if (o == 99)
		{
			SetColor(15);
			SetCursorPosition(20, 22);
			printf(" +--------------+ ");
			SetCursorPosition(20, 23);
			printf(" |请输入购买数量| ");
			SetCursorPosition(20, 24);
			printf(" |              | ");
			SetCursorPosition(20, 25);
			printf(" |Enter 确定    | ");
			SetCursorPosition(20, 26);
			printf(" +--------------+ ");

			SetCursorPosition(21, 24);
			cin >> temp;

			if (6 * temp <= money)
			{
				defense += temp;
				money -= 6 * temp;
				ofstream rolefile("role.txt");
				rolefile << maxlife << '\n' << attack << '\n' << defense << '\n' << speed << '\n' << critical_p << '\n' << critical_a << '\n' << penetration << '\n' << bloodsuck << '\n' << attack_m << '\n' << maxpower << '\n' << defense_m << '\n' << penetration_m << '\n' << bloodsuck_m << '\n' << money << '\n';
				rolefile.close();
			}
			else
			{
				while (true)
				{
					SetColor(15);
					SetCursorPosition(20, 22);
					printf(" +--------------+ ");
					SetCursorPosition(20, 23);
					printf(" |金币不足      | ");
					SetCursorPosition(20, 24);
					printf(" |              | ");
					SetCursorPosition(20, 25);
					printf(" |Enter 确定    | ");
					SetCursorPosition(20, 26);
					printf(" +--------------+ ");

					SetCursorPosition(21, 24);
					cin >> temp;

					if (6 * temp <= money)
					{
						defense += temp;
						money -= 6 * temp;
						ofstream rolefile("role.txt");
						rolefile << maxlife << '\n' << attack << '\n' << defense << '\n' << speed << '\n' << critical_p << '\n' << critical_a << '\n' << penetration << '\n' << bloodsuck << '\n' << attack_m << '\n' << maxpower << '\n' << defense_m << '\n' << penetration_m << '\n' << bloodsuck_m << '\n' << money << '\n';
						rolefile.close();
						break;
					}
				}
			}
		}

		else if (o == 100)
		{
			SetColor(15);
			SetCursorPosition(20, 22);
			printf(" +--------------+ ");
			SetCursorPosition(20, 23);
			printf(" |请输入购买数量| ");
			SetCursorPosition(20, 24);
			printf(" |              | ");
			SetCursorPosition(20, 25);
			printf(" |Enter 确定    | ");
			SetCursorPosition(20, 26);
			printf(" +--------------+ ");

			SetCursorPosition(21, 24);
			cin >> temp;

			if (3 * temp <= money)
			{
				speed += temp;
				money -= 3 * temp;
				ofstream rolefile("role.txt");
				rolefile << maxlife << '\n' << attack << '\n' << defense << '\n' << speed << '\n' << critical_p << '\n' << critical_a << '\n' << penetration << '\n' << bloodsuck << '\n' << attack_m << '\n' << maxpower << '\n' << defense_m << '\n' << penetration_m << '\n' << bloodsuck_m << '\n' << money << '\n';
				rolefile.close();
			}
			else
			{
				while (true)
				{
					SetColor(15);
					SetCursorPosition(20, 22);
					printf(" +--------------+ ");
					SetCursorPosition(20, 23);
					printf(" |金币不足      | ");
					SetCursorPosition(20, 24);
					printf(" |              | ");
					SetCursorPosition(20, 25);
					printf(" |Enter 确定    | ");
					SetCursorPosition(20, 26);
					printf(" +--------------+ ");

					SetCursorPosition(21, 24);
					cin >> temp;

					if (3 * temp <= money)
					{
						speed += temp;
						money -= 3 * temp;
						ofstream rolefile("role.txt");
						rolefile << maxlife << '\n' << attack << '\n' << defense << '\n' << speed << '\n' << critical_p << '\n' << critical_a << '\n' << penetration << '\n' << bloodsuck << '\n' << attack_m << '\n' << maxpower << '\n' << defense_m << '\n' << penetration_m << '\n' << bloodsuck_m << '\n' << money << '\n';
						rolefile.close();
						break;
					}
				}
			}
		}

		else if (o == 101)
		{
			SetColor(15);
			SetCursorPosition(20, 22);
			printf(" +--------------+ ");
			SetCursorPosition(20, 23);
			printf(" |请输入购买数量| ");
			SetCursorPosition(20, 24);
			printf(" |              | ");
			SetCursorPosition(20, 25);
			printf(" |Enter 确定    | ");
			SetCursorPosition(20, 26);
			printf(" +--------------+ ");

			SetCursorPosition(21, 24);
			cin >> temp;

			if (40 * temp <= money)
			{
				critical_p += temp;
				money -= 40 * temp;
				ofstream rolefile("role.txt");
				rolefile << maxlife << '\n' << attack << '\n' << defense << '\n' << speed << '\n' << critical_p << '\n' << critical_a << '\n' << penetration << '\n' << bloodsuck << '\n' << attack_m << '\n' << maxpower << '\n' << defense_m << '\n' << penetration_m << '\n' << bloodsuck_m << '\n' << money << '\n';
				rolefile.close();
			}
			else
			{
				while (true)
				{
					SetColor(15);
					SetCursorPosition(20, 22);
					printf(" +--------------+ ");
					SetCursorPosition(20, 23);
					printf(" |金币不足      | ");
					SetCursorPosition(20, 24);
					printf(" |              | ");
					SetCursorPosition(20, 25);
					printf(" |Enter 确定    | ");
					SetCursorPosition(20, 26);
					printf(" +--------------+ ");

					SetCursorPosition(21, 24);
					cin >> temp;

					if (40 * temp <= money)
					{
						critical_p += temp;
						money -= 40 * temp;
						ofstream rolefile("role.txt");
						rolefile << maxlife << '\n' << attack << '\n' << defense << '\n' << speed << '\n' << critical_p << '\n' << critical_a << '\n' << penetration << '\n' << bloodsuck << '\n' << attack_m << '\n' << maxpower << '\n' << defense_m << '\n' << penetration_m << '\n' << bloodsuck_m << '\n' << money << '\n';
						rolefile.close();
						break;
					}
				}
			}
		}
		else if (o == 102)
		{
			SetColor(15);
			SetCursorPosition(20, 22);
			printf(" +--------------+ ");
			SetCursorPosition(20, 23);
			printf(" |请输入购买数量| ");
			SetCursorPosition(20, 24);
			printf(" |              | ");
			SetCursorPosition(20, 25);
			printf(" |Enter 确定    | ");
			SetCursorPosition(20, 26);
			printf(" +--------------+ ");

			SetCursorPosition(21, 24);
			cin >> temp;

			if (10 * temp <= money)
			{
				critical_a += temp;
				money -= 10 * temp;
				ofstream rolefile("role.txt");
				rolefile << maxlife << '\n' << attack << '\n' << defense << '\n' << speed << '\n' << critical_p << '\n' << critical_a << '\n' << penetration << '\n' << bloodsuck << '\n' << attack_m << '\n' << maxpower << '\n' << defense_m << '\n' << penetration_m << '\n' << bloodsuck_m << '\n' << money << '\n';
				rolefile.close();
			}
			else
			{
				while (true)
				{
					SetColor(15);
					SetCursorPosition(20, 22);
					printf(" +--------------+ ");
					SetCursorPosition(20, 23);
					printf(" |金币不足      | ");
					SetCursorPosition(20, 24);
					printf(" |              | ");
					SetCursorPosition(20, 25);
					printf(" |Enter 确定    | ");
					SetCursorPosition(20, 26);
					printf(" +--------------+ ");

					SetCursorPosition(21, 24);
					cin >> temp;

					if (10 * temp <= money)
					{
						critical_a += temp;
						money -= 10 * temp;
						ofstream rolefile("role.txt");
						rolefile << maxlife << '\n' << attack << '\n' << defense << '\n' << speed << '\n' << critical_p << '\n' << critical_a << '\n' << penetration << '\n' << bloodsuck << '\n' << attack_m << '\n' << maxpower << '\n' << defense_m << '\n' << penetration_m << '\n' << bloodsuck_m << '\n' << money << '\n';
						rolefile.close();
						break;
					}
				}
			}
		}

		else if (o == 103)
		{
			SetColor(15);
			SetCursorPosition(20, 22);
			printf(" +--------------+ ");
			SetCursorPosition(20, 23);
			printf(" |请输入购买数量| ");
			SetCursorPosition(20, 24);
			printf(" |              | ");
			SetCursorPosition(20, 25);
			printf(" |Enter 确定    | ");
			SetCursorPosition(20, 26);
			printf(" +--------------+ ");

			SetCursorPosition(21, 24);
			cin >> temp;

			if (7 * temp <= money)
			{
				penetration += temp;
				money -= 7 * temp;
				ofstream rolefile("role.txt");
				rolefile << maxlife << '\n' << attack << '\n' << defense << '\n' << speed << '\n' << critical_p << '\n' << critical_a << '\n' << penetration << '\n' << bloodsuck << '\n' << attack_m << '\n' << maxpower << '\n' << defense_m << '\n' << penetration_m << '\n' << bloodsuck_m << '\n' << money << '\n';
				rolefile.close();
			}
			else
			{
				while (true)
				{
					SetColor(15);
					SetCursorPosition(20, 22);
					printf(" +--------------+ ");
					SetCursorPosition(20, 23);
					printf(" |金币不足      | ");
					SetCursorPosition(20, 24);
					printf(" |              | ");
					SetCursorPosition(20, 25);
					printf(" |Enter 确定    | ");
					SetCursorPosition(20, 26);
					printf(" +--------------+ ");

					SetCursorPosition(21, 24);
					cin >> temp;

					if (7 * temp <= money)
					{
						penetration += temp;
						money -= 7 * temp;
						ofstream rolefile("role.txt");
						rolefile << maxlife << '\n' << attack << '\n' << defense << '\n' << speed << '\n' << critical_p << '\n' << critical_a << '\n' << penetration << '\n' << bloodsuck << '\n' << attack_m << '\n' << maxpower << '\n' << defense_m << '\n' << penetration_m << '\n' << bloodsuck_m << '\n' << money << '\n';
						rolefile.close();
						break;
					}
				}
			}
		}

		else if (o == 104)
		{
			SetColor(15);
			SetCursorPosition(20, 22);
			printf(" +--------------+ ");
			SetCursorPosition(20, 23);
			printf(" |请输入购买数量| ");
			SetCursorPosition(20, 24);
			printf(" |              | ");
			SetCursorPosition(20, 25);
			printf(" |Enter 确定    | ");
			SetCursorPosition(20, 26);
			printf(" +--------------+ ");

			SetCursorPosition(21, 24);
			cin >> temp;

			if (36 * temp <= money)
			{
				penetration += temp;
				money -= 36 * temp;
				ofstream rolefile("role.txt");
				rolefile << maxlife << '\n' << attack << '\n' << defense << '\n' << speed << '\n' << critical_p << '\n' << critical_a << '\n' << penetration << '\n' << bloodsuck << '\n' << attack_m << '\n' << maxpower << '\n' << defense_m << '\n' << penetration_m << '\n' << bloodsuck_m << '\n' << money << '\n';
				rolefile.close();
			}
			else
			{
				while (true)
				{
					SetColor(15);
					SetCursorPosition(20, 22);
					printf(" +--------------+ ");
					SetCursorPosition(20, 23);
					printf(" |金币不足      | ");
					SetCursorPosition(20, 24);
					printf(" |              | ");
					SetCursorPosition(20, 25);
					printf(" |Enter 确定    | ");
					SetCursorPosition(20, 26);
					printf(" +--------------+ ");

					SetCursorPosition(21, 24);
					cin >> temp;

					if (36 * temp <= money)
					{
						bloodsuck += temp;
						money -= 36 * temp;
						ofstream rolefile("role.txt");
						rolefile << maxlife << '\n' << attack << '\n' << defense << '\n' << speed << '\n' << critical_p << '\n' << critical_a << '\n' << penetration << '\n' << bloodsuck << '\n' << attack_m << '\n' << maxpower << '\n' << defense_m << '\n' << penetration_m << '\n' << bloodsuck_m << '\n' << money << '\n';
						rolefile.close();
						break;
					}
				}
			}
		}

		else if (o == 105)
		{
			SetColor(15);
			SetCursorPosition(20, 22);
			printf(" +--------------+ ");
			SetCursorPosition(20, 23);
			printf(" |请输入购买数量| ");
			SetCursorPosition(20, 24);
			printf(" |              | ");
			SetCursorPosition(20, 25);
			printf(" |Enter 确定    | ");
			SetCursorPosition(20, 26);
			printf(" +--------------+ ");

			SetCursorPosition(21, 24);
			cin >> temp;

			if (8 * temp <= money)
			{
				attack_m += temp;
				money -= 8 * temp;
				ofstream rolefile("role.txt");
				rolefile << maxlife << '\n' << attack << '\n' << defense << '\n' << speed << '\n' << critical_p << '\n' << critical_a << '\n' << penetration << '\n' << bloodsuck << '\n' << attack_m << '\n' << maxpower << '\n' << defense_m << '\n' << penetration_m << '\n' << bloodsuck_m << '\n' << money << '\n';
				rolefile.close();
			}
			else
			{
				while (true)
				{
					SetColor(15);
					SetCursorPosition(20, 22);
					printf(" +--------------+ ");
					SetCursorPosition(20, 23);
					printf(" |金币不足      | ");
					SetCursorPosition(20, 24);
					printf(" |              | ");
					SetCursorPosition(20, 25);
					printf(" |Enter 确定    | ");
					SetCursorPosition(20, 26);
					printf(" +--------------+ ");

					SetCursorPosition(21, 24);
					cin >> temp;

					if (8 * temp <= money)
					{
						attack_m += temp;
						money -= 8 * temp;
						ofstream rolefile("role.txt");
						rolefile << maxlife << '\n' << attack << '\n' << defense << '\n' << speed << '\n' << critical_p << '\n' << critical_a << '\n' << penetration << '\n' << bloodsuck << '\n' << attack_m << '\n' << maxpower << '\n' << defense_m << '\n' << penetration_m << '\n' << bloodsuck_m << '\n' << money << '\n';
						rolefile.close();
						break;
					}
				}
			}
		}

		else if (o == 106)
		{
			SetColor(15);
			SetCursorPosition(20, 22);
			printf(" +--------------+ ");
			SetCursorPosition(20, 23);
			printf(" |请输入购买数量| ");
			SetCursorPosition(20, 24);
			printf(" |              | ");
			SetCursorPosition(20, 25);
			printf(" |Enter 确定    | ");
			SetCursorPosition(20, 26);
			printf(" +--------------+ ");

			SetCursorPosition(21, 24);
			cin >> temp;

			if (7 * temp <= money)
			{
				maxpower += 10 * temp;
				money -= 7 * temp;
				ofstream rolefile("role.txt");
				rolefile << maxlife << '\n' << attack << '\n' << defense << '\n' << speed << '\n' << critical_p << '\n' << critical_a << '\n' << penetration << '\n' << bloodsuck << '\n' << attack_m << '\n' << maxpower << '\n' << defense_m << '\n' << penetration_m << '\n' << bloodsuck_m << '\n' << money << '\n';
				rolefile.close();
			}
			else
			{
				while (true)
				{
					SetColor(15);
					SetCursorPosition(20, 22);
					printf(" +--------------+ ");
					SetCursorPosition(20, 23);
					printf(" |金币不足      | ");
					SetCursorPosition(20, 24);
					printf(" |              | ");
					SetCursorPosition(20, 25);
					printf(" |Enter 确定    | ");
					SetCursorPosition(20, 26);
					printf(" +--------------+ ");

					SetCursorPosition(21, 24);
					cin >> temp;

					if (7 * temp <= money)
					{
						maxpower += 10 * temp;
						money -= 7 * temp;
						ofstream rolefile("role.txt");
						rolefile << maxlife << '\n' << attack << '\n' << defense << '\n' << speed << '\n' << critical_p << '\n' << critical_a << '\n' << penetration << '\n' << bloodsuck << '\n' << attack_m << '\n' << maxpower << '\n' << defense_m << '\n' << penetration_m << '\n' << bloodsuck_m << '\n' << money << '\n';
						rolefile.close();
						break;
					}
				}
			}
		}

		else if (o == 107)
		{
			SetColor(15);
			SetCursorPosition(20, 22);
			printf(" +--------------+ ");
			SetCursorPosition(20, 23);
			printf(" |请输入购买数量| ");
			SetCursorPosition(20, 24);
			printf(" |              | ");
			SetCursorPosition(20, 25);
			printf(" |Enter 确定    | ");
			SetCursorPosition(20, 26);
			printf(" +--------------+ ");

			SetCursorPosition(21, 24);
			cin >> temp;

			if (6 * temp <= money)
			{
				defense_m += temp;
				money -= 6 * temp;
				ofstream rolefile("role.txt");
				rolefile << maxlife << '\n' << attack << '\n' << defense << '\n' << speed << '\n' << critical_p << '\n' << critical_a << '\n' << penetration << '\n' << bloodsuck << '\n' << attack_m << '\n' << maxpower << '\n' << defense_m << '\n' << penetration_m << '\n' << bloodsuck_m << '\n' << money << '\n';
				rolefile.close();
			}
			else
			{
				while (true)
				{
					SetColor(15);
					SetCursorPosition(20, 22);
					printf(" +--------------+ ");
					SetCursorPosition(20, 23);
					printf(" |金币不足      | ");
					SetCursorPosition(20, 24);
					printf(" |              | ");
					SetCursorPosition(20, 25);
					printf(" |Enter 确定    | ");
					SetCursorPosition(20, 26);
					printf(" +--------------+ ");

					SetCursorPosition(21, 24);
					cin >> temp;

					if (6 * temp <= money)
					{
						defense_m += temp;
						money -= 6 * temp;
						ofstream rolefile("role.txt");
						rolefile << maxlife << '\n' << attack << '\n' << defense << '\n' << speed << '\n' << critical_p << '\n' << critical_a << '\n' << penetration << '\n' << bloodsuck << '\n' << attack_m << '\n' << maxpower << '\n' << defense_m << '\n' << penetration_m << '\n' << bloodsuck_m << '\n' << money << '\n';
						rolefile.close();
						break;
					}
				}
			}
		}

		else if (o == 108)
		{
			SetColor(15);
			SetCursorPosition(20, 22);
			printf(" +--------------+ ");
			SetCursorPosition(20, 23);
			printf(" |请输入购买数量| ");
			SetCursorPosition(20, 24);
			printf(" |              | ");
			SetCursorPosition(20, 25);
			printf(" |Enter 确定    | ");
			SetCursorPosition(20, 26);
			printf(" +--------------+ ");

			SetCursorPosition(21, 24);
			cin >> temp;

			if (7 * temp <= money)
			{
				penetration_m += temp;
				money -= 7 * temp;
				ofstream rolefile("role.txt");
				rolefile << maxlife << '\n' << attack << '\n' << defense << '\n' << speed << '\n' << critical_p << '\n' << critical_a << '\n' << penetration << '\n' << bloodsuck << '\n' << attack_m << '\n' << maxpower << '\n' << defense_m << '\n' << penetration_m << '\n' << bloodsuck_m << '\n' << money << '\n';
				rolefile.close();
			}
			else
			{
				while (true)
				{
					SetColor(15);
					SetCursorPosition(20, 22);
					printf(" +--------------+ ");
					SetCursorPosition(20, 23);
					printf(" |金币不足      | ");
					SetCursorPosition(20, 24);
					printf(" |              | ");
					SetCursorPosition(20, 25);
					printf(" |Enter 确定    | ");
					SetCursorPosition(20, 26);
					printf(" +--------------+ ");

					SetCursorPosition(21, 24);
					cin >> temp;

					if (7 * temp <= money)
					{
						penetration_m += temp;
						money -= 7 * temp;
						ofstream rolefile("role.txt");
						rolefile << maxlife << '\n' << attack << '\n' << defense << '\n' << speed << '\n' << critical_p << '\n' << critical_a << '\n' << penetration << '\n' << bloodsuck << '\n' << attack_m << '\n' << maxpower << '\n' << defense_m << '\n' << penetration_m << '\n' << bloodsuck_m << '\n' << money << '\n';
						rolefile.close();
						break;
					}
				}
			}
		}

		else if (o == 109)
		{
			SetColor(15);
			SetCursorPosition(20, 22);
			printf(" +--------------+ ");
			SetCursorPosition(20, 23);
			printf(" |请输入购买数量| ");
			SetCursorPosition(20, 24);
			printf(" |              | ");
			SetCursorPosition(20, 25);
			printf(" |Enter 确定    | ");
			SetCursorPosition(20, 26);
			printf(" +--------------+ ");

			SetCursorPosition(21, 24);
			cin >> temp;

			if (27 * temp <= money)
			{
				bloodsuck_m += temp;
				money -= 27 * temp;
				ofstream rolefile("role.txt");
				rolefile << maxlife << '\n' << attack << '\n' << defense << '\n' << speed << '\n' << critical_p << '\n' << critical_a << '\n' << penetration << '\n' << bloodsuck << '\n' << attack_m << '\n' << maxpower << '\n' << defense_m << '\n' << penetration_m << '\n' << bloodsuck_m << '\n' << money << '\n';
				rolefile.close();
			}
			else
			{
				while (true)
				{
					SetColor(15);
					SetCursorPosition(20, 22);
					printf(" +--------------+ ");
					SetCursorPosition(20, 23);
					printf(" |金币不足      | ");
					SetCursorPosition(20, 24);
					printf(" |              | ");
					SetCursorPosition(20, 25);
					printf(" |Enter 确定    | ");
					SetCursorPosition(20, 26);
					printf(" +--------------+ ");

					SetCursorPosition(21, 24);
					cin >> temp;

					if (27 * temp <= money)
					{
						bloodsuck_m += temp;
						money -= 27 * temp;
						ofstream rolefile("role.txt");
						rolefile << maxlife << '\n' << attack << '\n' << defense << '\n' << speed << '\n' << critical_p << '\n' << critical_a << '\n' << penetration << '\n' << bloodsuck << '\n' << attack_m << '\n' << maxpower << '\n' << defense_m << '\n' << penetration_m << '\n' << bloodsuck_m << '\n' << money << '\n';
						rolefile.close();
						break;
					}
				}
			}
		}

		else if (o == 13)break;

	}
}

void Map(int map[], int mapcolour[], int& bornpointx, int& bornpointy,int stage)
{
	for (int j = 0; j < 49; ++j)
	{
		for (int k = 0; k < 49; ++k)
		{
			map[k * 50 + j] = 0;
		}
	}
	srand(time(0));
	bornpointx = 24;
	bornpointy = 24;
	map[24 * 50 + 24] = 2;
	int x = 24, y = 24;
	int temp, temp2,temp3;//随机数
	int dir;//方向
	int floorx[625] = {};//储存地面；
	int floory[625] = {};
	int floornow = 0;//储存指向第几个地面
	dir = rand() % 4;
	for (int i = 1; i <= 624; i++)
	{
		temp = rand() % 7;
		if (temp >= 4)
		{
			dir = ((temp - 3) + dir) % 4;
		}
		if (dir == 0)
		{
			if (y < 2)continue;
			--y;
		}
		if (dir == 1)
		{
			if (x < 2)continue;
			--x;
		}
		if (dir == 2)
		{
			if (y > 46)continue;
			++y;
		}
		if (dir == 3)
		{
			if (x > 46)continue;
			++x;
		}
		map[y * 50 + x] = 2;
		
	}

	for (int j = 0; j < 49; ++j)
	{
		for (int k = 0; k < 49; ++k)
		{
			if (map[k * 50 + j] == 2)
			{
				temp2 = rand() % 30;
				if ((temp2 == 0) && (!((j == bornpointx) && (k == bornpointy))))
				{
					map[k * 50 + j] = 4;//宝箱
				}
				else if ((temp2 < 4) && (!((j == bornpointx) && (k == bornpointy))))
				{
					
					temp3 = rand() % 4;
					if (temp3 < 1)
					{
						map[k * 50 + j] = 100 + stage;
					}
					else if (temp3 < 3)
					{
						map[k * 50 + j] = 101 + stage;
					}
					else
					{
						map[k * 50 + j] = 102 + stage;
					}
				}
			}
		}
	}

	for (int j = 0; j < 49; ++j)
	{
		for (int k = 0; k < 49; ++k)
		{
			if (map[k * 50 + j] == 2)
			{
				floorx[floornow] = j;
				floory[floornow] = k;
				++floornow;
			}
		}
	}
	while (1)
	{
		temp2 = rand() % floornow;
		if (!((floorx[temp2] == bornpointx) && (floory[temp2] == bornpointy)))
		{
			map[floory[temp2] * 50 + floorx[temp2]] = 3;//出口
			break;
		}
	}

	for (int j = 0; j < 49; ++j)//加墙
	{
		for (int k = 0; k < 49; ++k)
		{
			if ((map[k * 50 + j] != 0) && (map[k * 50 + j] != 1))
			{
				if (map[(k - 1) * 50 + j - 1] == 0) map[(k - 1) * 50 + j - 1] = 1;
				if (map[(k - 1) * 50 + j] == 0) map[(k - 1) * 50 + j] = 1;
				if (map[k * 50 + j - 1] == 0) map[k * 50 + j - 1] = 1;
				if (map[(k - 1) * 50 + j + 1] == 0) map[(k - 1) * 50 + j + 1] = 1;
				if (map[(k + 1) * 50 + j - 1] == 0) map[(k + 1) * 50 + j - 1] = 1;
				if (map[(k + 1) * 50 + j + 1] == 0) map[(k + 1) * 50 + j + 1] = 1;
				if (map[(k + 1) * 50 + j] == 0) map[(k + 1) * 50 + j] = 1;
				if (map[k * 50 + j + 1] == 0) map[k * 50 + j + 1] = 1;
			}
		}
	}
	for (int j = 0; j < 49; ++j)
	{
		for (int k = 0; k < 49; ++k)
		{
			if (map[k * 50 + j] == 0)//虚空
			{
				mapcolour[k * 50 + j] = 0;
			}
			else if (map[k * 50 + j] == 1)//墙
			{
				mapcolour[k * 50 + j] = 16;
			}
			else if (map[k * 50 + j] == 2)//地面
			{
				mapcolour[k * 50 + j] = 128;
			}
			else if (map[k * 50 + j] == 3)//出口
			{
				mapcolour[k * 50 + j] = 160;
			}
			else if (map[k * 50 + j] == 4)//宝箱
			{
				mapcolour[k * 50 + j] = 224;
			}
			else if ((map[k * 50 + j] > 100) && (map[k * 50 + j] < 200))//怪物
			{
				mapcolour[k * 50 + j] = 208;
			}
		}
	}
	system("cls");
	for (int j = 0; j < 49; ++j)
	{
		for (int k = 0; k < 49; ++k)
		{
			SetColor(mapcolour[k * 50 + j]);
			SetCursorPosition(k, j);
			printf("  ");
		}
	}
	/*while (_kbhit())
	{
	_getch();
	}
	while (!_kbhit());*/
}


int battle(int id, int maxlife, int &life, int attack, int defense, int speed, int critical_p, int critical_a, int penetration, int bloodsuck, int attack_m, int maxpower, int& power, int defense_m, int penetration_m, int bloodsuck_m, int& money)
{
	int rate_r=0, rate_m=0;
	Monster mons(id);
	
	while (1)
	{
		system("cls");
		SetColor(12);
		SetCursorPosition(0, 0);
		cout << "攻击进度：" << rate_r << '/' << "100000";
		SetCursorPosition(0, 24);
		cout << "生命：" << life << '/' << maxlife;
		SetCursorPosition(0, 25);
		cout << "物理攻击：" << attack;
		SetCursorPosition(0, 26);
		cout << "物理防御：" << defense;
		SetCursorPosition(0, 27);
		cout << "攻击速度：" << speed;
		SetCursorPosition(0, 28);
		cout << "暴击机率：" << critical_p;
		SetCursorPosition(0, 29);
		cout << "暴击效果：" << critical_a;
		SetCursorPosition(0, 30);
		cout << "物理穿透：" << penetration;
		SetCursorPosition(0, 31);
		cout << "物理吸血：" << bloodsuck;
		SetCursorPosition(0, 32);
		cout << "法术攻击：" << attack_m;
		SetCursorPosition(0, 33);
		cout << "法力：" << power << '/' << maxpower;
		SetCursorPosition(0, 34);
		cout << "法术防御：" << defense_m;
		SetCursorPosition(0, 35);
		cout << "法术穿透：" << penetration_m;
		SetCursorPosition(0, 36);
		cout << "法术吸血：" << bloodsuck_m;

		SetColor(13);
		SetCursorPosition(25, 0);
		cout << "攻击进度：" << rate_m << '/' << "100000";
		SetCursorPosition(25, 24);
		cout << "生命：" << mons.life << '/' << mons.maxlife;
		SetCursorPosition(25, 25);
		cout << "物理攻击：" << mons.attack;
		SetCursorPosition(25, 26);
		cout << "物理防御：" << mons.defense;
		SetCursorPosition(25, 27);
		cout << "攻击速度：" << mons.speed;
		SetCursorPosition(25, 28);
		cout << "暴击机率：" << mons.critical_p;
		SetCursorPosition(25, 29);
		cout << "暴击效果：" << mons.critical_a;
		SetCursorPosition(25, 30);
		cout << "物理穿透：" << mons.penetration;
		SetCursorPosition(25, 31);
		cout << "物理吸血：" << mons.bloodsuck;
		SetCursorPosition(25, 32);
		cout << "法术攻击：" << mons.attack_m;
		SetCursorPosition(25, 34);
		cout << "法术防御：" << mons.defense_m;
		SetCursorPosition(25, 35);
		cout << "法术穿透：" << mons.penetration_m;
		SetCursorPosition(25, 36);
		cout << "法术吸血：" << mons.bloodsuck_m;
		Sleep(500);
		if (life <= 0)
		{
			return 3;
		}

		else if (mons.life <= 0)
		{
			money += mons.money;//需要打开文件操作
			ofstream rolefile("role.txt");
			rolefile << maxlife << '\n' << attack << '\n' << defense << '\n' << speed << '\n' << critical_p << '\n' << critical_a << '\n' << penetration << '\n' << bloodsuck << '\n' << attack_m << '\n' << maxpower << '\n' << defense_m << '\n' << penetration_m << '\n' << bloodsuck_m << '\n' << money << '\n';
			rolefile.close();

			return 2;
		}
		while (true)
		{
			rate_r += speed;
			rate_m += mons.speed;
			if ((rate_r >= 100000) || (rate_m >= 100000))break;
		}

		if ((rate_r >= 100000) && (rate_m >= 100000))
		{
			if (rate_r >= rate_m)
			{
				SetColor(12);
				SetCursorPosition(0, 1);
				cout << "你的回合";
				if(mons.be_attacked_mode(id, maxlife, life, attack, defense, speed, critical_p, critical_a, penetration, bloodsuck, attack_m, maxpower, power, defense_m, penetration_m, bloodsuck_m, money)) return 1;//逃跑
				rate_r -= 100000;
				system("cls");
				SetColor(12);
				SetCursorPosition(0, 0);
				cout << "攻击进度：" << rate_r << '/' << "100000";
				SetCursorPosition(0, 24);
				cout << "生命：" << life << '/' << maxlife;
				SetCursorPosition(0, 25);
				cout << "物理攻击：" << attack;
				SetCursorPosition(0, 26);
				cout << "物理防御：" << defense;
				SetCursorPosition(0, 27);
				cout << "攻击速度：" << speed;
				SetCursorPosition(0, 28);
				cout << "暴击机率：" << critical_p;
				SetCursorPosition(0, 29);
				cout << "暴击效果：" << critical_a;
				SetCursorPosition(0, 30);
				cout << "物理穿透：" << penetration;
				SetCursorPosition(0, 31);
				cout << "物理吸血：" << bloodsuck;
				SetCursorPosition(0, 32);
				cout << "法术攻击：" << attack_m;
				SetCursorPosition(0, 33);
				cout << "法力：" << power << '/' << maxpower;
				SetCursorPosition(0, 34);
				cout << "法术防御：" << defense_m;
				SetCursorPosition(0, 35);
				cout << "法术穿透：" << penetration_m;
				SetCursorPosition(0, 36);
				cout << "法术吸血：" << bloodsuck_m;

				SetColor(13);
				SetCursorPosition(25, 0);
				cout << "攻击进度：" << rate_m << '/' << "100000";
				SetCursorPosition(25, 24);
				cout << "生命：" << mons.life << '/' << mons.maxlife;
				SetCursorPosition(25, 25);
				cout << "物理攻击：" << mons.attack;
				SetCursorPosition(25, 26);
				cout << "物理防御：" << mons.defense;
				SetCursorPosition(25, 27);
				cout << "攻击速度：" << mons.speed;
				SetCursorPosition(25, 28);
				cout << "暴击机率：" << mons.critical_p;
				SetCursorPosition(25, 29);
				cout << "暴击效果：" << mons.critical_a;
				SetCursorPosition(25, 30);
				cout << "物理穿透：" << mons.penetration;
				SetCursorPosition(25, 31);
				cout << "物理吸血：" << mons.bloodsuck;
				SetCursorPosition(25, 32);
				cout << "法术攻击：" << mons.attack_m;
				SetCursorPosition(25, 34);
				cout << "法术防御：" << mons.defense_m;
				SetCursorPosition(25, 35);
				cout << "法术穿透：" << mons.penetration_m;
				SetCursorPosition(25, 36);
				cout << "法术吸血：" << mons.bloodsuck_m;
				Sleep(500);
				if (life <= 0)
				{
					return 3;
				}

				else if (mons.life <= 0)
				{
					money += mons.money;//需要打开文件操作
					ofstream rolefile("role.txt");
					rolefile << maxlife << '\n' << attack << '\n' << defense << '\n' << speed << '\n' << critical_p << '\n' << critical_a << '\n' << penetration << '\n' << bloodsuck << '\n' << attack_m << '\n' << maxpower << '\n' << defense_m << '\n' << penetration_m << '\n' << bloodsuck_m << '\n' << money << '\n';
					rolefile.close();

					return 2;
				}

				SetColor(13);
				SetCursorPosition(25, 1);
				cout << "敌人的回合";
				Sleep(500);
				mons.attack_mode(id, maxlife, life, attack, defense, speed, critical_p, critical_a, penetration, bloodsuck, attack_m, maxpower, power, defense_m, penetration_m, bloodsuck_m, money);
				rate_m -= 100000;
			}
			else
			{
				SetColor(13);
				SetCursorPosition(25, 1);
				cout << "敌人的回合";
				Sleep(500);
				mons.attack_mode(id, maxlife, life, attack, defense, speed, critical_p, critical_a, penetration, bloodsuck, attack_m, maxpower, power, defense_m, penetration_m, bloodsuck_m, money);
				rate_m -= 100000;
				system("cls");
				SetColor(12);
				SetCursorPosition(0, 0);
				cout << "攻击进度：" << rate_r << '/' << "100000";
				SetCursorPosition(0, 24);
				cout << "生命：" << life << '/' << maxlife;
				SetCursorPosition(0, 25);
				cout << "物理攻击：" << attack;
				SetCursorPosition(0, 26);
				cout << "物理防御：" << defense;
				SetCursorPosition(0, 27);
				cout << "攻击速度：" << speed;
				SetCursorPosition(0, 28);
				cout << "暴击机率：" << critical_p;
				SetCursorPosition(0, 29);
				cout << "暴击效果：" << critical_a;
				SetCursorPosition(0, 30);
				cout << "物理穿透：" << penetration;
				SetCursorPosition(0, 31);
				cout << "物理吸血：" << bloodsuck;
				SetCursorPosition(0, 32);
				cout << "法术攻击：" << attack_m;
				SetCursorPosition(0, 33);
				cout << "法力：" << power << '/' << maxpower;
				SetCursorPosition(0, 34);
				cout << "法术防御：" << defense_m;
				SetCursorPosition(0, 35);
				cout << "法术穿透：" << penetration_m;
				SetCursorPosition(0, 36);
				cout << "法术吸血：" << bloodsuck_m;

				SetColor(13);
				SetCursorPosition(25, 0);
				cout << "攻击进度：" << rate_m << '/' << "100000";
				SetCursorPosition(25, 24);
				cout << "生命：" << mons.life << '/' << mons.maxlife;
				SetCursorPosition(25, 25);
				cout << "物理攻击：" << mons.attack;
				SetCursorPosition(25, 26);
				cout << "物理防御：" << mons.defense;
				SetCursorPosition(25, 27);
				cout << "攻击速度：" << mons.speed;
				SetCursorPosition(25, 28);
				cout << "暴击机率：" << mons.critical_p;
				SetCursorPosition(25, 29);
				cout << "暴击效果：" << mons.critical_a;
				SetCursorPosition(25, 30);
				cout << "物理穿透：" << mons.penetration;
				SetCursorPosition(25, 31);
				cout << "物理吸血：" << mons.bloodsuck;
				SetCursorPosition(25, 32);
				cout << "法术攻击：" << mons.attack_m;
				SetCursorPosition(25, 34);
				cout << "法术防御：" << mons.defense_m;
				SetCursorPosition(25, 35);
				cout << "法术穿透：" << mons.penetration_m;
				SetCursorPosition(25, 36);
				cout << "法术吸血：" << mons.bloodsuck_m;
				Sleep(500);
				if (life <= 0)
				{
					return 3;
				}

				else if (mons.life <= 0)
				{
					money += mons.money;//需要打开文件操作
					ofstream rolefile("role.txt");
					rolefile << maxlife << '\n' << attack << '\n' << defense << '\n' << speed << '\n' << critical_p << '\n' << critical_a << '\n' << penetration << '\n' << bloodsuck << '\n' << attack_m << '\n' << maxpower << '\n' << defense_m << '\n' << penetration_m << '\n' << bloodsuck_m << '\n' << money << '\n';
					rolefile.close();

					return 2;
				}

				SetColor(12);
				SetCursorPosition(0, 1);
				cout << "你的回合";
				if (mons.be_attacked_mode(id, maxlife, life, attack, defense, speed, critical_p, critical_a, penetration, bloodsuck, attack_m, maxpower, power, defense_m, penetration_m, bloodsuck_m, money)) return 1;//逃跑
				rate_r -= 100000;
			}
		}
		else if (rate_r >= 100000)
		{
			SetColor(12);
			SetCursorPosition(0, 1);
			cout << "你的回合";
			if (mons.be_attacked_mode(id, maxlife, life, attack, defense, speed, critical_p, critical_a, penetration, bloodsuck, attack_m, maxpower, power, defense_m, penetration_m, bloodsuck_m, money)) return 1;//逃跑
			rate_r -= 100000;
		}
		else
		{
			SetColor(13);
			SetCursorPosition(25, 1);
			cout << "敌人的回合";
			Sleep(500);
			mons.attack_mode(id, maxlife, life, attack, defense, speed, critical_p, critical_a, penetration, bloodsuck, attack_m, maxpower, power, defense_m, penetration_m, bloodsuck_m, money);
			rate_m -= 100000;
		}
	}

}
int prebattle(int id, int maxlife, int &life, int attack, int defense, int speed, int critical_p, int critical_a, int penetration, int bloodsuck, int attack_m, int maxpower, int& power, int defense_m, int penetration_m, int bloodsuck_m, int& money)
{
	int o;
	int temp;
	SetColor(15);
	SetCursorPosition(21,22);
	printf(" +----------+ ");
	SetCursorPosition(21, 23);
	printf(" |          | ");
	SetCursorPosition(21, 24);
	printf(" |          | ");
	SetCursorPosition(21, 25);
	printf(" |          | ");
	SetCursorPosition(21, 26);
	printf(" +----------+ ");

	SetCursorPosition(22, 23);
	if (id == 1)cout << "老鼠";
	if (id == 2)cout << "游灵";
	if (id == 3)cout << "饿狼";
	if (id == 4)cout << "恶魂";
	if (id == 5)cout << "圣剑";
	if (id == 6)cout << "幼龙";
	if (id == 7)cout << "巨蟒";
	if (id == 8)cout << "黑影";
	if (id == 9)cout << "腐肉";
	if (id == 10)cout << "巨龙";
	if (id == 11)cout << "魔王";
	if (id == 12)cout << "魔神";
	SetCursorPosition(22, 24);
	cout << "Enter:战斗";
	SetCursorPosition(22, 25);
	cout << "Esc:离开";

	while (_kbhit())
	{
		_getch();
	}
	
	while (true)
	{
		o=_getch();
		_getch();
		if (o == 13)
		{
			temp = battle(id, maxlife, life, attack, defense, speed, critical_p, critical_a, penetration, bloodsuck, attack_m, maxpower, power, defense_m, penetration_m, bloodsuck_m, money);
			return temp;
		}
		else if (o == 27) return 0;
	}
}

int getmoney(int temp, int maxlife, int &life, int attack, int defense, int speed, int critical_p, int critical_a, int penetration, int bloodsuck, int attack_m, int maxpower, int& power, int defense_m, int penetration_m, int bloodsuck_m, int& money)
{
	int o;
	SetColor(15);
	SetCursorPosition(21, 22);
	printf(" +----------+ ");
	SetCursorPosition(21, 23);
	printf(" |          | ");
	SetCursorPosition(21, 24);
	printf(" |          | ");
	SetCursorPosition(21, 25);
	printf(" |          | ");
	SetCursorPosition(21, 26);
	printf(" +----------+ ");
	ofstream rolefile("role.txt");
	rolefile << maxlife << '\n' << attack << '\n' << defense << '\n' << speed << '\n' << critical_p << '\n' << critical_a << '\n' << penetration << '\n' << bloodsuck << '\n' << attack_m << '\n' << maxpower << '\n' << defense_m << '\n' << penetration_m << '\n' << bloodsuck_m << '\n' << money << '\n';
	rolefile.close();
	SetCursorPosition(22, 23);
	cout << "获得金币";
	SetCursorPosition(22, 24);
	cout << temp;
	SetCursorPosition(22, 25);
	cout << "Enter:离开";

	while (_kbhit())
	{
		_getch();
	}

	while (true)
	{
		o = _getch();
		_getch();
		if (o == 13) return 0;
	}
}

int getlife(int temp, int maxlife, int &life, int attack, int defense, int speed, int critical_p, int critical_a, int penetration, int bloodsuck, int attack_m, int maxpower, int& power, int defense_m, int penetration_m, int bloodsuck_m, int& money)
{
	int o;
	SetColor(15);
	SetCursorPosition(21, 22);
	printf(" +----------+ ");
	SetCursorPosition(21, 23);
	printf(" |          | ");
	SetCursorPosition(21, 24);
	printf(" |          | ");
	SetCursorPosition(21, 25);
	printf(" |          | ");
	SetCursorPosition(21, 26);
	printf(" +----------+ ");
	SetCursorPosition(22, 23);
	cout << "获得生命";
	SetCursorPosition(22, 24);
	cout << temp;
	SetCursorPosition(22, 25);
	cout << "Enter:离开";

	while (_kbhit())
	{
		_getch();
	}

	while (true)
	{
		o = _getch();
		_getch();
		if (o == 13) return 0;
	}
}

int getpower(int temp, int maxlife, int &life, int attack, int defense, int speed, int critical_p, int critical_a, int penetration, int bloodsuck, int attack_m, int maxpower, int& power, int defense_m, int penetration_m, int bloodsuck_m, int& money)
{
	int o;
	SetColor(15);
	SetCursorPosition(21, 22);
	printf(" +----------+ ");
	SetCursorPosition(21, 23);
	printf(" |          | ");
	SetCursorPosition(21, 24);
	printf(" |          | ");
	SetCursorPosition(21, 25);
	printf(" |          | ");
	SetCursorPosition(21, 26);
	printf(" +----------+ ");
	SetCursorPosition(22, 23);
	cout << "获得法力";
	SetCursorPosition(22, 24);
	cout << temp;
	SetCursorPosition(22, 25);
	cout << "Enter:离开";

	while (_kbhit())
	{
		_getch();
	}

	while (true)
	{
		o = _getch();
		_getch();
		if (o == 13) return 0;
	}
}

void Playing()
{
	int map[50][50], mapcolour[50][50], bornpointx, bornpointy;
	int stage = 1;
	int maxlife, attack, defense, speed, critical_p, critical_a, penetration, bloodsuck, attack_m, maxpower, defense_m, penetration_m, bloodsuck_m, money;//角色属性
	int life,power;
	ifstream rolefile("role.txt");
	rolefile >> maxlife >> attack >> defense >> speed >> critical_p >> critical_a >> penetration >> bloodsuck >> attack_m >> maxpower >> defense_m >> penetration_m >> bloodsuck_m >> money;
	life = maxlife;
	power = maxpower;
	rolefile.close();
	while (1)
	{
		Map(map[0], mapcolour[0], bornpointx, bornpointy,stage);
		int x = bornpointx, y = bornpointy;
		SetColor(192);
		SetCursorPosition(bornpointx, bornpointy);
		printf("  ");
		bool out = 0;//记录是否逃出

		int oldx, oldy;
		bool moved;//记录是否移动
		while (true)
		{
			oldx = x;
			oldy = y;
			if (GetAsyncKeyState('W')) --y;
			if (GetAsyncKeyState('A')) --x;
			if (GetAsyncKeyState('S')) ++y;
			if (GetAsyncKeyState('D')) ++x;

			if (map[x][y] == 3)//出口赢了
			{
				if (GetAsyncKeyState(VK_TAB))out = 1;
			}
			if (out) break;
			if (map[x][y] == 4)//宝箱
			{
				if (GetAsyncKeyState(VK_TAB))
				{
					int temp,temp1;
					srand(time(0));
					
					map[x][y] = 2;
					mapcolour[x][y] = 128;

					temp = rand() % 10;
					if (temp == 0)
					{
						temp1 = maxlife / 10;
						if (temp1 + life > maxlife)
						{
							temp1 = maxlife - life;
							life = maxlife;
						}
						else life += temp1;
						getlife(temp1, maxlife, life, attack, defense, speed, critical_p, critical_a, penetration, bloodsuck, attack_m, maxpower, power, defense_m, penetration_m, bloodsuck_m, money);
					}
					else if (temp == 1)
					{
						temp1 = maxpower / 10;
						if (temp1 + power > maxpower)
						{
							temp1 = maxpower - power;
							power = maxpower;
						}
						else power += temp1;
						getpower(temp1, maxlife, life, attack, defense, speed, critical_p, critical_a, penetration, bloodsuck, attack_m, maxpower, power, defense_m, penetration_m, bloodsuck_m, money);
					}
					else
					{
						temp1 = rand() % (stage * 10);
						money += temp1;
						getmoney(temp1, maxlife, life, attack, defense, speed, critical_p, critical_a, penetration, bloodsuck, attack_m, maxpower, power, defense_m, penetration_m, bloodsuck_m, money);
					}
					for (int i = 21; i <= 27; ++i)
					{
						for (int j = 22; j <= 26; ++j)
						{
							SetColor(mapcolour[i][j]);
							SetCursorPosition(i, j);
							printf("  ");
						}
					}
					SetColor(192);
					SetCursorPosition(oldx, oldy);
					printf("  ");
				}
			}
			if ((map[x][y] > 100) && (map[x][y] < 200))//发现怪物
			{
				int temp = prebattle(map[x][y] - 100, maxlife, life, attack, defense, speed, critical_p, critical_a, penetration, bloodsuck, attack_m, maxpower, power, defense_m, penetration_m, bloodsuck_m, money);
				if (temp == 0)
				{
					for (int i = 21; i <= 27; ++i)
					{
						for (int j = 22; j <= 26; ++j)
						{
							SetColor(mapcolour[i][j]);
							SetCursorPosition(i, j);
							printf("  ");
						}
					}
					SetColor(192);
					SetCursorPosition(oldx, oldy);
					printf("  ");
				}
				else if (temp == 1)//逃跑
				{
					system("cls");
					for (int i = 0; i <= 48; ++i)
					{
						for (int j = 0; j <= 48; ++j)
						{
							SetColor(mapcolour[i][j]);
							SetCursorPosition(i, j);
							printf("  ");
						}
					}
					SetColor(192);
					SetCursorPosition(oldx, oldy);
					printf("  ");
				}
				else if (temp == 2)//胜利
				{
					map[x][y] = 2;
					mapcolour[x][y] = 128;
					system("cls");
					for (int i = 0; i <= 48; ++i)
					{
						for (int j = 0; j <= 48; ++j)
						{
							SetColor(mapcolour[i][j]);
							SetCursorPosition(i, j);
							printf("  ");
						}
					}
					SetColor(192);
					SetCursorPosition(oldx, oldy);
					printf("  ");
				}
				else if (temp == 3)//失败
				{
					return;
				}
			}

			if (((map[x][y] != 2) && (map[x][y] != 3) && (map[x][y] != 4)) || (((map[oldx][y] != 2) && (map[oldx][y] != 3) && (map[oldx][y] != 4)) && ((map[x][oldy] != 2) && (map[x][oldy] != 3) && (map[x][oldy] != 4))))
			{
				x = oldx;
				y = oldy;
			}

			if ((x == oldx) && (y == oldy))moved = 0;
			else moved = 1;
			if (moved)
			{
				SetColor(mapcolour[oldx][oldy]);
				SetCursorPosition(oldx, oldy);
				printf("  ");
				SetColor(192);
				SetCursorPosition(x, y);
				printf("  ");

				Sleep(100);
				if (((x - oldx + y - oldy) % 2 == 0) && moved) Sleep(100);
			}
		}
		if (out)
		{
			++stage;
			if (stage > 10)
			{
				system("cls");
				cout << "你赢了";
				while (_kbhit())
				{
					_getch();
				}
				while (!_kbhit());
				break;
			}
			continue;
		}
	}
}
