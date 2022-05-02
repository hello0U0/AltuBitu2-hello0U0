//11725 트리의 부모 찾기
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj_list;
vector<int> parent;

void dfs_recursion(int prev, int curr) {
    //부모가 정해졌으면 끝
    if (parent[curr]) {
        return;
    }
    //부모를 설정
    parent[curr] = prev;
    //해당 노드와 연관된 모든 관계에 대해
    for (int i = 0; i < adj_list[curr].size(); i++) {
        //부모가 비어있으면 해당 노드를 부모로 설정한다.
        dfs_recursion(curr, adj_list[curr][i]);
    }
}

/**
 * [트리의 부모 찾기]
 *
 * 1번 노드에서 출발해서 탐색
 * 루트 노드에서 출발 했기 때문에, 현재 노드의 부모는 이전 노드가 된다.
 */

int main() {
    int n, a, b;

    //입력
    cin >> n;
    adj_list.assign(n + 1, vector<int>(0));
    parent.assign(n + 1, 0);
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    //연산
    dfs_recursion(1, 1); //1번 노드는 루트노드이므로, 부모를 자기 자신으로 설정

    //출력
    for (int i = 2; i <= n; i++) {
        cout << parent[i] << '\n';
    }
    return 0;
}
