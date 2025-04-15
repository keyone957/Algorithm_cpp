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
vector<bool> visited;
int answer=0;
void DFS(vector<vector<int>> &arr, int node)
{
	if (visited[node] == 1)
	{
		return;
	}
	visited[node] = 1;
	
	for (int i = 0; i < arr[node].size(); i++)
	{
		int start = arr[node][i];
		// 인접리스트에 연결된 노드에 접근하여
		// 방문 여부를 돌기위해 start선언
		if (visited[start] != 1)
		{
			answer++;
			DFS(arr, start);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int computer,edge;

	cin >> computer;
	cin >> edge;
	linkedArr.resize(computer+1);
	visited.resize(computer + 1);
	for (int i = 1; i <= edge; i++)
	{
		int start, end;
		cin >> start >> end;
		linkedArr[start].push_back(end);
		linkedArr[end].push_back(start);
	}
	DFS(linkedArr, 1);
	// 어차피 1번에 연결된 컴퓨터의 갯수만 필요하므로 
	// 1번노드에 대한 dfs만 돌리면 된다
	cout << answer;
}