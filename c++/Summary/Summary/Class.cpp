#include <iostream>

using namespace std;

// ���α׷���

// ��ü : �Ӽ��� ����� ���� �޸𸮿� �Ҵ�Ǿ��ִ� ��
// ��üȭ : Ŭ���� �ڷ����� �޸𸮿� �Ҵ��ϴ� ��
// �ν��Ͻ� : �Ӽ��� ����� ������ �ʾƵ� �޸𸮿� �Ҵ�Ǿ��ִ� ��
// �ν��Ͻ�ȭ : �޸𸮿� �Ҵ��ϴ� ��

// 1. ��ü������ 3�Ӽ�
// ���м�
// -> �ܺο��� ����(����) �����ؼ� �ٲ��� ���ϰ� �Ϸ���
// -> ����Լ� �������� ������Ű����
// ���������� : public(��𿡼��� ����) / protected(����Լ�, �ڽ��� ����Լ�) / privatte(����Լ�, friend)
struct Vector // ����
{
public:
	float x;
	float y;
};

class Car // ��ü(�Ӽ�, ���)
{
public:
	// ����Լ�
	// - ���
	// ��������� ���� ���� -> �Ӽ��� �ٷ�� ���
	// ����Լ��� ��ü�� �־�� ȣ���� ����
	void PrintCar() { cout << _engine << endl; }
	int GetEngine() { return _engine; }
	void SetEngine(int engine) { this->_engine = engine; }

private:
	// �������
	// -�Ӽ�
	int _engine;
	int _handle;
	int _wheels;
	int _doors;
};

int main()
{
	Car car;

	// ����� ��� �ڵ�

	car.SetEngine(5);
	cout << car.GetEngine() << endl;

	return 0;
}