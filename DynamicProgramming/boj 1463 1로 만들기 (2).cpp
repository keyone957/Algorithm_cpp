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
x 가 3으로 나누어 떨어지면 3으로 나눔
2로 나누어 떨어지면 2로 나눔
1 뺌

--> 3개 사용해서 1만들거임
연산 사용 횟수 최솟값 .

*/
int x;
int dp[1000001];
/*
i 까지 왔을때 최소 연산횟수

*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> x;
    for (int i = 2; i <= x; i++)
    {
        dp[i] = dp[i - 1] + 1;//일단 모든 수에서 -1가능
        if (i % 3 == 0)
        {
            dp[i] = min(dp[i], dp[i / 3] + 1);//현재 그냥 수와 나누기 3한 수에 +1 둘을 비교해서 더 작은것으로 dp테이블 갱신.
            
        }
        if (i % 2 == 0)
        {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
    }
    cout << dp[x];
}