//2473 세 용액
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll INF = 3 * 1e9 + 1;

ll min_diff = INF;

//다른 위치에서 시작하여 서로를 향해 가까워지는 투 포인터
pair<ll, ll> liquid(vector<ll>& arr, ll fixed, int left, int right) {
    pair<ll, ll> ans;
    ans = make_pair(INF, INF);

    while (left < right) {
        //가장 작은 용액은 고정하고 그것보다 큰 용액 두개를 선택한다.(최초에는 양쪽 끝)
        ll mix = fixed + arr[left] + arr[right];
        //0보다 최소인 것은 없다.
        if (mix == 0) {
            return make_pair(arr[left], arr[right]);
        }//최소값 재설정
        if (abs(mix) < min_diff) {
            min_diff = abs(mix);
            ans = make_pair(arr[left], arr[right]);
        }//산성이면 오른쪽(산이 강한 쪽)을 줄이고
        if (mix > 0) {
            right--;
        }//알칼리면 왼쪽(알칼리가 강한 쪽)을 높인다.
        else {
            left++;
        }
    }
    return ans;
}

/**
 * 2470번 : 두 용액 섞기
 * 2473번 : 세 용액 섞기
 *
 * [세 용액]
 *
 * 1. 하나의 용액을 반드시 사용한다고 가정
 * 2. 용액 하나 고정
 * 3. 해당 용액 이후의 범위에 대해 투 포인터 알고리즘 적용
 *
 * pair : 2개의 값 저장
 * tuple : 3개의 값 저장
 *
 * !주의! 세 용액의 최댓값은 1e9(=10억)이기 때문에 3개를 섞은 최댓값은 30억이고, int를 넘어감!
 */
int main() {
    int n;

    //입력
    cin >> n;
    vector<ll> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //연산
    sort(arr.begin(), arr.end());           //용액 정렬
    tuple<ll, ll, ll> ans;
    //앞에서부터 용액들의 혼합을 계산하고 최소값을 찾는다.
    for (int i = 0; i < n - 2; i++) {
        pair<ll, ll> p = liquid(arr, arr[i], i + 1, n - 1); //arr[i] 용액은 고정
        if ((p.first != INF) && (p.second != INF)) { //최솟값이 갱신된 경우
            ans = make_tuple(arr[i], p.first, p.second);
        }
    }

    //출력
    cout << get<0>(ans) << ' ' << get<1>(ans) << ' ' << get<2>(ans);
    return 0;
}