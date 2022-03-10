#include<iostream>
#include<map>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, match = 1;
		cin >> n;

		//n=0이면 0출력 후 넘어가기
		if (n == 0) {
			cout << "0\n";
			continue;
		}//옷 이름 종류 입력받기
		map<string, int> name_kind;
		while(n--) {
			string name, kind;
			cin >> name >> kind;
		//종류별 옷 개수 저장하기
			name_kind[kind]++;
		}
		//각 종류별 옷 개수 +1을 곱한다.(안입는것까지 고려)
		for (auto iter:name_kind) {
			match *= (iter.second + 1);
		}
		//알몸일 경우 빼기
		match--;

		cout << match << '\n';
	}
}