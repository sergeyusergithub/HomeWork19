#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

int GCD(int n, int m) {
	int tmp, r;
	if (n < m) {
		tmp = n;
		n = m;
		m = tmp;
	}
	r = n % m;
	while (r != 0)
	{
		n = m;
		m = r;
		r = n % m;
	}
	return m;
	
}

int mirror_number(int num) {
	int invert = 0,r;
	while (num) {
		r = num % 10;
		invert = invert*10 + r;
		num = num / 10;
	}
	return invert;
}

void print_arr(int arr[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}

int index_sort(int arr[], const int length, int num) {
	int index = -1;
	for (int i = 0; i < length; i++) {
		if (arr[i] == num)
			index = i;
	}
		if (index == -1)
			return -1;
		else {
			std::sort(arr + index+1, arr + length);
			return index;
		}
			
}

void rand_arr(int arr[], const int length, int a, int b) {
	srand(time(NULL));
	int tmp;
	if (a > b){
		tmp = a;
		a = b;
		b = tmp;
	}
	for (int i = 0; i < length; i++) {
		arr[i] = rand()%(b - a + 1) + a;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	// Задача 1. Функция возвращающая НОД двух чисел

	std::cout << "Задача 1.\nНОД двух чисел:\n";
	std::cout << "НОД(4,16) = " << GCD(4, 16) << std::endl;
	std::cout << "НОД(16,4) = " << GCD(4, 16) << std::endl;
	std::cout << "НОД(5,16) = " << GCD(5, 16) << std::endl;
	std::cout << "НОД(18,30) = " << GCD(18, 30) << std::endl;
	std::cout << std::endl;
	
	// Задача 2. Функция возвращает отраженное число
	std::cout << "Задача 2.\nВведите число -> ";
	std::cin >> n;
	std::cout << "Отраженный вид числа: " << mirror_number(n) << "\n\n";

	// Задача 3. Функция возвращает позицию искомого 
	// числа и сортирует оставшуюся часть массива

	const int size = 10;
	int arr[size]{ 5, 10, 1, 3, 6, 12, 7, 2, 0, 4};

	std::cout << "Задача 3.\nИсходный массив:\n";
	print_arr(arr, size);

	std::cout << "Введите число -> ";
	std::cin >> n;

	int result = index_sort(arr, size, n);
	if (result != -1) {
		std::cout << "Первая позиция найденного числа в массиве: " << result << std::endl;
		std::cout << "Массив:\n";
		print_arr(arr, size);
		std::cout << std::endl;
	}
	else
		std::cout << "Заданное число не найдено!\n\n";


	

	// Задача 4. Функция принимает пустой массив и заполняет случайными
	// числами в заданном диапазоне

	int arr1[size]{ 0 };
	int a, b;
	std::cout << "Задача 4.\nВведите два числа (диапазон случайных чисел) -> ";
	std::cin >> a >> b;
	rand_arr(arr1, size, a, b);
	std::cout << "Массив случайных чисел в заданном диапазоне:\n";
	print_arr(arr1, size);
	std::cout << std::endl;


	return 0;
}