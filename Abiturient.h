#pragma once
#include "Person.h"

//����� Abiturient ����������� �� ������ Person
class Abiturient :
	public Person
{
public:
	Abiturient(void);//����������� ��� ����������
public:
	~Abiturient(void);//����������
	Abiturient(string, int, int, string);//����������� � �����������
	Abiturient(const Abiturient&);//����������� �����������
	void Set_Point(int);   //��������
	void Set_Spec(string); //��������
	void Input();
	void Show();												//������� ��� ��������� ��������� ������ � ������� ���������
	Abiturient& operator=(const Abiturient&);					//�������� ������������
protected:
	int cnt_point; // ���������� ������
	string spec;   // �������������
};
