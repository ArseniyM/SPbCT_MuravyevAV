#include <iostream>
#include <math.h>
using namespace std;
void main()
{
	setlocale(LC_ALL, ".1251");
	float a, b, c;
	cout << "\na = "; cin >> a;
	cout << "\nb = "; cin >> b;
	cout << "\nc = "; cin >> c;
	if (a <= 0 || b <= 0 || c <= 0) {
		cout << "\n Длины сторон должны быть положительными";
	}
	else if ((a + b) < c || (a + c) < b || (b + c) < a) {
		cout << "\n Такой треугольник не существует";
	}
	else {
		if (a == b && a == c)
		{
			cout << "\n Треугольник равносторонний";
		}
		else cout << "\n Треугольник не равносторонний.";
	}
}