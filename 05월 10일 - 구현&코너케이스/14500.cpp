//14500 테르로미노
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//일자계산
int calline(const vector<vector<int>>& field, const int a, const int b) {
	//4*1 윈도우를 씌운다.
	int max_sum = 0;
	for (int i = 0; i < a - 3; i++) {
		for (int j = 0; j < b; j++) {
			int sum = 0;
			for (int k = 0; k < 4; k++) sum += field[i + k][j];
			max_sum = max(sum, max_sum);
		}
	}
	return max_sum;
}
//정사각형 계산
int calRect(const vector<vector<int>>& field, const int a, const int b) {
	//2*2 정사각형의 윈도우를 씌운다.
	int max_sum = 0;
	for (int i = 0; i < a - 2; i++) {
		for (int j = 0; j < b - 2; j++) {
			int sum = field[i][j] + field[i + 1][j] + field[i][j + 1] + field[i + 1][j + 1];
			max_sum = max(sum, max_sum);
		}
	}
	return max_sum;
}
//나머지 계산
int calETC(const vector<vector<int>>& field, const int a, const int b) {
	int max_sum = 0;
	vector<vector<pair<int, int>>> direct = { {{0,0},{1,0}},{{0,1},{1,1}},{{1,0},{2,0}},{{1,1},{2,1}},{{0,0},{2,1}},{{0,1},{2,0}},{{0,0},{2,0}},{{0,1},{2,1}} };
	//3*2칸의 네모 윈도우를 씌워 합을 구하고 그 안에서 2개의 정사각형 값을 뺀다.
	for (int i = 0; i < a - 2; i++) {
		for (int j = 0; j < b - 1; j++) {
			int sum = 0;
			for (int x = 0; x < 3; x++) {
				for (int y = 0; y < 2; y++) sum += field[i + x][j + y];
			}
			for (int k = 0; k < 8; k++) {
				int now_diff = field[i + direct[k][0].first][j + direct[k][0].second] + field[i + direct[k][1].first][j + direct[k][1].second];
				max_sum = max(sum - now_diff, max_sum);
			}
		}
	}
	return max_sum;
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> field(n, vector<int>(m));	//세로로 긴 사각형의 윈도우를 씌우기 위함
	vector<vector<int>> field2(m, vector<int>(n));	//가로로 긴 사각형의 윈도우를 씌우기 위함
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> field[i][j];
			field2[j][i] = field[i][j];
		}
	}
	int max_sum = 0;
	max_sum = max(max_sum, calline(field, n, m));
	max_sum = max(max_sum, calline(field2, m, n));
	max_sum = max(max_sum, calRect(field, n, m));
	max_sum = max(max_sum, calETC(field, n, m));
	max_sum = max(max_sum, calETC(field2, m, n));
	cout << max_sum;
}
//