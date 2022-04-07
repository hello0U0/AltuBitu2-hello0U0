//13975 파일합치기 3
#include<iostream>
#include<queue>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> k;
		priority_queue<long long,vector<long long>,greater<>> min_q;
		for (int i = 0; i < k; i++) {
			int x;
			cin >> x;
			min_q.push(x);
		}
		long long ans = 0;
		while (--k>0) {//작은 것끼리 합치기
			long long a = min_q.top();
			min_q.pop();
			a += min_q.top();
			min_q.pop();
			ans += a;
			min_q.push(a);
		}
		cout << ans << "\n";
	}
}