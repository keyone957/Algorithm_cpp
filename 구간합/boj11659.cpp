#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
/*
�κ��� ����.
�ð��ʰ� ���� 
ios::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
==> ���� �ð��ʰ��� �߸� �̰� ������ �ذ�ȴٳ׿�
 */

	int N, M;
	int sumList[100000] = {};
	vector<int> answer;

	cin >> N;
	cin >> M;
	for (int i = 1; i <= N; i++)
	{
		int temp;
		cin >> temp;
		sumList[i] = sumList[i - 1] + temp;//==> �չ迭 ���ϴ� ����. S[i]=S[i-1]+A[i] s:�չ迭 a : �Ϲݹ迭
	}
	
	
	for (int i = 1; i <= M; i++)
	{
		int startIdx, endIdx;
		cin >> startIdx;
		cin >> endIdx;
		int result = 0;
		result = sumList[endIdx] - sumList[startIdx - 1];//i~j���� ������ ����. 
		answer.push_back(result);
	}
	for (int i = 0; i < M; i++)
	{
		cout << answer[i] << "\n";//endl���ٴ� \n�̿��ؼ� ��Ÿ���°� �ð��ʰ��� �ȶߴ���.
		
	}
	

}