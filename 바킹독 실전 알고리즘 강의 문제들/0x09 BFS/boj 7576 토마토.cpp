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
int board[1002][1002];
int dist[1002][1002];
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	cin >> n >> m;
	queue<pair<int, int>>	Q;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
			{
				Q.push({ i,j });//������
			}
			if (board[i][j] == 0)
			{
				dist[i][j] = -1;
			}
		}
	}

	while (!Q.empty())
	{
		pair<int, int> cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if (dist[nx][ny] == -1)
				//==> �丶�� �������κ� �϶� -1�� �ʱ�ȭ �آZ�� ������ ���� �̰� �湮 ���ߴٰ� ġ�ϱ� �Ÿ� +1 ��Ű��
			{
				dist[nx][ny] = dist[cur.first][cur.second] + 1;
				Q.push({ nx,ny });
			}
			
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dist[i][j] == -1)
			{
				cout << -1;
				return 0;
			}
		}
	}
	//for (int i = 0; i < m; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		cout << dist[i][j] << ' ';
	//	}
	//	cout << endl;
	//}
	int max_dist = 0;
	for (int i = 0; i < m; i++) {
		max_dist = max(max_dist, *max_element(dist[i], dist[i] + n));
	}
	cout << max_dist;
}