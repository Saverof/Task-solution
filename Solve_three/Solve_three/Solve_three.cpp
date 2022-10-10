#include <iostream>

using namespace std;

// А если надо передать произвольную матрицу?
bool max_in_col(int matrix[3][4], int i, int j)
{
	for (int k = 0; k < 3; k++)
	{
		if (matrix[k][j] > matrix[i][j])
			return false;
	}
	return true;
}

bool min_in_row(int matrix[3][4], int i, int j)
{
	for (int k = 0; k < 4; k++)
	{
		if (matrix[i][k] < matrix[i][j])
			return false;
	}
	return true;
}

void saddlePoints(int matrix[3][4])
 {
//	 Можно как-то оптимизировать поиск? Например одновременно анализировать и строку и столбец?
	 for (int i = 0; i < 3; i++)
	 {
		 for (int j = 0; j < 4; j++)
		 {
//				А что будет, если седловой точки нет?
			 if (!min_in_row(matrix, i, j) || !max_in_col(matrix, i, j)) continue;
			 cout << "Элемент " << matrix[i][j] <<  " является седловым.\n";
			 cout << "Строка " << i + 1 << " \t столбец: " << j + 1;
		 }
	 }
 }

 void show_matrix(int matrix[3][4])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << "\n";
	}
}


int main()
{
	setlocale(LC_ALL, "Rus");
	int matrix[3][4] = { {5,6,4,5}, {-2,5,3,7}, {8,7,-2,6} };
//	Зачем путать стиль написания названий методов? Нужно писать в одном стиле
	show_matrix(matrix);
	saddlePoints(matrix);

	return 0;
}

