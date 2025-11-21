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
int arr[100001];
/*
* 
ㅡㅡㅡㅡㅡ
5
1 2 3 4 5
ㅡㅡㅡㅡㅡ
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
2
2 3
2 3 4
2 3 4 5
3
3 4
3 4 5
4 
4 5
5


ㅡㅡㅡㅡ
5
1 2 3 1 2
ㅡㅡㅡㅡ
1
1 2
1 2 3
2
2 3
2 3 1
3
3 1
3 1 2
1
1 2
2
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
        cin >> arr[i];
    }
    int answer = 0;
    int left=0;
    int right = 0;


    /*while (true)
    {
        long long leftValue  = arr[left];
        long long rightValue = arr[right];
        for (int i = left; i < right+1; i++)
        {
            
        }
        if (left > right)
        {
            break;
        }
    }*/
    
    cout << answer;
}
/*
1 5 2 3 5

1
1 5
1 5 2
1 5 2 3
5
5 2
5 2 3
2
2 3
2 3 5
3
3 5


*/