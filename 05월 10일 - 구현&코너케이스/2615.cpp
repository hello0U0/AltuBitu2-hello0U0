//2615 오목
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 19;

//오목인지 체크
vector<pair<int, int>> calWin(const vector<vector<int>>& field, const int &x, const int &y) {
	vector<pair<int, int>> ans;		//오목의 위치를 저장, 왼쪽에 있는 것을 먼저 골라야하므로 계산의 편의를 위해 {y,x}형대로 저장
	vector<pair<int, int>> direct = { {0,1},{1,0},{1,-1},{1,1} };	//오른쪽, 아래, 왼쪽 아래 대각선, 오른쪽 아래 대각선 체크

	for (int i = 0; i < direct.size(); i++) {
		ans.push_back({ y,x });
		int nowx = x, nowy = y;
		//체크하려는 방향의 반대방향에 같은 돌이 있으면 패스(시작점이 아니므로 넘어간다.)
		int prevx = nowx - direct[i].first, prevy = nowy - direct[i].second;
		if (prevx >= 0 && prevx < MAX && prevy >= 0 && prevy < MAX && field[prevx][prevy] == field[x][y]) {
			ans.clear();
			continue;
		}
		while (true) {
			nowx += direct[i].first;
			nowy += direct[i].second;
			//범위를 벗어나거나 같은 돌이 아니면 멈추기
			if (nowx < 0 || nowx >= MAX || nowy < 0 || nowy >= MAX || field[nowx][nowy] != field[x][y]) break;
			ans.push_back({ nowy,nowx });
		}
		if (ans.size() == 5) break;
		//바둑독 개수가 딱 다섯개가 아니면 실패
		ans.clear();
	}
	return ans;
}

vector<int> cal(vector<vector<int>>& field) {
	vector<int> ans;
	vector<vector<int>> visited(MAX, vector<int>(MAX, 0));
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (field[i][j] == 0) continue;		//빈 곳이면 패스
			vector<pair<int, int>> nowans = calWin(field, i, j);
			if (nowans.empty()) continue;		//답이 없으면 넘어가기
			//이겼으면 제일 왼쪽, 제일 위쪽의 지점을 기록하고 끝낸다.(배열은 0번부터시작하기 때문에 1을 더한다.)
			pair<int, int> min_xy = *min_element(nowans.begin(), nowans.end());
			ans.push_back(field[i][j]);
			ans.push_back(min_xy.second + 1);
			ans.push_back(min_xy.first + 1);
			break;
		}
		if (!ans.empty()) break;
	}
	return ans;
}

int main() {
	vector<vector<int>> field(MAX, vector<int>(MAX));
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) cin >> field[i][j];
	}
	//계산
	vector<int> ans = cal(field);
	//출력
	if (ans.empty()) cout << 0;
	else cout << ans[0] << '\n' << ans[1] << " " << ans[2];
}