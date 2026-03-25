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
/*
n개의 물건 
각 물건은 무게 w 가치 v
최대k만큼의 무게만을 넣을 수 있는 배낭

*/
int n, k;
long long weight[101];
long long price[101];
long long dp[101];//i무게 까지 왓을때 얻을 수 있는 최대 가치
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n>>k;
    for (int i = 1; i <= n; i++)
    {
        cin >> weight[i] >> price[i];
    }

    for (int i = 1; i <= k; i++)
    {

    }
}