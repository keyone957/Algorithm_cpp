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
using namespace std;
int input[2001];
int dp[2001][2001];
/*
i번째수 부터 j번째수까지가 펠린드롬이면 1 아님 0
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 1; //일단 길이가 1일때는 무조건 펠린드롬.
    }
    for (int i = 2; i <= n; i++)//여기서 i는 길이. 즉 펠린드롬수인지를 비교할 범위를 나타냄
    {
        for (int start = 1; start <= n - i + 1; start++)//그 현재 비교하는 거리까지 for문
        {
            int end = start + i - 1;
            //시작점에서 길이만큼 떨어져 있는걸 구하는 인덱스
            //끝점계산 공식
            if (i == 2)
            {
                if (input[start-1] == input[end-1])
                {
                    dp[start][end]=1;
                }
            }
            else if(i>2)
            /*
            길이가 3이상일때
            양쪽끝이 똑같고 && 그 다음에 그 안에 있는 수들도 펠린드롬 수이면 그 범위는 펠린드롬수가 맞음.
            */
            {
                if (input[start-1] == input[end-1] && dp[start+1][end-1] == 1)
                {
                    dp[start][end] = 1;
                }
            }

        }
    }

    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        int start, end;
        cin >> start >> end;
        cout <<dp[start][end] << "\n";
    }
   /* while (tc--)
    {
        int start, end;
        cin >> start >> end;
        cout << dp[start][end]<<'\n';
    }*/
}