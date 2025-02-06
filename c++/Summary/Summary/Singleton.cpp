#include <iostream>
#include <unordered_map>

using namespace std;

// static 변수 : 정적 변수

// 메모리 4영역
// CODE
// DATA : Global, static
// 생성주기 : 프로그램 시작 / 프로그램 종료
// STACK : parameter, local
// 생성주기 : 함수 호출 시 / 함수 종료 시
// HEAP : 프로그래머 영역 

// 디자인패턴 : 어떤 문제를 해결하기 위해 사람들이 고안해서 굳혀진 패턴
// 싱클톤
// 1. 단 하나만 존재해야 함
// 2. 전역에서 접근해야 함
// 3. 생성주기도 조절할 수 있어야 함

class SoundManager
{
public:
	static void Create()
	{
		if(instance == nullptr)
			instance = new SoundManager();
	}

	static void Delete()
	{
		if (instance != nullptr)
		{
			delete instance;
			instance = nullptr;
		}
	}

	static SoundManager* Instance()
	{
		if (instance != nullptr)
			return instance;
		return nullptr;
	}

	void AttackSound() { cout << "Attack!!" << endl; }
	void PlaySound(string key) { cout << _soundMap[key] << endl; }

private:
	SoundManager()
	{
		_soundMap["Attack"] = "Attack!! Sound!";
		_soundMap["Dead"] = "Dead Sound!";
	
	}
	static SoundManager* instance;

	unordered_map<string, string> _soundMap;
};

SoundManager* SoundManager::instance = nullptr;

int main()
{
	SoundManager::Create();

	// SoundManager::Instance()->AttackSound();

	SoundManager::Instance()->PlaySound("Dead");

	SoundManager::Delete();

	return 0;
}