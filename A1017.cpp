//PAT A1017
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>

void test()
{
	std::string str0;
	str0.append(2, '0');
	getchar();
}
void func()
{
	int numCustomers, numWindows;
	float waitTime = 0;
	std::cin >> numCustomers;
	std::cin >> numWindows;
	std::vector<float> arriveTime(numCustomers), processTime(numCustomers);
	float HH, MM, SS, lateCustomers = 0;
	std::string str;
	for (int i = 0; i < numCustomers; ++i)
	{
		std::cin >> str;
		HH = atoi(str.substr(0, 2).c_str());
		MM = atoi(str.substr(3, 2).c_str());
		SS = atoi(str.substr(6, 2).c_str());
		std::cin >> processTime[i];
		arriveTime[i] = HH * 60 + MM + SS / 60;
		if (arriveTime[i] > 1020)
		{
			processTime[i] = 0;
			++lateCustomers;
		}
		if (arriveTime[i] < 480) arriveTime[i] = 480;
	}
	//ÅÅÐò
	for (int i = 0; i < numCustomers; ++i)
	{
		for (int j = numCustomers - 1; j > i; --j)
		{
			if (arriveTime[j] < arriveTime[j - 1])
			{
				std::swap(arriveTime[j], arriveTime[j - 1]);
				std::swap(processTime[j], processTime[j - 1]);
			}
		}
	}

	std::string str2;
	str2.append(numCustomers, '0');
	int servedCustomers = 0;
	int findMin, pnos = 0;
	for (int i = 0; i < numCustomers - lateCustomers; ++i)
	{
		for (int k = 0; k < servedCustomers; ++k)
		{
			if (arriveTime[str2.find("1", pnos)] + processTime[str2.find("1", pnos)] <= arriveTime[i])
			{
				--servedCustomers;
				str2[str.find("1", pnos)] = 0;
				++pnos;
			}
		}
		pnos = 0;
		if (servedCustomers == numWindows)
		{
			findMin = str2.find("1");
			for (int j = 0; j < numCustomers&&str2.find("1", j) != -1; ++j)
			{
				if (arriveTime[findMin] + processTime[findMin] > arriveTime[str2.find("1", j)] + processTime[str2.find("1", j)])
				{
					findMin = str2.find("1", j);
				}
			}
			waitTime += (arriveTime[findMin] + processTime[findMin]) - arriveTime[i];
			arriveTime[i] = arriveTime[findMin] + processTime[findMin];
			str2[i] = '1';
			str2[findMin] = '0';
		}
		else
		{
			++servedCustomers;
			str2[i] = '1';
		}
	}
	std::cout.setf(std::ios::fixed);
	std::cout <<std::fixed<<std::setprecision(1)<< waitTime / (numCustomers - lateCustomers);
	getchar();
}

int main()
{
	func();
	system("pause");
	return 0;
}