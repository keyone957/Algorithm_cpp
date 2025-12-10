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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while (true)
    {
        string input;
        cin >> input;
        if (input=="0")
        {
            break;
        }
        int start = 0;
        int end = input.size() - 1;
        bool isPel = false;
        while (start < end)
        {
            if (input[start] == input[end])
            {
                start++;
                end--;
            }
            else
            {
                isPel = true;
                break;
            }
        }
        if (isPel)
        {
            cout << "no" << '\n';
        }
        else
        {
            cout << "yes" << '\n';
        }
    }
}