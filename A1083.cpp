//A1083
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
struct person
{
	std::string name;
	std::string ID;
	int grade;
};
bool cmp(person a, person b)
{
	person tmp;
	if (a.grade > b.grade)
	{
		tmp = a;
		a = b;
		b = tmp;
		return true;
	}
	else
		return false;
}
void input(std::vector<person>& list, int& up, int& low)
{
	int n;
	person tmp;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> tmp.name;
		std::cin >> tmp.ID;
		std::cin >> tmp.grade;
		list.push_back(tmp);
	}
	std::cin >> low;
	std::cin >> up;
}
std::vector<person> process(std::vector<person>& list, int& up, int& low)
{
	std::vector<person>::iterator iter = list.begin();
	while (iter != list.end())
	{
		if ((*iter).grade<low || (*iter).grade>up)
		{
			iter = list.erase(iter);
		}
		else
			iter++;
	}
	std::sort(list.begin(), list.end(), cmp);
	return list;
}
void output(std::vector<person> result)
{
	if (result.size() == 0)
		std::cout << "NONE";
	else
	{
		std::vector<person>::iterator iter = result.begin();
		while (iter != result.end())
		{
			std::cout << (*iter).name << " " << (*iter).ID << std::endl;
			iter++;
		}
	}

}
int main()
{
	int up, low;
	std::vector<person> list, result;
	input(list, up, low);
	result = process(list, up, low);
	output(result);
	system("pause");
	return 0;
}