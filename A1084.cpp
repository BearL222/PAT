//PAT A1084
#include<iostream>
#include<string>
#include<algorithm>

void func()
{
	std::string str1, str2,str3;
	std::cin >> str1;
	std::cin >> str2;
	std::transform(str1.begin(), str1.end(), str1.begin(), toupper);
	std::transform(str2.begin(), str2.end(), str2.begin(), toupper);
	int i, j;
	for (i = 0,j = 0; i < str1.length(), j < str2.length();)
	{
		if (str1[i] != str2[j]&&str3.find(str1[i])==-1)
		{
			str3.append(str1.substr(i,1));
			++i;
		}
		else if(str1[i] != str2[j] && str3.find(str1[i]) != -1)
		{
			++i;
		}
		else
		{
			++i;
			++j;
		}
	}
	if (i < str1.length())
	{
		for (; i < str1.length(); ++i)
		{
			if (str3.find(str1[i]) == -1)
			{
				str3.append(str1.substr(i, 1));
			}
		}
	}
	std::cout << str3;
}

int main()
{
	func();
	system("pause");
	return 0;
}