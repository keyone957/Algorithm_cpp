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
int n, m;
vector<long long> arr;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        long long num;
        cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    int left = 0;
    int right = 0;
    long long answer = 2e18;
    while (right < n && left < n)// 오른쪽 인덱스와 왼쪽 인덱스의 값이 둘다 범위를 넘어가지 않도록 조건을 넣어줘야함
    {
        long long lValue = arr[left];
        long long rValue = arr[right];
        long long a = rValue - lValue;
        if (a >= m)
        {
            answer = min(answer, a);
            left++;
        }
        else
        {
            right++;
        }

    }
    cout << answer;


}