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
vector<vector<int>> arr;
vector<int> visit;
vector<int> answer;
void DFS(int node)
{
	if (visit[node]==1)
	{
		return;
	}
	visit[node] = 1;
	//arr[node] --> node와 연결된 이웃들의 리스트 
	for (int i = 0; i < arr[node].size(); i++)
	{
		//i번째 원소 arr[node][i]를 꺼내서 next에 저장
		int next = arr[node][i];
		//이 next는 지금 node에서 열결된 실제 노드 번호
		if (visit[next] != 1)
		{
			answer[next] = node;//next의 부모는 node
			DFS(next);//next를 대상으로 다시 dfs next로 들어가서 그 자식들을 탐색
			//즉 next는 그 다음에 탐색할 노드가 되는것.
			//계속 자식으로 들어감
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
	arr.resize(count + 1);
	visit.resize(count + 1);
	answer.resize(count + 1);
	for (int i = 1; i < count; i++)
	{
		int start, end;
		cin >> start >> end;
		arr[start].push_back(end);
		arr[end].push_back(start);
	}
	DFS(1);//루트 노드는 1이라고 말하였음
	for (int i = 2; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}
}