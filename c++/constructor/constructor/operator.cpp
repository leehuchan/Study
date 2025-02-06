#include <iostream>

using namespace std;

// 2차원 벡터
// 벡터는 힘과 방향

class Vector
{
public:
	Vector() : x(0.0f), y(0.0f) {}
	Vector(float x, float y)
		: x(x), y(y)
	{
		// this : 이 함수를 호출한 객체를 가리키는 포인터

		this->x = x;
		this->y = y;

	}
	~Vector() {}

	float x;
	float y;

	// 벡터의 덧셈
	Vector operator+(const Vector& other)
	{
		Vector result;
		result.x = this->x + other.x;
		result.y = this->y + other.y;

		return result;
		// return Vector(this->x + other.x, this->y + other.y); // 임시객체

	}

	// 벡터의 뺄셈

	// 벡터와 실수의 곱셈
	Vector operator*(float value)
	{
		Vector result;
		result.x = this->x * value;
		result.y = this->y * value;
	}

	// 대입연산자
	// a = b       a에다가 b를 대입하고, a의 원본을 반환한다.
	// 암시적으로 컴파일러가 만들어준다.
	Vector& operator=(const Vector& other)
	{
		this->x = other.x;
		this->y = other.y;

		return *this;
	}

	// 증감연산자
	// 전위 연산
	// ++a : a에다 1을 더하고 a원본을 반환

	// 후위
	// a++ : 임시값에 a를 복사하고 a에 1을 더한 후 임시값을 반환

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

	// 벡터의 힘의 크기
	float Length() const // 함수 뒤에 const는 멤버를 바꾸지 못하게 한다.
	{
		return sqrtf(this->x * this->x + this->y * this->y);
	}

	// 벡터 정규화(길이가 1인 벡터로 만드는 작업) -> 단위 벡터
	void Normalize()
	{
		// 구현
	}

	// 벡터 내적
	float Dot(const Vector& other)
	{
		// 구현
	}

	// 벡터의 외적 : 두 벡터에 모두 수직인 벡터
	float Cross(const Vector& other)
	{

	}
};


int main()
{
	Vector(); // 임시객체
	Vector v1(1, 1);
	Vector v2(2, 2);

	Vector v3 = v1 + v2 ;

	v1.PrintV();

	return 0;
}