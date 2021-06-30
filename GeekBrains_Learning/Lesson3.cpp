#include <iostream>

extern int a, b, c, d;

int main()
{

	// Задание №1 (4)

	float  fResult = a * (b + (static_cast<float>(c) / d));

	std::cout << fResult << std::endl;

	// Задание №2

	int value = 10;
	int result = (value <= 21) ? (value - 21) : 2 * (value - 21);

	std::cout << result << std::endl;

	// Задание №3

	int massiv[3][3][3] = {
		{
			{1, 2, 3}, {4, 5, 6}, {7, 8, 9},
		},
		{
			{10, 11, 12}, {13, 14, 15}, {16, 17, 18},
		},
		{
			{19, 20, 21}, {22, 23, 24}, {25, 26, 27},
		},
	};

	int* ptr = nullptr;
	ptr = &(massiv[1][1][1]);
	std::cout << *ptr << std::endl; // 14
	(*ptr) *= 3;
	std::cout << *ptr << std::endl; // 42

	return 0;
}