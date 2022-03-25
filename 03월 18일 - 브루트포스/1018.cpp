//1018 체스판 다시 칠하기
#include<iostream>
#include<vector>
#include<bitset>
#include<algorithm>
using namespace std;

void calBoard(vector<bitset<52>>& wboard, const int& n, const int& m) {
	//모두 색이 번갈아가며 나올 수 있게 색을 칠하고 어느 곳에 칠했는지 표시.
	char x;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> x;
			if ((i + j) % 2 == 0 && x != 'W') wboard[i][j] = 1;
			else if ((i + j) % 2 != 0 && x == 'W') wboard[i][j] = 1;
		}
	}
	return;
}
int calChess(const vector<bitset<52>>& board, const int x, const int y) {
	int sumw = 0;
	//w로 시작하는 체스판에 색을 칠했다면 b는 안칠한다. 색을 안칠했다면 b는 칠한다.
	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			if (board[i][j] == 1) sumw++;
		}
	}
	return min(sumw, 64 - sumw);
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<bitset<52>> wboard(n);		//(0,0)이 하얀색으로 시작하는 n*m 체스보드
	//각 보드에 맞게 색칠해야하는 부분을 표시
	calBoard(wboard, n, m);

	int sum = 2500;
	//보드를 8*8로 잘랐을 때 색칠한 부분의 개수가 최소가 되게 구한다.
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			int now_sum = calChess(wboard, i, j);
			sum = min(sum, now_sum);
		}
	}
	cout << sum;
}