//PAT L1-2
#include<iostream>
#include<string>

void func()
{
	int num;
	char cstr;
	std::cin >> num;
	std::cin >> cstr;
	int n = 0;
	while (2 * pow(n,2) - 1 <= num)
	{
		++n;
	}
	--n;
	int remain = num - 2*pow(n,2)+1;
	std::string tmp;
	for (int i = n; i > 0; --i)
	{
		std::cout << tmp.append((2 * n - 1 - (2 * i - 1))/2, ' ');
		tmp = "";
		std::cout << tmp.append(2 * i - 1, cstr) << std::endl;
		tmp = "";
	}
	for (int i = 2; i <= n; ++i)
	{
		std::cout << tmp.append((2 * n - 1 - (2 * i - 1)) / 2, ' ');
		tmp = "";
		std::cout << tmp.append(2 * i - 1, cstr) << std::endl;
		tmp = "";
	}
	std::cout << remain;
}

int main()
{
	func();
	system("pause");
	return 0;
}