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
vector<int> curArr;
int visit[9];
void func(int count)
{
    if (count == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << curArr[i]<<' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visit[i])
        {
            curArr.push_back(input[i]);
            visit[i] = 1;
            func(count + 1);
            curArr.pop_back();
            visit[i] = 0;
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