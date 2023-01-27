#include "Vector.h"
#include "Event.h"
#include "Person.h"
#include "Abiturient.h"

//����������
Vector::~Vector(void)
{
	if (beg != 0)delete[] beg;
	beg = 0;
}
//����������� � �����������
Vector::Vector(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}

//����������� ��� �����������
Vector::Vector()
{
	beg = new Object * [0];
	cur = 0;
	size = 0;
}

//���������� �������, �� ������� ��������� ��������� p � ������
void Vector::Add()
{
	Object* p;
	//����� �� �������� ���� ��������� �������
	cout << "1.Person" << endl;
	cout << "2.Abiturient" << endl;
	int y;
	cin >> y;
	if (y == 1)//���������� ������� ������ Person
	{
		Person* a = new (Person);
		a->Input();//���� �������� ���������
		p = a;
		if (cur < size)
		{
			beg[cur] = p;//���������� � ������
			cur++;
		}
	}
	else
		if (y == 2) //���������� ������� ������ Lorry
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
//�������� �������
void Vector::Show()
{
	if (cur == 0) cout << "Empty" << endl;
	Object** p = beg;//��������� �� ��������� ���� Object
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();//����� ������ Show() (������� ����������)
		p++;//����������� ��������� �� ��������� ������
	}
}

//������� �������� �������� ������
void Vector::Age()
{
	if (cur == 0) cout << "Empty Age" << endl;
	int age = 0;
	Object** p = beg;//��������� �� ��������� ���� Object
	for (int i = 0; i < cur; i++)
	{
		age += (*p)->GetAge();//����� ������ GetAge() (������� ����������)
		p++;//����������� ��������� �� ��������� ������
	}
	age = age / cur;
	cout << "������� ������� ������: " << age << endl;
}

//��������, ������� ���������� ������ �������
int Vector::operator ()()
{
	return cur;
}
//�������� �������� �� �������, ������ �� �������������!
void Vector::Del()
{
	if (cur == 0)return;//������
	cur--;
}

void Vector::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			(*p)->HandleEvent(e);//����� ������ (������� ����������)
			p++;//����������� ��������� �� ��������� ������
		}
	}
}