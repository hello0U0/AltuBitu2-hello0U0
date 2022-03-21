#include<iostream>
#include<cmath>
using namespace std;

int calgcd(const int& a, const int& b) {
	if (b == 0) return a;
	return calgcd(b, a % b);
}
int main() {
	int gcd, lcm, a, b;
	cin >> gcd >> lcm;
	//a*gcd와 b*gcd 두 수를 구한다고 하면 a*b=multi이고 a와 b는 서로소이다.
	int multi = lcm / gcd;
	//a<b라면 a는 루트multi보다 작은 수이다.
	for (a = (int)sqrt(multi); a > 0; a--) {
		//a*b!=multi이면 넘어간다.
		if (multi % a != 0) continue;
		b = multi / a;
		//서로소가 아니면 넘어간다.
		if (calgcd(b, a) != 1) continue;
		break;
	}
	cout << a * gcd << " " << b * gcd;
}