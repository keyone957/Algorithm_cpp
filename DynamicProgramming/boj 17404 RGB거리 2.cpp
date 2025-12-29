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
int n;
/*
빨 초 파 칠해.
1. 1번집은  //// 2번, N번집의 색과 같지 않아야함.
    -> 첫번째 집은 두번째 집과 n번의 집과 같지 않아야함.
2. N번 집의 색은 N-1번, 1번 집의 색과 같지 않아야함.
    --> 첫번째 집은 n과 n-1 의 집과 같지 않아야함.

3.  i-1, i, i+1 이 같지 않아야함.
    --> 각 인접한 집들은 색이 같지 않아야함.

ex)
-------------------input
//비용 주어짐
3
26 40 83
49 60 57
13 89 99

40 + 57 + 13 = 110
----------------- output
110

==> 위 규칙들을 만족하고 
모든 집에 색을 칠하는 최소 비용
*/
int R[1001];
int G[1001];
int B[1001];
int dpR[1001][3];
int dpG[1001][3];
int dpB[1001][3];
/*
i번집을 색 j로 칠했을때 최소 비용

일단 먼저 첫번째 집이 어떤 값이냐에 따라 달라지기 때문에
첫번째 집을 r g b 각각 입력을 받아놓고 dp를 3번 돌리기?

그래서 각 테이블의 의미는 
첫집의 r,g,b값을 고정시키고 그 다음부터 dp테이블을 갱신시키기. 
why? => 첫번째 집의 색에 따라서 달라지기 때문
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
        cin >> R[i] >> G[i] >> B[i];
    }

    dpR[0][0] = R[0];
    dpR[0][1] = 1e9;
    dpR[0][2] = 1e9;
    //첫집을 각각 색으로 고정함.
    for (int i = 1; i < n; i++)
    {
        dpR[i][0] = min(dpR[i - 1][1], dpR[i - 1][2]) + R[i];
        dpR[i][1] = min(dpR[i - 1][0], dpR[i - 1][2]) + G[i];
        dpR[i][2] = min(dpR[i - 1][0], dpR[i - 1][1]) + B[i];
    }
    int rA = min(dpR[n-1][1],dpR[n-1][2]);
    //근데 이제 마지막에 비교할때 고정된 첫집에 따라서 그 첫집을 제외하고는 최소값 비교 x



    dpG[0][0] = 1e9;
    dpG[0][1] = G[0];
    dpG[0][2] = 1e9;
    
    for (int i = 1; i < n; i++)
    {
        dpG[i][0] = min(dpG[i - 1][1], dpG[i - 1][2]) + R[i];
        dpG[i][1] = min(dpG[i - 1][0], dpG[i - 1][2]) + G[i];
        dpG[i][2] = min(dpG[i - 1][0], dpG[i - 1][1]) + B[i];
    }
    int gA = min(dpG[n-1][0], dpG[n-1][2]);

    dpB[0][0] = 1e9;
    dpB[0][1] = 1e9;
    dpB[0][2] = B[0];
    for (int i = 1; i < n; i++)
    {
        dpB[i][0] = min(dpB[i - 1][1], dpB[i - 1][2]) + R[i];
        dpB[i][1] = min(dpB[i - 1][0], dpB[i - 1][2]) + G[i];
        dpB[i][2] = min(dpB[i - 1][0], dpB[i - 1][1]) + B[i];
    }
    int bA = min(dpB[n-1][0], dpB[n-1][1]);
    
    cout << min(rA,min(gA,bA));
}