#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>0
#include <stack>
#include <string>
#include <vector>
#include <unordered_set>
#include<unordered_map>
#include<math.h>
using namespace std;
int dx[8] = {0,-1,-1,-1,0,1,1,1};
int dy[8] = {-1,-1,0,1,1,1,0,-1};
pair<int, int> board[5][5];
int answer = 0;
/*
물고기는 작은 물고기 순으로 이동
물고기를 먹으면 그 물고기의 방향을 갖게됨.
주변에 먹을 물고기가 없으면 그냥 집감.

물고기는 주변에 45씩 돌면서 탐색을함 없으면 이동 x
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int num, dir;
            cin >> num >> dir;
            board[i][j].first=num;
            board[i][j].second = dir-1;
        }
    }
    
}