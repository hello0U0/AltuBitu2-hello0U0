//11000 강의실 배정
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> times;
	priority_queue<int> lectures;
	//강의들을 늦게 끝나는 순으로 배치
	for (int i = 0; i < n; i++) {
		int s, t;
		cin >> s >> t;
		times.push_back({ t,s });	//강의 끝 시간, 시작 시간
	}
	sort(times.begin(), times.end());
	//첫 강의 넣기
	lectures.push(times[n - 1].second);
	for (int i = n - 2; i >= 0; i--) {
		//빈 강의실에 넣기
		pair<int, int> now = times[i];
		if (now.first <= lectures.top()) {
			lectures.pop();
		}
		lectures.push(now.second);
	}

	cout << lectures.size();
	return 0;
}