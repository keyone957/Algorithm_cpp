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
6 9 5 7 4
수신하는 탑이 없으면 0 출력

*/
int tower[500001];
struct Tinfo
{
    int height;
    int index;
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    stack<Tinfo> st;
    vector<int> answer;
  
    for (int i = 1; i <= n; i++)
    {

        cin >> tower[i];
        Tinfo towerInfo;
        towerInfo.height = tower[i];
        towerInfo.index = i;
        if (i == 1)
        {
            st.push(towerInfo);
            answer.push_back(0);
        }
        else
        {
            while (!st.empty())
            {
                if (st.top().height < tower[i]) //낮은 거는 필요 없음 삭제.
                {
                    st.pop();
                }
                else
                {
                   
                    answer.push_back(st.top().index);
                    st.push(towerInfo);
                    break;
                }
            }
            if (st.empty())
            {
                answer.push_back(0);
                st.push(towerInfo);
            }
        }
    }
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    

}