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
vector<bool> done;//시작 노드가 dfs가 다 끝났는지 안끝났는지에 대한 벡터
//false면 아직 탐색중
int person;
int timestamp = 1;
void dfs(int node)
{
	//int timestamp = 1;
	if (visited[node] != 0)
	{
		return;
	}

	//visited[node] = 1;

	visited[node] = timestamp++;
	int start = linkedArr[node][0];
	if (visited[start] == 0/*이미 방문한 노드*/)
	{
		dfs(start);
	}
	else if (!done[start])
	{
		// 방문은 했지만 아직 완전히 처리되지 않았다면
		// → 현재 경로 상에 next가 남아 있다는 뜻, 사이클 진입 지점
		// 사이클 크기 = (현재까지 찍힌 timestamp - 1) - visited[next] + 1
		person += (timestamp - 1) - visited[start] + 1;
	}

	done[node] = true;
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
		timestamp = 1;
		/*linkedArr.resize(nodeCount + 1, {});
		visited.resize(nodeCount + 1,0);
		done.resize(nodeCount + 1,false);*/
		linkedArr.assign(nodeCount + 1, vector<int>());
		visited.assign(nodeCount + 1, 0);
		done.assign(nodeCount + 1, false);
		person = 0;
		for (int i = 1; i < nodeCount + 1; i++)
		{
			int end;
			cin >> end;
			linkedArr[i].push_back(end);
		}
		for (int a = 1; a < nodeCount + 1; a++)
		{

			if (visited[a] == 0)
			{
				dfs(a);
			}
		}
		cout << nodeCount-person<<"\n";
		//person = 0;

		//cout << person;
	}
}