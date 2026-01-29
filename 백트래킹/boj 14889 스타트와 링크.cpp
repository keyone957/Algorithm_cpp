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

Sij는 i번 사람과 j번 사람이 같은 팀에 속했을때 팀에 더해지는 능력치.

두 팀을 이룰때 두 팀의 능력치가 최소가 되게 하는 최솟값 출력
*/
int n;
int s[21][21];
int answer = 1e9;
bool visit[21];
void func(int count, int next)
{
    if (n / 2 == count)
    {
        int groupA = 0;
        int groupB = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visit[i] && visit[j])
                {
                    groupA += s[i][j];

                }
                if (!visit[i] && !visit[j])
                {
                    groupB += s[i][j];

                }
            }
        }
        int minusGroup = abs(groupA - groupB);
        answer = min(answer, minusGroup);
        return;
    }
    int prev = -1;
    for (int i = 0; i < n; i++)
    {

        if (!visit[i])
        {
            if (count == 0 || next < i)
            {
                visit[i] = true;
                func(count + 1, i);
                visit[i] = false;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> s[i][j];
        }
    }
    func(0, 0);
    cout << answer;

}