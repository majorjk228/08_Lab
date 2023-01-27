#include "Abiturient.h"
#include<cmath> // Для вычислений в степень

//конструктор без параметров
Abiturient::Abiturient(void) :Person()
{
	cnt_point = 0;
	spec = "";
}

//дестрктор
Abiturient::~Abiturient(void)
{
}

//конструктор с параметрами
Abiturient::Abiturient(string F, int S, int G, string R) :Person(F, S)
{
	cnt_point = G;
	spec = R;
}

//конструктор копирования
Abiturient::Abiturient(const Abiturient& L)
{
	name = L.name;
	age = L.age;
	cnt_point = L.cnt_point;
	spec = L.spec;
}

//модификатор
void Abiturient::Set_Point(int G)
{
	cnt_point = G;
}

//модификатор
void Abiturient::Set_Spec(string R)
{
	spec = R;
}

//оперция присваивания
Abiturient& Abiturient::operator=(const Abiturient& L)
{
	if (&L == this)return *this;
	name = L.name;
	age = L.age;
	cnt_point = L.cnt_point;
	spec = L.spec;
	return *this;
}

//ввод
void Abiturient::Input()
{
	cout << "\nName:"; cin >> name;
	cout << "\nAge:"; cin >> age;
	cout << "\nPoints:"; cin >> cnt_point;
	cout << "\nSpecialntost : "; cin >> spec;
}

// Вывод
void Abiturient::Show()
{
	cout << "\nName : " << name;
	cout << "\nAge : " << age;
	cout << "\nPoints: " << cnt_point;
	cout << "\nSpecialntost: " << spec;
	cout << "\n";
}

