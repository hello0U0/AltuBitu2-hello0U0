#include<iostream>
#include<vector>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//1~1000000까지 소수인지 판단
	vector<bool> prime(1000001, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i <= 1000; i++) {
		if (!prime[i]) continue;
		for (int j = i * i; j <= 1000000; j += i) {
			if (prime[j]) prime[j] = false;
		}
	}

	while (1) {
		int n, result;
		cin >> n;
		if (n == 0) break;
		//오름차순으로 어떤 수 result와 n-result가 소수인지 판단.
		for (result = 2; result <= n / 2; result++) {
			if (prime[result] && prime[n - result]) break;
		}
		//두 소수를 찾으면 출력 소수가 없으면 없다고 출력
		if (result == n / 2 + 1) cout << "Goldbach's conjecture is wrong.\n";
		else cout << n << " = " << result << " + " << n - result << '\n';
	}
	return 0;
}