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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	int dist[102][102];
	//�Ÿ� ������ �־��� dist �迭
	// �����¿��� ĭ�� ���� ���� �� �־�����
	//�迭�� �̸� -1�� �س��� vis�迭 ���� ���� �ʾƵ� �湮 ���θ� �� �� �ִ�
	string s[102];
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			dist[i][j] = -1;
		}
	}
	queue<pair<int, int>> Q;
	dist[0][0] = 0;
	Q.push({ 0,0 });
	while (!Q.empty())
	{
		pair<int, int> cur = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
			if (dist[nx][ny] != -1 || s[nx][ny] != '1')continue;
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			Q.push({ nx,ny });
		}
	}
	cout << dist[n - 1][m - 1] + 1;



}