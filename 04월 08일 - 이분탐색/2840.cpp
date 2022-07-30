//2840 행운의 바퀴
#include<iostream>
#include<unordered_set>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	string cycle(n,'?');	//물음표로 초기화
	int i = 0;
	unordered_set<char> alpha;
	while (k--) {
		int xi;
		char xch;
		cin >> xi >> xch;

		//바퀴를 만들 수 없으면 더이상의 계산이 의미없다.
		if (i == -1) continue;
		//현재 화살표가 있는 칸
		i = (i - xi) % n;
		if (i < 0) i += n;
		//빈칸이 아니면 같은 문자여야한다.
		if (cycle[i] != '?') {
			if (cycle[i] != xch) i = -1;
			continue;
		}
		//이미 있는 알파벳이면 끝
		if (alpha.find(xch) != alpha.end()) {
			i = -1;
			continue;
		}
		cycle[i] = xch;
		alpha.insert(xch);
	}
	if (i == -1) cycle = "!";
	else cycle = cycle.substr(i, cycle.size()) + cycle.substr(0, i);
	cout << cycle;
	return 0;
}