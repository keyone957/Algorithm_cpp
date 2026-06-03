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
const int root = 1;
int unused = 2;
const int MAX = 2000005;
vector<bool> check;
vector<vector<int>> nxt;
int c2i(char c)
{
    return c - '0';
}
void insert(string& s)
{
    int cur = root;
    for (int i = 0; i < s.size(); i++)
    {
        int digit = c2i(s[i]);
        if (nxt[cur][digit] == -1)
        {
            // 공간이 부족하면 실시간으로 트라이 노드 공간을 확장 (Segfault 방지)
            if (unused >= nxt.size()) {
                nxt.push_back(vector<int>(10, -1));
                check.push_back(false);
            }
            /*
            원래 윗 부분 없이 그냥 쌩으로 check배열과 nxt 배열을 max값으로 때려 박아버렸음 그러니 자꾸 맨 마지막 에서 메모리 segfault가 떠서 이거는 동적으로
            크기를 늘리는 식으로 했음
            */
            nxt[cur][digit] = unused++;
        }
        cur = nxt[cur][digit];
    }

    check[cur] = true;
}
bool find(string& s)
{
    int cur = root;
    for (int i = 0; i < s.size(); i++)
    {
        if (nxt[cur][c2i(s[i])] == -1) return false;
        cur = nxt[cur][c2i(s[i])];
    }
    for (int i = 0; i < 10; i++)
    {
        if (nxt[cur][i] != -1)
        {
            return true; // 자식 존재 => 접두어
            //119 -> 아래에 더 이어질 수 있는 게 있음
        }
    }

    return false;
}

bool solution(vector<string> phone_book) {

    // 매 테스트 케이스마다 크기 할당 및 초기화
    unused = 2;
    check.assign(MAX, false);
    nxt.assign(MAX, vector<int>(10, -1));
    for (int i = 0; i < phone_book.size(); i++)
    {
        insert(phone_book[i]);
    }
    for (int i = 0; i < phone_book.size(); i++)
    {
        if (find(phone_book[i]))
        {
            return false;
        }
    }

    return true;
}