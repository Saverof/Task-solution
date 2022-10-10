#include <iostream>

using namespace std;

template <int n, int m>
bool max_in_col(int (&matrix)[n][m], int i, int j)
{
	for (int k = 0; k < n; k++)
	{
		if (matrix[k][j] > matrix[i][j])
			return false;
	}
	return true;
}

template <int n, int m>
bool min_in_row(int (&matrix)[n][m], int i, int j)
{
	for (int k = 0; k < m; k++)
	{
		if (matrix[i][k] < matrix[i][j])
			return false;
	}
	return true;
}

template <int n, int m>
void saddle_points(int (&matrix)[n][m])
 {
	bool found = false;
	 for (int i = 0; i < n; i++)
	 {
		 for (int j = 0; j < m; j++)
		 {
			 if (!min_in_row(matrix, i, j) || !max_in_col(matrix, i, j)) continue;
			 cout << "Элемент " << matrix[i][j] <<  " является седловым.\n";
			 cout << "Строка: " << i + 1 << " \t столбец: " << j + 1;
			 found = true;
		 }
	 }
	 if (found == false)
		 cout << "В данной матрице нет седловой точки.\n";
 }

template <int n, int m>
 void show_matrix(int (& matrix)[n][m])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << "\n";
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");

	// Зададим число строк и столбцов
	const int n = 3; 
	const int m = 4;

	// Зададим значения матрицы
	int matrix[n][m] = { 
		{5,6,4,5}, 
		{-2,5,3,7}, 
		{8,7,-2,6} };

	// Выведем результат
	show_matrix(matrix);
	saddle_points(matrix);

	return 0;
}

