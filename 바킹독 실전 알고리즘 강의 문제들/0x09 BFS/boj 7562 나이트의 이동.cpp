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
int board[302][302];
int dist[302][302];
int isVisit[302][302];
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int dx[8] = { -1,1,2,2,1,-1,-2,-2 };
	int dy[8] = { -2,-2,-1,1,2,2,1,-1 };
	int input;
	cin >> input;
	for (int i = 0; i < input; i++)
	{
		int chessSize;
		pair<int, int> startPoint;
		pair<int, int> endPoint;
		queue<pair<int, int>>Q;
		cin >> chessSize;
		cin >> startPoint.first >> startPoint.second;
		cin >> endPoint.first >> endPoint.second;
		for (int i = 0; i < 302; i++)
		{
			for (int j = 0; j < 302; j++)
			{
				board[i][j] = 0;
				isVisit[i][j] = 0;
				dist[i][j] = 0;
			}
		}
		while (!Q.empty())
		{
			Q.pop();
		}
		for (int i = 0; i < chessSize; i++)
		{
			for (int j = 0; j < chessSize; j++)
			{
				dist[i][j] = -1;
			}
		}
		dist[startPoint.first][startPoint.second] = 0;
		//맨처음 시작지점을 0으로 초기화 시켜줘야해. 난 이부분때문에 계속 헤맴..... 그래야 
		//시작지점의 dist가 -1에서 초기화 되지 않은 상태로 남아있어서 
		//나는 cout << dist[endPoint.first][endPoint.second]+1<< "\n";이렇게 했었는데
		// 저러면 언뜻 맞아보이나 도착지점과 시작지점이 같을때에도 bfs가 계속 실행이된다.
				
		Q.push(startPoint);
		while (!Q.empty())
		{
			pair<int, int> cur = Q.front();
			if (cur==endPoint)
			{
				cout << dist[endPoint.first][endPoint.second]<< "\n";// 도착지점에 도착하면 이제 break 하여 bfs끝내고 다음으로 넘어가
				break;// 도착했으니 break꼭 넣어라
			}
			Q.pop();
			for (int i = 0; i < 8; i++)
			{
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];
				if (nx < 0 || nx >= chessSize || ny < 0 || ny >= chessSize)continue;
				if (dist[nx][ny] != -1) continue;
				dist[nx][ny] = dist[cur.first][cur.second] + 1;
				Q.push({ nx, ny });
			}
		}

	}
}