#include<iostream>
#include<stack>
#include<string>

using namespace std;

char topPop(stack<char> &cal) {		//스택에서 값을 뺀다.
	char ans=cal.top();
	cal.pop();
	return ans;
}

int main() {
	string s;
	string answer = "";
	stack<char> cal;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		char now = s[i];

		switch (now) {
		case '+': case '-':
			while (!cal.empty() && cal.top() != '(') {
				answer += topPop(cal);
			}
			cal.push(now);
			break;
		case '*': case '/':
			while (!cal.empty()&&(cal.top()=='*' || cal.top() == '/')){
				answer += topPop(cal);
			}
			cal.push(now);
			break;
		case '(':
			cal.push(now);
			break;
		case ')':
			while (cal.top() != '(') {
				answer += topPop(cal);
			}
			cal.pop();
			break;
		default:
			answer += now;
			break;
		}
	}
	//스택에 남아있는 사칙연산을 더한다.
	while (!cal.empty()) {
		answer += topPop(cal);
	}
	cout << answer;
}