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
int l[21];//잃을 체력
int J[21];//얻을 행복지수
int dp[21][100];//i까지의 사람까지 봤을때 현재 체력이 j일때 최대로 얻을 수 있는 행복의 지수
//세준 체력 100
/*


*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> l[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> J[i];
    }
   
    dp[0][0] = 0;

    for (int i=1; i <= n; i++)
    {
        for (int j = 1; j <= 100; j++)
        {
            dp[i][j] = dp[i - 1][j];//인사를 안하는 경우는 그냥 이전 사람의 최대 행복수를 가져와서 갱신
            if (j - l[i - 1] > 0)//그 충분한 체력이 남아 있다면.
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j-l[i-1]]+ J[i-1]);//이전사람의 체력 현재 체력에서 체력 빼고 + 그다음에 행복 지수 더한것 중 큰값
            }
        }
    }
    int answer = 0;
    for (int j = 0; j <= 100; j++)
    {
        answer = max(answer, dp[n][j]);
    }
    cout << answer;
}