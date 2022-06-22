//16114 화살표 연산자
#include<iostream>
#include<string>
using namespace std;
const string INFINITE = "INFINITE";
const string ERROR = "ERROR";

string cal(int& x, int& n) {
	if (n == 1) {		//n==1이면 단항 부정 연산자
		x = -x;
		n = 0;
	}
	if (n % 2) return ERROR;		//n은 짝수개여야함(한개면 그냥 음수 부호)
	if (x > 0 && n == 0) return INFINITE;	//x가 양수고 n이 0이면 무한
	n /= 2;		//-가 2개면 -1이므로 -가 n개면 -n/2
	x -= n;		//뺄셈이 먼저 계산된다.
	if (x <= 0) return "0";		//x가 0또는 음수면 무조건 0
	int ans = x / n;	//x/n번동안은 while이 True
	if (x % n) ans++;	//x%n이 있으면 x/n번 계산하고도 양수
	return to_string(ans);
}
int main() {
	int x, n;
	cin >> x >> n;
	
	cout << cal(x, n);
}