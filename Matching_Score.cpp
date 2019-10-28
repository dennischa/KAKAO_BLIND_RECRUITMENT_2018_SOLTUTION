#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm> 

using namespace std;

map<string, vector<string>> refs;
static int s_index = 0;

struct Wpage
{
	Wpage(string url) :address(url), basic_score(0), link_count(0), match_score(0)
	{
		index = s_index++;
	}
	string address;
	int index;
	int basic_score;
	int link_count;
	double match_score;

	void set_basic_score(string str, string word)
	{
		transform(str.begin(), str.end(), str.begin(), ::tolower);
		transform(word.begin(), word.end(), word.begin(), ::tolower);
		basic_score = 0;
		const string sb = "<body>";
		const string eb = "</body>";

		int pos = str.find(sb) + sb.size();
		int epos = str.find(eb, pos);

		while (pos < epos)
		{
			pos = str.find(word, pos);
			if (pos == string::npos)
				break;

			if (!isalpha(str[pos - 1]) && !isalpha(str[pos + word.size()]))
				basic_score++;

			pos += word.size();
		}
	}

	void set_out_links(string str)
	{
		const string sb = "<body>";
		const string eb = "</body>";
		int pos = str.find(sb) + sb.size();
		int epos = str.find(eb, pos);

		while (pos < epos)
		{
			pos = str.find("<a", pos);
			if (pos == string::npos)
				break;
			link_count++; //외부 링크 개수 
			pos = str.find("\"", pos) + 1;
			int el = str.find("\"", pos);
			string link = str.substr(pos, el - pos);

			if (refs.find(link) == refs.end()) //링크된 외부 링크 목록 관리 
				refs[link] = vector<string>(1, address);
			else
				refs[link].push_back(address);
		}
	}
};

string get_address(string str)
{
	int pos, epos = 0;

	while (true)
	{
		pos = str.find("<meta", epos);
		epos = str.find(">", pos);

		if (pos == string::npos)
			return "";

		pos += 5; //<meta size

		char meta[epos - pos + 1];
		strcpy(meta, str.substr(pos, epos - pos).c_str());
		char* ptr = strtok(meta, " =\"");
		if (strcmp(ptr, "property") != 0)
			continue;

		ptr = strtok(NULL, " =\"");
		if (strcmp(ptr, "og:url") != 0)
			continue;

		ptr = strtok(NULL, " =\"");
		if (strcmp(ptr, "content") != 0)
			continue;

		ptr = strtok(NULL, " =\"");
		return string(ptr);
	}
}

bool comp(const Wpage* lw, const Wpage* rw)
{
	if (lw->match_score == rw->match_score)
		return lw->index < rw->index;
	else
		return lw->match_score > rw->match_score;
}

int solution(string word, vector<string> pages) {

	map<string, Wpage*> m;

	for (int i = 0; i < pages.size(); i++)
	{
		const string page = pages.at(i);
		string address = get_address(page);
		Wpage* wpage = new Wpage(address);
		wpage->set_basic_score(page, word);
		wpage->set_out_links(page);

		m[address] = wpage;
	}

	vector<Wpage*> vw;
	map<string, Wpage*>::iterator it = m.begin();
	//매치 점수 계산
	for (; it != m.end(); it++)
	{
		Wpage* wptr = it->second;
		double match_score = wptr->basic_score;
		const int& link_count = wptr->link_count;

		if (refs.find(wptr->address) != refs.end())
		{
			vector<string>& ref = refs[wptr->address];
			for (int i = 0; i < ref.size(); i++)
			{
				string& link = ref[i];
				if (m.find(link) != m.end())
				{
					match_score += (double)m[link]->basic_score / (double)m[link]->link_count;
				}
			}
		}
		wptr->match_score = match_score;
		vw.push_back(wptr);
	}

	sort(vw.begin(), vw.end(), comp);
	int answer = vw.front()->index;

	for (int i = 0; i < vw.size(); i++)
	{
		delete vw[i]; //메모리 해제
	}

	return answer;
}