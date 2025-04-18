#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
vector<vector<int>> linkedArr;
vector<int> visited;
int person;
void dfs(int node)
{
	if (visited[node]!=0)
	{
		cout << visited[node];
		return;
	}

	visited[node]++;

	for (int i = 0; i < linkedArr[node].size(); i++)
	{
		int start = linkedArr[node][i];
		if (visited[start]==0)
		{
			dfs(i);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int count;
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		int nodeCount;
		cin >> nodeCount;
		linkedArr.resize(nodeCount + 1);
		visited.resize(nodeCount + 1);
		person = 0;
		for (int i = 1; i < nodeCount + 1; i++)
		{
			int end;
			cin >> end;
			linkedArr[i].push_back(end);
		}
		for (int a = 1; a < nodeCount + 1; a++)
		{

			if (visited[a]==0)
			{
				dfs(a);
			}
		}
		//cout << person;
	}
}