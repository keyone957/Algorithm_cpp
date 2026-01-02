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
char board[51][51];
int n, m;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int answer = 1e9;
/*
맨 왼쪽 위에 B 또는 W로 시작.



*/
int Chess(int y, int x)
{
    int startB=0, startW=0;
    //각각 b,W로 시작할때 바꿔야할 갯수
    //
    for (int i = y; i < y + 8; i++)
    {
        for (int j = x; j < x + 8; j++)
        {
            if ((i + j) % 2 == 0)//
            {
                if (board[i][j] != 'B') startB++;//시작을 B로 했으니 시작색인 B와 같지 않으면 변경해야함.
                if (board[i][j] != 'W') startW++;
            }
            else
            {
                if (board[i][j] != 'W') startB++;//홀수일때는 이제 B와는 다른색이어야 하므로 아니면 변경해야함.
                if (board[i][j] != 'B') startW++;
            }

        }
    }
    return min(startB, startW);//B or W로 시작 할 때 둘중에 더 작은걸로 RETURN
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < m; j++)
        {
            board[i][j] = input[j];
        }
    }
    
    for (int i = 0; i <= n - 8; i++)
    {
        for (int j = 0; j <= m - 8; j++)
        {
            answer=min(answer,Chess(i, j));
        }
    }
    cout << answer;
}