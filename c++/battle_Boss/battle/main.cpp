#include "pch.h"

#include <string>
#include <Windows.h>

#include "Creature/Creature.h"
#include "Creature/Player/Player.h"
#include "Creature/Monster/Monster.h"
#include "Creature/Monster/Goblin.h"
#include "Creature/Player/Knight.h"
#include "Creature/Player/Mage.h"
#include "Creature/Player/Archer.h"
#include "Creature/Monster/Boss.h"

int main()
{
	Knight knight1("knight1", 20, 10);

	Mage mage1("mage1", 10, 10);

	Archer archer1("archer1", 5, 15);

	Knight knight2("knight2", 20, 5);

	Mage mage2("mage2", 10, 10);

	Archer archer2("archer2", 5, 15);

	Knight knight3("knight3", 20, 50);

	Mage mage3("mage3", 10, 100);

	Boss boss("boss", 150, 50);


	while (true)
	{
		// knight1
		boss.Attacked(knight1);
		if (boss.IsDead())
		{
			boss.end();
			break;
		}
		else
		{
			boss.Attack(&knight1);
		}
		
		// mage1
		boss.Attacked(mage1);
		if (boss.IsDead())
		{
			boss.end();
			break;
		}
		else
		{
			boss.Attack(&mage1);
		}

		// archer1
		boss.Attacked(archer1);
		if (boss.IsDead())
		{
			boss.end();
			break;
		}
		else
		{
			boss.Attack(&archer1);
		}

		// knight2
		boss.Attacked(knight2);
		if (boss.IsDead())
		{
			boss.end();
			break;
		}
		else
		{
			boss.Attack(&knight2);
		}

		// mage2
		boss.Attacked(mage2);
		if (boss.IsDead())
		{
			boss.end();
			break;
		}
		else
		{
			boss.Attack(&mage2);
		}

		// archer2
		boss.Attacked(archer2);
		if (boss.IsDead())
		{
			boss.end();
			break;
		}
		else
		{
			boss.Attack(&archer2);
		}

		// knight3
		boss.Attacked(knight3);
		if (boss.IsDead())
		{
			boss.end();
			break;
		}
		else
		{
			boss.Attack(&knight3);
		}

		// mage3
		boss.Attacked(mage3);
		if (boss.IsDead())
		{
			boss.end();
			break;
		}
		else
		{
			boss.Attack(&mage3);
			if (mage3.IsDead())
			{
				Sleep(3000);
				system("cls");
				cout << "모든 Player가 쓰러졌습니다." << endl << endl;
				cout << "Boss가 승리했습니다.";

				break;
			}
		}

	}

	return 0;
}