#pragma once
class Monster
{
public:
	Monster(int id)
	{
		if (id == 1)
		{
			maxlife = 680;
			life = maxlife;
			attack = 60;
			defense = 18;
			speed = 100;
			critical_p = 0;
			critical_a = 200;
			penetration = 0;
			bloodsuck = 0;
			attack_m = 0;
			defense_m = 18;
			penetration_m = 0;
			bloodsuck_m = 0;
			money = 1;
		}
		else if (id == 2)
		{
			maxlife = 620;
			life = maxlife;
			attack = 0;
			defense = 36;
			speed = 150;
			critical_p = 0;
			critical_a = 200;
			penetration = 0;
			bloodsuck = 0;
			attack_m = 24;
			defense_m = 36;
			penetration_m = 0;
			bloodsuck_m = 0;
			money = 2;
		}
		if (id == 3)
		{
			maxlife = 860;
			life = maxlife;
			attack = 204;
			defense = 54;
			speed = 100;
			critical_p = 0;
			critical_a = 200;
			penetration = 0;
			bloodsuck = 0;
			attack_m = 0;
			defense_m = 54;
			penetration_m = 0;
			bloodsuck_m = 0;
			money = 3;
		}
		if (id == 4)
		{
			maxlife = 690;
			life = maxlife;
			attack = 0;
			defense = 54;
			speed = 150;
			critical_p = 0;
			critical_a = 200;
			penetration = 0;
			bloodsuck = 0;
			attack_m = 144;
			defense_m = 54;
			penetration_m = 0;
			bloodsuck_m = 0;
			money = 4;
		}
		if (id == 5)
		{
			maxlife = 1680;
			life = maxlife;
			attack = 132;
			defense = 126;
			speed = 100;
			critical_p = 0;
			critical_a = 200;
			penetration = 0;
			bloodsuck = 0;
			attack_m = 0;
			defense_m = 126;
			penetration_m = 0;
			bloodsuck_m = 0;
			money = 5;
		}
		if (id == 6)
		{
			maxlife = 1190;
			life = maxlife;
			attack = 900;
			defense = 36;
			speed = 50;
			critical_p = 0;
			critical_a = 200;
			penetration = 0;
			bloodsuck = 0;
			attack_m = 900;
			defense_m = 36;
			penetration_m = 0;
			bloodsuck_m = 0;
			money = 6;
		}
		if (id == 7)
		{
			maxlife = 1400;
			life = maxlife;
			attack = 492;
			defense = 54;
			speed = 100;
			critical_p = 0;
			critical_a = 200;
			penetration = 0;
			bloodsuck = 0;
			attack_m = 0;
			defense_m = 54;
			penetration_m = 0;
			bloodsuck_m = 0;
			money = 7;
		}
		if (id == 8)
		{
			maxlife = 1740;
			life = maxlife;
			attack = 0;
			defense = 72;
			speed = 50;
			critical_p = 0;
			critical_a = 200;
			penetration = 0;
			bloodsuck = 0;
			attack_m = 492;
			defense_m = 72;
			penetration_m = 0;
			bloodsuck_m = 0;
			money = 8;
		}
		if (id == 9)
		{
			maxlife = 3780;
			life = maxlife;
			attack = 240;
			defense = 198;
			speed = 100;
			critical_p = 0;
			critical_a = 200;
			penetration = 0;
			bloodsuck = 0;
			attack_m = 0;
			defense_m = 198;
			penetration_m = 0;
			bloodsuck_m = 0;
			money = 9;
		}
		if (id == 10)
		{
			maxlife = 2430;
			life = maxlife;
			attack = 324;
			defense = 108;
			speed = 100;
			critical_p = 0;
			critical_a = 200;
			penetration = 0;
			bloodsuck = 0;
			attack_m = 324;
			defense_m = 108;
			penetration_m = 0;
			bloodsuck_m = 0;
			money = 10;
		}
		if (id == 11)
		{
			maxlife = 3560;
			life = maxlife;
			attack = 0;
			defense = 72;
			speed = 100;
			critical_p = 0;
			critical_a = 200;
			penetration = 0;
			bloodsuck = 0;
			attack_m = 492;
			defense_m = 72;
			penetration_m = 0;
			bloodsuck_m = 0;
			money = 11;
		}
		if (id == 12)
		{
			maxlife = 3560;
			life = maxlife;
			attack = 324;
			defense = 126;
			speed = 100;
			critical_p = 0;
			critical_a = 200;
			penetration = 0;
			bloodsuck = 0;
			attack_m = 324;
			defense_m = 126;
			penetration_m = 0;
			bloodsuck_m = 0;
			money = 12;
		}
	}
	int maxlife, attack, defense, speed, critical_p, critical_a, penetration, bloodsuck, attack_m, defense_m, penetration_m, bloodsuck_m, money;
	int life;
	void attack_mode(int id, int r_maxlife, int &r_life, int &r_attack, int &r_defense, int &r_speed, int &r_critical_p, int &r_critical_a, int &r_penetration, int &r_bloodsuck, int &r_attack_m, int r_maxpower, int& r_power, int &r_defense_m, int &r_penetration_m, int &r_bloodsuck_m, int& r_money);
	int be_attacked_mode(int id, int r_maxlife, int &r_life, int &r_attack, int &r_defense, int &r_speed, int &r_critical_p, int &r_critical_a, int &r_penetration, int &r_bloodsuck, int &r_attack_m, int r_maxpower, int& r_power, int &r_defense_m, int &r_penetration_m, int &r_bloodsuck_m, int& r_money);
};