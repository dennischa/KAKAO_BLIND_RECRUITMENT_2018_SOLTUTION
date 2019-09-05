//Problem URL : https://programmers.co.kr/learn/courses/30/lessons/42890
//문제 : 후보키
//Time Complex Prediction : O(2^n)
#include <string>
#include <vector>
#include <bitset>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> relation)
{
	const int column_num = relation.front().size();
	const int tuple_num = relation.size();
	const int total = 1 << column_num;
	vector<bitset<8>> keys;

	for (int i = 0; i < total; i++)
	{
		bool is_minimal = true;
		bitset<8> set = i;

		for (int i = 0; i < keys.size(); i++)
		{
			if ((keys[i] & set) == keys[i])
			{
				is_minimal = false;
				break;
			}
		}

		if (!is_minimal)
			continue;

		unordered_map<string, bool> tuples;
		for (int i = 0; i < tuple_num; i++)
		{
			string tmp = "";
			for (int j = 0; j < column_num; j++)
			{
				if (set[j])
					tmp += relation[i][j];
			}
			tuples[tmp] = true;
		}

		if (tuples.size() == tuple_num)
		{
			keys.push_back(set);
		}
	}

	return keys.size();
}