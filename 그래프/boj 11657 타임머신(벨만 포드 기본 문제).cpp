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
/*
n개의 도시 버스 m개
벨만포드 사용해서 음수 사이클 있는지 없는지에 대해 판단 및 최단 경로 확인하는 문제
*/
vector<pair<int, int>> arr[501];
int n, m;
vector<long long> distArr;// 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        arr[start].push_back({ end,cost });
    }

    distArr.assign(n + 1, 1e9);
    distArr[1] = 0;
    for (int i = 0; i < n - 1; i++)
    //n-1번까지 벨만포드 갱신해서 일단 최단 거리 배열 갱신
    //why n-1 인가 최단 경로는 간선 개수가 최대 n-1개 이기때문.
    {
        for (int j = 1; j <= n; j++)// 모든 정점 j를 돌아
        {
            if (distArr[j] == 1e9) continue;
            for (int a = 0; a < arr[j].size(); a++)
            {
                int end = arr[j][a].first;
                int cost = arr[j][a].second;
                if (distArr[end] > distArr[j] + cost)
                {
                    distArr[end] = distArr[j] + cost;
                }
            }
        }
    }
    
    bool isCycle=false;
    for (int i = 1; i <= n; i++)
    {
        if (distArr[i] == 1e9) continue;
        for (int a = 0; a < arr[i].size(); a++)
        {
            int end = arr[i][a].first;
            int cost = arr[i][a].second;
            if (distArr[end] > distArr[i] + cost)// 만약에 이 최단거리 배열이 갱신이 되면 음수 사이클이므로 즉시 for문 끊고 결과 출력
            {
                isCycle = true;
                break;
            }
        }
    }
    if (isCycle)
    {
        cout << -1<<'\n';
        return 0;
    }
    for (int i = 2; i <= n; i++)
    {
        if (distArr[i] == 1e9)
        {
            cout << -1;
        }
        else
        {
            cout << distArr[i];
        }
        cout << '\n';
    }

}