//17281 야구
#include<iostream>
#include<algorithm>
using namespace std;

const int pc = 9;

int cal(const vector<vector<int>>& player, const vector<int>& playernum, const int& n) {
	int nowscore = 0;				// 현재까지의 점수
	int gri = 0;					// 현재 타자의 번호
	for (int i = 0; i < n; i++) {
		int out = 3;
		int gr = 0;						// 1루수 2, 2루수 4, 3루수 8, 홈 16
		//3명이 아웃되기 전까지
		while (out > 0) {
			//현재타자결과
			int now = player[i][playernum[gri]];
			//아웃이면 체크
			if (now == 0) {
				out--;
			}
			else {//아니면 결과만큼 타자를 진행시킨다.
				gr++;
				for (int j = 0; j < now; j++) {
					gr *= 2;
					nowscore += gr / 16;	//16이면 타자가 홈으로 들어온 것이다.
					gr %= 16;
				}
			}
			gri = (gri + 1) % pc;
		}
	}
	return nowscore;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, score = 0;
	cin >> n;
	vector<vector<int>> player(n,vector<int>(pc));	// 각 선수의 결과
	vector<int> playernum(pc);		// 타자에게 선수번호 부여
	for (int i = 0; i < pc; i++) playernum[i] = i;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < pc; j++) {
			cin >> player[i][j];
		}
	}
	
	do {
		//4번타자에게 1번 선수값을 넣는다.
		swap(playernum[0], playernum[3]);

		int nowscore = cal(player, playernum, n);
		//가장 큰 점수를 구한다.
		score = max(nowscore, score);

		//다음 결과를 위해 값을 되돌린다.
		swap(playernum[0], playernum[3]);
	} while (next_permutation(playernum.begin() + 1, playernum.end()));		//4번타자(1번선수)만 남기고 타자순서를 바꾼다.

	cout << score;
	return 0;
}