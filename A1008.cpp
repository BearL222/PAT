#include <iostream>

void func()
{
	int total,DesFloor,TmpFloor=0,sum=0;
	std::cin >> total;
	for (int i = 0; i < total; ++i)
	{
		std::cin >> DesFloor;
		if (DesFloor > TmpFloor)
		{
			sum += (DesFloor - TmpFloor) * 6 + 5;
			TmpFloor = DesFloor;
		}
		else if (DesFloor < TmpFloor)
		{
			sum += (TmpFloor - DesFloor) * 4 + 5;
			TmpFloor = DesFloor;
		}
		else if (DesFloor == TmpFloor)
		{
			sum += 5;
			TmpFloor = DesFloor;
		}
	}
	std::cout << sum;
}

int main()
{
	func();
	system("pause");
	return 0;
}