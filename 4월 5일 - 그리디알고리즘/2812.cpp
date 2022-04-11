//2812 크게 만들기
#include<iostream>
#include<vector>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	string ans = "";
	ans.push_back(s[0]);
	for (int i =1; i < n; i++) {//현재값보다 큰애가 나올때까지 현재값보다 작은 수는 뺀다.
		while (k!=0&&!ans.empty()) {
			//ans값이 더 크다면 멈춘다.
			if (ans.back() >= s[i]) break;
			//작다면 ans의 마지막 값을 뺀다.
			ans.pop_back();
			k--;
		}
		ans.push_back(s[i]);
	}
	while (k--) {
		ans.pop_back();
	}
	cout << ans;
	return 0;
}