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
/*
주사위 1~6 
100칸

input 
 사다리 수, 뱀의수
output

*/
int n, m;
int board[101] = {0};
int visit[101];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        board[start] = end;
    }
    for (int i = 0; i < m; i++)
    {
        int start, end;
        cin >> start >> end;
        board[start] = end;
    }
    fill(visit, visit + 101, -1);
    queue<int> q;
    q.push(1);
    visit[1] = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        int endPoint = board[cur];
        for (int i = 1; i <= 6; i++)
        {
            int nextPoint = cur + i;//다이스 굴려서 이제 다음에 갈 칸
            if (nextPoint > 100) continue;//100번 이상이면 pass
            if (board[nextPoint] != 0)
            //뱀 or 사다리이면 board[nextpoint] 즉 목적지를 먼저 확인해야함. 
            // 만약에 0이 아니면 다음 칸으로 가는게 아니라 뱀 or 사다리 이후에 칸으로 이동후에 그 위치에서 +1 및 방문 처리를 해야함.
            {
                nextPoint = board[nextPoint];//nextpoint를 이제 뱀 or 사다리 이후 칸으로 이동시킴
            }
            if (visit[nextPoint] != -1) continue;//그리고 방문 했는지 확인
            visit[nextPoint] = visit[cur] + 1;//그리고 뱀or 사다리 이동 또는 그 다음칸(+1~+6)에서 방문 횟수를 ++
            q.push(nextPoint);
        }
    }
    cout << visit[100];
}