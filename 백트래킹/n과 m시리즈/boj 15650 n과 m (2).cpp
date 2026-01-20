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
int arr[9];
int visit[9];
void func(int count)
{
    if (count == m)
    {

        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visit[i])
        {
            if (arr[count - 1] < i||count==0)//이전수가 더 작을때 or 일단 0부터 갱신.
            {
                arr[count] = i;
                visit[i] = 1;
                func(count + 1);
                visit[i] = 0;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    func(0);

}