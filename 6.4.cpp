#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(double* a, const int size, const int Low, const int High)
{
	for (int i = 0; i < size; i++)
		a[i] = Low + rand() % (High - Low + 1);
}
void Print(double* a, const int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(4) << a[i];
	cout << endl;
}
int Sum(double* a, const int size)
{
	int S = 0;
	for (int i = 1; i < size; i += 2) { // Починаємо з індексу 1 і проходимо через кожен другий елемент
		S += a[i];
	}
	return S;
}
int SumNegatives(double* a, const int size)
{
	int firstNegativeIndex = -1;
	int lastNegativeIndex = -1;

	// Пошук першого від'ємного елемента
	for (int i = 0; i < size; i++) {
		if (a[i] < 0) {
			firstNegativeIndex = i;
			break;
		}
	}

	// Пошук останнього від'ємного елемента
	for (int i = size - 1; i >= 0; i--) {
		if (a[i] < 0) {
			lastNegativeIndex = i;
			break;
		}
	}

	// Якщо не знайдено від'ємних елементів або вони збігаються
	if (firstNegativeIndex == -1 || lastNegativeIndex == -1 || firstNegativeIndex >= lastNegativeIndex) {
		return 0; // Якщо між ними немає елементів, повертаємо 0
	}

	// Обчислення суми між першим і останнім від'ємними елементами
	int sum = 0;
	for (int i = firstNegativeIndex + 1; i < lastNegativeIndex; i++) {
		sum += a[i];
	}

	return sum;
}
void Sort(double* a, const int size) // метод вставки
{
	for (int i = 1; i < size; i++) // індекс початку невпорядкованої частини
	{
		int tmp = a[i]; // вибрали елемент для вставки
		int j = 0;      // пошук позиції вставки

		// Умова для перевірки. Наприклад, заміна непарних чисел на 0
		if (tmp > 1) {
			a[i] = 0; // замінюємо непарний елемент на 0
			continue; // пропускаємо подальші операції для цього елемента
		}

		// Пошук позиції вставки
		while (j < i && tmp > a[j])
			j++;

		// Зсув елементів
		for (int k = i - 1; k >= j; k--)
			a[k + 1] = a[k];

		a[j] = tmp; // вставка елемента
	}
}

int main()
{
	srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
	int n;
	cout << "n= "; cin >> n;
	double* a = new double[n];
	int Low = -40;
	int High = 50;
	Create(a, n, Low, High);
	Print(a, n);
	int S = Sum(a, n); // Обчислюємо суму елементів на непарних індексах
	cout << "Sum of elements with odd indexes: " << S << endl;
	int sum = SumNegatives(a, n);
	cout << "Sum between first and last negative elements: " << sum << endl;
	Sort(a, n);
	Print(a, n);
	delete[] a; // Звільнення пам'яті
	return 0;

}
