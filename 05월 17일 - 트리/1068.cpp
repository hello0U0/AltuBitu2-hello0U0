//1068 트리
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;

//주어진 정점을 지웠을 때의 리프 노드의 수
int eraseLeafCnt(int node, int& erase_node) {
    if (node == erase_node) {   //지울 노드가 (부분트리의) 루트노드면 트리가 없다.
        return 0;
    }
    if (tree[node].empty() || (tree[node].size() == 1 && tree[node][0] == erase_node)) {    //현재 노드가 (부분트리의)루트 노드이거나, 루트의 유일한 자식이 지울 노드면
        return 1;   //(부분트리의)루트노드 하나만 남는다.
    }
    int cnt = 0;
    for (int i = 0; i < tree[node].size(); i++) {   //현재 노드의 모든 자식들에 대해
        cnt += eraseLeafCnt(tree[node][i], erase_node);    //지울수 있으면 지운 값을 생각한다. 리프노드의 개수를 체크한다. 
    }
    return cnt; //리프노드의 개수를 반환한다.
}

/**
 * [트리]
 *
 * 기존 리프 노드 개수를 세는 dfs 탐색에서 지우는 정점을 만나면 더 이상 탐색하지 않고 0을 리턴
 *
 * !주의! 지우는 정점이 해당 부모 노드의 유일한 자식 노드였을 경우, 해당 정점을 지우면 부모 노드가 리프 노드가 돼서 개수가 1 증가함을 주의
 * !주의! 루트 노드가 항상 0이 아님을 주의
 */

int main() {
    int n, par, root, erase_node;

    //입력
    cin >> n;
    tree.assign(n, vector<int>(0));
    for (int i = 0; i < n; i++) {
        cin >> par;
        if (par == -1) {    //-1이면 루트
            root = i;   //루트노드값을 저장
            continue;
        }
        tree[par].push_back(i); //부모노드 par에 자식노드 i가 있다.
    }
    cin >> erase_node;  

    //연산 & 출력
    cout << eraseLeafCnt(root, erase_node);
    return 0;
}