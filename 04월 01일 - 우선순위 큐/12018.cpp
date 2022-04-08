//12018 Yonsei TOTO
#include<iostream>
#include<queue>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	priority_queue<int,vector<int>,greater<>> sung;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int p, l, x;
		cin >> p >> l;
		priority_queue<int> now;
		while (p--) {
			cin >> x;
			now.push(x);
		}
		while (l-->1&&!now.empty()) {
			now.pop();
		}
		int now_sung = now.empty() ? 1 : now.top();
		sung.push(now_sung);
	}
	int ans = 0, i;
	for (i = 1; i <= n; i++) {
		ans += sung.top();
		sung.pop();
		if (ans > m) break;
	}
	i--;
	cout << i;
	return 0;
}