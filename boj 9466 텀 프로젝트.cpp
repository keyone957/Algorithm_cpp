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
using namespace std;
int t, n;
vector<int> arr;
vector<int> visited;
vector<bool> inCycle;
/*
각각 연결된 그래프가 한 사이클을 이루면 그 사이클에 있는 노드는 
짝을 이룬것.
visited[]의 상태
0 -> 아직 방문 안함
1 -> 방문 중에 있음 (사이클 판단중에 있음)
2 -> 사이클 안에 있다는걸 확인해서 이제 더이상 접근 할 필요 없음.
*/
void dfs(int node)
{
    visited[node] = 1;
    int next = arr[node];
    if (visited[next] == 0)
    {
        dfs(next);
    }
    else if (visited[next] == 1)
    {
        for (int i = next; i != node; i = arr[i])
        {
            inCycle[i] = true;
        }
        inCycle[node] = true; // 자기 자신도 포함
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;

    while (t--)
    {
        cin >> n;
        arr.assign(n + 1,0);
        visited.assign(n + 1, 0);
        inCycle.assign(n + 1, false);

        for (int i = 1; i <= n; i++)
        {
            int input;
            cin >> input;
            arr[i] = input;
        }
    }
    
}