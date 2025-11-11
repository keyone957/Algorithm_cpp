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
12ab112ab2ab
12ab ->폭팔 단어
1. *12ab*112ab2ab
2.1*12ab*2ab
3.*12ab*
출력 -> FRULA

while 문안에서? 끝났을때? true 로 while문 없애면되나?-- >이렇게 풀면 이거 시간 초과나드라.
///////////////////////////////////////////////////////////
size_t pos; 
while ((pos = input.find(bomb)) != string::npos) 
{ 
    input.erase(pos, bomb.size()); 
}  --> 오답 (시간초과)
//////////////////////////////////////////////////////////
mirkovC4nizCC44
C4

12ab112ab2ab
12ab
따라서 이제 맨처음에 input을 입력을 받고 stack에 이 문자열을 넣으면서 비교를 하는거지.
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string input,bomb;
    cin >> input;
    cin >> bomb;
    stack<char> inputStack;
    int inputSize = input.size();
    int bombSize = bomb.size();
    for (int i = 0; i < inputSize; i++)
    {
        inputStack.push(input[i]);
        if (inputStack.top() == bomb[bombSize - 1]&&inputStack.size()>=bombSize)
        // 일단 stack에 넣으면서 top 과 폭팔단어 맨 위에가 같으면
        // 확인. 
        {
            string temp = "";
            for (int j = 0; j < bombSize; j++)
            {
                temp += inputStack.top();
                inputStack.pop();
            }
            reverse(temp.begin(), temp.end());//스택이므로 꺼낼때 거꾸로 나오기 때문에 다시 원래순서대로 
            if (temp != bomb)// 만약에 폭발언어가 일치 하지 않으면 다시 스택에 넣기
            {
                for (int a = 0; a < bombSize; a++)
                {
                    inputStack.push(temp[a]);
                }
            }
        }
    }
    vector<char> answer;
    while (!inputStack.empty())
    {
        answer.push_back(inputStack.top());
        inputStack.pop();
    }
    if (answer.size() == 0)
    {
        cout << "FRULA";
        return 0;
    }
    reverse(answer.begin(), answer.end());//스택이므로 역순으로 다시 나오게.
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i];
    }
    
}