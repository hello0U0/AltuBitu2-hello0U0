//2580 스도쿠
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 9;
vector<vector<int>> sudoku(MAX, vector<int>(MAX));	//스도쿠판
vector<pair<int, int>> xy;
//값을 넣을 수 있는지 확인
bool isok_sudo(const int x, const int y, const int num) {
	int j;
	//가로줄 체크
	for (j = 0; j < MAX; j++) {
		if (sudoku[x][j] == num) return false;
	}
	if (j != MAX) return false;
	//세로줄 체크
	for (j = 0; j < MAX; j++) {
		if (sudoku[j][y] == num) return false;
	}
	if (j != MAX) return false;
	//네모칸 체크
	int xx = x - x % 3, yy = y - y % 3;
	for (j = 0; j < MAX; j++) {
		if (sudoku[xx + j / 3][yy + j % 3] == num) return false;
	}
	if (j != MAX) return false;
	return true;
}
bool cal(int time) {
	if (time == xy.size()) return true;
	for (int i = 1; i <= MAX; i++) {
		int x = xy[time].first, y = xy[time].second;
		if (!isok_sudo(x, y, i)) continue;
		sudoku[x][y] = i;
		if (cal(time + 1)) return true;
		sudoku[x][y] = 0;
	}
	return false;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int x;
	//스도쿠 입력을 받음, 빈칸 위치 기억
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> x;
			sudoku[i][j] = x;
			if (x == 0) {
				xy.push_back(pair<int, int>(i, j));
			}
		}
	}
	cal(0);
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cout << sudoku[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}