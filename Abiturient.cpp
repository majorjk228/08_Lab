#include "Abiturient.h"
#include<cmath> // ��� ���������� � �������

//����������� ��� ����������
Abiturient::Abiturient(void) :Person()
{
	cnt_point = 0;
	spec = "";
}

//���������
Abiturient::~Abiturient(void)
{
}

//����������� � �����������
Abiturient::Abiturient(string F, int S, int G, string R) :Person(F, S)
{
	cnt_point = G;
	spec = R;
}

//����������� �����������
Abiturient::Abiturient(const Abiturient& L)
{
	name = L.name;
	age = L.age;
	cnt_point = L.cnt_point;
	spec = L.spec;
}

//�����������
void Abiturient::Set_Point(int G)
{
	cnt_point = G;
}

//�����������
void Abiturient::Set_Spec(string R)
{
	spec = R;
}

//������� ������������
Abiturient& Abiturient::operator=(const Abiturient& L)
{
	if (&L == this)return *this;
	name = L.name;
	age = L.age;
	cnt_point = L.cnt_point;
	spec = L.spec;
	return *this;
}

//����
void Abiturient::Input()
{
	cout << "\nName:"; cin >> name;
	cout << "\nAge:"; cin >> age;
	cout << "\nPoints:"; cin >> cnt_point;
	cout << "\nSpecialntost : "; cin >> spec;
}

// �����
void Abiturient::Show()
{
	cout << "\nName : " << name;
	cout << "\nAge : " << age;
	cout << "\nPoints: " << cnt_point;
	cout << "\nSpecialntost: " << spec;
	cout << "\n";
}

