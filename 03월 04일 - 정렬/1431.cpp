#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(const string a, string b) {
	int a_size = a.size(), b_size = b.size();
	//A와 B의 길이가 다르다면, 짧은 것이 먼저 온다
	if (a_size != b_size)	return a_size < b_size;
	//A의 모든 자리수의 합과 B의 모든 자리수의 합을 비교해서 작은 것부터 온다
	int a_count = 0, b_count = 0;
	for (int i = 0; i < a_size; i++) if (a[i] >= '0' && a[i] <= '9') a_count += a[i] - '0';
	for (int i = 0; i < b_size; i++) if (b[i] >= '0' && b[i] <= '9') b_count += b[i] - '0';
	if (a_count != b_count) return a_count < b_count;

	if(a.compare(b)>0) return false;
	return true;
}

int main() {
	int n;
	cin >> n;
	vector<string> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr.begin(), arr.end(),cmp);
	
	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}
	return 0;
}