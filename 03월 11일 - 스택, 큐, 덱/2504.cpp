#include<iostream>
#include<stack>
#include<string>
#include<map>
using namespace std;

int main() {
	string s;
	int answer = 1;
	stack<int> sstack;
	//대괄호는 -1, 소괄호는 -2로 설정한다.
	map<char, int> parent;
	parent[')'] = '(';
	parent[']'] = '[';
	parent['('] = -2;
	parent['['] = -1;

	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		int nowi = parent[s[i]];
		//여는괄호면 스택에 저장
		if (nowi < 0) {
			sstack.push(nowi);
			continue;
		}

		answer = 0;
		//여는 괄호가 나올때까지 값들을 더하기
		while (!sstack.empty() && sstack.top() > 0) {
			answer += sstack.top();
			sstack.pop();
		}
		//괄호 사이에 값이 없다면 1로 설정
		if (answer == 0) answer = 1;
		//[,(가 없거나 괄호 짝이 안맞는다면 끝
		if (sstack.empty() || parent[nowi] != sstack.top()) {
			answer = 0;
			break;
		}
		//괄호 안 값에 해당 괄호에 맞는 값을 곲해서 넣기
		sstack.pop();
		sstack.push((parent[nowi] + 4) * answer);
	}

	//올바른 괄호가 아니라면 0을 출력
	if (answer == 0) {
		cout << answer;
		return 0;
	}
	answer = 0;
	while (!sstack.empty()) {
		if (sstack.top() < 0) {
			answer = 0;
			break;
		}
		answer += sstack.top();
		sstack.pop();
	}
	cout << answer;
	return 0;
}