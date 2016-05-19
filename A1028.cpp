//A1028
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<cstdio>  
#include<cstring>  
#include<vector>  
#include<queue>  
#include<map>  
#include<bitset>  
struct student
{
	char ID_string[10];
	int ID;
	char name[10];
	int	grade;
};
std::vector<student> list;
int N,c;
bool cmp1(student a, student b)
{
	return strcmp(a.ID_string, b.ID_string) < 0;
}
bool cmp2(student a, student b)
{
	return strcmp(a.name, b.name) == 0 ? strcmp(a.ID_string, b.ID_string) < 0 : strcmp(a.name, b.name) < 0;
}
bool cmp3(student a, student b)
{
	return a.grade == b.grade ? strcmp(a.ID_string, b.ID_string) < 0 : a.grade < b.grade;
}
void input()
{
	student tmp;
	scanf("%d%d", &N, &c);
	for (int i = 0; i < N; i++)
	{
		scanf("%s%s%d", &tmp.ID_string, &tmp.name, &tmp.grade);
		tmp.ID = std::atoi(tmp.ID_string);
		list.push_back(tmp);
	}
}
void output()
{
	std::vector<student>::iterator iter = list.begin();
	while (iter != list.end())
	{
		printf("%s %s %d\n", (*iter).ID_string, (*iter).name, (*iter).grade);
		iter++;
	}
}
int main()
{
	input();
	if (c==1)
		std::sort(list.begin(), list.end(), cmp1);
	else if (c==2)
		std::sort(list.begin(), list.end(), cmp2);
	else
		std::sort(list.begin(), list.end(), cmp3);
	output();
	system("pause");
	return 0;
}