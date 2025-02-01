//#include <string>
//#include <vector>
//#include <unordered_map>
//
//using namespace std;
//
//int solution(vector<string> want, vector<int> number, vector<string> discount) {
//	int answer = 0;
//	int totalDays = 10; 
//	int discountSize = discount.size();
//
//	unordered_map<string, int> wantMap; 
//	for (size_t i = 0; i < want.size(); i++) {
//		wantMap[want[i]] = number[i];
//	}
//
//	for (int i = 0; i <= discountSize - totalDays; i++) {
//		unordered_map<string, int> discountMap;
//		for (int j = i; j < i + totalDays; j++) {
//			discountMap[discount[j]]++;
//		}
//
//		bool isEligible = true;
//		for (auto& item : wantMap) {
//			if (discountMap[item.first] < item.second) {
//				isEligible = false;
//				break;
//			}
//		}
//
//		if (isEligible) {
//			answer++;
//		}
//	}
//
//	return answer;
//}