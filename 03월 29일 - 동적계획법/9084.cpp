#include <iostream>                                     //
#include <vector>                                       //

using namespace std;                                    //

int knapsack(int n, int m, vector<int> &coin) {         //
    vector<int> dp(m + 1, 0);                           // 

    dp[0] = 1;                                          // 돈이 없으면 만들 수 있는 동전 종류는 1이다.
    for (int i = 0; i < n; i++) {                       // i번째 돈을 사용한다면
        for (int j = coin[i]; j <= m; j++) {            // i번째 돈의 금액부터 목표금액까지
            dp[j] += dp[j - coin[i]];                   // 해당 돈의 방법수는 i번째 동전 1개와 나머지 금액의 가지수의 합이다.
        }                                               //
    }                                                   //
    return dp[m];                                       //
}

/**
 * dp[i] = 주어진 동전 종류를 사용해서 i원을 만드는 경우의 수
 *
 * dp[0] = 1 을 넣고 시작 (0원을 만드는 경우의 수 1로 생각)
 * 각 동전마다 해당 동전부터 만들어야 하는 금액(m)까지 돌리면서 해당 동전을 사용하기 전 금액의 경우의 수와 현재 경우의 수를 더함
 * 해당 동전 사용하기 전 금액의 경우의 수가 0이면 금액을 만들 수 없는 경우이지만, 어차피 더해도 값 변화는 없으므로 따로 고려하지 않음
 */

int main() {                                            //
    int t, n, m;                                        //
                    
    //입력
    cin >> t;                                           //
    while (t--) {                                       //
        cin >> n;                                       //
        vector<int> coin(n, 0);                         //
        for (int i = 0; i < n; i++) {                   //
            cin >> coin[i];                             //
        }                                               //
        cin >> m;                                       //

        //연산 & 출력
        cout << knapsack(n, m, coin) << '\n';           //
    }                                                   //
    return 0;                                           //
}                                                       //