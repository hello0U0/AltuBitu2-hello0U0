//12100 2048
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
//최대 수 계산
int findMaxNum(const vector<vector<int>>& field, const int& n) {
	int max_num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			max_num = max(max_num, field[i][j]);
		}
	}
	return max_num;
}
//좌표가 필드 범위 안에 있는지 체크
bool check(const int &now, const int &n) {
	if (now < 0 || now >= n) return false;
	return true;
}
//위로 올리기
void goUp(vector<vector<int>> &field,const int &n) {
	//맨 윗줄 전체에 대해
	for (int i = 0; i < n; i++) {
		queue<int> result;
		int prevx = 0;	//밀었을 때 붙는 윗쪽 수
		int nextx = 1;	//밀었을 때 붙는 아래쪽 수
		//두 수를 합치기 계산
		while (check(nextx, n)) {	//인덱스 범위 내에서 계산. next는 무조건 prev보다 앞선다.
			if (field[nextx][i] == 0) {	//next값이 없으면 next를 높임
				nextx++;
				continue;
			}
			if (field[prevx][i] == 0) {	//prev값이 없으면 prev를 높임
				prevx++;
				continue;
			}
			if (prevx == nextx) {	//prev와 next가 만나면 next를 높임
				nextx++;
				continue;
			}//prev와 next에 자리가 있다.
			//다르면 prev 저장, next부터 다시 체크
			if (field[prevx][i] != field[nextx][i]) {
				result.push(field[prevx][i]);
				prevx = nextx;
				nextx++;
			}
			else {//합칠 수 있으면 합치고 값 저장, 그 다음블록부터 다시 체크
				result.push(field[prevx][i] + field[nextx][i]);
				prevx = nextx + 1;
				nextx += 2;
			}
		}
		//prev값이 존재하면 prev를 저장
		if (check(prevx,n) && field[prevx][i] > 0) result.push(field[prevx][i]);

		//field에 저장
		int xi = 0;
		while (!result.empty()) {
			field[xi++][i] = result.front();
			result.pop();
		}
		while (xi < n) {
			field[xi++][i] = 0;
		}
	}
	return;
}
//아래로 내리기
void goDown(vector<vector<int>>& field, const int& n) {
	//맨 아래줄 전체에 대해
	for (int i = 0; i < n; i++) {
		queue<int> result;
		int prevx = n-1;	//밀었을 때 붙는 아래쪽 수
		int nextx = n-2;	//밀었을 때 붙는 윗쪽 수
		//두 수를 합치기 계산
		while (check(nextx, n)) {	//인덱스 범위 내에서 계산. next는 무조건 prev보다 앞선다.
			if (field[nextx][i] == 0) {	//next값이 없으면 next를 다음칸으로
				nextx--;
				continue;
			}
			if (field[prevx][i] == 0) {	//prev값이 없으면 prev를 다음칸으로
				prevx--;
				continue;
			}
			if (prevx == nextx) {	//prev와 next가 만나면 next를 다음칸으로
				nextx--;
				continue;
			}//prev와 next에 값이 있다.
			//다르면 prev 저장, next부터 다시 체크
			if (field[prevx][i] != field[nextx][i]) {
				result.push(field[prevx][i]);
				prevx = nextx;
				nextx--;
			}
			else {//합칠 수 있으면 합치고 값 저장, 그 다음블록부터 다시 체크
				result.push(field[prevx][i] + field[nextx][i]);
				prevx = nextx - 1;
				nextx -= 2;
			}
		}
		//prev값이 존재하면 prev를 저장
		if (check(prevx, n) && field[prevx][i] > 0) result.push(field[prevx][i]);

		//field에 저장
		int xi = n-1;
		while (!result.empty()) {
			field[xi--][i] = result.front();
			result.pop();
		}
		while (xi >= 0) {
			field[xi--][i] = 0;

		}
	}
	return;
}
//왼쪽으로 밀기
void goLeft(vector<vector<int>>& field, const int& n) {
	//맨 윗줄 전체에 대해
	for (int i = 0; i < n; i++) {
		queue<int> result;
		int prevx = 0;	//밀었을 때 붙는 왼쪽
		int nextx = 1;	//밀었을 때 붙는 오른쪽 수
		//두 수를 합치기 계산
		while (check(nextx, n)) {	//인덱스 범위 내에서 계산. next는 무조건 prev보다 앞선다.
			if (field[i][nextx] == 0) {	//next값이 없으면 next를 높임
				nextx++;
				continue;
			}
			if (field[i][prevx] == 0) {	//prev값이 없으면 prev를 높임
				prevx++;
				continue;
			}
			if (prevx == nextx) {	//prev와 next가 만나면 next를 높임
				nextx++;
				continue;
			}//prev와 next에 자리가 있다.
			//다르면 prev 저장, next부터 다시 체크
			if (field[i][prevx] != field[i][nextx]) {
				result.push(field[i][prevx]);
				prevx = nextx;
				nextx++;
			}
			else {//합칠 수 있으면 합치고 값 저장, 그 다음블록부터 다시 체크
				result.push(field[i][prevx] + field[i][nextx]);
				prevx = nextx + 1;
				nextx += 2;
			}
		}
		//prev값이 존재하면 prev를 저장
		if (check(prevx, n) && field[i][prevx] > 0) result.push(field[i][prevx]);

		//field에 저장
		int yi = 0;
		while (!result.empty()) {
			field[i][yi++] = result.front();
			result.pop();
		}
		while (yi < n) {
			field[i][yi++] = 0;
		}
	}
	return;
}
//오른쪽으로 밀기
void goRight(vector<vector<int>>& field, const int& n) {
	//오른쪽 줄 전체에 대해
	for (int i = 0; i < n; i++) {
		queue<int> result;
		int prevx = n-1;	//밀었을 때 붙는 오른쪽 인덱스
		int nextx = n-2;	//밀었을 때 붙는 왼쪽 인덱스
		//두 수를 합치기 계산
		while (check(nextx, n)) {	//인덱스 범위 내에서 계산. next는 무조건 prev보다 앞선다.
			if (field[i][nextx] == 0) {	//next값이 없으면 next를 높임
				nextx--;
				continue;
			}
			if (field[i][prevx] == 0) {	//prev값이 없으면 prev를 높임
				prevx--;
				continue;
			}
			if (prevx == nextx) {	//prev와 next가 만나면 next를 높임
				nextx--;
				continue;
			}//prev와 next에 자리가 있다.
			//다르면 prev 저장, next부터 다시 체크
			if (field[i][prevx] != field[i][nextx]) {
				result.push(field[i][prevx]);
				prevx = nextx;
				nextx--;
			}
			else {//합칠 수 있으면 합치고 값 저장, 그 다음블록부터 다시 체크
				result.push(field[i][prevx] + field[i][nextx]);
				prevx = nextx - 1;
				nextx -= 2;
			}
		}
		//prev값이 존재하면 prev를 저장
		if (check(prevx, n) && field[i][prevx] > 0) result.push(field[i][prevx]);

		//field에 저장
		int yi = n-1;
		while (!result.empty()) {
			field[i][yi--] = result.front();
			result.pop();
		}
		while (yi >= 0) {
			field[i][yi--] = 0;
		}
	}
	return;
}
//2048 계산
int cal2048(int time,int dir, vector<vector<int>> field, const int &n) {
	int max_num = 0;
	//처음 계산
	if (time == 0) {
		for (int i = 0; i < 4; i++) {
			int now = cal2048(time + 1, i, field, n);
			max_num = max(now, max_num);
		}
		return max_num;
	}
	//이동 계산
	if (dir == 0) goUp(field, n);
	else if (dir == 1) goDown(field, n);
	else if (dir == 2) goLeft(field, n);
	else goRight(field, n);
	//5번 다하면 끝
	if (time == 5) {
		//최대 수 계산
		max_num=findMaxNum(field, n);
		return max_num;
	}
	//아니면 다음 계산
	for (int i = 0; i < 4; i++) {
		int now = cal2048(time + 1, i, field, n);
		max_num = max(now, max_num);
	}
	return max_num;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> field(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> field[i][j];
		}
	}
	cout<<cal2048(0, 0, field, n);
	return 0;
}