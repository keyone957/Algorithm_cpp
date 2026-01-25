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
int k;
char op[9];
vector<int> curArr;
bool visit[10];
string minStr = "";
string maxStr = "";
void func(int count)
{
    if (count == k + 1)
    {
        string s;
        s.reserve(k + 1);
        for (int i = 0; i < count; i++)
            s.push_back(char('0' + curArr[i]));

        if (minStr.empty() || s < minStr) minStr = s;
        if (maxStr.empty() || s > maxStr) maxStr = s;
        return;
    }
    for (int i = 0; i < 10; i++)
    {
        if (!visit[i])
        {
            if (count == 0)
            {
                visit[i] = true;
                curArr.push_back(i);
                func(count + 1);
                curArr.pop_back();
                visit[i] = false;
            }
            else
            {
                if (op[count - 1] == '<' && curArr[count - 1] < i)
                {
                    visit[i] = true;
                    curArr.push_back(i);
                    func(count + 1);
                    curArr.pop_back();
                    visit[i] = false;
                }
                else if (op[count - 1] == '>' && curArr[count - 1] > i)
                {
                    visit[i] = true;
                    curArr.push_back(i);
                    func(count + 1);
                    curArr.pop_back();
                    visit[i] = false;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> op[i];
    }
    func(0);
    cout << maxStr << '\n';
    cout << minStr ;
}