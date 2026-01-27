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
int l, c;
/*
비밀번호 자리수 l
비밀번호 구성되어있는 문자 개수 c
최소 1개의 모음,
최소 두개의 자음
*/
vector<char> input;
vector<char> curArr;
bool visit[15];
int charCnt[5];
int moCnt = 0;
bool checkMo(char check)
{
    bool isMo = false;
    if (check == 'a' || check == 'e' || check == 'i' || check == 'o' || check == 'u')
    {
        isMo = true;
    }
    return isMo;
}
void func(int count)
{
    if (count == l)
    {
        if (moCnt >= 1 && l - moCnt >= 2)
        {
            int check = 0;
            for (int i = 0; i < l; i++)
            {
                cout << curArr[i];
            }
            cout << '\n';
        }
        return;
    }
    for (int i = 0; i < c; i++)
    {
        if (!visit[i])
        {
            if (count == 0 || curArr[count - 1] < input[i])
            {
                visit[i] = true;
                curArr.push_back(input[i]);
                if (checkMo(input[i])) moCnt++;
                func(count + 1);
                if (checkMo(input[i])) moCnt--;
                curArr.pop_back();
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
    cin >> l >> c;
    for (int i = 0; i < c; i++)
    {
        char a;
        cin >> a;
        input.push_back(a);
    }
    sort(input.begin(), input.end());
    func(0);
}