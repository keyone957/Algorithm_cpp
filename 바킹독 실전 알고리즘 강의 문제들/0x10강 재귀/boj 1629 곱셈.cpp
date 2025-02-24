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
#include <cmath>
using namespace std;
long long powCustom(int a, int b, int c)
{
	if (b == 1) return a % c;
	long long val = powCustom(a, b / 2, c);// ��� �ݾ� �ٿ����鼭 ���� �ٿ�����.
	val = val * val % c;//�ѹ��� �� ���ؼ� �������� ���ϴ°��� �ƴ� A * A �ѹ� �Ҷ����� �������� RETURN����.==>�׸���������
	if (b % 2 == 0) return val;
	return val * a % c;//Ȧ�� �϶� ex) 2^5 == 2^4*2 == 2^2*2^2*2�̹Ƿ� �������� a�ϳ� �����ְ� ������ ���������
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b, c;
	cin >> a >> b >> c;
	cout << powCustom(a, b, c);
}