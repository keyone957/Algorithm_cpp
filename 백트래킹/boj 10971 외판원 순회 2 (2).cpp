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
int n;
int w[11][11];
bool visit[11];
int answer = 1e9;
/*
w[i][j]
 => i에서 j가는 비용
 0이면 못감.
 i i는 항상 0
 
 */
void func(int count,int curDist,int curCity)//재귀 깊이, 갱신 거리, 현재 방문중인 도시
{
    if (curDist >= answer)//더 비용이 높으면 그 경로는 탐색 필요 없음
    {
        return;
    }
    if (count == n&&w[curCity][0]!=0)//다시 원 점으로 돌아오는 경로가 있을 때
    {
        answer = min(answer, curDist+w[curCity][0]);
        //이제 다시 원래 위치로 돌아오는 경우도 더해야함. 
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visit[i]&&w[curCity][i]!=0)//현재 도시 방문 안했다면? && 경로가 있는 도시이면?
        {
            visit[i] = true;
            func(count + 1, curDist + w[curCity][i], i);//재귀 깊이 +1 , 거리 갱신, 다음 도시로 변경
            visit[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> w[i][j];
        }
    }
    visit[0] = true;
    func(1, 0, 0);
    cout << answer;
}