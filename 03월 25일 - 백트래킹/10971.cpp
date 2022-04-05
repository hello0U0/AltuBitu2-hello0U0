//10971 외판원 순회 2
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 1e7 + 1;
vector< vector<int> > cost;
vector<bool> use;
int n, min_cost;
int nowallcost;

int baTr(int time, int prev_town) {
	int prevtown = prev_town;
	if (time == n) {
		if (cost[prevtown][0] == 0) return MAX;
		return nowallcost + cost[prevtown][0];
	}
	for (int i = 1; i < n; i++) {
		//이미 간 곳이나 가지 못하는 곳이면 넘어간다.
		if (use[i] || cost[prevtown][i] == 0) continue;
		int nowcost = cost[prevtown][i];
		use[i] = 1;
		nowallcost += nowcost;
		prevtown = i;
		min_cost = min(baTr(time + 1, prevtown), min_cost);
		use[i] = 0;
		nowallcost -= nowcost;
		prevtown = prev_town;
	}
	return min_cost;
}


int main() {
	cin >> n;
	cost.assign(n, vector<int>(n));
	use.resize(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cost[i][j];
		}
	}
	//0번부터 시작
	min_cost = MAX;
	nowallcost = 0;
	use[0] = 1;
	cout << baTr(1, 0);
}