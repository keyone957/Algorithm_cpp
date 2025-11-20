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
vector<pair<int,int>> linkedList[1001];
int path[1001];
vector<int> minDist;
int INF = 1e9;
/*
** 오답노트 ** 
일단 아무것도 삭제 안했을때 최단거리를 구한 후 그 최단 거리의 경로 즉 노드들을 따로 저장해 두고 
그 최단 거리의 경로의 도로들을 하나하나 제외 하면서 거리를 갱신시킴

이전 문제 풀이 
-> 그냥 모든 간선들을 하나하나 제외 시키면서 간선 개수 만큼 갱신시킴
but 이러면 시간초과가 나버림. 
최단 경로에 있는 간선을 삭제해야 지연이 발생이 된다. 따라서 모든 간선을 삭제해서 경로를 갱신 시킬 필욕 없단다.

*/
int n,m;
void bfs(int startNode)
{
    
    priority_queue<pair<int, int>> pq;
    minDist[startNode] = 0;
    pq.push({ 0,startNode });
    while (!pq.empty())
    {
        int curNode = pq.top().second;
        int curNodeCost = -pq.top().first;
        pq.pop();
        if (minDist[curNode] < curNodeCost)continue;
        for (int i = 0; i < linkedList[curNode].size(); i++)
        {
            int cost = curNodeCost+linkedList[curNode][i].second;
            if (cost < minDist[linkedList[curNode][i].first])
            {
                minDist[linkedList[curNode][i].first] = cost;
                pq.push(make_pair(-cost, linkedList[curNode][i].first));
                path[linkedList[curNode][i].first] = curNode;
            }
        }
    }
}
void bfs2(int startNode,int eStart,int eEnd)
{
    priority_queue<pair<int, int>> pq;
    minDist[startNode] = 0;
    pq.push({ 0,startNode });
    while (!pq.empty())
    {
        int curNode = pq.top().second;
        int curNodeCost = -pq.top().first;
        pq.pop();
        if (minDist[curNode] < curNodeCost)continue;
        for (int i = 0; i < linkedList[curNode].size(); i++)
        {
            int cost = curNodeCost + linkedList[curNode][i].second;
            if ((curNode == eStart && linkedList[curNode][i].first == eEnd)||
                (curNode == eEnd && linkedList[curNode][i].first== eStart)) continue;
            //--> 
            if (cost < minDist[linkedList[curNode][i].first])
            {
                minDist[linkedList[curNode][i].first] = cost;
                pq.push(make_pair(-cost, linkedList[curNode][i].first));
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    minDist.resize(n+1);
    for (int i = 0; i < m; i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        linkedList[start].push_back({ end,cost });
        linkedList[end].push_back({ start,cost });
    }
    fill(minDist.begin(), minDist.end(), INF);
    bfs(1);
    int thiefDist;

    thiefDist = minDist[n];

    int answer = -1;
    int endNode = n;
    while (endNode != 1) {
        int startNode = path[endNode]; // endNode의 부모(직전 방문 노드)
        fill(minDist.begin(), minDist.end(), INF);
        bfs2(1, startNode, endNode);

        if (minDist[n] == INF) {
            cout << -1;
            return 0;
        }

        answer = max(answer, minDist[n] - thiefDist);

        // 다음 단계로 이동 (거꾸로 올라감)
        endNode = startNode;
    }
    
    cout << answer;
}