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
int dist[100001];
int n, k;
int wayCnt[100001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //cout.tie(NULL);

    cin >> n >> k;
    queue<int> q;
    q.push(n);
    dist[n] = 1;
    int answer = 0;
    int count = 0;
    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        if (cur == k)
        {
            answer = dist[cur]-1;
            count++;
        }
        if (cur - 1 >= 0 && (dist[cur - 1] == 0||dist[cur-1]==dist[cur]+1))//중복 방문을 했더라도 최단시간의 거리와 같다면 방문또하게.
        {
            dist[cur - 1] = dist[cur] + 1;
            q.push(cur - 1);
        }
        if (cur + 1 <= 100000 && (dist[cur + 1] == 0|| dist[cur +1] == dist[cur] + 1))
        {
            dist[cur + 1] = dist[cur] + 1;
            q.push(cur + 1);
        }
        if (cur * 2 <= 100000 && (dist[cur * 2] == 0||dist[cur*2] == dist[cur] + 1))
        {
            dist[cur * 2] = dist[cur] + 1;
            q.push(cur * 2);
        }
    }
        
    cout << answer<<'\n';
    cout << count;
    
}