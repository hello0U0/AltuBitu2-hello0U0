#include <iostream>                                                                                                 //
#include <vector>                                                                                                   //
#include <algorithm>                                                                                                //

using namespace std;                                                                                                //

/**
 * 1.
 *
 * 강의자료 점화식
 *
 * 시간 복잡도 O(n^2)
 */
int lis(int n, vector<int> &arr) {                                                                                  //
    vector<int> dp(n, 1);                                                                                           //
    int ans = 1;                                                                                                    //

    for (int i = 1; i < n; i++) {                                                                                   //i+1번째 수까지
        for (int j = 0; j < i; j++) {                                                                               //처음 숫자부터
            if (arr[i] > arr[j]) { //증가하는 관계라면                                                              //이전 값보다 증가라면 이전값에 1을 더하고 
                dp[i] = max(dp[i], dp[j] + 1);                                                                      //현재까지의 최장길이와 이번에 계산한 최장길이중 더 긴 것을 택한다.
            }                                                                                                       //
        }                                                                                                           //
        ans = max(ans, dp[i]); //최장 길이 갱신                                                                     //최종 답의 최장길이를 계산한다.
    }                                                                                                               //
    return ans;                                                                                                     //
}                                                                                                                   //

/**
 * 2.
 *
 * dp[i] : 증가하는 부분 수열의 길이가 i인 수 중에 가장 작은 수
 * idx : 가장 긴 증가하는 부분 수열의 길이
 *
 * 시간 복잡도 O(nk) (k는 idx의 크기)
 *
 * -> k가 n이 될 수 있으므로 이론상 시간복잡도는 O(n^2)으로 동일하지만,
 *    증가하는 관계일 때 break를 해줌으로써 실제 연산횟수는 더 적어서 1번 함수보다 빠른 풀이
 *
 * 해설 : https://myunji.tistory.com/214
 */
int lisAdv(int n, vector<int> &arr) {                                                                               //
    vector<int> dp(n + 1, 0); //dp[1]을 갱신하기 위해 dp[0] = 0으로 설정                                            //
    int idx = 0;                                                                                                    //

    for (int i = 0; i < n; i++) {                                                                                   //lis 함수와 동일하게 계산하다가
        for (int j = idx; j >= 0; j--) {                                                                            //
            if (arr[i] > dp[j]) { //증가하는 관계라면                                                               //
                dp[j + 1] = arr[i];                                                                                 //
                if (j == idx) { //최장 길이 갱신                                                                    //원하는 답까지 계산하면 멈추고
                    idx++;                                                                                          //
                }                                                                                                   //
                break;                                                                                              //
            }                                                                                                       //
        }                                                                                                           //
    }                                                                                                               //
    return idx;                                                                                                     //원하는 답을 반환한다.
}                                                                                                                   //

/**
 * 3.
 *
 * lisAdv에서 line 36~43의 과정을 이분탐색으로 구현
 *
 * 시간 복잡도 O(nlogk) (k는 dp의 크기)
 * 해설 : https://myunji.tistory.com/270
 */
int lisFinal(int n, vector<int> &arr) {                                                                             //
    vector<int> dp;                                                                                                 //

    for (int i = 0; i < n; i++) {                                                                                   //
        int pos = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin(); //arr[i] 이상의 값이 처음 나오는 위치     // i번째 수가 있다 하고, i보다 큰 수가 나오는 부분을 확인
        if (pos == dp.size()) { //arr[i]가 가장 크다면 pos 값이 dp.size()와 같음 -> 최장 길이 갱신                  // 현재 최장부분수열에 더 큰 수가 없으면 현재까지가 최장부분수열이다.
            dp.push_back(arr[i]);                                                                                   //
        }                                                                                                           //
        dp[pos] = arr[i]; //dp[pos]의 값이 arr[i]이상이므로 더 작은 arr[i]로 덮어 씌우기                            // 해당 수가 최장수열에 포함된다.
    }                                                                                                               //
    return dp.size();                                                                                               //
}                                                                                                                   //

int main() {                                                                                                        //
    int n;                                                                                                          //

    //입력
    cin >> n;                                                                                                       //
    vector<int> arr(n, 0);                                                                                          //
    for (int i = 0; i < n; i++) {                                                                                   //
        cin >> arr[i];                                                                                              //
    }                                                                                                               //

    //연산 & 출력
    cout << lis(n, arr);                                                                                            //
    return 0;                                                                                                       //
}                                                                                                                   //