// Лабораторная работа №8, Вариант 3 (2 семестр).
//

#include <iostream>
#include <windows.h>    // Библиотека для русской локализации
#include "Dialog.h"
#include "Person.h"
#include "Abiturient.h"

using namespace std;


void main()
{
    setlocale(LC_ALL, "Russian");
    
    Dialog D;
    D.Execute();
}

