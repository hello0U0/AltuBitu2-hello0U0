//13305 주유소
#include<iostream>
#include<queue>
using namespace std;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, x;
	cin >> n;
	long long money = 0;
	int town = n - 1;	//차의 위치
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<>> oil;
	int *load = new int[n-1];
	//도시거리
	for (int i = 0; i < n - 1; i++) {
		cin >> load[i];
	}
	//기름값
	for (int i = 0; i < n; i++) {
		cin >> x;
		oil.push(pair<int, int>(x, i));	//기름값,도시
	}
	//기름값이 작은 것부터
	while (!oil.empty()) {
		pair<int, int> now = oil.top();
		oil.pop();
		//이미 계산된 도시면 넘어가기
		if (now.second >= town) continue;
		long long nowmoney = 0;
		// 현재 기름값의 도시부터 계산이 되지 않은 도시까지의 도로길이 * 기름값
		for (int i = now.second; i < town; i++) {
			nowmoney += load[i];
		}
		nowmoney *= now.first;
		//비용을 계산한다.
		money += nowmoney;
		town = now.second;
		//시작지점까지 갔으면 멈추기
		if (town == 0) break;
	}
	cout << money;
	return 0;
}