//A1035
#include<iostream>
#include<string>
#include<vector>
int N;
int M = 0;
std::string *id, *pw;
std::vector<int> modified;
void input()
{
	std::cin >> N;
	id = new std::string[N];
	pw = new std::string[N];
	for (int i = 0; i < N; i++) std::cin >> id[i] >> pw[i];
}
void correct()
{
	int flag;
	for (int i = 0; i < N; i++)
	{
		flag = 0;
		for (int j = 0; j < pw[i].size(); j++)
		{
			if (pw[i][j] == '1') { pw[i][j] = '@'; flag = 1; }
			else if (pw[i][j] == '0'){ pw[i][j] = '%'; flag = 1; }
			else if (pw[i][j] == 'l'){ pw[i][j] = 'L'; flag = 1; }
			else if (pw[i][j] == 'O'){ pw[i][j] = 'o'; flag = 1; }
		}
		if (flag != 0)
		{
			modified.push_back(i);
		}
	}
	M = modified.size();
}
void output()
{
	if (M == 0) N == 1 ? std::cout << "There is 1 account and no account is modified" : std::cout << "There are " << N << " accounts and no account is modified";
	else
	{
		std::cout << M << std::endl;
		std::vector<int>::iterator iter = modified.begin();
		while (iter != modified.end())
		{
			std::cout << id[*iter] << ' ' << pw[*iter] << std::endl;
			iter++;
		}	
	}
}
int main()
{
	input();
	correct();
	output();
	system("pause");
	return 0;
}