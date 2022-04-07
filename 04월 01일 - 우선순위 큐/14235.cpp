//14235 크리스마스선물
#include<iostream>
#include<queue>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, a;
	priority_queue<int> present;
	cin >> n;
	while (n--) {
		cin >> a;
		if (a == 0) {
			if (present.empty()) {
				cout << "-1\n";
			}
			else {
				cout << present.top() << '\n';
				present.pop();
			}
			continue;
		}
		while (a--) {
			int x;
			cin >> x;
			present.push(x);
		}

	}
	return 0;
}