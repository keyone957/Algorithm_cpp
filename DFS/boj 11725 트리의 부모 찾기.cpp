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
	//arr[node] --> node�� ����� �̿����� ����Ʈ 
	for (int i = 0; i < arr[node].size(); i++)
	{
		//i��° ���� arr[node][i]�� ������ next�� ����
		int next = arr[node][i];
		//�� next�� ���� node���� ����� ���� ��� ��ȣ
		if (visit[next] != 1)
		{
			answer[next] = node;//next�� �θ�� node
			DFS(next);//next�� ������� �ٽ� dfs next�� ���� �� �ڽĵ��� Ž��
			//�� next�� �� ������ Ž���� ��尡 �Ǵ°�.
			//��� �ڽ����� ��
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
	DFS(1);//��Ʈ ���� 1�̶�� ���Ͽ���
	for (int i = 2; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}
}