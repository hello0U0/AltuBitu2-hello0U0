//10971 외판원 순회 2
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX = 10000001;

int main() {
	int n,x;
	cin >> n;
	vector<vector<int>> cost(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> x;
			cost[i].push_back(x);
		}
	}
	// 외판원이 순회하는 도시 순서 road
	vector<int> road(n);
	int mincost = MAX;
	for (int i = 0; i < n; i++) road[i] = i;
	//[1->2->3] [2->3->1] [3->1->2]같은 경우는 모두 같은 루트다
	//따라서 첫번째 숫자를 첫번째 도시로 고정
	 do {
		 x = 0;
		// 순회하는 도시 순서대로 계산
		for (int i = 0; i < n; i++) {
			int nowcost = (i!=n-1)?cost[road[i]][road[i+1]]: cost[road[n-1]][road[0]];
			//길이 없으면 멈추기
			if (nowcost == 0) {
				x = MAX;
				break;
			}//비용 추가
			x += nowcost;
		}
		mincost = min(mincost, x);
	} while (next_permutation(road.begin()+1, road.end()));
	cout << mincost;
}