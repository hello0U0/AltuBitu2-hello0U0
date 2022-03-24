//11723 집합
#include<iostream>
#include<string>
#include<set>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	string cals;
	int m, cali;
	set<int> s;
	set<int> s_all;		//all 연산 초기화 셋
	for (int i = 1; i <= 20; i++) s_all.insert(i);

	cin >> m;
	while (m--) {
		cin >> cals;
		if (cals == "all") {
			s = s_all;
			continue;
		}
		else if (cals == "empty") {
			s.clear();
			continue;
		}

		cin >> cali;
		if (cals == "add") {
			s.insert(cali);
		}
		else if (cals == "remove") {
			auto iter = s.find(cali);
			if (iter != s.end()) s.erase(iter);
		}
		else if (cals == "check") {
			cout << (s.find(cali) == s.end() ? 0 : 1) << '\n';
		}
		else if (cals == "toggle") {
			if (s.find(cali) == s.end()) s.insert(cali);
			else s.erase(cali);
		}
	}
}