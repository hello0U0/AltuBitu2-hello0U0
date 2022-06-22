//1516 게임개발
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//위상정렬 + DP
vector<int> topologicalSort(int n, vector<int> &t, vector<int> &indegree, vector<vector<int>> &graph) {
    queue<int> q;
    vector<int> dp(n + 1, 0);       //해당 건물 짓기 까지의 최단시간 계산

    for (int i = 1; i <= n; i++) {      //모든 건물에 대해
        dp[i] = t[i];                   //해당 건물을 짓는 시간으로 세팅
        if (!indegree[i]) {             //이전에 필요한 작업이 없으면
            q.push(i);                  //큐에 추가
        }
    }
    while (!q.empty()) {                //큐가 빌 때까지
        int node = q.front();           //건물을 가져온다.
        q.pop();

        for (int i = 0; i < graph[node].size(); i++) {   //다음 작업들에 대해
            int next_node = graph[node][i];                 
            dp[next_node] = max(dp[next_node], dp[node] + t[next_node]); //다음 건물의 기존 비용과 현재 건물을 짓고 다음건물을 짓는 것 중 긴 시간을 선택

            indegree[next_node]--;      //다음 건물의 필요한 이전 건물 수를 줄이낟.
            if (!indegree[next_node]) { //다음 건물을 지을 수 있으면
                q.push(next_node);      //큐에 추가
            }
        }
    }
    return dp;
}

/**
 * [게임 개발]
 *
 * - ACM Craft (1005) 와 동일한 문제
 * - 최소 시간 = 건물을 동시에 지을 수 있는 건 최대한 동시에 지어야 최소 시간이 걸리므로 그 전 정점 중 가장 오래 걸리는 시간을 선택
 */

int main() {
    int n, input;        

    //입력
    cin >> n;               //건물 수
    vector<int> t(n + 1, 0); //건물을 짓는데 걸리는 시간
    vector<int> indegree(n + 1, 0); //이전에 필요한 건물 수
    vector<vector<int>> graph(n + 1, vector<int>(0));
    for (int i = 1; i <= n; i++) {  //모든 건물에 대해
        cin >> t[i];
        while (cin >> input) {      //입력값이 -1이면 멈춘다.
            if (input == -1) {
                break;
            }
            graph[input].push_back(i);  //아니면 먼저 지어져야 하는 건물-> 현재 건물로 저장
            indegree[i]++;              //이전에 필요한 건물 수 갱신
        }
    }

    //연산
    vector<int> ans = topologicalSort(n, t, indegree, graph);

    //출력
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}