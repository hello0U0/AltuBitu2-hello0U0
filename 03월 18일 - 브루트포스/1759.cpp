//1759 암호만들기
#include<iostream>
#include<set>
#include<unordered_map>
#include<string>
using namespace std;
string ans;
unordered_map<char, bool> vowmap;
set<char> alpha;

void cal(int l, set<char>::iterator alpha_i) {
	if (l == 0) {//4개를 다 골랐으면
		int vow_count = 0;
		//모음 개수를 센다
		for (auto iter : ans) {
			vow_count += vowmap[iter];
		}//모음이 최소 1개이상 자음이 최소 2개 이상 필요하다.
		if (vow_count < 1) return;
		if (ans.size() - vow_count < 2) return;
		cout << ans << '\n';
		return;
	}
	//사전순으로 알파벳을 하나씩 골라 추가한다.
	for (auto iter = alpha_i; iter != alpha.end(); iter++) {
		ans += *iter;
		cal(l - 1, next(iter, 1));
		ans.pop_back();
	}
	return;
}

int main() {
	int l, c;
	ans = "";
	vowmap['a'] = vowmap['e'] = vowmap['i'] = vowmap['o'] = vowmap['u'] = 1;
	cin >> l >> c;
	while (c--) {
		char x;
		cin >> x;
		alpha.insert(x);
	}
	//알파벳을 골라 조건에 맞는지 검사한다.
	cal(l, alpha.begin());
	return 0;
}