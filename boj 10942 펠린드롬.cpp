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
int input[2001];
int dp[2001][2001];
//i번째수 부터 j번째수까지가 펠린드롬이면 1 아님 0
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    int tc;

    cin >> tc;
    while (tc--)
    {
        int start, end;
        cin >> start >> end;

    }

}