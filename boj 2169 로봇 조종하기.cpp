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
int n, m;
int board[1001][1001];
int dp[1001][1001];
/*
현재 위치 에서 이전 왼 위 오른쪽에서 값을 확인할때 가장 큰값?으로갱신
i-1 j / i j-1 / i+1 j 
이중에서 가장 큰값을 현재 위치에 있는 값과 더한것과 / 현재 위치 ?
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

        }
    }
}