#include <iostream>
#include <vector>
#include <string>
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

	int n;
	int leftIdx = 1;
	int rightIdx = 1;
	int answer = 1;

	cin >> n;

	while (rightIdx != n)
	{
		int sum = 0;
		for (int i = leftIdx; i <= rightIdx; i++)
		{
			sum += i;
		}
		if (sum == n)//만약에 SUM과 답이 맞으면 ANSER++하고 오른쪽 인덱스를 늘림
		{
			answer++;
			rightIdx++;
		}
		else if (sum > n)//SUM이 N보다 크면 시작 인덱스를 늘려 수를 작게함
		{
			leftIdx++;
		}
		else if (sum < n)//SUM이 N보다 작으면 마지막 인덱스를 늘려 수를 크게함
		{
			rightIdx++;
		}
	}


	cout << answer;
}