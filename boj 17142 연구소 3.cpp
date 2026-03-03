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
struct V
{
    int x, y;
};
int n,m;
int board[51][51];
int visit[51][51];
int dx[4] = { 0,0,-1,1 };
int  dy[4] = { 1,-1,0,0 };
vector<V> virusArr;

int answer = 1e9;
/*
0 빈칸
1 벽
2 바이러스
m개의 바이러스를 활성화 한다 침
이때 모든 빈 칸에 바이러스를 퍼뜨리는 최소 시간 구하기.
백트래킹으로 모든 활성화할 바이러스 조합 구한다음에 
만약 활성화할 바이러스가 도달하면 그때 bfs로 칸을 돌면서 시간 갱신 하여 최소 시간 구해줌.
*/
void clear()
{
    fill(visit, visit + n, -1);
}
int dfs(int index,int choose)
{
    if (choose == m)
    {
        return;
    }


    

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int input;
            cin >> input;
            board[i][j] = input;
            if (input == 2)
            {
                V vi;
                vi.x = j;
                vi.y = i;
                virusArr.push_back(vi);
            }
        }
    }
    //dfs(0);
}