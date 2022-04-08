//5397 키로거
#include<iostream>
#include<vector>
#include<string>
#include<deque>
using namespace std;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		deque<char> first;
		deque<char> second;
		string n;
		cin >> n;
		for (int l = 0; l < n.size(); l++) {
			char now = n[l];
			switch (now) {
			case '-':
				if (first.empty()) break;
				first.pop_back();
				break;
			case '>':
				if (second.empty()) break;
				first.push_back(second.front());
				second.pop_front();
				break;
			case '<':
				if (first.empty()) break;
				second.push_front(first.back());
				first.pop_back();
				break;
			default:
				first.push_back(now);
				break;
			}
		}
		while (!first.empty()) {
			cout << first.front();
			first.pop_front();
		}
		while (!second.empty()) {
			cout << second.front();
			second.pop_front();
		}
		cout << '\n';
	}
	return 0;
}