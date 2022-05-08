//1504 특정한 최단 경로
#include<iostream>
#include<queue>
using namespace std;
typedef pair<int, int> ci;
const int INF = 8e5 + 1;

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
int calMinTime(const int &n,const int &v1,const int &v2, vector<vector<ci>> &direct) {
	vector<int> path = dijkstra(1, n, direct);
	int one_v1 = path[v1];	//1->v1
	int one_v2 = path[v2];	//1->v2
	path = dijkstra(v1, n, direct);
	int v1_v2 = path[v2];	//v2->v1 && v1->v2
	//v1-v2길이 없으면 길이 없는 것
	if (v1_v2 == INF) return -1;
	path = dijkstra(n, n, direct);
	int v1_n = path[v1];	//v1->n
	int v2_n = path[v2];	//v2->n
	int ans1 = one_v1 + v1_v2 + v2_n;	//1 -> v1 -> v2 -> n
	int ans2 = one_v2 + v1_v2 + v1_n;	//1 -> v2 -> v1 -> n
	//경로가 없는 경우 제외
	int ansinf = 3 * INF;
	if (one_v1 == INF || v2_n == INF) ans1 = ansinf;
	if (one_v2 == INF || v1_n == INF) ans2 = ansinf;
	if (ans1 == ansinf && ans2 == ansinf) return - 1;
	//더 짧은 것을 결정
	return ans1 < ans2 ? ans1 : ans2;
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