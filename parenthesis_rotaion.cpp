//#include <string>
//#include <vector>
//#include <stack>
//
//using namespace std;
//
//bool isValidBracketString(const string& s) {
//	stack<char> st;
//	for (char c : s) {
//		// 여는 괄호인 경우 스택에 push
//		if (c == '(' || c == '[' || c == '{') {
//			st.push(c);
//		}
//		// 닫는 괄호인 경우
//		else {
//			if (st.empty()) return false; // 스택이 비어있으면 유효하지 않음
//			char top = st.top();
//			// 짝이 맞는지 확인
//			if ((c == ')' && top == '(') ||
//				(c == ']' && top == '[') ||
//				(c == '}' && top == '{')) {
//				st.pop();
//			}
//			else {
//				return false; // 짝이 맞지 않으면 유효하지 않음
//			}
//		}
//	}
//	return st.empty(); // 모든 괄호가 짝을 이루었는지 확인
//}
//
//int solution(string s) {
//	int answer = 0;
//	int n = s.length();
//
//	for (int i = 0; i < n; i++) {
//		string rotated = s.substr(i) + s.substr(0, i);
//
//		if (isValidBracketString(rotated)) {
//			answer++;
//		}
//	}
//
//	return answer;
//}