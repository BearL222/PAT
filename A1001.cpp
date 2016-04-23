#include<iostream>
#include<sstream>
#include<string>
void func()
{
	int a, b,result;
	std::cin >> a;
	std::cin >> b;
	result = a + b;
	std::stringstream ss;
	ss << result;
	std::string str;
	ss >> str;
	int j = 0;
	if (str[0] == '-')
	{
		std::cout << '-';
		if (str.length() == 8)
		{
			std::cout << str[1] << ',' << str.substr(2, 3) << ',' << str.substr(5, 3);
		}
		else if (str.length() > 4)
		{
			j = str.length() - 4;
			for (int k = 1; k < j+1; ++k)
			{
				std::cout << str[k];
			}
			std::cout << ','<<str[j+1]<<str[j+2]<<str[j+3];
		}
		else
		{
			j = str.length()-1;
			for (int k = 1; k < j+1; ++k)
			{
				std::cout << str[k];
			}
		}
	}
	else
	{
		if (str.length() == 7)
		{
			std::cout << str[0] << ',' << str.substr(1, 3) << ',' << str.substr(4, 3);
		}
		else if (str.length() >= 4)
		{
			j = str.length() - 3;
			for (int k = 0; k < j; ++k)
			{
				std::cout << str[k];
			}
			std::cout << ',' << str[j]<< str[j + 1] << str[j + 2];
		}
		else
		{
			j = str.length();
			for (int k = 0; k < j; ++k)
			{
				std::cout << str[k];
			}
		}
	}
}

int main()
{
	func();
	system("pause");
	return 0;
}