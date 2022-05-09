//11559 Puyo Puyo
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int ROW = 12, COL = 6;

//뿌요들 내리기
vector<vector<char>> downPoyo(vector<vector<char>>& nowfield) {
	vector<vector<char>> newfield(ROW, vector<char>(COL, '.'));
	for (int i = 0; i < COL; i++) {
		vector<char> newpuyo;
		int j;
		//기존 필드에서 문자만 골라서
		for (j = 0; j < ROW; j++) {
			if (nowfield[j][i] != '.') newpuyo.push_back(nowfield[j][i]);
		}//새 필드에 넣는다.
		while (!newpuyo.empty()) {
			newfield[--j][i] = newpuyo.back();
			newpuyo.pop_back();
		}
	}
	return newfield;
}

//뿌요를 지운다
bool deletePoyo(vector<vector<char>>& nowfield, vector<vector<bool>> visited) {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (visited[i][j]) nowfield[i][j] = '.';
		}
	}
	return true;
}

//현재위치의 문자를 지우고 함께 지울 뿌요 위치를 chain에 기록. 지우는 뿌요 수를 반환한다.
int calBFSDelete(pair<int, int> start, const vector<vector<char>>& nowfield, vector<vector<bool>>& visited) {
	queue<pair<int, int>> que;
	vector<pair<int, int>> calnum = { {-1,0},{1,0},{0,-1},{0,1} };
	que.push(start);
	visited[start.first][start.second] = true;
	int count = 1;		//지우는 뿌요 개수
	while (!que.empty()) {
		int x = que.front().first, y = que.front().second;
		que.pop();
		//해당 뿌요의 상하좌우에 대해
		for (int i = 0; i < 4; i++) {
			int nowx = x + calnum[i].first, nowy = y + calnum[i].second;
			//필드 범위 밖이면 넘어가기
			if (nowx >= ROW || nowx < 0 || nowy >= COL || nowy < 0) continue;
			//이미 계산했으면 넘어가기
			if (visited[nowx][nowy]) continue;
			//지워야할 문자와 같은 문자면 chain에 넣는다.
			if (nowfield[nowx][nowy] == nowfield[x][y]) {
				que.push({ nowx, nowy });
				visited[nowx][nowy] = true;
				count++;
			}
		}
	}
	return count;
}

//연쇄가 몇번 일어나는지 계산
int calChainReact(vector<vector<char>>& poyo_field) {
	int chainCnt = -1;
	while (true) {
		bool is_deletepoyo = false;
		//필드를 돌면서 지울 수 있는 뿌요들은 지우기
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				//뿌요가 없으면 넘어가기
				if (poyo_field[i][j] == '.') continue;
				vector<vector<bool>> visited(ROW, vector<bool>(COL, false));			//한번에 지우는 뿌요들 위치
				//뿌요가 있으면 연쇄작용이 가능한지 체크. 지울 수 있으면 지운다.
				if (calBFSDelete({ i,j }, poyo_field, visited) >= 4) {
					is_deletepoyo = deletePoyo(poyo_field, visited);
				}
			}
		}
		//뿌요의 빈 자리를 없앤다.
		if (is_deletepoyo) {
			chainCnt++;
			poyo_field = downPoyo(poyo_field);
		}
		else break;
	}
	return chainCnt;
}


int main() {
	vector<vector<char>> poyo_field(ROW, vector<char>(COL));
	//필드 입력받기
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			cin >> poyo_field[i][j];
		}
	}
	//연산 및 출력
	cout << calChainReact(poyo_field);
}