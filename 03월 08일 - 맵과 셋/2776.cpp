#include<iostream>
#include<unordered_set>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		unordered_set<int> note1;
		//수첩 1 입력
		cin >> n;
		while (n--) {
			cin >> m;
			note1.insert(m);
		}
		//수첩 2 입력 및 출력
		cin >> n;
		while (n--) {
			cin >> m;
			cout << (note1.find(m) != note1.end()) << '\n';
		}
	}
	return 0;
}