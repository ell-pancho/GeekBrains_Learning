#include <iostream>


bool isSimple(int a)
{
	if (a >= 0 && a <= 2)
		return true;

	if (a % 2 == 0)
		return false;

	for (size_t i=3; i <= round(sqrt(a)); i += 2)
	{
		if (a % i == 0)
			return false;
	}

	return true;
}

int main()
{
	std::cout << "Hello world" << std::endl;

	bool result;
	int a;

	a = 100;
	result = isSimple(a);
	std::cout << a << "->" << result << std::endl;

	a = 2;
	result = isSimple(a);
	std::cout << a << "->" << result << std::endl;

	a = 17;
	result = isSimple(a);
	std::cout << a << "->" << result << std::endl;

	return 0;
}