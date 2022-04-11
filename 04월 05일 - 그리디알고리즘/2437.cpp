//2437 저울
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> num(n + 1);
	num[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}
	//작은 수부터 정렬한다.
	sort(num.begin(), num.end());
	// n번째 숫자는 이전 숫자배열에서 +n번째 수를 더한 것과 같다.
	// 1번 -> 1번 -> 1
	// 2번 -> 0+2번 1번+2번	 -> 1,2(,3)으로 연속
	// 3번 -> 0+3번 1번+3번 2번+3번 1번+2번+3번 (0+3번은 1번+2번+1보다 크면 안된다.) ->연속의 수에 더하기 때문에 새로 만들어진 수도 연속이다.
	// 이전번 숫자들의 집합은 연속이어야한다.(그래야 빈 숫자가 안생긴다.)
	int endnum = 0;
	
	for (int i = 1; i <= n; i++) {
		if (num[i] > endnum + 1) {
			break;
		}
		endnum += num[i];
	}
	cout << endnum + 1;
	return 0;
}
