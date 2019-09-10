//Problem URL : https://programmers.co.kr/learn/courses/30/lessons/42891
//문제 : 무지의 먹방 라이브
//Time Complex Prediction : O(nlogn)
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
struct Food
{
	Food(int n, int ft) :num(n), food_time(ft) {}
	int num;
	int food_time;
};

bool comp_food_time(const Food& lf, const Food& rf)
{
	return lf.food_time < rf.food_time;
}

bool comp_num(const Food& lf, const Food& rf)
{
	return lf.num < rf.num;
}

int solution(vector<int> food_times, long long k)
{
	vector<Food> v;
	for (int i = 0; i < food_times.size(); i++)
	{
		v.push_back(Food(i, food_times.at(i)));
	}

	sort(v.begin(), v.end(), comp_food_time);

	long long time = k;
	int pos = -1;
	int sum = 0;

	for (int i = 0; i < v.size(); i++)
	{
		int food_time = v[i].food_time - sum;

		if (food_time <= 0)
			continue;

		time = time - (v.size() - i) * (food_time);
		sum += (food_time);

		if (time < 0)
		{
			pos = i;
			time = time + (v.size() - i) * food_time;
			break;
		}
	}

	if (pos == -1)
		return -1;

	sort(v.begin() + pos, v.end(), comp_num);
	time %= v.size() - pos;

	return pos + time >= v.size() ? v[pos].num + 1 : v[pos + time].num + 1;
}