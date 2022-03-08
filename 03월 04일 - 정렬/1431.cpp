#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int calNum(string s, int size) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (isdigit(s[i]) > 0) count += s[i] - '0';
	}
	return count;
}
bool cmp(const string a, string b) {
	int a_size = a.size(), b_size = b.size();
	//A와 B의 길이가 다르다면, 짧은 것이 먼저 온다
	if (a_size != b_size)	return a_size < b_size;
	//A의 모든 자리수의 합과 B의 모든 자리수의 합을 비교해서 작은 것부터 온다
	int b_count = calNum(b, b_size);
	int a_count = calNum(a, a_size);
	if (b_count != a_count) return b_count > a_count;

	if (a > b) return false;
	return true;
}

int main() {
	int n;
	cin >> n;
	vector<string> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}
	return 0;
}