#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> arr;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());

	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		int K = arr[i];
		int sum = 0;
		int startIdx = 0;
		int endIdx = n - 1;
		while (startIdx < endIdx)
		{
			sum = arr[startIdx] + arr[endIdx];
			if (sum == K)
			{
				if (startIdx != i && endIdx != i)
				{
					answer++;
					break;
				}
				else if (startIdx == i)
				{
					startIdx++;
				}
				else if (endIdx == i)
				{
					endIdx--;
				}
				///////////////////////////////////////////////
				// 중요한 부분! ==> 현재 자기 자신 (비교할 대상 코드에서는 i의 인덱스)를 제외하고 더해야함. 
				// 만약에 startidx나 endidx가 i에 도달했을 경우 startidx 는 ++ endidx는 -- 해줘서 포인터 이동
				// 만약에 i가 아니면 그대로 답을 ++ 하고 while 문 탈출
				///////////////////////////////////////////////
			}
			else if (sum > K)
			{
				endIdx--;
			}
			else if (sum < K)
			{
				startIdx++;
			}
		}
	}

	cout << answer;

}