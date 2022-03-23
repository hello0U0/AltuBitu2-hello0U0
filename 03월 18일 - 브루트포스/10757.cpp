//10757 큰 수 A+B
#include<iostream>
#include<string>
using namespace std;

int main() {
	string s1, s2, ans = "";
	int next = 0;
	cin >> s1 >> s2;
	//끝자리부터 덧셈계산을 한다.
	while (!s1.empty() || !s2.empty()) {
		char now = (!s1.empty() ? (s1.back() - '0') : 0) + (!s2.empty() ? (s2.back() - '0') : 0) + next;
		if (now >= 10) {
			next = 1;
			now -= 10;
		}
		else {
			next = 0;
		}
		now += '0';
		ans = now + ans;
		if (!s1.empty()) s1.pop_back();
		if (!s2.empty()) s2.pop_back();
	}

	if (next > 0) cout << next;
	cout << ans;

}
