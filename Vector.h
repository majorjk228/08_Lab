#pragma once
#include "object.h"
#include <string>
#include <iostream>
using namespace std;


class Vector
{
public:
	Vector(int);//конструктор с параметрами
	Vector();//конструктор без параметрами
public:
	~Vector(void);//деструктор
	void Add();//добавление элемента в вектор
	void Del();
	void Show();
	void Age();
	int operator()();//размер вектора
	virtual void HandleEvent(const TEvent& e);
protected:
	Object** beg;//указатель на первый элемент вектора
	int size;//размер
	int cur;//текущая позиция
};