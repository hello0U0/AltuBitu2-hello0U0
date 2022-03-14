#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	string s;
	int answer = 1;
	stack<int> sstack;
	cin >> s;
	
	//대괄호는 -1, 소괄호는 -2로 설정한다.
	for (int i = 0; i < s.size(); i++) {
		char now = s[i];
		if (now == '['||now=='(') {
			sstack.push(now == '[' ? -1 : -2);
		}
		else{
			int now_int = now==']' ? -1 : -2;
			int now_answer = 0;                  //괄호 안의 값
			//[나 (가 나올때까 지 값들을 더하기
			while (!sstack.empty()&&sstack.top() != -2 && sstack.top() != -1) {
				now_answer += sstack.top();
				sstack.pop();
			}
			//괄호 사이에 값이 없다면 1로 설정
			if (now_answer == 0) now_answer = 1;

			//[,(가 없거나 괄호 짝이 안맞는다면 끝
			if (sstack.empty()||now_int!=sstack.top()) {
				answer = 0;
				break;
			}
			sstack.pop();
			//괄호 안 값에 해당 괄호에 맞는 값을 곲해서 넣기
			sstack.push(now_int == -1 ? now_answer * 3: now_answer * 2);
		}
	}
	//올바른 괄호가 아니라면 바로 끝으로
	if (answer == 0) goto END;
	answer = 0;
	while (!sstack.empty()) {
		if (sstack.top() == -1 || sstack.top() == -2) {
			answer = 0;
			break;
		}
		answer += sstack.top();
		sstack.pop();
	}
	END:
	cout << answer;
	return 0;
}