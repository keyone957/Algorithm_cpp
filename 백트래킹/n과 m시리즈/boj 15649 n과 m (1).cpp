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
1부터 n까지 자연수 중에서 중복없이 m 개를 고른 수열
*/
int n, m;
int arr[9];
bool visit[9];
vector<int> cur;
void func(int count)
{
    if (count == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << cur[i] << ' ';
        }
        cout << "\n";
        return;//직전 갈림길로 돌아가셈
    }
  
    for (int i = 1; i <= n; i++)
    {
        if (!visit[i])
        {
            cur.push_back(i);
            visit[i] = true;
            func(count + 1);
            cur.pop_back();//다 사용했으면 현재 출력할 배열에서 삭제 후 방문처리 해제해
            visit[i] = false;
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