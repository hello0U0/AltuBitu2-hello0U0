//10282 해킹
#include<iostream>
#include<queue>
using namespace std;
typedef pair<int, int> ci;
const int INF = 1e7 + 1;

vector<int> dijkstra(const int& start, const int& n, vector<vector<ci>>& direct) {
	vector<int> dist(n + 1, INF);	//각 정점까지의 최단경로
	priority_queue<ci, vector<ci>, greater<>> pq;	//현재까지의 최단경로
	//초기화
	dist[start] = 0;
	pq.push({ 0,start });
	//더이상 계산할 수 없을 때까지
	while (!pq.empty()) {
		int weight = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		//이미 더 적은 시간 내에 해킹되었다면 패스
		if (weight > dist[node]) continue;
		//해당 컴퓨터가 감염시킬 수 있는 모든 컴터에 대해 
		for (int i = 0; i < direct[node].size(); i++) {
			int next_node = direct[node][i].first;
			int next_weight = weight + direct[node][i].second;
			//해당 컴퓨터가 감염시키는게 더 빠른 경우를 기록
			if (next_weight < dist[next_node]) {
				dist[next_node] = next_weight;
				pq.push({ next_weight,next_node });
			}
		}
	}

	return dist;
}

pair<int, int> calHacking(const int& start, const int& n, vector<vector<ci>>& direct) {
	pair<int, int> ans = { 0,0 };	//감염된 컴퓨터 수, 최단시간
	//다익스트라로 시작점에서 각 정점까지 도달하는 시간을 체크한다.
	vector<int> dist = dijkstra(start, n, direct);
	//INF는 아니면서 제일 오래 걸린 시간이 최단시간이다.
	//INF가 아닌 수의 개수가 감염된 컴퓨터의 개수다.
	for (int i = 1; i <= n; i++) {
		//시간이 INF면 감염이 되지 않은 것이다.
		if (dist[i] == INF) continue;
		ans.first++;
		if (ans.second < dist[i]) ans.second = dist[i];
	}
	return ans;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n, d, c, a, b, s;
		cin >> n >> d >> c;
		vector<vector<ci>> direct(n + 1);
		while (d--) {
			cin >> a >> b >> s;
			direct[b].push_back({ a,s });
		}
		pair<int, int> ans = calHacking(c, n, direct);



		//연산 및 출력
		cout << ans.first << " " << ans.second << '\n';
	}
}