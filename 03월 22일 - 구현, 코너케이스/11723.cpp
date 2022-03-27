//11723 집합
#include<iostream>
#include<string>
#include<set>
#include<bitset>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	string cals;
	int m, cali;
	bitset<24> s;
	cin >> m;
	while (m--) {
		cin >> cals;
		if (cals == "all") {
			s.set();
			continue;
		}
		else if (cals == "empty") {
			s.reset();
			continue;
		}
		cin >> cali;
		if (cals == "add") {
			s[cali] = 1;
		}
		else if (cals == "remove") {
			s[cali] = 0;
		}
		else if (cals == "check") {
			cout << s[cali] << '\n';
		}
		else {
			s[cali] = !s[cali];
		}

	}
}