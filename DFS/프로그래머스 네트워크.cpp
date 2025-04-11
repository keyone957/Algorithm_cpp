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
vector<int> visit;
void DFS(vector<vector<int>>arr,int node)
{
	if (visit[node] == 1) return;
	visit[node] = 1;
	for (int i = 0; i < arr[node].size(); i++)
	{
		if (arr[node][i]==1 && visit[i] != 1)
		{
			DFS(arr, i);
		}
	}

}
int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	visit.resize(n,0);
	for (int i = 0; i < n; i++)
	{
		if (visit[i] != 1)
		{
			DFS(computers,i);
			answer++;
		}
	}
	
	return answer;
}
int main()
{
	int n = 3;
	vector<vector<int>> input = { {1,1,0},{1,1,0},{0,0,1} };
	cout << solution(n, input);
}