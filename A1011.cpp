//PAT A1011
#include<iostream>
#include<algorithm>
#include<iomanip>

double pickMax(double(&A)[3])
{
	if (A[0] > A[1])
	{
		if (A[0] > A[2])
		{
			std::cout << 'W'<<' ';
			return A[0];
		}
		else
		{
			std::cout << 'L' << ' ';
			return A[2];
		}
	}
	else
	{
		if (A[1] > A[2])
		{
			std::cout << 'T' << ' ';
			return A[1];
		}
		else
		{
			std::cout << 'L' << ' ';
			return A[2];
		}
	}
}
void func()
{
	double WTL[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cin >> WTL[i][j];
		}
	}
	double profit = 1;
	for (int i = 0; i < 3; i++)
	{
		profit *= pickMax(WTL[i]);
	}
	std::cout.setf(std::ios::fixed);
	std::cout << std::fixed << std::setprecision(2) << (profit*0.65-1)*2;
}

int main()
{
	func();
	system("pause");
	return 0;
}