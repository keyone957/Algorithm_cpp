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
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int x, y, originTime, crossTime;
	cin >> x >> y >> originTime >> crossTime;
	/**
		originTime<=crossTime
		이때는 굳이 대각선으로 이동하는 것보다 모두 그냥 모두 한칸씩 이동하는게 더 빠름
	 */
}