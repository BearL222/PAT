#include <iostream>
#include<string>

std::string func1(std::string s)
{
	int numP = 0, numT = 0,numA=0;
	int posP, posT;
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] != 'P' && s[i] != 'A' && s[i] != 'T') return "NO";
		else if (s[i] == 'P') 
		{
			++numP;
			posP = i;
		}
		else if (s[i] == 'T')
		{
			++numT;
			posT = i;
		}
		else if (s[i] == 'A') ++numA;
	}
	if (numP != 1 || numT != 1 || numA == 0 || posT - posP > 3) return "NO";
	if (s.length() - posT - 1 == posP&&posT-posP==2) return "YES";
	else
	{
		if (posP*2 == s.length() - posT-1&&posT-posP==3) return "YES";
	}
	return "NO";
}
void func()
{
	int num;
	std::cin >> num;
	std::string *Array = new std::string[num];
	for (int i = 0; i < num; ++i)
	{
		std::cin >> Array[i];
	}
	std::string string1;
	for (int i = 0; i < num; ++i)
	{
		std::cout << func1(Array[i]) << std::endl;
	}
}

int main()
{
	func();
	system("pause");
	return 0;
}