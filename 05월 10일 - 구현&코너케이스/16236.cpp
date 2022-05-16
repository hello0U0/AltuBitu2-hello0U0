//16236 아기 상어
#include<iostream>
#include<queue>
#include<cmath>
#include<tuple>
using namespace std;
typedef pair<int, int> ci;
typedef tuple<int, int, int> ti;

int bfs(const int& n, vector<vector<int>>& field, ti& babyshark) {
	vector<ci> dir = { {-1,0},{0,-1},{0,1},{1,0} };			//상하좌우 방향벡터
	vector<vector<bool>> visited(n, vector<bool>(n, 0));	//방문 기록
	priority_queue<ti, vector<ti>, greater<>> find;			//시간이 작을수록, row가 작을수록, col이 작을수록 먼저 계산한다.
	int shark = get<0>(babyshark), x = get<1>(babyshark), y = get<2>(babyshark);
	int now = 0;											//물고기를 먹기위해 이동한 수
	int cnt = 0;
	//초기화. 아기상어 위치부터 탐색	
	find.push({ now,x,y });
	while (!find.empty()) {
		now = get<0>(find.top());
		x = get<1>(find.top());
		y = get<2>(find.top());
		find.pop();
		if (visited[x][y] == 1) continue;
		visited[x][y] = 1;
		//먹을 수 있는 물고기면 물고기를 먹고 끝낸다.
		if (field[x][y] > 0 && field[x][y] < shark) {
			cnt = now;
			field[x][y] = 0;
			babyshark = { shark, x,y };
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nowx = x + dir[i].first;
			int nowy = y + dir[i].second;
			//범위 밖이면 넘어간다.이미 방문했으면 넘어간다.
			if (nowx < 0 || nowx >= n || nowy < 0 || nowy >= n || visited[nowx][nowy] == 1) continue;
			//큰 물고기면 그 다음은 못지나간다.
			if (field[nowx][nowy] > shark) continue;
			//같은 사이즈의 물고기거나 빈 칸이라면 지나간다.
			find.push({ now + 1,nowx,nowy });
		}
		now = 0;
	}
	return cnt;
}

int countFish(const int& n, vector<vector<int>>& field, ti& babyshark) {
	int ans = 0;		//이동한 시간
	int eat = 0;		//먹은 물고기수
	while (true) {
		//물고기를 먹기 위해 이동한 시간을 구한다. 0이면 먹을 물고기가 없다는 것
		int cnt = bfs(n, field, babyshark);
		if (cnt == 0) break;
		ans += cnt;
		eat++;
		//먹은 물고기 수가 상어 사이즈와 같다면 상어 사이즈를 키운다.
		if (get<0>(babyshark) == eat) {
			get<0>(babyshark)++;
			eat = 0;
		}
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> field(n, vector<int>(n));		//필드
	ti babyshark;							//아기상어 위치
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> field[i][j];
			if (field[i][j] == 9) {			//9는 아기상어를 의미,
				babyshark = { 2,i,j };		//아기상어의 크기, 위치를 기록
				field[i][j] = 0;
			}
		}
	}

	cout << countFish(n, field, babyshark);
}