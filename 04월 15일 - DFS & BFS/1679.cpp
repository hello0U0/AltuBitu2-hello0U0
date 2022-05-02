//1679 숨바꼭질
#include <iostream>
#include <queue>

using namespace std;
const int SIZE = 1e5;

int bfs(int n, int k) {
    vector<int> check(SIZE + 1, 0);
    queue<int> q; //큐에 좌표값 저장
    int ans = 0;

    check[n] = 1; //시작 노드 방문체크 + 시간 초기화
    q.push(n);  //위치 저장
    while (!q.empty()) {
        int x = q.front();  
        q.pop();
        //목적지에 도달했으면 끝
        if (x == k) {   
            //시작노드가 1이라 가정했었다.
            ans = check[x] - 1;
            break;
        }
        //현재위치에서 앞으로 가거나 뒤로 가거나 순간이동을 한다.
        vector<int> child = { x - 1, x + 1, x * 2 }; //자식 노드
        for (int i = 0; i < 3; i++) {
            //다음 위치가 범위 내여야 하고 이전에 방문(했던 일을 다시 반복하게 된다)하지 않았다면
            if (child[i] >= 0 && child[i] <= SIZE && !check[child[i]]) {
                //해당 위치를 방문할 수 있다.
                check[child[i]] = check[x] + 1;
                q.push(child[i]);
            }
        }
    }
    return ans;
}

/**
 * [숨바꼭질]
 *
 * x좌표 위에서 x-1, x+1, 2*x의 위치로 계속 이동하며 탐색
 * 가장 빠른 시간을 찾아야 하므로 주변 노드부터 탐색하는 풀이로 풀어서 k에 도달하면 바로 탐색 종료 (bfs)
 */

int main() {
    int n, k;

    //입력
    cin >> n >> k;

    //연산 & 출력
    cout << bfs(n, k);
    return 0;
}