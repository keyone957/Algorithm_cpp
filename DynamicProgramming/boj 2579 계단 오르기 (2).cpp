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
int stairs[301];
int dp[301];
/*
현재 i까지 왔을때 최대로 얻을 수 있는 점수

조건
1. 한계단 또는 두계단 씩 오를 수 있음
2. 연속으로 3개 계단 밟기 불가능
3. 마지막 계단은 무조건 밟기
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int count;
    cin >> count;
    for (int i = 1; i <= count; i++)
    {
        cin >> stairs[i];
    }
    dp[0] = 0;
    dp[1] = stairs[1];
    dp[2] = stairs[1] + stairs[2];

    for (int i = 3; i <= count; i++)
    {
        dp[i] = max(dp[i - 2] + stairs[i], dp[i-3] + stairs[i - 1] + stairs[i]);
        //현재 계단에서 두칸아래 밟은거 + 현재 계단 vs 현재 계단에서 3칸아래에서 밟은거 + 바로 아래 계단 + 현재 계단 (3개 연속으로 밟지 않게 하기 위함)
        
    }
    cout << dp[count];
}