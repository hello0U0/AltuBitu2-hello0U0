#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	long long max = 0;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr.begin(), arr.end(),greater<>());
	
	for (int i = 0; i < n; i++) {
		int tip = arr[i] - i;
		if (tip < 0)tip = 0;
		max += tip;
	}

	cout << max;
	return 0;
}