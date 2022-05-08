#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ci;
const int INF = 2e7 + 1;

vector<int> dijkstra(const int start, const int n, const vector<vector<ci>> direct) {
    vector<int> dist(n + 1, INF);
    dist[start] = 0;
    priority_queue<ci, vector<ci>, greater<>> pq;
    pq.push({ 0,start });
    while (!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (weight > dist[node]) continue;
        for (int i = 0; i < direct.size(); i++) {
            int next_node = direct[node][i].first;
            int next_weight = weight + direct[node][i].second;
            if (next_weight < dist[next_node]) {
                dist[next_node] = next_weight;
                pq.push({ next_weight,next_node });
            }
        }
    }
    return dist;
}

vector<vector<ci>> calDirect(const int n, const vector<vector<int>>& fares) {
    vector<vector<ci>> direct(n + 1);
    for (int i = 0; i < fares.size(); i++) {
        direct[fares[i][0]].push_back({ fares[i][1],fares[i][2] });
        direct[fares[i][1]].push_back({ fares[i][0],fares[i][2] });
    }
    return direct;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    vector<vector<ci>> direct = calDirect(n, fares);
    //다익스트라 a출발, b출발, s출발 구함
    vector<int> apath = dijkstra(a, n, direct);
    vector<int> bpath = dijkstra(b, n, direct);
    vector<int> spath = dijkstra(s, n, direct);

    int sa = apath[s];//a혼자 퇴근
    int sb = bpath[s];//b 혼자 퇴근
    //s에서 x까지 같이 퇴근
    answer = sa + sb;
    for (int i = 1; i <= n; i++) {
        int nowpath = spath[i] + apath[i] + bpath[i];
        if (nowpath < answer) answer = nowpath;
    }
    //x에서 a혼자 퇴근

    //x에서 b 혼자 퇴근

    //a+b 와 sx+xa+xb를 비교 최소값을 반환

    return answer;
}

int main() {

}