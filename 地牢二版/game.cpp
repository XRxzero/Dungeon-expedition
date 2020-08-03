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
	SetWindowSize(49, 49);//���ô��ڴ�С
						  //SetColor(64);//���ÿ�ʼ������ɫ
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
	//����۾�
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
	//գ��
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
	printf("�밴���������");
	while (!_kbhit());
	while (_kbhit())//������̻���
	{
		_getch();
	}
}

void Shop()
{
	int o;//����
	int temp;//��������
	int maxlife, attack,defense,speed,critical_p,critical_a, penetration,bloodsuck,attack_m,maxpower,defense_m,penetration_m,bloodsuck_m,money;//��ɫ����
	ifstream rolefile("role.txt");
	rolefile >> maxlife>>attack>>defense>>speed>>critical_p>>critical_a>>penetration>>bloodsuck>>attack_m>>maxpower>>defense_m>>penetration_m>>bloodsuck_m>>money;
	rolefile.close();
	while (1)
	{
		SetColor(14);
		system("cls");
		cout << "��ǰ�ܽ������Ϊ" << endl << endl;
		cout << "A ��ǰ�������Ϊ                " << "ÿ1�����������Ҫ���1" << endl << endl;
		cout << "B ��ǰ������Ϊ                " << "ÿ1����������Ҫ���12" << endl << endl;
		cout << "C ��ǰ�������Ϊ                " << "ÿ1�����������Ҫ���6" << endl << endl;
		cout << "D ��ǰ�����ٶ�Ϊ                " << "ÿ1�㹥���ٶ���Ҫ���3" << endl << endl;
		cout << "E ��ǰ��������Ϊ                " << "ÿ1%����������Ҫ���40" << endl << endl;
		cout << "F ��ǰ����Ч��Ϊ                " << "ÿ1%�㱩��Ч����Ҫ���10" << endl << endl;
		cout << "G ��ǰ����͸Ϊ                " << "ÿ1������͸��Ҫ���7" << endl << endl;
		cout << "H ��ǰ������ѪΪ                " << "ÿ1%������Ѫ��Ҫ���36" << endl << endl;
		cout << "I ��ǰ��������Ϊ                " << "ÿ1�㷨��������Ҫ���8" << endl << endl;
		cout << "J ��ǰ�����Ϊ                " << "ÿ10���������Ҫ���7" << endl << endl;
		cout << "K ��ǰ��������Ϊ                " << "ÿ1�㷨��������Ҫ���6" << endl << endl;
		cout << "L ��ǰ������͸Ϊ                " << "ÿ1�㷨����͸��Ҫ���7" << endl << endl;
		cout << "M ��ǰ������ѪΪ                " << "ÿ1%������Ѫ��Ҫ���27" << endl << endl;
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
			printf(" |�����빺������| ");
			SetCursorPosition(20, 24);
			printf(" |              | ");
			SetCursorPosition(20, 25);
			printf(" |Enter ȷ��    | ");
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
					printf(" |��Ҳ���      | ");
					SetCursorPosition(20, 24);
					printf(" |              | ");
					SetCursorPosition(20, 25);
					printf(" |Enter ȷ��    | ");
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
			printf(" |�����빺������| ");
			SetCursorPosition(20, 24);
			printf(" |              | ");
			SetCursorPosition(20, 25);
			printf(" |Enter ȷ��    | ");
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
					printf(" |��Ҳ���      | ");
					SetCursorPosition(20, 24);
					printf(" |              | ");
					SetCursorPosition(20, 25);
					printf(" |Enter ȷ��    | ");
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
			printf(" |�����빺������| ");
			SetCursorPosition(20, 24);
			printf(" |              | ");
			SetCursorPosition(20, 25);
			printf(" |Enter ȷ��    | ");
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
					printf(" |��Ҳ���      | ");
					SetCursorPosition(20, 24);
					printf(" |              | ");
					SetCursorPosition(20, 25);
					printf(" |Enter ȷ��    | ");
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
			printf(" |�����빺������| ");
			SetCursorPosition(20, 24);
			printf(" |              | ");
			SetCursorPosition(20, 25);
			printf(" |Enter ȷ��    | ");
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
					printf(" |��Ҳ���      | ");
					SetCursorPosition(20, 24);
					printf(" |              | ");
					SetCursorPosition(20, 25);
					printf(" |Enter ȷ��    | ");
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
			printf(" |�����빺������| ");
			SetCursorPosition(20, 24);
			printf(" |              | ");
			SetCursorPosition(20, 25);
			printf(" |Enter ȷ��    | ");
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
					printf(" |��Ҳ���      | ");
					SetCursorPosition(20, 24);
					printf(" |              | ");
					SetCursorPosition(20, 25);
					printf(" |Enter ȷ��    | ");
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
			printf(" |�����빺������| ");
			SetCursorPosition(20, 24);
			printf(" |              | ");
			SetCursorPosition(20, 25);
			printf(" |Enter ȷ��    | ");
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
					printf(" |��Ҳ���      | ");
					SetCursorPosition(20, 24);
					printf(" |              | ");
					SetCursorPosition(20, 25);
					printf(" |Enter ȷ��    | ");
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
			printf(" |�����빺������| ");
			SetCursorPosition(20, 24);
			printf(" |              | ");
			SetCursorPosition(20, 25);
			printf(" |Enter ȷ��    | ");
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
					printf(" |��Ҳ���      | ");
					SetCursorPosition(20, 24);
					printf(" |              | ");
					SetCursorPosition(20, 25);
					printf(" |Enter ȷ��    | ");
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
			printf(" |�����빺������| ");
			SetCursorPosition(20, 24);
			printf(" |              | ");
			SetCursorPosition(20, 25);
			printf(" |Enter ȷ��    | ");
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
					printf(" |��Ҳ���      | ");
					SetCursorPosition(20, 24);
					printf(" |              | ");
					SetCursorPosition(20, 25);
					printf(" |Enter ȷ��    | ");
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
			printf(" |�����빺������| ");
			SetCursorPosition(20, 24);
			printf(" |              | ");
			SetCursorPosition(20, 25);
			printf(" |Enter ȷ��    | ");
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
					printf(" |��Ҳ���      | ");
					SetCursorPosition(20, 24);
					printf(" |              | ");
					SetCursorPosition(20, 25);
					printf(" |Enter ȷ��    | ");
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
			printf(" |�����빺������| ");
			SetCursorPosition(20, 24);
			printf(" |              | ");
			SetCursorPosition(20, 25);
			printf(" |Enter ȷ��    | ");
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
					printf(" |��Ҳ���      | ");
					SetCursorPosition(20, 24);
					printf(" |              | ");
					SetCursorPosition(20, 25);
					printf(" |Enter ȷ��    | ");
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
			printf(" |�����빺������| ");
			SetCursorPosition(20, 24);
			printf(" |              | ");
			SetCursorPosition(20, 25);
			printf(" |Enter ȷ��    | ");
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
					printf(" |��Ҳ���      | ");
					SetCursorPosition(20, 24);
					printf(" |              | ");
					SetCursorPosition(20, 25);
					printf(" |Enter ȷ��    | ");
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
			printf(" |�����빺������| ");
			SetCursorPosition(20, 24);
			printf(" |              | ");
			SetCursorPosition(20, 25);
			printf(" |Enter ȷ��    | ");
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
					printf(" |��Ҳ���      | ");
					SetCursorPosition(20, 24);
					printf(" |              | ");
					SetCursorPosition(20, 25);
					printf(" |Enter ȷ��    | ");
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
			printf(" |�����빺������| ");
			SetCursorPosition(20, 24);
			printf(" |              | ");
			SetCursorPosition(20, 25);
			printf(" |Enter ȷ��    | ");
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
					printf(" |��Ҳ���      | ");
					SetCursorPosition(20, 24);
					printf(" |              | ");
					SetCursorPosition(20, 25);
					printf(" |Enter ȷ��    | ");
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
	int temp, temp2,temp3;//�����
	int dir;//����
	int floorx[625] = {};//������棻
	int floory[625] = {};
	int floornow = 0;//����ָ��ڼ�������
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
					map[k * 50 + j] = 4;//����
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
			map[floory[temp2] * 50 + floorx[temp2]] = 3;//����
			break;
		}
	}

	for (int j = 0; j < 49; ++j)//��ǽ
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
			if (map[k * 50 + j] == 0)//���
			{
				mapcolour[k * 50 + j] = 0;
			}
			else if (map[k * 50 + j] == 1)//ǽ
			{
				mapcolour[k * 50 + j] = 16;
			}
			else if (map[k * 50 + j] == 2)//����
			{
				mapcolour[k * 50 + j] = 128;
			}
			else if (map[k * 50 + j] == 3)//����
			{
				mapcolour[k * 50 + j] = 160;
			}
			else if (map[k * 50 + j] == 4)//����
			{
				mapcolour[k * 50 + j] = 224;
			}
			else if ((map[k * 50 + j] > 100) && (map[k * 50 + j] < 200))//����
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
		cout << "�������ȣ�" << rate_r << '/' << "100000";
		SetCursorPosition(0, 24);
		cout << "������" << life << '/' << maxlife;
		SetCursorPosition(0, 25);
		cout << "��������" << attack;
		SetCursorPosition(0, 26);
		cout << "���������" << defense;
		SetCursorPosition(0, 27);
		cout << "�����ٶȣ�" << speed;
		SetCursorPosition(0, 28);
		cout << "�������ʣ�" << critical_p;
		SetCursorPosition(0, 29);
		cout << "����Ч����" << critical_a;
		SetCursorPosition(0, 30);
		cout << "����͸��" << penetration;
		SetCursorPosition(0, 31);
		cout << "������Ѫ��" << bloodsuck;
		SetCursorPosition(0, 32);
		cout << "����������" << attack_m;
		SetCursorPosition(0, 33);
		cout << "������" << power << '/' << maxpower;
		SetCursorPosition(0, 34);
		cout << "����������" << defense_m;
		SetCursorPosition(0, 35);
		cout << "������͸��" << penetration_m;
		SetCursorPosition(0, 36);
		cout << "������Ѫ��" << bloodsuck_m;

		SetColor(13);
		SetCursorPosition(25, 0);
		cout << "�������ȣ�" << rate_m << '/' << "100000";
		SetCursorPosition(25, 24);
		cout << "������" << mons.life << '/' << mons.maxlife;
		SetCursorPosition(25, 25);
		cout << "��������" << mons.attack;
		SetCursorPosition(25, 26);
		cout << "���������" << mons.defense;
		SetCursorPosition(25, 27);
		cout << "�����ٶȣ�" << mons.speed;
		SetCursorPosition(25, 28);
		cout << "�������ʣ�" << mons.critical_p;
		SetCursorPosition(25, 29);
		cout << "����Ч����" << mons.critical_a;
		SetCursorPosition(25, 30);
		cout << "����͸��" << mons.penetration;
		SetCursorPosition(25, 31);
		cout << "������Ѫ��" << mons.bloodsuck;
		SetCursorPosition(25, 32);
		cout << "����������" << mons.attack_m;
		SetCursorPosition(25, 34);
		cout << "����������" << mons.defense_m;
		SetCursorPosition(25, 35);
		cout << "������͸��" << mons.penetration_m;
		SetCursorPosition(25, 36);
		cout << "������Ѫ��" << mons.bloodsuck_m;
		Sleep(500);
		if (life <= 0)
		{
			return 3;
		}

		else if (mons.life <= 0)
		{
			money += mons.money;//��Ҫ���ļ�����
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
				cout << "��Ļغ�";
				if(mons.be_attacked_mode(id, maxlife, life, attack, defense, speed, critical_p, critical_a, penetration, bloodsuck, attack_m, maxpower, power, defense_m, penetration_m, bloodsuck_m, money)) return 1;//����
				rate_r -= 100000;
				system("cls");
				SetColor(12);
				SetCursorPosition(0, 0);
				cout << "�������ȣ�" << rate_r << '/' << "100000";
				SetCursorPosition(0, 24);
				cout << "������" << life << '/' << maxlife;
				SetCursorPosition(0, 25);
				cout << "��������" << attack;
				SetCursorPosition(0, 26);
				cout << "���������" << defense;
				SetCursorPosition(0, 27);
				cout << "�����ٶȣ�" << speed;
				SetCursorPosition(0, 28);
				cout << "�������ʣ�" << critical_p;
				SetCursorPosition(0, 29);
				cout << "����Ч����" << critical_a;
				SetCursorPosition(0, 30);
				cout << "����͸��" << penetration;
				SetCursorPosition(0, 31);
				cout << "������Ѫ��" << bloodsuck;
				SetCursorPosition(0, 32);
				cout << "����������" << attack_m;
				SetCursorPosition(0, 33);
				cout << "������" << power << '/' << maxpower;
				SetCursorPosition(0, 34);
				cout << "����������" << defense_m;
				SetCursorPosition(0, 35);
				cout << "������͸��" << penetration_m;
				SetCursorPosition(0, 36);
				cout << "������Ѫ��" << bloodsuck_m;

				SetColor(13);
				SetCursorPosition(25, 0);
				cout << "�������ȣ�" << rate_m << '/' << "100000";
				SetCursorPosition(25, 24);
				cout << "������" << mons.life << '/' << mons.maxlife;
				SetCursorPosition(25, 25);
				cout << "��������" << mons.attack;
				SetCursorPosition(25, 26);
				cout << "���������" << mons.defense;
				SetCursorPosition(25, 27);
				cout << "�����ٶȣ�" << mons.speed;
				SetCursorPosition(25, 28);
				cout << "�������ʣ�" << mons.critical_p;
				SetCursorPosition(25, 29);
				cout << "����Ч����" << mons.critical_a;
				SetCursorPosition(25, 30);
				cout << "����͸��" << mons.penetration;
				SetCursorPosition(25, 31);
				cout << "������Ѫ��" << mons.bloodsuck;
				SetCursorPosition(25, 32);
				cout << "����������" << mons.attack_m;
				SetCursorPosition(25, 34);
				cout << "����������" << mons.defense_m;
				SetCursorPosition(25, 35);
				cout << "������͸��" << mons.penetration_m;
				SetCursorPosition(25, 36);
				cout << "������Ѫ��" << mons.bloodsuck_m;
				Sleep(500);
				if (life <= 0)
				{
					return 3;
				}

				else if (mons.life <= 0)
				{
					money += mons.money;//��Ҫ���ļ�����
					ofstream rolefile("role.txt");
					rolefile << maxlife << '\n' << attack << '\n' << defense << '\n' << speed << '\n' << critical_p << '\n' << critical_a << '\n' << penetration << '\n' << bloodsuck << '\n' << attack_m << '\n' << maxpower << '\n' << defense_m << '\n' << penetration_m << '\n' << bloodsuck_m << '\n' << money << '\n';
					rolefile.close();

					return 2;
				}

				SetColor(13);
				SetCursorPosition(25, 1);
				cout << "���˵Ļغ�";
				Sleep(500);
				mons.attack_mode(id, maxlife, life, attack, defense, speed, critical_p, critical_a, penetration, bloodsuck, attack_m, maxpower, power, defense_m, penetration_m, bloodsuck_m, money);
				rate_m -= 100000;
			}
			else
			{
				SetColor(13);
				SetCursorPosition(25, 1);
				cout << "���˵Ļغ�";
				Sleep(500);
				mons.attack_mode(id, maxlife, life, attack, defense, speed, critical_p, critical_a, penetration, bloodsuck, attack_m, maxpower, power, defense_m, penetration_m, bloodsuck_m, money);
				rate_m -= 100000;
				system("cls");
				SetColor(12);
				SetCursorPosition(0, 0);
				cout << "�������ȣ�" << rate_r << '/' << "100000";
				SetCursorPosition(0, 24);
				cout << "������" << life << '/' << maxlife;
				SetCursorPosition(0, 25);
				cout << "��������" << attack;
				SetCursorPosition(0, 26);
				cout << "���������" << defense;
				SetCursorPosition(0, 27);
				cout << "�����ٶȣ�" << speed;
				SetCursorPosition(0, 28);
				cout << "�������ʣ�" << critical_p;
				SetCursorPosition(0, 29);
				cout << "����Ч����" << critical_a;
				SetCursorPosition(0, 30);
				cout << "����͸��" << penetration;
				SetCursorPosition(0, 31);
				cout << "������Ѫ��" << bloodsuck;
				SetCursorPosition(0, 32);
				cout << "����������" << attack_m;
				SetCursorPosition(0, 33);
				cout << "������" << power << '/' << maxpower;
				SetCursorPosition(0, 34);
				cout << "����������" << defense_m;
				SetCursorPosition(0, 35);
				cout << "������͸��" << penetration_m;
				SetCursorPosition(0, 36);
				cout << "������Ѫ��" << bloodsuck_m;

				SetColor(13);
				SetCursorPosition(25, 0);
				cout << "�������ȣ�" << rate_m << '/' << "100000";
				SetCursorPosition(25, 24);
				cout << "������" << mons.life << '/' << mons.maxlife;
				SetCursorPosition(25, 25);
				cout << "��������" << mons.attack;
				SetCursorPosition(25, 26);
				cout << "���������" << mons.defense;
				SetCursorPosition(25, 27);
				cout << "�����ٶȣ�" << mons.speed;
				SetCursorPosition(25, 28);
				cout << "�������ʣ�" << mons.critical_p;
				SetCursorPosition(25, 29);
				cout << "����Ч����" << mons.critical_a;
				SetCursorPosition(25, 30);
				cout << "����͸��" << mons.penetration;
				SetCursorPosition(25, 31);
				cout << "������Ѫ��" << mons.bloodsuck;
				SetCursorPosition(25, 32);
				cout << "����������" << mons.attack_m;
				SetCursorPosition(25, 34);
				cout << "����������" << mons.defense_m;
				SetCursorPosition(25, 35);
				cout << "������͸��" << mons.penetration_m;
				SetCursorPosition(25, 36);
				cout << "������Ѫ��" << mons.bloodsuck_m;
				Sleep(500);
				if (life <= 0)
				{
					return 3;
				}

				else if (mons.life <= 0)
				{
					money += mons.money;//��Ҫ���ļ�����
					ofstream rolefile("role.txt");
					rolefile << maxlife << '\n' << attack << '\n' << defense << '\n' << speed << '\n' << critical_p << '\n' << critical_a << '\n' << penetration << '\n' << bloodsuck << '\n' << attack_m << '\n' << maxpower << '\n' << defense_m << '\n' << penetration_m << '\n' << bloodsuck_m << '\n' << money << '\n';
					rolefile.close();

					return 2;
				}

				SetColor(12);
				SetCursorPosition(0, 1);
				cout << "��Ļغ�";
				if (mons.be_attacked_mode(id, maxlife, life, attack, defense, speed, critical_p, critical_a, penetration, bloodsuck, attack_m, maxpower, power, defense_m, penetration_m, bloodsuck_m, money)) return 1;//����
				rate_r -= 100000;
			}
		}
		else if (rate_r >= 100000)
		{
			SetColor(12);
			SetCursorPosition(0, 1);
			cout << "��Ļغ�";
			if (mons.be_attacked_mode(id, maxlife, life, attack, defense, speed, critical_p, critical_a, penetration, bloodsuck, attack_m, maxpower, power, defense_m, penetration_m, bloodsuck_m, money)) return 1;//����
			rate_r -= 100000;
		}
		else
		{
			SetColor(13);
			SetCursorPosition(25, 1);
			cout << "���˵Ļغ�";
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
	if (id == 1)cout << "����";
	if (id == 2)cout << "����";
	if (id == 3)cout << "����";
	if (id == 4)cout << "���";
	if (id == 5)cout << "ʥ��";
	if (id == 6)cout << "����";
	if (id == 7)cout << "����";
	if (id == 8)cout << "��Ӱ";
	if (id == 9)cout << "����";
	if (id == 10)cout << "����";
	if (id == 11)cout << "ħ��";
	if (id == 12)cout << "ħ��";
	SetCursorPosition(22, 24);
	cout << "Enter:ս��";
	SetCursorPosition(22, 25);
	cout << "Esc:�뿪";

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
	cout << "��ý��";
	SetCursorPosition(22, 24);
	cout << temp;
	SetCursorPosition(22, 25);
	cout << "Enter:�뿪";

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
	cout << "�������";
	SetCursorPosition(22, 24);
	cout << temp;
	SetCursorPosition(22, 25);
	cout << "Enter:�뿪";

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
	cout << "��÷���";
	SetCursorPosition(22, 24);
	cout << temp;
	SetCursorPosition(22, 25);
	cout << "Enter:�뿪";

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
	int maxlife, attack, defense, speed, critical_p, critical_a, penetration, bloodsuck, attack_m, maxpower, defense_m, penetration_m, bloodsuck_m, money;//��ɫ����
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
		bool out = 0;//��¼�Ƿ��ӳ�

		int oldx, oldy;
		bool moved;//��¼�Ƿ��ƶ�
		while (true)
		{
			oldx = x;
			oldy = y;
			if (GetAsyncKeyState('W')) --y;
			if (GetAsyncKeyState('A')) --x;
			if (GetAsyncKeyState('S')) ++y;
			if (GetAsyncKeyState('D')) ++x;

			if (map[x][y] == 3)//����Ӯ��
			{
				if (GetAsyncKeyState(VK_TAB))out = 1;
			}
			if (out) break;
			if (map[x][y] == 4)//����
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
			if ((map[x][y] > 100) && (map[x][y] < 200))//���ֹ���
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
				else if (temp == 1)//����
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
				else if (temp == 2)//ʤ��
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
				else if (temp == 3)//ʧ��
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
				cout << "��Ӯ��";
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
