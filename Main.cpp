#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
void fill_arr(T arr[], int length, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (right - left + 1) + left;	// [left..right]
}

template <typename T>
void print_arr(T arr[], int length) {
	std::cout << '[';
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}

template <typename T>
void resize_arr(T*& arr, int length, int new_length) {
	if (new_length == length) {
		std::cout << "New size is equal to initial. No resize needed!\n";
		return;
	}
	T* tmp = new T[new_length]{};
	int min = length < new_length ? length : new_length;
	for (int i = 0; i < min; i++)
		tmp[i] = arr[i];
	delete[] arr;
	arr = tmp;
}

int main() {
	int n, m;

	// 24.1 Arrays merge
	std::cout << "\t24.1 Arrays merge\n";
	std::cout << "Enter 1st array size -> ";
	std::cin >> n;
	int* arr_A = new int[n];
	fill_arr(arr_A, n, 0, 10);	// [0..10]
	std::cout << "Initial 1st array:\n";
	print_arr(arr_A, n);

	std::cout << "\nEnter 2nd array size -> ";
	std::cin >> m;
	int* arr_B = new int[m];
	fill_arr(arr_B, m, 0, 10);	// [0..10]
	std::cout << "Initial 2nd array:\n";
	print_arr(arr_B, m);

	int* arr_C = new int[n + m];
	for (int i = 0; i < n; i++)
		arr_C[i] = arr_A[i];
	for (int i = n; i < n + m; i++)
		arr_C[i] = arr_B[i - n];
	std::cout << "\nResult array after merging:\n";
	print_arr(arr_C, n+ m);

	delete[] arr_A;
	delete[] arr_B;
	delete[] arr_C;


	//24.2 Array resize
	std::cout << "\n\t24.2 Array resize\n";
	std::cout << "Enter array size -> ";
	std::cin >> n;
	int* arr = new int[n];
	fill_arr(arr, n, 0, 10);	// [0..10]
	std::cout << "Initial array:\n";
	print_arr(arr, n);
	std::cout << "\nEnter new array size -> ";
	std::cin >> m;
	resize_arr(arr, n, m);
	std::cout << "Result array:\n";
	print_arr(arr, m);

	delete[] arr;

	return 0;
}