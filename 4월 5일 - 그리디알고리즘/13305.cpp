//13305 주유소
#include<iostream>
using namespace std;

const int OILMAX = 1e9 + 1;

int main() {
	int n, x;
	cin >> n;
	long long money = 0;
	int* load = new int[n - 1];
	long long min_oil = OILMAX;
	//도시거리
	for (int i = 0; i < n - 1; i++) {
		cin >> load[i];
	}
	//기름값
	for (int i = 0; i < n - 1; i++) {
		cin >> x;
		//가장 작은 기름값 선택
		if (min_oil > x) min_oil = x;
		money += load[i] * min_oil;
	}
	cin >> x;
	cout << money;
	return 0;
}