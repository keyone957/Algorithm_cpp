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
뒤에있는 상자의 크기보다 작으면 앞에 있는 상자를 뒤에 상자안에 넣기.

5
1 5 2 3 7 

*/
int dp[1001];
/*
여기까지 왔을때 최대 박스 개수
*/
int box[1001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> box[i];
        dp[i] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (box[i] > box[j])//현재 비교할 박스들 계속 넣어가면서 dp 테이블 갱신
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int answer = *max_element(dp, dp + n);
    cout << answer;
}