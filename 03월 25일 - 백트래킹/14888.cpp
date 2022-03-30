//14888 연산자 끼워넣기
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX = 1000000001;

int main() {
	int n, x;
	int maxresult = -MAX, minresult = MAX;
	cin >> n;
	vector<int> num(n), cal;			
	for (int i = 0; i < n; i++) cin >> num[i];
	for (int i = 0; i < 4; i++) {	//cal : + - * /순으로 입력
		cin >> x;
		while (x--) cal.push_back(i);
	}

	do {
		int now = num[0];
		for (int i = 0; i < cal.size(); i++) {
			if (cal[i] == 3) now = now / num[i + 1];
			else if (cal[i] == 2) now = now * num[i + 1];
			else if (cal[i] == 1) now = now - num[i + 1];
			else now = now + num[i + 1];
		}
		if (now > maxresult) maxresult = now;
		if (now < minresult) minresult = now;
	} while (next_permutation(cal.begin(), cal.end()));
	cout << maxresult << '\n' << minresult;
}	