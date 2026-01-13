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
/*
R -> 뒤집기
D -> 버리기 첫번째 수 버리기. 만약 배열 비어있는데 D하면 에러 띄움

*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count;
    cin >> count;
    while (count--)
    {
        deque<int> dq;
        string command;
        cin >> command;
        int commandSize = command.size();

        int arrSize;
        cin >> arrSize;
        string arrInfo;
        cin >> arrInfo;
        arrInfo.erase(0, 1);
        arrInfo.erase(arrInfo.size()-1, arrInfo.size());
        stringstream ss(arrInfo);
        string temp;
        while (getline(ss, temp, ','))
        {
            dq.push_back(stoi(temp));
        }
        bool isFront = false;
        // -> false 가 앞에서
        // true가 뒤에서 
        bool isError = false;
        for (int i = 0; i < commandSize; i++)
        {
            if (command[i] == 'R')
            {
                isFront = !isFront;
                
            }
            else if (command[i] == 'D')
            {
                if (dq.empty())
                {
                    cout << "error"<<'\n';
                    isError = true;
                    break;
                }
                else if (!isFront)
                {
                    dq.pop_front();
                }
                else
                {
                    dq.pop_back();
                }
            }
        }
        if (!isError)
        {
            cout << '[';
            int dqsize = dq.size();
            for (int i = 0; i < dqsize; i++)
            {
                if (!isFront)
                {
                    cout << dq.front();
                    dq.pop_front();
                }
                else
                {
                    cout << dq.back();
                    dq.pop_back();
                }
                if (i != dqsize - 1)
                {
                    cout << ',';
                }
            }
            cout << ']';
            cout << '\n';
        }

    }
}