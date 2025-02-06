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


// sln : solution
// - 서점
// proj : project
// - 구역

bool IsAllDead(Goblin arr[], int size)
{
	bool allDead = true;

	for (int i = 0; i < size; i++)
	{
		if (arr[i].IsDead() == false)
			return false;
	}

	return allDead;
}

int main()
{
	int characterChoice;
	int monsterChoice;
	int monsterNum = 1;
	int turn = 0;
	int turn2 = 0;

	while (true)
	{
		cout << "캐릭터를 선택하세요." << endl << endl;
		cout << "1. Knight 2. Mage 3. Archer" << endl;

		cin >> characterChoice;

		if (characterChoice == 1)
		{
			while (true)
			{
				system("cls");

				Knight knight("Knight", 250, 50);

				cout << endl;

				cout << "난이도를 선택하세요." << endl << endl;
				cout << "1. Easy Mode 2. Hard Mode" << endl;

				cin >> monsterChoice;

				if (monsterChoice == 1)
				{
					system("cls");
					cout << "Easy Mode를 선택하셨습니다.";
					Sleep(3000);
					system("cls");

					Goblin goblin("Goblin", 300, 50);
					Sleep(4000);

					system("cls");

					cout << "전투 시작";
					Sleep(3000);

					system("cls");

					while (true)
					{
						turn++;

						system("cls");

						cout << "턴 " << turn << endl << endl;

						knight.Attack(&goblin);
						Sleep(3000);

						if (goblin.IsDead())
						{
							break;
						}
						else
						{
							cout << endl;

							goblin.Attack(&knight);

							if (knight.IsDead())
							{
								break;
							}
						}

						Sleep(5000);

					}

					break;
				}
				else if (monsterChoice == 2)
				{
					system("cls");
					cout << "Hard Mode를 선택하셨습니다.";
					Sleep(3000);
					system("cls");

					cout << "몬스터 Goblin 10 마리가 출현했습니다." << endl;
					cout << "각각 Goblin들의 HP : 50" << endl;
					cout << "각각 Goblin들의 ATK : 5" << endl;

					Goblin goblins[10] = {};
					for (int i = 0; i < 10; i++)
					{
						goblins[i].SetName("Goblin " + to_string(monsterNum));
						monsterNum++;
					}

					Sleep(5000);

					system("cls");

					cout << "전투 시작";

					Sleep(2000);

					system("cls");

					for (int i = 0; i < 10; i++)
					{
						turn2++;

						system("cls");

						cout << "턴 " << turn2 << endl << endl;

						knight.Attack(&goblins[i]);
						Sleep(3000);

						if (goblins[9].IsDead())
						{
							break;
						}
						else if (!goblins[i + 1].IsDead())
						{
							cout << endl;

							goblins[i + 1].Attack(&knight);
							Sleep(5000);

							if (knight.IsDead())
							{
								break;
							}

						}
						else
						{
							cout << "오류";
						}

					}

					break;
				}
				else
				{
					system("cls");
					cout << "잘못 입력하셨습니다." << endl << "1번, 2번 중에 선택하세요. (숫자만 입력해주세요.)" << endl;
					Sleep(4000);
				}
			}
			cout << "게임 종료";
			exit(0);
		}
		else if (characterChoice == 2)
		{
			while (true)
			{
				system("cls");

				Mage mage("Mage", 150, 150);

				cout << endl;

				cout << "난이도를 선택하세요." << endl << endl;
				cout << "1. Easy Mode 2. Hard Mode" << endl;

				cin >> monsterChoice;

				if (monsterChoice == 1)
				{
					system("cls");
					cout << "Easy Mode를 선택하셨습니다.";
					Sleep(3000);
					system("cls");

					Goblin goblin("Goblin", 300, 50);
					Sleep(4000);

					system("cls");

					cout << "전투 시작";
					Sleep(3000);

					system("cls");

					while (true)
					{
						turn++;

						system("cls");

						cout << "턴 " << turn << endl << endl;

						mage.Attack(&goblin);
						Sleep(3000);

						if (goblin.IsDead())
						{
							break;
						}
						else
						{
							cout << endl;

							goblin.Attack(&mage);

							if (mage.IsDead())
							{
								break;
							}
							Sleep(5000);
						}
					}
					break;
				}
				else if (monsterChoice == 2)
				{
					system("cls");
					cout << "Hard Mode를 선택하셨습니다.";
					Sleep(3000);
					system("cls");

					cout << "몬스터 Goblin 10 마리가 출현했습니다." << endl;
					cout << "각각 Goblin들의 HP : 50" << endl;
					cout << "각각 Goblin들의 ATK : 5" << endl;

					Goblin goblins[10] = {};

					for (int i = 0; i < 10; i++)
					{
						goblins[i].SetName("Goblin " + to_string(monsterNum));
						monsterNum++;
					}

					Sleep(5000);

					system("cls");

					cout << "전투 시작";

					Sleep(2000);

					system("cls");

					for (int i = 0; i < 10; i++)
					{
						turn2++;

						system("cls");

						cout << "턴 " << turn2 << endl << endl;

						mage.Attack(&goblins[i]);
						Sleep(3000);

						if (goblins[9].IsDead())
						{
							break;
						}
						else if (!goblins[i + 1].IsDead())
						{
							cout << endl;

							goblins[i + 1].Attack(&mage);
							Sleep(5000);

							if (mage.IsDead())
							{
								break;
							}
						}
						else
						{
							cout << "오류";
						}
					}
					break;
				}
				else
				{
					system("cls");
					cout << "잘못 입력하셨습니다." << endl << "1번, 2번 중에 선택하세요. (숫자만 입력해주세요.)" << endl;
					Sleep(4000);
				}
			}
			cout << "게임 종료";
			exit(0);
		}
		else if (characterChoice == 3)
		{
			while (true)
			{
				system("cls");

				Archer archer("Archer", 200, 100);

				cout << endl;

				cout << "난이도를 선택하세요." << endl << endl;
				cout << "1. Easy Mode 2. Hard Mode" << endl;

				cin >> monsterChoice;

				if (monsterChoice == 1)
				{
					system("cls");
					cout << "Easy Mode를 선택하셨습니다.";
					Sleep(3000);
					system("cls");

					Goblin goblin("Goblin", 300, 50);
					Sleep(4000);

					system("cls");

					cout << "전투 시작";
					Sleep(3000);

					system("cls");

					while (true)
					{
						turn++;

						system("cls");

						cout << "턴 " << turn << endl << endl;

						archer.Attack(&goblin);
						Sleep(3000);

						if (goblin.IsDead())
						{
							break;
						}
						else
						{
							cout << endl;

							goblin.Attack(&archer);

							if (archer.IsDead())
							{
								break;
							}
							Sleep(5000);
						}
					}
					break;
				}
				else if (monsterChoice == 2)
				{
					system("cls");
					cout << "Hard Mode를 선택하셨습니다.";
					Sleep(3000);
					system("cls");

					cout << "몬스터 Goblin 10 마리가 출현했습니다." << endl;
					cout << "각각 Goblin들의 HP : 50" << endl;
					cout << "각각 Goblin들의 ATK : 5" << endl;

					Goblin goblins[10] = {};

					for (int i = 0; i < 10; i++)
					{
						goblins[i].SetName("Goblin " + to_string(monsterNum));
						monsterNum++;
					}
					Sleep(5000);

					system("cls");

					cout << "전투 시작";

					Sleep(2000);

					system("cls");

					for (int i = 0; i < 10; i++)
					{
						turn2++;

						system("cls");

						cout << "턴 " << turn2 << endl << endl;

						archer.Attack(&goblins[i]);
						Sleep(3000);

						if (goblins[9].IsDead())
						{
							break;
						}
						else if (!goblins[i + 1].IsDead())
						{
							cout << endl;

							goblins[i + 1].Attack(&archer);

							Sleep(5000);


							if (archer.IsDead())
							{
								break;
							}
						}
						else
						{
							cout << "오류";
						}
					}
					break;
				}
				else
				{
					system("cls");
					cout << "잘못 입력하셨습니다." << endl << "1번, 2번 중에 선택하세요. (숫자만 입력해주세요.)" << endl;
					Sleep(4000);
				}
			}
			cout << "게임 종료";
			exit(0);
		}
		else
		{
			system("cls");
			cout << "잘못 입력하셨습니다." << endl << "1번, 2번, 3번 중에 선택하세요. (숫자만 입력해주세요.)" << endl;
			Sleep(4000);
			system("cls");
		}


		// system("cls");
		cout << "게임 종료";
	}

	return 0;
}

// 과제 1.
// - Player가 Knight, Mage, Archer 중 하나 선택
// - Player와 Goblin과 죽을 때 까지 전투

// Extra
// - Player가 Knight, Mage, Archer 중 하나 선택
// - Goblin 배열로 10마리
// - Player 1 vs Goblin 10
// - 고블린이 전부 죽거나, Player가 죽으면 게임 끝


// 질문사항
// 1. 추상클래스 선언 후 오버라이딩 하는 도중 protected인데도 Creature* 변수를 가져오지 못하는 이유
// 2. lvalue