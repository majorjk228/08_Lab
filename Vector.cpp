#include "Vector.h"
#include "Event.h"
#include "Person.h"
#include "Abiturient.h"

//деструктор
Vector::~Vector(void)
{
	if (beg != 0)delete[] beg;
	beg = 0;
}
//конструктор с параметрами
Vector::Vector(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}

//конструктор без параметрами
Vector::Vector()
{
	beg = new Object * [0];
	cur = 0;
	size = 0;
}

//добавление объекта, на который указывает указатель p в вектор
void Vector::Add()
{
	Object* p;
	//выбор из объектов двух возможных классов
	cout << "1.Person" << endl;
	cout << "2.Abiturient" << endl;
	int y;
	cin >> y;
	if (y == 1)//добавление объекта класса Person
	{
		Person* a = new (Person);
		a->Input();//ввод значений атрибутов
		p = a;
		if (cur < size)
		{
			beg[cur] = p;//добавление в вектор
			cur++;
		}
	}
	else
		if (y == 2) //добавление объекта класса Lorry
		{
			Abiturient* b = new Abiturient;
			b->Input();
			p = b;
			if (cur < size)
			{
				beg[cur] = p;
				cur++;
			}
		}
		else return;
}
//просмотр вектора
void Vector::Show()
{
	if (cur == 0) cout << "Empty" << endl;
	Object** p = beg;//указатель на указатель типа Object
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();//вызов метода Show() (позднее связывание)
		p++;//передвигаем указатель на следующий объект
	}
}

//Подсчет среднего возраста группы
void Vector::Age()
{
	if (cur == 0) cout << "Empty Age" << endl;
	int age = 0;
	Object** p = beg;//указатель на указатель типа Object
	for (int i = 0; i < cur; i++)
	{
		age += (*p)->GetAge();//вызов метода GetAge() (позднее связывание)
		p++;//передвигаем указатель на следующий объект
	}
	age = age / cur;
	cout << "Средний возраст группы: " << age << endl;
}

//операция, которая возвращает размер вектора
int Vector::operator ()()
{
	return cur;
}
//удаление элемента из вектора, память не освобождается!
void Vector::Del()
{
	if (cur == 0)return;//пустой
	cur--;
}

void Vector::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			(*p)->HandleEvent(e);//вызов метода (позднее связывание)
			p++;//передвигаем указатель на следующий объект
		}
	}
}