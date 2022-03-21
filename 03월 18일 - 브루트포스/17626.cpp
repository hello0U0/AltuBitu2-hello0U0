//17626 Four squares
#include<iostream>
#include<cmath>
#define MAX_TIME 4
using namespace std;

int calCount(int n, int time) {
	//가능한 경우를 찾았으면 횟수를 리턴
	if (n == 0) return time;
	//4개 이상의 제곱수가 필요하다면 5를 리턴
	if (time == MAX_TIME) return MAX_TIME + 1;
	int min = MAX_TIME + 1;
	for (int i = (int)sqrt(n); i > 0; i--) {
		//남은 횟수동안 해당 제곱수가 들어간다 해도 n을 맞추지 못하면 멈춘다.
		if (i * i * (MAX_TIME - time) < n) break;
		int nowmin=calCount(n-i*i, time + 1);
		if (min > nowmin) min = nowmin;
	}
	return min;
}

int main() {
	int n;
	cin >> n;
	int min = calCount(n, 0);
	cout << min;
}