//2580 스도쿠
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int x;
	//스도쿠 입력을 받음, 1~9가 각각 몇번 나왔는지 확인
	vector<vector<int>> sudoku(9);	//스도쿠판
	vector<int> number(10, 9);		//스도쿠의 각 숫자 수
	vector<pair<int, int>> xy;		//빈칸 위치
	vector<int> input_sudo;			//빈칸에 넣을 값
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> x;
			sudoku[i].push_back(x);
			number[x]--;
			if (x == 0) {
				xy.push_back(pair<int, int>(i, j));
			}
		}
	}
	//위에서부터 오른쪽으로 가면서 빈칸에 넣을 숫자 리스트를 뽑는다.
	for (int i = 1; i <= 9; i++) {
		while (number[i]--) {
			input_sudo.push_back(i);
		}
	}
	int i, j, pprev = 0, prev = 0;
	do {//xy위치에 input_sudo 값을 넣는다
		if (prev != 0 && pprev != input_sudo[prev - 1])prev--;
		for (i = prev; i < xy.size() - 1; i++) {
			int x = xy[i].first, y = xy[i].second, num = input_sudo[i];
			//가로줄 체크
			for (j = 0; j < 9; j++) {
				if (sudoku[x][j] == num) break;
			}
			if (j != 9) break;
			//세로줄 체크
			for (j = 0; j < 9; j++) {
				if (sudoku[j][y] == num) break;
			}
			if (j != 9) break;
			//네모칸 체크
			int xx = x - x % 3, yy = y - y % 3;
			for (j = 0; j < 9; j++) {
				if (sudoku[xx + j / 3][yy + j % 3] == num) break;
			}
			if (j != 9) break;
			sudoku[x][y] = num;
		}
		//전체 다 통과라면 멈춘다.
		if (i == xy.size() - 1) {
			sudoku[xy.back().first][xy.back().second] = input_sudo.back();
			break;
		}
		sort(input_sudo.begin() + (i + 1), input_sudo.end(), greater<>());
		prev = i;
		if(prev) pprev = input_sudo[i - 1];
	} while (next_permutation(input_sudo.begin(), input_sudo.end()));

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << sudoku[i][j] << " ";
		}
		cout << '\n';
	}
}