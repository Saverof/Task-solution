#include <iostream>
#include <iomanip>

using namespace std;

// Зачем здесь шаблоны??? Первый раз вижу такое решение. С указателями работал?
/*

Работал, и не раз. Использование шаблонов это один из методов передачи константного массива в функцию, на языке С++.
Почему не использовал указатели. В задании не сказано, будет меняться массив внутри программы или нет, будет ли пользователь работать с ним каким то образом или нет.
Я сделал вывод, что нужно использовать константный массив, а не динамический, так как для такого случия он, по моему мнению, идеально подходил.
Так как за таким массивом не надо следить, не нужно удалять память, он легче читается, а значит код проще.

*/

bool max_in_col(int **matrix, int i, int j, int n)
{
	for (int k = 0; k < n; k++)
	{
		if (matrix[k][j] > matrix[i][j])
			return false;
	}
	return true;
}

bool min_in_row(int** matrix, int i, int j, int m)
{
	for (int k = 0; k < m; k++)
	{
		if (matrix[i][k] < matrix[i][j])
			return false;
	}
	return true;
}

void saddle_points(int** matrix, int n, int m)
{
	bool found = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!min_in_row(matrix, i, j, m) || !max_in_col(matrix, i, j, n)) continue;
			cout << "Элемент " << matrix[i][j] << " является седловым.\n";
			cout << "Строка: " << i + 1 << " \t столбец: " << j + 1 << endl;
			found = true;
			break;
		}
	}
	if (found == false)
		cout << "В данной матрице нет седловой точки.\n";
}

void show_matrix(int** matrix, int n, int m)
{
	cout << "\nВведено:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setw(3) << matrix[i][j];
		}
		cout << endl;

	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Rus");

	const int n = 3;
	const int m = 4;
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++)
		matrix[i] = new int[m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "Ведите элемент [" << i + 1 << "]";
			cout << "[" << j + 1 << "] = ";
			cin >> matrix[i][j];
		}
	}

	// Выведем результат
	show_matrix(matrix, n, m);
	saddle_points(matrix, n, m);

	// Освобождение памяти
	delete[] matrix;

	return 0;
}
