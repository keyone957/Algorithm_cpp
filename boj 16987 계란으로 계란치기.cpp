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
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int count;
    cin >> count;
    vector<pair<int,int>> egg;
    for (int i = 0; i < count; i++)
    {
        int S, W;
        cin >> S >> W;
        egg.push_back({S,W});
    }


}