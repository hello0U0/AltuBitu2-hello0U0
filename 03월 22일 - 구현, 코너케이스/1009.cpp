//1009 분산처리
#include<iostream>
using namespace std;

//곱셈 계산, 10의 배수는 의미없는 부분이므로 빼기
int cal(int a, int b) {
	a *= b;
	a %= 10;
	return a;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int a, b, etc = 1;
		cin >> a >> b;
		//10의 배수부분은 어떻게 계산해도 10의 배수이므로 의미 없음
		a %= 10;
		while (b>1) {
			// 제곱을 할 수 없는 것은 따로 계산
			if (b % 2 == 1) {
				etc = cal(etc, a);
				b--;
			}
			//a를 제곱하고 b를 절반으로 줄이기
			a = cal(a, a);
			b = b / 2;
			//a가 1이나 0이면 몇번 계산해도 1과 0
			if (a <= 1) break;
		}
		//나머지 계산
		a = cal(a, etc);
		//0은 10번 컴퓨터를 의미
		if (a == 0) a = 10;
		cout << a <<'\n';
	}
	return 0;
}