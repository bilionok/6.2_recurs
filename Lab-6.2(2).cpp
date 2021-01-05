// Lab_06_2.cpp
// < Біліонок Ярослав >
// Лабораторна робота № 6.2(2)
// Опрацювання одновимірних масивів рекурсивнис способoм
// Варіант 1

#include <iostream>
#include <cmath>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, const int size, const int Low, const  int High, int i) // Функція, що формує масив
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);

}

void Print(int* a, const int size, int i) // Функція, яка вивиодить масив на екран
{
	cout << setw(4) << a[i];

	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;

}

int FindMin(int* a, const int size, int min, int imin, int i) // Функція, яка шукає мінімальний елемент масиву і повертає його індекс у функцію main
{

	if (a[i] < min)
	{
		min = a[i];
		imin = i;
	}
	if (i < size - 1)
		FindMin(a, size, min,imin, i + 1);
	else
		return imin;
}
int FindMax(int* a, const int size, int max, int imax, int i) //  Функція, яка шукає максимальний елемент масиву і повертає його індекс у функцію main
{
	if (a[i] > max)
	{
		max = a[i];
		imax = i;
	}
	if (i < size - 1)
		FindMax(a, size, max, imax, i + 1);
	else
		return imax;
}
void Sort(int* a, const int size, int imin, int imax) // функція, яка міняє місцями максимальний та мінімальний елементи одновимірного масиву
{
	int max = a[imax];
	int min = a[imin];

	a[imax] = min;
	a[imin] = max;
}


int main()
{
	srand((unsigned)time(NULL));


	int Low, High, Min, Max, n;

	cout << "Array size ="; cin >> n;

	int* a = new int[n];


	cout << "Low ="; cin >> Low;
	cout << "High ="; cin >> High;
	cout << endl;

	Create(a, n, Low, High,0);
	cout << "Array =";
	Print(a, n, 0);
	cout << endl;

	Min = FindMin(a, n, a[0],0, 0);
	Max = FindMax(a, n, a[0],0, 0);

	cout << "Min a[" << Min << "]=" << a[Min] << endl;
	cout << "Max a[" << Max << "]=" << a[Max] << endl;
	cout << endl;

	Sort(a, n, Min, Max);
	cout << "Array =";
	Print(a, n, 0);
	cout << endl;

	return 0;
}