//Problem URL : https://programmers.co.kr/learn/courses/30/lessons/42894
//문제 : 블록 게임
#include <string>
#include <vector>
#include <map>

using namespace std;
const int black = 201;

struct Rectangle
{
	Rectangle() {}
	Rectangle(int i, int x, int y) :index(i), min_x(51), min_y(51), max_x(0), max_y(0), removed(false)
	{
		add_block(x, y);
	}
	int index;
	int min_x, min_y, max_x, max_y;
	bool removed;

	void add_block(int x, int y)
	{
		min_x = min(min_x, x);
		min_y = min(min_y, y);
		max_x = max(max_x, x);
		max_y = max(max_y, y);
	}
};

void drop(vector<vector<int>>& board, map<unsigned int, Rectangle>& mr)
{
	const int n = board.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[j][i] == black)
				continue;
			if (board[j][i] > 0 && mr[board[j][i]].removed == false)
				break;
			board[j][i] = black;
		}
	}
}

int check(vector<vector<int>>& board, map<unsigned int, Rectangle>& mr)
{
	const int n = board.size();
	int removed = 0;
	map<unsigned int, Rectangle>::iterator it = mr.begin();

	for (; it != mr.end(); it++)
	{
		Rectangle& r = it->second;
		if (r.removed == true)
			continue;

		bool isrec = true;
		for (int i = r.min_x; i <= r.max_x; i++)
		{
			for (int j = r.min_y; j <= r.max_y; j++)
			{
				if (board[i][j] != black && board[i][j] != r.index)
				{
					isrec = false;
					break;
				}
			}
			if (!isrec)
				break;
		}

		if (isrec)
		{
			r.removed = true;
			removed++;
		}
	}
	return removed;
}

int solution(vector<vector<int>> board)
{
	const int n = board.size();
	map<unsigned int, Rectangle> mr;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] > 0)
			{
				int& num = board[i][j];
				if (mr.find(num) == mr.end())
				{
					mr[num] = Rectangle(num, i, j);
				}
				else
				{
					mr[num].add_block(i, j);
				}
			}
		}
	}

	int answer = 0;
	int removed = 0;

	do
	{
		drop(board, mr);
		removed = check(board, mr);
		answer += removed;
	} while (removed > 0);

	return answer;
}