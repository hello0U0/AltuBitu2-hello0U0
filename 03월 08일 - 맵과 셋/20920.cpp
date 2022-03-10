#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
	if (a.second != b.second) return a.second > b.second;
	if (a.first.size() != b.first.size())return a.first.size() > b.first.size();
	return a.first < b.first;
}

int main() {
	int n, m;
	cin >> n >> m;
	map<string, int> voca_count;	//단어와 각 단어가 등장한 횟수
	vector<pair<string, int>> voca;			//단어장
	while (n--) {
		string s;
		cin >> s;
		//m보다 작은 길이는 넘어간다.
		if (s.size() < m) continue;
		//단어와 단어가 나온 개수를 저장한다.
		voca_count[s]++;
	}
	//단어장에 저장한다.
	for (auto iter : voca_count) {
		voca.push_back(pair<string, int>(iter.first, iter.second));
	}
	//단어장을 정렬한다.
	sort(voca.begin(), voca.end(), cmp);

	for (auto iter : voca) {
		cout << iter.first << '\n';
	}
}