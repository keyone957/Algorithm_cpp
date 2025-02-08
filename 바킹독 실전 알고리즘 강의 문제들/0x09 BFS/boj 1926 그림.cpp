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
int board[502][502];
bool vis[502][502];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	int picCount = 0, picMaxSize = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 1 && vis[i][j] == 0)// ������ ã��
			{
				int curPicSize = 0;
				picCount++;// ==> �������� ã�Ҵٴ� �̾߱� . ���� �׸� ���� ++
				queue<pair<int, int>> Q;
				vis[i][j] = 1;
				Q.push({ i,j });
				while (!Q.empty())
				{
					pair<int, int> cur = Q.front(); Q.pop();
					curPicSize++;//pop�Ҷ� ���� �׸��� ũ�� ++
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (vis[nx][ny] == 1 || board[nx][ny] != 1) continue;
						vis[nx][ny] = 1;
						Q.push({ nx,ny });
					}
				}
				if (curPicSize > picMaxSize)
					picMaxSize = curPicSize;
			}
		}
	}
	cout << picCount << "\n" << picMaxSize;

}