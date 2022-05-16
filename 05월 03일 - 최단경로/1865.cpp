//1865 웜홀
#include<iostream>
#include<tuple>
#include<vector>
using namespace std;

typedef tuple<int, int, int> tp;
typedef long long ll;
const int INF = 5e7 + 1;

ll bellmanFord(int start, int n, int m, const vector<tp>& edges) {
	vector<ll> dist(n + 1, INF);	//최단거리
	dist[start] = 0;				//자기자신은 0

	for (int i = 1; i <= n; i++) {
		bool flag = true;
		for (int j = 0; j < m; j++) {		//모든 간선에 대해
			int s = get<0>(edges[j]);		//s->d 비용 w
			int d = get<1>(edges[j]);
			int w = get<2>(edges[j]);
			if (dist[s] == INF) continue;	//start->s가 없으면 패스
			ll next_weight = dist[s] + w;	//start->d의 최단거리 업뎃
			if (next_weight < dist[d]) {
				dist[d] = next_weight;
				flag = false;
				if (i == n) return { -1 };	//간선은 n-1개까지 허용 그 이상 넘어가면 최단거리가 음수이며 무한루프
			}
		}
		if (flag) break;
	}
	return dist[0];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n, m, w, s, e, t;
		cin >> n >> m >> w;
		int edgenum = m * 2 + w;
		vector<tp>edges;
		while (m--) {
			cin >> s >> e >> t;
			edges.push_back({ s,e,t });
			edges.push_back({ e,s,t });
		}
		while (w--) {
			cin >> s >> e >> t;
			edges.push_back({ s,e,-t });
		}
		//연산 및 출력
		bool ans = false;
		//출발지점을 1~n이라 설정했을 때 시간을 되돌아서 도착할 수 있는 경우가 있으면 체크한다.
		for (int i = 1; i <= n; i++) {
			if (bellmanFord(i, n, edgenum, edges) == -1) {
				ans = true;
				break;
			}
		}
		cout << (ans ? "YES\n" : "NO\n");
	}
}