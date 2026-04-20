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
/*
7
1 6
1 7
3 2
3 1
2 4
2 5
6 1

15




*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // 입력은 데드라인 기준으로 최소힙 오름차순으로 정렬
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int dead, cost;
        cin >> dead >> cost;
        pq.push({ dead,cost });
    }
    

}