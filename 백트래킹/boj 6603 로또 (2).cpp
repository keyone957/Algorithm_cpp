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
vector<int> input;
vector<int> inputArr;
//vector<bool> visited;

void dfs(int count, int startIdx)
//다음 시작할 인덱스를 재귀로 넘겨줘서 거기서 부터 시작하게끔 
{
    int size = input.size();
    if (count == 6)
    {
        for (int i = 0; i < 6; i++)
        {
            cout << inputArr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = startIdx; i < size; i++)
    {
            inputArr.push_back(input[i]);
            int prevNum = input[i];
            //visited[i] = true;
            dfs(count + 1, i + 1);
            inputArr.pop_back();
            //visited[i] = false;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (true)
    {

        int numCnt;
        cin >> numCnt;
        if (numCnt == 0)
        {
            break;
        }
        for (int i = 0; i < numCnt; i++)
        {
            int num;
            cin >> num;
            input.push_back(num);
        }
        /*inputArr.resize(numCnt + 1);*/
        //visited.resize(numCnt + 1);
        dfs(0, 0);
        input.clear();
        inputArr.clear();
        //visited.clear();
        cout << '\n';
    }
}