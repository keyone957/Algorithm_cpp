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
n개의 수열이 주어짐
수와 수 사이에 연산자 넣어서 수식 만드는데 순서 바꾸면 x

input
수의 개수 n
둘째 줄에는 입력 수
합이 n-1인 4개의 정수?
0      1     2     3
덧셈, 뺄셈 곱셈 나누셈 개수 주어짐

output
수식 사용해서 나올수 있는 최소 최대 값
*/
int n;
int input[11];
int op[4];
int maxSum = -1e9;
int minSum = 1e9;
void func(int count, int curValue)
{
    if (count == n)
    {
        minSum = min(minSum, curValue);
        maxSum = max(maxSum, curValue);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (op[i] > 0)
        {
            op[i]--;
            int next;
            if (i == 0) next = curValue + input[count];
            else if (i == 1) next = curValue - input[count];
            else if (i == 2) next = curValue * input[count];
            else next = curValue / input[count];
            func(count + 1, next);
            op[i]++;
            
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
        cin >> input[i];
    }

    for (int i = 0; i < 4; i++)
    {
        cin >> op[i];
    }
    func(1, input[0]);
    cout << maxSum << '\n'<<minSum;

}