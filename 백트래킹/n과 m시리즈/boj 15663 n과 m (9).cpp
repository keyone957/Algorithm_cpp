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
vector<int> input;
int visit[9];
vector<int> curArr;
void func(int count)
{
    if (count == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << curArr[i] << ' ';
        }
        cout << endl;
        return;
    }
    int prev=-1;
    for (int i = 0; i < n; i++)
    {
        if (input[i] == prev)continue;//이전 값과 현재 사용할 값이 같으면 재귀 패스
        if (!visit[i])
        {
            visit[i] = 1;
            curArr.push_back(input[i]);
            prev = input[i];
            func(count + 1);
            visit[i] = 0;
            curArr.pop_back();
        }
    }

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        input.push_back(a);
    }
    sort(input.begin(), input.end());
    func(0);

}