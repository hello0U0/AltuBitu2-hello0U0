#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int calMid(map<int, int> nmap, const int n) {
	int mid=0;
	int n_mid = n / 2 + 1;
	for (auto iter : nmap) {
		if (mid < n_mid && n_mid <= mid + iter.second) {
			mid = iter.first;
			break;
		}
		mid += iter.second;
	}
	return mid;
}
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	return a.second != b.second ? a.second > b.second:a.first < b.first;
}
int calMax(map<int, int> &nmap) {
	vector<pair<int, int>> nvector(nmap.begin(), nmap.end());
	sort(nvector.begin(), nvector.end(), cmp);
	return nvector[0].second==nvector[1].second?nvector[1].first:nvector[0].first;
}
int main() {
	int n;
	int avg = 0,mid=0, max=0, scope;
	map<int, int> nmap;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		nmap[x]++;
		avg += x;
	}

	if (n == 1) {//값이 한개일 때,
		cout << avg << '\n' << avg << '\n' << avg << "\n0";
		return 0;
	}
	//산술평균 구하기
	avg = (avg + avg % n) / n;
	//중앙값 구하기
	mid=calMid(nmap, n);
	//최빈값 구하기
	max = calMax(nmap);
	//범위 구하기
	scope = (*nmap.rbegin()).first - (*nmap.begin()).first;

	cout << avg << '\n' << mid << '\n' << max<< '\n' << scope;
}