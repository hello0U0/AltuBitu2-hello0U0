#include<iostream>
using namespace std;

int gcdR(int a, int b) {
	if (b == 0) return a;
	return gcdR(b, a % b);
}
int main() {
	int n, m, gcd;
	cin >> n;
	cin.ignore(256, ':');
	cin >> m;

	if (n > m) {
		gcd = gcdR(n, m);
		cout << n / gcd << ":" << m / gcd;
	}
	else {
		gcd = gcdR(m, n);
		cout << n / gcd << ":" << m / gcd;
	}
	return 0;
}