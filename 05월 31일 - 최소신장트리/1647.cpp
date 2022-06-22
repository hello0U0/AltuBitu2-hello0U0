//1647 도시 분할 계획
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
typedef tuple<int, int, int> tp;

vector<int> parent;

//Find 연산
int findParent(int x) {
    if (parent[x] < 0) {        //루트노드면 본인을 반환
        return x;
    }
    return parent[x] = findParent(parent[x]);   //아니면 부모노드 반환
}

//Union 연산
bool unionNodes(int x, int y) { //두 집을 연결
    int px = findParent(x);     //루트 노드 계산
    int py = findParent(y);

    if (px == py) {         //루트노드가 같으면 끝
        return false;
    }//아니면 두 집을 연결
    if (parent[px] < parent[py]) { //새로운 루트 px
        parent[px] += parent[py];
        parent[py] = px;
    } else { //새로운 루트 py
        parent[py] += parent[px];
        parent[px] = py;
    }
    return true;
}

int kruskal(int n, vector<tp> &edge) {
    int sum = 0, cnt = 0;
    for (int i = 0; i < edge.size(); i++) {     //모든 길에 대해
        int w = get<0>(edge[i]);
        int u = get<1>(edge[i]);
        int v = get<2>(edge[i]);
        if (!unionNodes(u, v)) {    //두 길이 이어져있으면 넘어가기
            continue;
        }
        sum += w;       //비용계산
        cnt++;          //만든 길의 수 계산
        if (cnt == n - 1) { //필요한 모든 길을 추가했으면 
            return sum;     //끝
        }
    }
    return 0;
}

/**
 * [도시 분할 계획]
 *
 * 마을을 두개로 분리하고, 각 집끼리 이동할 수 있는 최소한의 도로만 남기는 문제
 * 즉, 2개의 최소신장트리를 만들어야 하는 문제
 * -> 하나의 최소신장트리를 만들고, 그 중 가장 유지비가 큰 도로를 삭제
 * -> 크루스칼 알고리즘에서 가장 마지막에 삭제되는 도로가 유지비가 가장 큼
 * -> 크루스칼 알고리즘에서 간선을 n-2개만 선택하여 그 합을 구하여 해결
 */
int main() {
    int n, m, a, b, c;

    //입력
    cin >> n >> m;          //집의 수, 길의 수
    vector<tp> edge;        //길 정보
    parent.assign(n + 1, -1);   //루트노드 정보
    while (m--) {
        cin >> a >> b >> c;     //a - b 두 집의 길 정보를 저장
        edge.push_back({c, a, b});
    }

    //연산
    sort(edge.begin(), edge.end()); //정렬

    //연산&출력
    cout << kruskal(n - 1, edge);
    return 0;
}