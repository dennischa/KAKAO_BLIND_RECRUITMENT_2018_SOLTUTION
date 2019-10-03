//Problem URL : https://programmers.co.kr/learn/courses/30/lessons/42892
//문제 : 길 찾기 게임
//Time Complex Prediction : O(nlogn)
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;
struct Node
{
	Node(int v, int l, int n) :value(v), level(l), num(n) {}
	int level;
	int value;
	int num;
	Node* left = nullptr;
	Node* right = nullptr;

	void add_child(Node* n)
	{
		if (n->value < value)
		{
			if (left == nullptr)
				left = n;
			else
				left->add_child(n);
		}
		else
		{
			if (right == nullptr)
				right = n;
			else
				right->add_child(n);
		}
	}

	void pre_order(vector<int>& v)
	{
		v.push_back(num);
		if (left != nullptr)
			left->pre_order(v);
		if (right != nullptr)
			right->pre_order(v);
	}

	void post_order(vector<int>& v)
	{
		if (left != nullptr)
			left->post_order(v);
		if (right != nullptr)
			right->post_order(v);
		v.push_back(num);
	}
};

bool comp(Node ln, Node rn)
{
	return ln.level > rn.level;
}

vector<vector<int>>  solution(vector<vector<int>> nodeinfo)
{
	vector<vector<int>> answer(2);
	vector<Node> v;

	for (int i = 0; i < nodeinfo.size(); i++)
	{
		int& x = nodeinfo[i][0];
		int& y = nodeinfo[i][1];

		v.emplace_back(x, y, i + 1);
	}

	sort(v.begin(), v.end(), comp);

	Node* root = &v[0];

	for (int i = 1; i < v.size(); i++)
	{
		root->add_child(&v[i]);
	}

	root->pre_order(answer[0]);
	root->post_order(answer[1]);

	return answer;
}