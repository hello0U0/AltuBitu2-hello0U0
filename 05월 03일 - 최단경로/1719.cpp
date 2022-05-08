//1719 택배
#include<iostream>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;
typedef pair<int, int> ci;
const int INF = 2e5 + 1;

void floydWarshall(const int &n, vector<vector<ci>>& direct) {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int cost = direct[i][k].second + direct[k][j].second;
				if (direct[i][j].second > cost) {
					direct[i][j].first = direct[i][k].first;
					direct[i][j].second = cost;
				}
			}
		}
	}
}

int main() {
	int n, m, a, b, s;
	cin >> n >> m;
	vector<vector<ci>> direct(n + 1, vector<ci>(n + 1, { 0,INF }));		//최단거리의 첫번째 방문노드, 최단거리
	//초기화
	for (int i = 1; i <= n; i++) {
		direct[i][i].first = i;
		direct[i][i].second = 0;
	}//입력
	while (m--) {
		cin >> a >> b >> s;
		direct[a][b].first = b;
		direct[a][b].second = min(direct[a][b].second, s);
		direct[b][a].first = a;
		direct[b][a].second = min(direct[b][a].second, s);
	}//연산
	floydWarshall(n, direct);
	//출력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << (i == j ? "-" : to_string(direct[i][j].first)) << " ";
		}
		cout << '\n';
	}
}