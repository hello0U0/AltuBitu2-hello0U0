//11000 강의실 배정
#include<iostream>
#include<queue>
using namespace std;

int main() {
	int n;
	cin >> n;
	priority_queue<pair<int, int>> times;
	priority_queue<int> lectures;
	//강의들을 늦게 끝나는 순으로 배치
	for (int i = 0; i < n; i++) {
		int s, t;
		cin >> s >> t;
		times.push({t,s});	//강의 끝 시간, 시작 시간
	}
	//첫 강의 넣기
	lectures.push(times.top().second);
	times.pop();
	while (!times.empty()) {
		//빈 강의실에 넣기
		pair<int,int> now = times.top();
		times.pop();
		if (now.first <= lectures.top()) {
			lectures.pop();
		}
		lectures.push(now.second);
	}

	cout << lectures.size();
	return 0;
}