//1774 우주신과의 교감
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>

using namespace std;
typedef tuple<double, int, int> tp;
typedef pair<double, double> ci;

vector<int> parent;

//Find 연산
int findParent(int x) {//루트 노드 구하기
    if (parent[x] < 0) {    //루트면 본인을 반환
        return x;
    }
    return parent[x] = findParent(parent[x]);   //아니면 부모노드 반환
}

//Union 연산
bool unionNodes(int x, int y) {     //두 점을 연결
    int px = findParent(x);         //루트 노드 계산
    int py = findParent(y);

    if (px == py) {     //부모가 같으면 끝
        return false;
    }//아니면 두 점을 연결
    if (parent[px] < parent[py]) { //새로운 루트 px
        parent[px] += parent[py];
        parent[py] = px;
    } else { //새로운 루트 py
        parent[py] += parent[px];
        parent[px] = py;
    }
    return true;
}

double kruskal(int v, vector<tp> &edge) {
    double sum = 0;     //비용
    int cnt = 0;        //이은 간선 수

    for (int i = 0; i < edge.size(); i++) { //모든 간선에 대해
        double cost = get<0>(edge[i]);
        int x = get<1>(edge[i]);
        int y = get<2>(edge[i]);

        if (!unionNodes(x, y)) {    //이미 연결된 간선이면 넘어가기
            continue;
        }
        sum += cost;        //비용추가
        cnt++;              //이은 간선 수 기록
        if (cnt == v - 1) { //필요한 모든 간선을 이엇다면
            return sum;     //비용 반환
        }
    }
    return 0;
}

/**
 * [우주신과의 교감]
 *
 * 4386번 : 별자리 만들기의 응용 문제
 * 이미 연결된 정점들이 존재한다는 것을 제외하고는 4386번과 동일
 *
 * 1. 임의의 두 별에 대한 거리(간선) 모두 구하기
 * 2. 이미 존재하는 통로들 표시
 *    !주의! 통로의 개수가 m개라면 v-m-1개의 간선만 더 추가하면 될까?
 *          이미 연결된 통로들도 사이클을 이룰 수 있기 때문에 유니온 연산을 하며 사이클 없이 연결된 간선만 세기
 * 3. 이미 연결된 통로의 수를 k개라고 하면 v-k-1개의 간선을 추가로 선택
 */
int main() {
    int n, m, a, b, v = 0;
    double x, y;

    //입력
    cin >> n >> m;          //우주신의 수, 통로 수
    parent.assign(n + 1, -1);   //루트노드 정보 저장
    vector<tp> edge;            //통로 정보
    vector<ci> star(n + 1);     //

    for (int i = 1; i <= n; i++) {      //모든 우주신들에 대해
        cin >> x >> y;                  //좌표 입력
        for (int j = 1; j < i; j++) {   //다른 우주신들과의
            //임의의 두 별에 대한 거리(간선) 모두 구하기
            double dx = x - star[j].first;
            double dy = y - star[j].second;
            edge.push_back({sqrt(dx * dx + dy * dy), i, j});    //거리, 우주신 1, 우주신 2 저장
        }
        star[i] = {x, y};       //우주신의 좌표 저장
    }

    //연산
    while (m--) {               //모든 통로에 대해
        cin >> a >> b;
        if (unionNodes(a, b)) { //이미 연결된 통로
            v++;                //이미 연결된 통로 수 체크
        }
    }
    sort(edge.begin(), edge.end()); //거리순으로 정렬

    //연산 & 출력
    cout << fixed;
    cout.precision(2);      //소수점 둘째자리까지 출력
    cout << kruskal(n - v, edge);
    return 0;
}
