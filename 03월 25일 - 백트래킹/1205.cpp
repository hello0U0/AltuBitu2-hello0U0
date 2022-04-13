#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX = 2e9 + 1;

int main() {
	int n, ts, p;
	cin >> n >> ts >> p;
	vector<int> score(n+1);
	score[0] = MAX;
	for (int i = 1; i < n+1; i++) {
		cin >> score[i];
	}
	//점수를 내림차순으로 정렬한다.
	sort(score.begin(), score.end(), greater<>());
	//점수가 순위 밖이면 -1을 출력
	if (p <= n && score[p] >= ts) {
		cout << "-1\n";
		return 0;
	}
	//앞에서부터 순위를 파악한다.
	int ans = 0;
	for (ans = 1; ans <= p; ans++) {
		//맨 마지막 점수보다 낮으면 끝
		if (ans >= score.size()) break;
		//순위 파악
		if (score[ans - 1] > ts && ts >= score[ans]) break;
	}
	cout << (ans > p ? -1 : ans) << '\n';
}