//19637 IF문 좀 대신 써줘
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	map<int, string> max_title;
	max_title[-1] = "";
	for (int i = 0; i < n; i++) {
		int xi;
		string xs;
		cin >> xs >> xi;
		if (max_title[xi] == "") max_title[xi] = xs;
	}
	n = max_title.size() - 1;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		cout << (*max_title.lower_bound(x)).second << '\n';
	}
	return 0;
}