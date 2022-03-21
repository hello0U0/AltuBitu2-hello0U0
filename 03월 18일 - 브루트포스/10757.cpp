//10757 큰 수 A+B
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	string s1, s2;
	int next = 0;
	cin >> s1 >> s2;
	//자리수가 다르면 부족한 곳에 0을 넣어 자리수가 같게 맞춘다. 
	int sminus = s1.size() - s2.size();
	string ans(abs(sminus),'0');
	sminus > 0 ? s2 = ans + s2 : s1 = ans + s1;
	//끝자리부터 덧셈계산을 한다.
	for (int i = s1.size() - 1; i >= 0; i--) {
		int now = s1[i] - '0' + s2[i] - '0' + next;
		if (now >= 10) {
			next = 1;
			now -= 10;
		}
		else {
			next = 0;
		}
		s1[i] = now + '0';
	}

	if (next > 0) cout << next;
	cout << s1;

}
	