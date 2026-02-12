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
(현재 몸무게^2) -(성원이가 기억하는 몸무게 ^2)
현재 몸무게를 출력
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int g;
    cin >> g;
    bool exist = false;
    /*
    1 4
    64-49=15
    
    */
    int curW=2,memW=1;
   
    while (true)
    {
        int cur= curW*curW;
        int mem = memW*memW;
        int result = cur-mem;
        if (result == g)
        {
            cout << curW << '\n';
            curW++;
            memW++;
            exist = true;
        }
        else if (result< g)
        {
            curW++;
        }
        else if (result>g)
        {
            if (curW - memW == 1)
            {
                break;
            }
            memW++;
           
        }

    }
    if (!exist)
    {
        cout << -1;
    }
}