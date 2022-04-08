//7662 이중 우선순위 큐
#include<iostream>
#include<queue>
#include<map>
using namespace std;
const int MAX = 1e6 + 1;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;

	cin >> t;
	while (t--) {
		int k;
		long long n;
		char di;
		priority_queue<long long, vector<long long>, less<>> que_up;
		priority_queue<long long, vector<long long>, greater<>> que_down;
		map<int, int> ans;
		cin >> k;
		while (k--) {
			cin >> di >> n;
			//데이터 삽입
			if (di == 'I') {
				que_up.push(n);
				que_down.push(n);
				ans[n]++;
				continue;
			}//최소값 삭제
			if (n == 1) {
				int now;
				while (!que_up.empty()) {
					now = que_up.top();
					que_up.pop();
					if (ans[now] == 0) continue;
					ans[now]--;
					break;
				}
			}//최대값 삭제
			else {
				int now;
				while (!que_down.empty()) {
					now = que_down.top();
					que_down.pop();
					if (ans[now] == 0) continue;
					ans[now]--;
					break;
				}
			}
		}
		long long down, up;
		//남은 것 없애기
		while (!que_up.empty()) {
			up = que_up.top();
			if (ans[up] > 0) break;
			que_up.pop();
		}//남은 수가 없다면 비어있다.
		if (que_up.empty()) {
			cout << "EMPTY\n";
			continue;
		}
		while (!que_down.empty()) {
			down = que_down.top();
			if (ans[down] > 0) break;
			que_down.pop();
		}

		cout << up << " " << down << '\n';
	}
	return 0;
}