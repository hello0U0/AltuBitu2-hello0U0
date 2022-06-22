//2637 장난감 조립
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

vector<int> bfs(int n, vector<vector<ci>> &graph) {
    queue<int> q;   //답안 역순
    vector<int> cnt(n + 1, 0); //큐에 있는 부품 번호에 따른 개수 저장 + 방문체크
    vector<int> ans(n + 1, 0); //기본 부품 개수 저장

    //시작 정점 초기화
    q.push(n);      //완제품 추가
    cnt[n] = 1;     //완제품 방문

    while (!q.empty()) {    //q가 빌때까지
        int x = q.front();  //제품을 꺼낸다.
        q.pop();

        //리프노드(기본부품)인 경우
        if (graph[x].empty()) { 
            ans[x] += cnt[x];   //제품을 만드는데 들어간 개수 기록
        }
        //중간부품인 경우
        for (int i = 0; i < graph[x].size(); i++) { //해당 노드의 자식 노드에 대해
            int y = graph[x][i].first;
            int k = graph[x][i].second;
            if (!cnt[y]) {  //방문하지 않았으면 큐에 추가
                q.push(y);
            }
            cnt[y] += k * cnt[x];   //k개의 제품을 만들어 저장한다.
        }
        cnt[x] = 0; //처리가 끝나면 0으로 리셋
    }
    return ans;   //각 부품당 개수 반환
}

/**
 * [장난감 조립]
 *
 * - 완제품을 만들기 위해 필요한 기본 부품의 개수를 구하는 문제
 * - y(필요한 부품) -> x(만들어지는 부품)의 관계를 역으로 만들면 x -> y가 되면서 루트노드가 완제품이 되고 리프노드가 기본 부품이 됨
 * - 따라서, BFS/DFS 탐색을 통해 필요한 리프노드의 총 개수를 구함
 */
int main() {
    int n, m, x, y, k;

    //입력
    cin >> n >> m;  //완제품 번호, 부품간 관계 수
    vector<vector<ci>> graph(n + 1, vector<ci>(0));     //그래프
    while (m--) {모든 관계에 대해
        cin >> x >> y >> k;     //y->x간선 y가 k개 필요
        graph[x].push_back({y, k}); //그래프에 저장
    }

    //연산
    vector<int> result = bfs(n, graph);

    //출력
    for (int i = 1; i <= n; i++) {
        if (result[i]) {
            cout << i << ' ' << result[i] << '\n';
        }
    }
    return 0;
}