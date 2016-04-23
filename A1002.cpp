#include<iostream>
#include<sstream>
#include<string>
void func()
{
	int num;
	float sum = 0;
	int exponent;
	float coefficient;
	for (int j = 0; j < 2; ++j)
	{
		std::cin >> num;
		for (int i = 0; i < num; ++i)
		{
			std::cin >> exponent;
			std::cin >> coefficient;
			sum += pow(2, exponent)*coefficient;
		}
	}
	int max;
	for (int i = 0; i < 12; ++i)
	{
		if (pow(2, i) >= sum)
		{
			max = i;
		}
	}
	std::cout << max + 1;
}

int main()
{
	func();
	system("pause");
	return 0;
}