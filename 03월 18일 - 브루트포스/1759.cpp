//1759 암호만들기
#include<iostream>
#include<set>
#include<string>
using namespace std;

void cal(string& ans, int l, const char* vow, set<char>::iterator alpha_i, const set<char>& alpha) {
	if (l == 0) {//4개를 다 골랐으면
		int vow_count = 0;
		//모음 개수를 센다
		for (int i = 0; i < 5; i++) {
			size_t found = ans.find(vow[i]);
			if (found != string::npos) {
				vow_count++;
			}
		}//모음이 최소 1개이상 자음이 최소 2개 이상 필요하다.
		if (vow_count < 1) return;
		if (ans.size() - vow_count < 2) return;
		cout << ans << '\n';
		return;
	}
	//사전순으로 알파벳을 하나씩 골라 추가한다.
	for (auto iter = alpha_i; iter != alpha.end(); iter++) {
		ans += *iter;
		cal(ans, l - 1, vow, next(iter, 1), alpha);
		ans.pop_back();
	}
	return;
}

int main() {
	int l, c;
	set<char> alpha;
	string ans = "";
	char vow[] = { 'a','e','i','o','u' };
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		char x;
		cin >> x;
		alpha.insert(x);
	}
	//알파벳을 골라 조건에 맞는지 검사한다.
	cal(ans, l, vow, alpha.begin(), alpha);
	return 0;
}