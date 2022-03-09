#include<iostream>
#include<set>
using namespace std;

int main() {
	string s;
	set<string> spart;
	cin >> s;
	int s_size = s.size();
	
	for (int i = 1; i < s_size; i++) {	//s 전체 문자열은 하나밖에 없으므로 계산에서 제외
		//s에서 i 길이의 부분수열을 set에 저장
		for (int j = 0; j <= s_size-i; j++) {
			spart.insert(s.substr(j, i));
		}
	}

	cout << spart.size() + 1;
}