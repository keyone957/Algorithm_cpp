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
#include <unordered_set>
#include<unordered_map>
#include<math.h>
#include<cstring>
using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int t;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;

    while (t--)
    {
        int board[51][51] = {0,};
        bool isVisited[51][51] = {false,};
        int m, n, k;
        int bugCnt = 0;
        cin >> m >> n >> k;

        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            board[y][x] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 1 && !isVisited[i][j])
                {
                    queue<pair<int, int>> q;
                    q.push({ i,j });
                    isVisited[i][j] = true;
                    while (!q.empty())
                    {
                        pair<int, int> cur = q.front();
                        q.pop();
                        for (int dir = 0; dir < 4; dir++)
                        {
                            int nextY = cur.first + dy[dir];
                            int nextX = cur.second + dx[dir];
                            if (nextX < 0 || nextY < 0 || nextX >= m || nextY >= n) continue;
                            if (isVisited[nextY][nextX]) continue;
                            if (board[nextY][nextX] != 1) continue;
                            isVisited[nextY][nextX] = true;
                            q.push({ nextY,nextX });
                        }
                    }
                    bugCnt++;
                }
            }
        }
        cout << bugCnt << '\n';
    }

}