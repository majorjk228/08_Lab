#pragma once
#include "Person.h"

//класс Abiturient наследуется от класса Person
class Abiturient :
	public Person
{
public:
	Abiturient(void);//конструктор без параметров
public:
	~Abiturient(void);//деструктор
	Abiturient(string, int, int, string);//конструктор с параметрами
	Abiturient(const Abiturient&);//конструктор копирования
	void Set_Point(int);   //селектор
	void Set_Spec(string); //селектор
	void Input();
	void Show();												//функция для просмотра атрибутов класса с помощью указателя
	Abiturient& operator=(const Abiturient&);					//операция присваивания
protected:
	int cnt_point; // Количество баллов
	string spec;   // специальность
};
