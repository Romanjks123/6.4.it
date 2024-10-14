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
	for (int i = 1; i < size; i += 2) { // �������� � ������� 1 � ��������� ����� ����� ������ �������
		S += a[i];
	}
	return S;
}
int SumNegatives(double* a, const int size)
{
	int firstNegativeIndex = -1;
	int lastNegativeIndex = -1;

	// ����� ������� ��'������ ��������
	for (int i = 0; i < size; i++) {
		if (a[i] < 0) {
			firstNegativeIndex = i;
			break;
		}
	}

	// ����� ���������� ��'������ ��������
	for (int i = size - 1; i >= 0; i--) {
		if (a[i] < 0) {
			lastNegativeIndex = i;
			break;
		}
	}

	// ���� �� �������� ��'����� �������� ��� ���� ���������
	if (firstNegativeIndex == -1 || lastNegativeIndex == -1 || firstNegativeIndex >= lastNegativeIndex) {
		return 0; // ���� �� ���� ���� ��������, ��������� 0
	}

	// ���������� ���� �� ������ � ������� ��'������ ����������
	int sum = 0;
	for (int i = firstNegativeIndex + 1; i < lastNegativeIndex; i++) {
		sum += a[i];
	}

	return sum;
}
void Sort(double* a, const int size) // ����� �������
{
	for (int i = 1; i < size; i++) // ������ ������� �������������� �������
	{
		int tmp = a[i]; // ������� ������� ��� �������
		int j = 0;      // ����� ������� �������

		// ����� ��� ��������. ���������, ����� �������� ����� �� 0
		if (tmp > 1) {
			a[i] = 0; // �������� �������� ������� �� 0
			continue; // ���������� �������� �������� ��� ����� ��������
		}

		// ����� ������� �������
		while (j < i && tmp > a[j])
			j++;

		// ���� ��������
		for (int k = i - 1; k >= j; k--)
			a[k + 1] = a[k];

		a[j] = tmp; // ������� ��������
	}
}

int main()
{
	srand((unsigned)time(NULL)); // ����������� ���������� ���������� �����
	int n;
	cout << "n= "; cin >> n;
	double* a = new double[n];
	int Low = -40;
	int High = 50;
	Create(a, n, Low, High);
	Print(a, n);
	int S = Sum(a, n); // ���������� ���� �������� �� �������� ��������
	cout << "Sum of elements with odd indexes: " << S << endl;
	int sum = SumNegatives(a, n);
	cout << "Sum between first and last negative elements: " << sum << endl;
	Sort(a, n);
	Print(a, n);
	delete[] a; // ��������� ���'��
	return 0;

}
