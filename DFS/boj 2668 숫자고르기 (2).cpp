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
int n;
int arr[101];//현재 i가 가리키는 다음 숫자
int cur[101];//현재 i돌면서 필요한 사이클 확인용 
bool isMatch[101]; // 최종적으로 사이클이 되어 매치가 된 노드
vector<int> answer;//정답 사이클 노드
void dfs(int start,int curNode)
{
    int next = arr[curNode];//현재 노드가 가리키는 노드
    if (next==start)// 사이클 판정 됐을때
    {
        int v = start;
        while (!isMatch[v])
        {
            isMatch[v] = true;//사이클 완료 처리
            answer.push_back(v);//사이클 완료된 노드 넣기
            v = arr[v];//다음 노드로 ㄱㄱ
            if (v == start)break;//처음으로 왔으니 break
        }
        return;
    }
    else//안됐을때
    {
        cur[curNode] = start;//일단 이번 사이클에서 한번 방문했다는 표시
        if (cur[next] == start)
        {
            //원래 맨처음 start로 돌아온게 아니라 중간에서 루프가 발생해서 return
            return;
        }
    }
    dfs(start, next);

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (!isMatch[i])
        {
            dfs(i,i);
        }
    }
    cout << answer.size()<<'\n';
    sort(answer.begin(), answer.end());
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i]<<'\n';
    }
}