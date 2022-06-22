//1244 스위치 켜고 끄기
#include <iostream>
#include <vector>

using namespace std;

//남학생의 스위치 바꾸기
vector<int> changeSwitchBoy(int n, int number, vector<int> switches) {
    for (int i = number; i <= n; i += number) { //배수에 있는 스위치 바꾸기
        switches[i] = !switches[i];         //배수의 스위치 상태 바꾸기
    }
    return switches;
}

//여학생의 스위치 바꾸기
vector<int> changeSwitchGirl(int n, int number, vector<int> switches) {
    switches[number] = !switches[number];       //학생 본인의 상태 지우기
    for (int i = 1; i < number; i++) {          //학생을 기준으로 한칸씩 늘려가며(number-number은 0이기 대문에 이전까지만 계산)
        if ((number + i > n) || (switches[number - i] != switches[number + i])) { //스위치 범위 넘어가거나 좌우 대칭이 아니면 멈추기
            break;
        }
        switches[number - i] = !switches[number - i];       //좌우대칭이면 스위치들 바꾸기
        switches[number + i] = !switches[number + i];
    }
    return switches;
}

/**
 * [스위치 켜고 끄기]
 *
 * 남학생 -> 해당 번호의 배수에 해당하는 스위치 상태 바꾸기
 * 여학생 -> 해당 번호를 중심으로 좌우 대칭이면서 가장 많은 스위치 포함하는 구간의 상태 모두 바꾸기
 *
 * 좌우 대칭 검사 시, 스위치 범위 주의 (주어진 스위치 범위 넘어가지 않도록)
 * 스위치 20개씩 출력하는 부분 주의
 */
int main() {
    int n, m;           //스위치 개수, 학생 수
    int student, number;        //성별, 숫자

    //입력
    cin >> n;
    vector<int> switches(n + 1, 0);     //스위치 상태
    for (int i = 1; i <= n; i++) {
        cin >> switches[i];     
    }

    //입력 & 연산
    cin >> m;
    while (m--) {
        cin >> student >> number;
        if (student == 1) {     //남자애일 경우의 계산
            switches = changeSwitchBoy(n, number, switches);
        } else {                //여자애일 경우의 계산
            switches = changeSwitchGirl(n, number, switches);
        }
    }

    //출력
    for (int i = 1; i <= n; i++) {
        cout << switches[i] << ' ';
        if (i % 20 == 0) {
            cout << '\n';
        }
    }
    return 0;
}