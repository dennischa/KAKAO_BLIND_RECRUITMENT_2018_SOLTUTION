//Problem URL : https://programmers.co.kr/learn/courses/30/lessons/42889
//문제 : 실패율
//Time Complex Prediction : O(n^2)
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Stage
{
	Stage(int n) :num(n), stopped(0), arrivaled(0) {}
	int num;
	int stopped;
	int arrivaled;

	float get_failure_ratio() const
	{
		if (arrivaled == 0)
			return 0;
		return (float)stopped / (float)arrivaled;
	}

	bool operator<(const Stage& comp)
	{
		const float f1 = this->get_failure_ratio();
		const float f2 = comp.get_failure_ratio();

		if (f1 == f2)
			return this->num < comp.num;
		else
			return f1 > f2;
	}
};

vector<int> solution(int N, vector<int> stages)
{
	vector<Stage> stage_infos;
	for (int i = 0; i < N; i++)
	{
		stage_infos.push_back(Stage(i));
	}

	for (int i = 0; i < stages.size(); i++)
	{
		int stopped = stages.at(i) - 1;
		stage_infos[stopped].stopped++;

		for (int j = 0; j <= stopped; j++)
			stage_infos[j].arrivaled++;
	}

	sort(stage_infos.begin(), stage_infos.end());

	vector<int> answer;

	for (int i = 0; i < N; i++)
	{
		answer.push_back(stage_infos.at(i).num + 1);
	}

	return answer;
}