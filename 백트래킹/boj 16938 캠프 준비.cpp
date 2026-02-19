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
int n, l, r, x;
vector<int> arr;
vector<int> curArr;
int answer = 0;
/*
문제난이도의 합은 L이상 R이하. 
가장 높은 문제와 낮은 문제의 난이도 차는 X보다 크거나 같아야함
캠프에 사용할 문제를 고르는 방법의수?
그러면 백트래킹을 언제 멈춰야할까...흠
*/
void dfs(int count)
{
    if (count == n)
    {
        if (curArr.size() < 2)//문제는 2개부터 한다 함
        {
            return;
        }
        else
        {
            int sum = 0;
            for (int i = 0; i < curArr.size(); i++)
            {
                sum += curArr[i];
            }
            int minNum = *min_element(curArr.begin(), curArr.end());
            int maxNum = *max_element(curArr.begin(), curArr.end());
            int diff = maxNum - minNum;
            if (sum >= l && sum <= r && diff >= x)
            {
                answer++;
            }
            return;
        }
    }
    curArr.push_back(arr[count]);
    dfs(count + 1);
    curArr.pop_back();
    dfs(count + 1);//아무것도 안넣는 경우.

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> l >> r >> x;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        arr.push_back(input);
    }
    dfs(0);
    cout << answer;
}