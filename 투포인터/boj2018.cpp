#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
int main()
{
	//�������� ����
	//���� for���� ������ ��� ���ϰ� ���� üũ�ϸ� �ð� ���⵵�� O(N^2)
	//but �������� ����Ͽ� ���� Ǯ�� O(N)
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
		if (sum == n)//���࿡ SUM�� ���� ������ ANSER++�ϰ� ������ �ε����� �ø�
		{
			answer++;
			rightIdx++;
		}
		else if (sum > n)//SUM�� N���� ũ�� ���� �ε����� �÷� ���� �۰���
		{
			leftIdx++;
		}
		else if (sum < n)//SUM�� N���� ������ ������ �ε����� �÷� ���� ũ����
		{
			rightIdx++;
		}
	}


	cout << answer;
}