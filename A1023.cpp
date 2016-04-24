//A1023
#include<iostream>
#include<string>
std::string get(std::string a)
{
	std::string s="0000000000";
	for (int i = 0; i < a.length(); i++)
	{
		s[a[i]-48]++;
	}
	return s;
}
void fun(std::string a)
{
	std::string b, tmp = "0";
	for (int i = 0; i < a.length(); i++)
	{
		b.append(tmp);
	}
	int x;
	for (int i = a.length()-1; i >=1; i--)
	{
		x = 2 * (a[i] - 48) + b[i] - 48;
		b[i] = x % 10+48;
		b[i - 1] = x / 10 + 48;
	}
	std::string y;
	x = 2 * (a[0] - 48) + b[0] - 48;
	if (x >= 10)
	{
		b[0] = x%10 + 48;
		y = x / 10 + 48;
		b.insert(0, y);
		std::cout << "No";
	}
	else
	{
		b[0] = x+48;
		if (get(b) != get(a)) std::cout << "No";
		else std::cout << "Yes";
	}
	std::cout << std::endl<<b;
}
int main()
{
	std::string s;
	std::cin >> s;
	fun(s);
	system("pause");
	return 0;
}