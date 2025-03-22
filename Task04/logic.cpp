// Сумма элементов столбцов с экстремальными элементами
// [The Sum of elements of columns with extreme elements]
// 
// Дана математическая прямоугольная матрица размером N на M.
// Необходимо разработать функцию (или программу), которая 
// высчитывает сумму элементов в тех столбцах заданной матрицы,
// которые содержат хотя бы один экстремальный элемент.

#include "logic.h"

int get_extreme_values(int** matrix, int n, int m, bool type) {
	int value = matrix[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			bool condition = type ? matrix[i][j] < value : matrix[i][j] > value;
			if (condition) {
				value = matrix[i][j];
			}
		}
	}

	return value;
}

//int get_min_values(int** matrix, int n, int m, bool type) {
//	int min = matrix[0][0];
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			if (min > matrix[i][j]) {
//				min = matrix[i][j];
//			}
//		}
//	}
//
//	return min;
//}

bool is_extreame_elements_in_columns(int** matrix, int n, int index, int min, int max) {
	for (int i = 0; i < n; i++) {
		if (matrix[i][index] == max || matrix[i][index] == min) {
			return true;
		}
	}

	return false;
}

int sum_elements_of_columns_with_extreme_value(int** matrix, int n, int m) {
	if( n <= 0 || matrix == nullptr) {
		return 0;
	}

	int max = get_extreme_values(matrix, n, m, false);
	int min = get_extreme_values(matrix, n, m, true);
	int sum = 0;

	for (int j = 0; j < m; j++) {
		if (is_extreame_elements_in_columns(matrix, n, j, min, max)) {
			for (int i = 0; i < n; i++) {
				sum += matrix[i][j];
			}
		}
	}

	return sum;
}