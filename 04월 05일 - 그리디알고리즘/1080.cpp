//1080 행렬
#include<iostream>
#include<vector>
using namespace std;

int reverse(vector<vector<bool>> &arr,int x,int y) {
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			arr[i][j] = !arr[i][j];
		}
	}
	return 1;
}
int isSame(vector<vector<bool>>& arr, const int& n, const int& m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j]) {
				return -1;
			}
		}
	}
	return 0;
}
int cal(vector<vector<bool>>& arr, const int &n, const int &m) {
	int time = 0;
	//왼쪽 위부터 3*3의 왼쪽위가 바꿔야 하면 뒤집기
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (arr[i][j]) {
				time += reverse(arr, i, j);
			}
		}//마지막 두개 중 값이 다른 것이 있다면 가능성이 없다.
		if (arr[i][m - 2] || arr[i][m - 1]) return -1;
	}//마지막 두줄도 체크해서 맞지 않는 숫자가 있으면 가능성이 없다.
	for (int i = n - 2; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j]) return -1;
		}
	}
	return time;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	string x;
	cin >> n >> m;
	vector<vector<bool>> arr(n);

	//A저장
	for (int i = 0; i < n; i++) {
		cin >> x;
		for (int j = 0; j < m; j++) {
			arr[i].push_back(x[j]-'0');
		}
	}//A와 B와 비교해서 다른것 찾기
	for (int i = 0; i < n; i++) {
		cin >> x;
		for (int j = 0; j < m; j++) {
			arr[i][j] = (arr[i][j] == x[j] - '0') ? 0 : 1;
		}
	}
	//3*3을 만들지 못할 때, 같으면 맞고 틀리면 가능성이 없다.
	if (n < 3 || m < 3) {
		cout << isSame(arr, n, m);
		return 0;
	}

	cout << cal(arr, n, m);
	return 0;
}
