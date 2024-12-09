#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;
int main()
{
	//투포인터 문제
	//이중 for문을 돌려서 계속 더하고 답을 체크하면 시간 복잡도가 O(N^2)
	//but 투포인터 사용하여 문제 풀면 O(N)
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N;
	cin >> M;
	vector<int> arr;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	int leftIdx=0;
	int rightIdx=N-1;
	int answer = 0;
	while (leftIdx <rightIdx)
		//정렬된 상태로 양쪽 끝에서 오기 때문에 
		// leftidx가 rightidx보다 크면 이제 넘어가니까? 모든 경우의 수를 계산한것
	{
		int sum = arr[leftIdx] + arr[rightIdx];
		if (sum == M)
		{
			leftIdx++;
			rightIdx--;
			answer++;
		}
		else if (sum>M)
		{
			rightIdx--;
		}
		else if (sum < M)
		{
			leftIdx++;
		}
	}
	cout << answer;
	
}