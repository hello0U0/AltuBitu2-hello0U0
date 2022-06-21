//14907 프로젝트 스케줄링
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int SIZE = 26;            //최대 작업 수

vector<string> splitInput(string input) { //입력 문자열 분리
    vector<string> result; //작업 번호, 작업 일수, 전에 해야하는 작업 목록 순서로 저장
    string tmp;
    input += " "; //마지막 문자열 분리를 위해 공백 추가
    for (int i = 0; i < input.length(); i++) {  //문자열을 읽으면서
        if (input[i] == ' ') {          //띄어쓰기가 있으면
            result.push_back(tmp);      //분리
            tmp = "";                   //tmp초기화
            continue;
        }
        tmp += input[i];                //tmp에 문자 추가
    }
    return result;
}

//위상정렬 + DP
int topologicalSort(vector<int> &days, vector<int> &indegree, vector<vector<int>> &graph) {
    queue<int> q;
    vector<int> dp(SIZE, 0); //현재 작업 하기까지 걸린 시간
    int ans = 0;

    for (int i = 0; i < SIZE; i++) {        //가능한 작업번호에 대해
        dp[i] = days[i]; //dp 배열 초기화    //본인의 작업일수로 초기화
        if (days[i] && !indegree[i]) {  //해당 작업은 있는데 이전에 필요한 작업수가 없으면
            q.push(i);                  //해당 작업을 큐에 저장
        }
    }
    while (!q.empty()) {    //큐가 빌때까지
        int node = q.front();   //작업을 선택
        q.pop();

        ans = max(ans, dp[node]); //정답 갱신 (마지막 정점이 여러 개일 경우, 가장 긴 시간을 선택해야 하기 때문)
        for (int i = 0; i < graph[node].size(); i++) {  //필요한 모든 작업에 대해
            int next_node = graph[node][i];             //다음 노드의
            indegree[next_node]--;                      //필요한 작업 수를 줄인다.
            if (!indegree[next_node]) {                 //다음 작업이 가능하면
                q.push(next_node);                      //큐에 추가한다.
            }
            //다음 정점의 최소 시간 계산 -> 이어진 전 정점 중 가장 긴 작업 일수를 가진 정점을 선택
            dp[next_node] = max(dp[next_node], dp[node] + days[next_node]); //다음 작업까지의 기존 비용과 현재까지 작업하고 다음 작업을 할 경우 중 더 오래걸리는 것을 선택
        }
    }
    return ans;
}

/**
 * [프로젝트 스케줄링]
 *
 * 위상 정렬의 끝나는 정점이 여러 개일 경우, 가장 긴 시간을 선택해야 하기 때문에 정답을 항상 max처리 해주어야 함
 *
 * !주의! 입력으로 들어오는 그 전에 해야 할 작업은 0개일 수 있음. 즉 주어지지 않을 수 있음.
 * -> 따라서, getline을 통해 한 번에 입력받은 후, 작업, 작업 일수, 이 전에 해야 할 작업으로 나눠서 저장
 */
int main() {
    vector<int> indegree(SIZE, 0);                  //이전에 필요한 작업 수
    vector<vector<int>> graph(SIZE, vector<int>(0));
    vector<int> days(SIZE, 0);
    string input;

    //입력
    while (getline(cin, input)) {   //입력이 있다면 진행
        vector<string> list = splitInput(input);    //작업번호, 날짜, 완료해야하는 작업으로 분리
        int work = list[0][0] - 'A'; //작업 번호
        days[work] = stoi(list[1]); //해당 작업 일수
        if (list.size() == 2) { //그 전에 해야 하는 작업이 없다면
            continue;
        }
        string prev = list[2]; //그 전에 해야 하는 작업
        indegree[work] = prev.length();     //그전에 해야할 작업 수 저장
        for (int i = 0; i < prev.length(); i++) {   // 이전 작업 -> 해당 작업 저장
            graph[prev[i] - 'A'].push_back(work);
        }
    }

    //연산 & 출력
    cout << topologicalSort(days, indegree, graph);
    return 0;
}