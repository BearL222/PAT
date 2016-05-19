//A1025
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
struct person
{
	int location;
	long long ID;
	int score;
	int final_rank;
	int local_rank;
};
bool cmp(person a, person b)
{
	person tmp;
	if ((a.score > b.score) || a.score == b.score&&a.ID < b.ID)
	{
		tmp = a;
		a = b;
		b = tmp;
		return true;
	}
	else
		return false;
}
int input(std::vector<person>& list)
{
	int location_num, person_num;
	person tmp;
	std::cin >> location_num;
	for (int i = 0; i < location_num; i++)
	{
		std::cin >> person_num;
		for (int j = 0; j < person_num; j++)
		{
			tmp.location = i + 1;
			std::cin >> tmp.ID;
			std::cin >> tmp.score;
			list.push_back(tmp);
		}
	}
	return location_num;
}
std::vector<person> process(std::vector<person> list,int location_num)
{
	std::sort(list.begin(), list.end(), cmp);
	std::vector<person>::iterator iter = list.begin() + 1;
	std::vector<person> tmp;
	int rank = 1;
	int gap = 0;
	list.front().final_rank = 1;
	while (iter != list.end())
	{
		if ((*(iter - 1)).score == (*iter).score)
		{
			gap++;
		}
		else
		{
			rank += gap + 1;
			gap = 0;
		}
		(*iter).final_rank = rank;
		iter++;
	}
	int *local_rank= new int[location_num];
	memset(local_rank, 0, sizeof(int)*location_num);
	int *local_gap = new int[location_num];
	memset(local_gap, 0, sizeof(int)*location_num); 
	int *judge1 = new int[location_num];
	memset(judge1, 0, sizeof(int)*location_num); 
	iter = list.begin();
	while (iter != list.end())
	{
		if (judge1[(*iter).location - 1] == (*iter).final_rank)
		{
			(*iter).local_rank = local_rank[(*iter).location - 1];
			local_gap[(*iter).location - 1]++;
		}
		else
		{
			local_rank[(*iter).location - 1] += local_gap[(*iter).location - 1] + 1;
			local_gap[(*iter).location - 1] = 0;
			(*iter).local_rank = local_rank[(*iter).location - 1];
		}
		judge1[(*iter).location - 1] = (*iter).final_rank;
		iter++;
	}
	/*std::vector<person> result = list;
	std::vector<person>::iterator iter1;
	std::vector<person>::iterator iter2;
	for (int i = 0; i < location_num; i++)
	{
		iter = list.begin();
		while (iter != list.end())
		{
			if ((*iter).location == i + 1)
			{
				tmp.push_back(*iter);
				iter = list.erase(iter);
			}
			else
				iter++;
		}
		iter1 = tmp.begin() + 1;
		rank = 1;
		gap = 0;
		tmp.front().local_rank = 1;
		while (iter1 != tmp.end())
		{
			if (iter1 != tmp.begin() && (*(iter1 - 1)).score == (*iter1).score)
			{
				gap++;
			}
			else
			{
				rank += gap + 1;
				gap = 0;
			}
			(*iter1).local_rank = rank;
			iter1++;
		}
		iter1 = tmp.begin();
		while (iter1 != tmp.end())
		{
			iter2 = result.begin();
			while (iter2 != result.end())
			{
				if ((*iter2).ID == (*iter1).ID)
				{
					(*iter2).local_rank = (*iter1).local_rank;
					break;
				}
				iter2++;
			}
			iter1++;
		}
		tmp.clear();
	}*/
	return list;
}
void output(std::vector<person> result)
{
	std::vector<person>::iterator iter = result.begin();
	std::cout << result.size() << std::endl;
	while (iter != result.end())
	{
		std::cout << (*iter).ID << ' ' << (*iter).final_rank << ' ' << (*iter).location << ' ' << (*iter).local_rank << std::endl;
		iter++;
	}
}
int main()
{
	std::vector<person> list, result;
	int location_num = input(list);
	result = process(list,location_num);
	output(result);
	system("pause");
	return 0;
}