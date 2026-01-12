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
규칙 
연속으로 놓여있는 3잔을 마실 수 없음
*/
int input[10001];
int dp[10001];
/*
* dp테이블 정의
현재까지 포함해서 최대로 먹을수 있는 포도주의 양
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> input[i];
        dp[i] = input[i];
    }
    dp[0] = 0;
    dp[1] = input[1];
    dp[2] = input[1] + input[2];
    for (int i = 3; i <= n; i++)
    {
        dp[i] = max({ dp[i - 2] + input[i], dp[i - 3] + input[i] + input[i - 1],dp[i - 1] });
        /*
                1. 3개연속으로 겹치지 않게 하기 위해 전전꺼 먹고 자기꺼 먹기
                2. 자기 자신 , 바로전 , 전전 꺼 먹은거 최대값
                3. 현재꺼 안먹고 그냥 바로 전에 먹었던게 더 큼
        
        */
    }
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        answer = max(dp[i], answer);
    }
    cout << answer;
    
}