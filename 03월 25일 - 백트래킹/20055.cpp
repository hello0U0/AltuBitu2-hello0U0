//20055 컨베이어 벨트 위의 로봇
#include<iostream>
#include<deque>

using namespace std;

//로봇 이동하고 내구고가 0이 됐는지 알려주기
int goRobot(deque<pair<int, bool>>& belt, const int i) {
	belt[i].first--;;
	belt[i].second = 1;
	if (belt[i].first == 0) return 1;
	return 0;
}

int main() {
	int n, k;
	int zero = 0, time = 0;
	cin >> n >> k;
	deque<pair<int, bool>> belt(2 * n);
	for (int i = 0; i < 2 * n; i++) {
		int x;
		cin >> x;
		belt[i] = pair<int, bool>(x, 0);
		if (x == 0) zero++;
	}
	while (zero < k) {
		time++;
		//1단계 - 벨트랑 로봇 한단계 앞으로,
		belt.push_front(belt.back());
		belt.pop_back();
		//맨 마지막 로봇 없애기
		if (belt[n - 1].second == 1) belt[n - 1].second = 0;
		//2단계 로봇들 뒤에서부터 로봇을 앞으로 보내기
		for (int i = n - 2; i > 0; i--) {
			//로봇이 없는 칸, 앞에 로봇이 있는 칸, 앞에 내구도가 없는 칸은 패스
			if (!belt[i].second || belt[i + 1].second || belt[i + 1].first == 0) continue;
			belt[i].second = 0;
			zero += goRobot(belt, i + 1);
		}
		//맨 마지막 로봇 없애기
		if (belt[n - 1].second == 1) belt[n - 1].second = 0;
		//3단계 - 로봇 올리기
		if (belt[0].first > 0) {
			zero += goRobot(belt, 0);
		}
	}
	cout << time;
}