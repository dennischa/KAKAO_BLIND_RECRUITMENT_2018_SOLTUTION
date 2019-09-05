//Problem URL : https://programmers.co.kr/learn/courses/30/lessons/42888
//문제 : 오픈채팅방
//Time Complex Prediction : O(n)

#include <string>
#include <vector>
#include <map>
#include <string.h>
#include <utility>

using namespace std;

vector<string> solution(vector<string> record)
{
	vector<pair<char, string>> logs;
	vector<string> answer;
	map<string, string> name_map;

	for (int i = 0; i < record.size(); i++)
	{
		char str[record.at(i).size()];
		strcpy(str, record.at(i).c_str());
		char* command = strtok(str, " ");
		char* id = strtok(NULL, " ");

		switch (command[0])
		{
		case 'E': //Enter
		{
			logs.push_back(make_pair(command[0], id));
			char* name = strtok(NULL, "");
			name_map[id] = string(name);
			break;
		}
		case 'L': //Leave
		{
			logs.push_back(make_pair(command[0], id));
			break;
		}
		case 'C': //Change
		{
			char* name = strtok(NULL, "");
			name_map[id] = string(name);
			break;
		}
		}
	}

	for (int i = 0; i < logs.size(); i++)
	{
		pair<char, string>& log = logs.at(i);
		switch (log.first)
		{
		case 'E':
			answer.push_back(string(name_map[log.second] + "님이 들어왔습니다."));
			break;
		case 'L':
			answer.push_back(string(name_map[log.second] + "님이 나갔습니다."));
			break;
		}
	}

	return answer;
}