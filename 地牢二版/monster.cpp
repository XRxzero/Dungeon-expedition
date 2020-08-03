#include "monster.h"
#include <conio.h>
#include <cstdlib>
#include <ctime>
void Monster::attack_mode(int id, int r_maxlife, int &r_life, int &r_attack, int &r_defense, int &r_speed, int &r_critical_p, int &r_critical_a, int &r_penetration, int &r_bloodsuck, int &r_attack_m, int r_maxpower, int& r_power, int &r_defense_m, int &r_penetration_m, int &r_bloodsuck_m, int& r_money)
{
	if (id == 1)//物理攻击模板
	{
		srand(time(0));
		int d_p = r_defense - penetration;
		if (d_p < 0)d_p = 0;
		if (rand() % 100 < critical_p)
		{
			r_life -= (critical_a*attack / 100) * 605 / (605 + d_p);
			life += ((critical_a*attack / 100) * 605 / (605 + d_p))*bloodsuck / 100;
		}
		else
		{
			r_life -= attack * 605 / (605 + d_p);
			life += (attack * 605 / (605 + d_p))*bloodsuck / 100;
		}
	}
	else if (id == 2)//法术攻击模板
	{
		int d_p = r_defense_m - penetration_m;
		if (d_p < 0)d_p = 0;
		else
		{
			r_life -= attack_m * 605 / (605 + d_p);
			life += (attack_m * 605 / (605 + d_p))*bloodsuck_m / 100;
		}
	}
	else if (id == 3)
	{
		srand(time(0));
		int d_p = r_defense - penetration;
		if (d_p < 0)d_p = 0;
		if (rand() % 100 < critical_p)
		{
			r_life -= (critical_a*attack / 100) * 605 / (605 + d_p);
			life += ((critical_a*attack / 100) * 605 / (605 + d_p))*bloodsuck / 100;
		}
		else
		{
			r_life -= attack * 605 / (605 + d_p);
			life += (attack * 605 / (605 + d_p))*bloodsuck / 100;
		}
	}
	else if (id == 4)
	{
		int d_p = r_defense_m - penetration_m;
		if (d_p < 0)d_p = 0;
		else
		{
			r_life -= attack_m * 605 / (605 + d_p);
			life += (attack_m * 605 / (605 + d_p))*bloodsuck_m / 100;
		}
	}
	else if (id == 5)
	{
		srand(time(0));
		int d_p = r_defense - penetration;
		if (d_p < 0)d_p = 0;
		if (rand() % 100 < critical_p)
		{
			r_life -= (critical_a*attack / 100) * 605 / (605 + d_p);
			life += ((critical_a*attack / 100) * 605 / (605 + d_p))*bloodsuck / 100;
		}
		else
		{
			r_life -= attack * 605 / (605 + d_p);
			life += (attack * 605 / (605 + d_p))*bloodsuck / 100;
		}
	}
	else if (id == 6)//物法双休
	{
		srand(time(0));
		if (rand() % 2 == 0)
		{
			int d_p = r_defense - penetration;
			if (d_p < 0)d_p = 0;
			if (rand() % 100 < critical_p)
			{
				r_life -= (critical_a*attack / 100) * 605 / (605 + d_p);
				life += ((critical_a*attack / 100) * 605 / (605 + d_p))*bloodsuck / 100;
			}
			else
			{
				r_life -= attack * 605 / (605 + d_p);
				life += (attack * 605 / (605 + d_p))*bloodsuck / 100;
			}
		}
		else
		{
			int d_p = r_defense_m - penetration_m;
			if (d_p < 0)d_p = 0;
			else
			{
				r_life -= attack_m * 605 / (605 + d_p);
				life += (attack_m * 605 / (605 + d_p))*bloodsuck_m / 100;
			}
		}
	}
	else if (id == 7)
	{
		srand(time(0));
		int d_p = r_defense - penetration;
		if (d_p < 0)d_p = 0;
		if (rand() % 100 < critical_p)
		{
			r_life -= (critical_a*attack / 100) * 605 / (605 + d_p);
			life += ((critical_a*attack / 100) * 605 / (605 + d_p))*bloodsuck / 100;
		}
		else
		{
			r_life -= attack * 605 / (605 + d_p);
			life += (attack * 605 / (605 + d_p))*bloodsuck / 100;
		}
	}
	else if (id == 8)
	{
		int d_p = r_defense_m - penetration_m;
		if (d_p < 0)d_p = 0;
		else
		{
			r_life -= attack_m * 605 / (605 + d_p);
			life += (attack_m * 605 / (605 + d_p))*bloodsuck_m / 100;
		}
	}
	else if (id == 9)
	{
		srand(time(0));
		int d_p = r_defense - penetration;
		if (d_p < 0)d_p = 0;
		if (rand() % 100 < critical_p)
		{
			r_life -= (critical_a*attack / 100) * 605 / (605 + d_p);
			life += ((critical_a*attack / 100) * 605 / (605 + d_p))*bloodsuck / 100;
		}
		else
		{
			r_life -= attack * 605 / (605 + d_p);
			life += (attack * 605 / (605 + d_p))*bloodsuck / 100;
		}
	}
	else if (id == 10)
	{
		srand(time(0));
		if (rand() % 2 == 0)
		{
			int d_p = r_defense - penetration;
			if (d_p < 0)d_p = 0;
			if (rand() % 100 < critical_p)
			{
				r_life -= (critical_a*attack / 100) * 605 / (605 + d_p);
				life += ((critical_a*attack / 100) * 605 / (605 + d_p))*bloodsuck / 100;
			}
			else
			{
				r_life -= attack * 605 / (605 + d_p);
				life += (attack * 605 / (605 + d_p))*bloodsuck / 100;
			}
		}
		else
		{
			int d_p = r_defense_m - penetration_m;
			if (d_p < 0)d_p = 0;
			else
			{
				r_life -= attack_m * 605 / (605 + d_p);
				life += (attack_m * 605 / (605 + d_p))*bloodsuck_m / 100;
			}
		}
	}
	else if (id == 11)
	{
		int d_p = r_defense_m - penetration_m;
		if (d_p < 0)d_p = 0;
		else
		{
			r_life -= attack_m * 605 / (605 + d_p);
			life += (attack_m * 605 / (605 + d_p))*bloodsuck_m / 100;
		}
	}
	else if (id == 12)
	{
		srand(time(0));
		if (rand() % 2 == 0)
		{
			int d_p = r_defense - penetration;
			if (d_p < 0)d_p = 0;
			if (rand() % 100 < critical_p)
			{
				r_life -= (critical_a*attack / 100) * 605 / (605 + d_p);
				life += ((critical_a*attack / 100) * 605 / (605 + d_p))*bloodsuck / 100;
			}
			else
			{
				r_life -= attack * 605 / (605 + d_p);
				life += (attack * 605 / (605 + d_p))*bloodsuck / 100;
			}
		}
		else
		{
			int d_p = r_defense_m - penetration_m;
			if (d_p < 0)d_p = 0;
			else
			{
				r_life -= attack_m * 605 / (605 + d_p);
				life += (attack_m * 605 / (605 + d_p))*bloodsuck_m / 100;
			}
		}
	}
}
int Monster::be_attacked_mode(int id, int r_maxlife, int &r_life, int &r_attack, int &r_defense, int &r_speed, int &r_critical_p, int &r_critical_a, int &r_penetration, int &r_bloodsuck, int &r_attack_m, int r_maxpower, int& r_power, int &r_defense_m, int &r_penetration_m, int &r_bloodsuck_m, int& r_money)
{
	int key;//输入
	while (true)
	{
		while (_kbhit())
		{
			_getch();
		}
		key = _getch();
		_getch();
		if (key == 49)
		{
			srand(time(0));
			int d_p = defense - r_penetration;
			if (d_p < 0)d_p = 0;
			if (rand() % 100 < r_critical_p)
			{
				life -= (r_critical_a*r_attack / 100) * 605 / (605 + d_p);
				r_life += ((r_critical_a*r_attack / 100) * 605 / (605 + d_p))*r_bloodsuck / 100;
			}
			else
			{
				life -= r_attack * 605 / (605 + d_p);
				r_life += (r_attack * 605 / (605 + d_p))*r_bloodsuck / 100;
			}
			break;
		}
		else if (key == 50)
		{
			if (r_power >= 30)
			{
				int d_p = defense_m - r_penetration_m;
				if (d_p < 0)d_p = 0;
				life -= r_attack_m * 605 / (605 + d_p);
				r_life += (r_attack_m * 605 / (605 + d_p))*r_bloodsuck_m / 100;
				r_power -= 30;
				break;
			}
			else continue;
		}
		else if (key == 27) return 1;//逃跑
	}
	return 0;//未逃跑
}