//1504 특정한 최단 경로
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int, int> ci;
const int INF = 24e5 + 1;

vector<int> dijkstra(const int& start, const int& n, vector<vector<ci>>& direct) {
	vector<int> dist(n + 1, INF);	//각 정점까지의 최단경로
	dist[start] = 0;
	priority_queue<ci, vector<ci>, greater<>> pq;	//현재까지의 최단경로
	//초기화
	dist[start] = 0;
	pq.push({ 0,start });
	//더이상 계산할 수 없을 때까지
	while (!pq.empty()) {
		int weight = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		//이미 더 적은 시간이 걸린다면  패스
		if (weight > dist[node]) continue;
		//해당 노드에서 갈 수 있는 모든 루트에 대해
		for (int i = 0; i < direct[node].size(); i++) {
			int next_node = direct[node][i].first;
			int next_weight = weight + direct[node][i].second;
			//새로운 루트가 더 빠르다면 업데이트
			if (next_weight < dist[next_node]) {
				dist[next_node] = next_weight;
				pq.push({ next_weight,next_node });
			}
		}
	}
	return dist;
}
int calMinTime(const int& n, const int& v1, const int& v2, vector<vector<ci>>& direct) {
	int ans1 = 0;	//1 -> v1 -> v2 -> n
	int ans2 = 0;	//1 -> v2 -> v1 -> n
	vector<int> path = dijkstra(1, n, direct);
	ans1 += path[v1];
	ans2 += path[v2];
	path = dijkstra(v1, n, direct);
	ans1 += path[v2];
	ans2 += path[v2];
	path = dijkstra(n, n, direct);
	ans1 += path[v2];
	ans2 += path[v1];
	//경로가 없는 경우 제외
	ans1 = min(ans1, ans2);
	if (ans1 >= INF) ans1 = -1;
	//더 짧은 것을 결정
	return ans1;
}

int main() {
	int n, e, a, b, c, v1, v2;
	cin >> n >> e;
	vector<vector<ci>> direct(n + 1);
	while (e--) {
		cin >> a >> b >> c;
		direct[a].push_back({ b,c });
		direct[b].push_back({ a,c });
	}
	cin >> v1 >> v2;
	int ans = calMinTime(n, v1, v2, direct);
	cout << ans;
}