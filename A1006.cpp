//PAT A1006
#include<iostream>
#include<string>

void func()
{
	int num;
	std::cin >> num;
	std::string FirstIn, LastOut;
	float timeIn = 1440, timeOut = 0;
	std::string tmp, time;
	float tmpIn, tmpOut;
	int HH, MM, SS;
	for (int i = 0; i < num; ++i)
	{
		std::cin >> tmp;
		std::cin >> time;
		HH = atoi(time.substr(0, 2).c_str());
		MM = atoi(time.substr(3, 2).c_str());
		SS = atoi(time.substr(6, 2).c_str());
		tmpIn = HH * 60 + MM + SS / 60;
		if (tmpIn < timeIn)
		{
			timeIn = tmpIn;
			FirstIn = tmp;
		}
		std::cin >> time;
		HH = atoi(time.substr(0, 2).c_str());
		MM = atoi(time.substr(3, 2).c_str());
		SS = atoi(time.substr(6, 2).c_str());
		tmpOut = HH * 60 + MM + SS / 60;
		if (tmpOut > timeOut)
		{
			timeOut = tmpOut;
			LastOut = tmp;
		}
	}
	std::cout << FirstIn << " " << LastOut;
}

int main()
{
	func();
	system("pause");
	return 0;
}