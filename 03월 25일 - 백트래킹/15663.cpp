//15663 N과 M (9)
#include<iostream>
#include<vector>
#include<unordered_map>

#include<algorithm>
#include<string>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m, x;
	cin >> n >> m;
	vector<int> num;
	for (int i = 0; i < n; i++) {
		cin >> x;
		num.push_back(x);
	}
	sort(num.begin(), num.end());
	do {
		for (int i = 0; i < m; i++) {
			cout << num[i]<<" ";
		}
		cout << "\n";
		sort(num.begin() + m, num.end(),greater<>());
	} while (next_permutation(num.begin(), num.end()));
}