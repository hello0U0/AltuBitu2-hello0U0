#include <iostream>                                                             //
#include <vector>                                                               //

using namespace std;                                                            //

//LCS 길이 구하는 함수
int lcs(string str1, string str2) {                                             //
    int n = str1.length();                                                      //
    int m = str2.length();                                                      //
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));                       //
    for (int i = 1; i <= n; i++) {                                              // str1의 문자열을 전체 돌면서
        for (int j = 1; j <= m; j++) {                                          // str2의 문자열과 하나씩 비교한다.
            if (str1[i - 1] != str2[j - 1]) { //두 문자가 서로 다르면           // 문자가 같지 않은 시점에서
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);                     // str1의 str1을 기준으로 최장수열인 것과, str2를 기준으로 최장 수열 인 것충 더 긴 것을 가진다.
            } else if (str1[i - 1] == str2[j - 1]) { //두 문자가 서로 같다면    // 문자가 같으면
                dp[i][j] = dp[i - 1][j - 1] + 1;                                // 최장수열은 증가
            }                                                                   //
        }                                                                       //
    }                                                                           //
    return dp[n][m]; //LCS 길이 리턴                                            //
}

/**
 * LCS (해당 풀이는 "08. 동적계획법.pdf" 참고)
 *
 * 해당 풀이는 인덱스를 편하게 관리하기 위해 dp와 path 배열을 (1, 1)부터 시작
 */

int main() {                                                                   //
    string str1, str2;                                                         //

    //입력
    cin >> str1 >> str2;                                                       //

    //연산 & 출력
    cout << lcs(str1, str2); //lcs                                             // 최장수열 계산
    return 0;                                                                  //
}                                                                              //