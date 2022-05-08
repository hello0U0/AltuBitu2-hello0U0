//18111 마인크래프트
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX = 13e7 + 1;

//hight 높이일 때 걸리는 시간을 구한다.
int calTime(const vector<int>& land, const int &hight, const int &b) {
	int sum = b;
	int time = 0;
	for (int i = 0; i < land.size(); i++) {
		int now = land[i] - hight;
		sum += now;
		if (now >= 0)time += 2 * now;
		else time -= now;
	}
	if (sum < 0) return MAX;
	return time;
}

//최소 시간의 최대 높이를 구한다.
pair<int, int> calMinTime(vector<int>& land, const int& b) {
	pair<int, int> ans = { MAX,0 };	//최소시간, 최대 높이
	//땅의 높이를 정렬한다.
	sort(land.begin(), land.end());
	//낮은 높이부터 높은 높이까지 각 높이당 걸리는 시간을 구한다.
	for (int hight = land[0]; hight <=land.back(); hight++) {
		//hight 높이를 만들기 위해 걸리는 시간
		int now_time = calTime(land, hight, b);
		//최소 시간의 최대 높이를 갱신한다.
		if (ans.first >= now_time) {
			ans.first = now_time;
			ans.second = hight;
		}
	}
	return ans;
}

int main() {
	int n, m, b;
	cin >> n >> m >> b;
	vector<int> land(n * m);
	for (int i = 0; i < n * m; i++) {
		cin >> land[i];
	}
	pair<int, int> ans = calMinTime(land, b);
	cout << ans.first << " " << ans.second;
	return 0;
}