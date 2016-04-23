#include<iostream>
#include<sstream>
#include<string>
void func()
{
	std::string integer, result;
	std::stringstream ss;
	int sum = 0, tmp;
	std::cin >> integer;
	for (int i = 0; i < integer.length(); ++i)
	{
		sum += integer[i]-48;
	}
	ss << sum;
	ss >> result;
	for (int i = 0; i < result.length(); ++i)
	{
		switch (result[i])
		{
		case '0':
			std::cout << "zero";
			break;
		case '1':
			std::cout << "one";
			break;
		case '2':
			std::cout << "two";
			break;
		case '3':
			std::cout << "three";
			break;
		case '4':
			std::cout << "four";
			break;
		case '5':
			std::cout << "five";
			break;
		case '6':
			std::cout << "six";
			break;
		case '7':
			std::cout << "seven";
			break;
		case '8':
			std::cout << "eight";
			break;
		case '9':
			std::cout << "nine";
			break;
		}
		if (i != result.length()-1) std::cout << " ";
	}
}

int main()
{
	func();
	system("pause");
	return 0;
}