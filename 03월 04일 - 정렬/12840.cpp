#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int h, m, s, q, t, c, clock;
	cin >> h >> m >> s >> q;
	//초단위 시간으로 변경
	clock = h * 3600 + m * 60 + s;

	for (int i = 0; i < q; i++) {
		cin>>t;
		switch (t) {
		case 1:
			cin >> c;
			clock += c;
			if (clock >= 86400) clock %= 86400;
			break;
		case 2:
			cin >> c;
			clock -= c;
			if (clock <= -86400) clock%= 86400;
			if (clock < 0) clock += 86400;
			break;
		default:
			h = clock / 3600;
			m = (clock % 3600) / 60;
			s = clock % 60;
			cout << h << " " << m << " " << s << "\n";
			break;
		}
	}

	return 0;
}