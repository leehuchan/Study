#include <iostream>

using namespace std;

// 2���� ����
// ���ʹ� ���� ����

class Vector
{
public:
	Vector() : x(0.0f), y(0.0f) {}
	Vector(float x, float y)
		: x(x), y(y)
	{
		// this : �� �Լ��� ȣ���� ��ü�� ����Ű�� ������

		this->x = x;
		this->y = y;

	}
	~Vector() {}

	float x;
	float y;

	// ������ ����
	Vector operator+(const Vector& other)
	{
		Vector result;
		result.x = this->x + other.x;
		result.y = this->y + other.y;

		return result;
		// return Vector(this->x + other.x, this->y + other.y); // �ӽð�ü

	}

	// ������ ����

	// ���Ϳ� �Ǽ��� ����
	Vector operator*(float value)
	{
		Vector result;
		result.x = this->x * value;
		result.y = this->y * value;
	}

	// ���Կ�����
	// a = b       a���ٰ� b�� �����ϰ�, a�� ������ ��ȯ�Ѵ�.
	// �Ͻ������� �����Ϸ��� ������ش�.
	Vector& operator=(const Vector& other)
	{
		this->x = other.x;
		this->y = other.y;

		return *this;
	}

	// ����������
	// ���� ����
	// ++a : a���� 1�� ���ϰ� a������ ��ȯ

	// ����
	// a++ : �ӽð��� a�� �����ϰ� a�� 1�� ���� �� �ӽð��� ��ȯ

	Vector operator++(int)
	{
		Vector result(*this);
		this->x += 1.0f;
		this->y += 1.0f;
		
		return result;

	}

	void PrintV()
	{
		cout << "X : " << x << endl;
		cout << "Y : " << y << endl;
	}

	// ������ ���� ũ��
	float Length() const // �Լ� �ڿ� const�� ����� �ٲ��� ���ϰ� �Ѵ�.
	{
		return sqrtf(this->x * this->x + this->y * this->y);
	}

	// ���� ����ȭ(���̰� 1�� ���ͷ� ����� �۾�) -> ���� ����
	void Normalize()
	{
		// ����
	}

	// ���� ����
	float Dot(const Vector& other)
	{
		// ����
	}

	// ������ ���� : �� ���Ϳ� ��� ������ ����
	float Cross(const Vector& other)
	{

	}
};


int main()
{
	Vector(); // �ӽð�ü
	Vector v1(1, 1);
	Vector v2(2, 2);

	Vector v3 = v1 + v2 ;

	v1.PrintV();

	return 0;
}