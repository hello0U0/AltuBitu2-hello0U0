//19636 요요 시뮬레이션
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main() {
	int w0, l0, t, d, l, a;
	string ans="";
	cin >> w0 >> l0 >> t >> d >> l >> a;
	//첫째줄 출력
	long long wd = w0 + d * (l - l0 - a);		//d일 후 체중
	ans += (wd <= 0) ? "Danger Diet\n" : to_string(wd) + " " + to_string(l0) + "\n";
	cout << ans;
	ans = "";
	//둘째줄 출력
	wd = w0;		//일일 체중
	int ld = l0;	//일일 기초대사량
	while(d--) {
		int change_w = l - (ld + a);
		//체중변화
		wd = wd + change_w;
		//기초대사량 변화
		if (change_w < -t) {
			//음수 나눗셈 계산 맞추기
			change_w --;
			ld = ld + change_w / 2;
		}
		//사망조건
		if (wd <= 0 || ld <= 0) break;
	}
	//사망이면
	if (wd <= 0 || ld <= 0) {
		ans += "Danger Diet";
		cout << ans;
		return 0;
	}
	//요요 체크
	ans += to_string(wd) + " " + to_string(ld) + " ";
	ans += (l0 > ld) ? "YOYO" : "NO";
	cout << ans;
	return 0;
}