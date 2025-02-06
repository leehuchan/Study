#include <iostream>

using namespace std;
// ��ȣ�� ���� ���������� ��Ʈ������ �ؾ��� (������ ������ ���� ����)

// ��Ʈ ����
// &, |, ^, >>, <<
// & : ��Ʈ and ����
// | : ��Ʈ or ����
// ^ : ��Ʈ xor ���� => �� �� ������ 0, �ٸ��� 1

// << : ���� ����Ʈ ����
// ȿ�� : X2
// �� ���� ��Ʈ�� �������� �ȴ�.
// ������ ��Ʈ�� 0���� ä����
// 
// >> : ���� ����Ʈ ����
// �� ������ ��Ʈ�� �������� �ȴ�.
// �� ���ʺ�Ʈ�� ��ȣ�� ������ �ȴ�.

// ���� ���� cc�⿡�ɷȴ��� Ȯ��
unsigned char bitFlag = 0;
const unsigned char stun = 1;
const unsigned char subdue = (1 << 1);
const unsigned char sleep = (1 << 2);
const unsigned char transition = (1 << 3);



int main()
{
	// ����, ����
	bitFlag = subdue;

	// �������ɷ��ֽ��ϱ�?
	// & stun -> ��Ʈ����ũ

	if (bitFlag & stun)
	{
		cout << "������ �ɷ��ֽ��ϴ�." << endl;
	}

	// ���п� �ɸ���, ������ Ǯ��

	bitFlag |= subdue;
	bitFlag ^= stun;

	// �����̰� ���̻������� ����
	if ((bitFlag & subdue) && (subdue | transition))
	{
		cout << "�����̰� ���̻����Դϴ�." << endl;
	}

	return 0;
}