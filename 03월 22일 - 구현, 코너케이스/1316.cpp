//1316 그룹 단어 체커
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main() {
	int n, ans = 0;
	cin >> n;
	while (n--) {
		string s;
		unordered_map<char, bool> alpha;
		char now, prev;
		cin >> s;
		//그룹단어는 거꾸로 해도 그룹단어다.
		while (!s.empty()) {
			 now = s.back();
			 //처음 나온 글자면 통과
			 if (alpha[now] == 0) alpha[now]=1;
			 //처음나오지 않았는데 이전 글자와 다르면 탈락
			 else if (now != prev) break;

			 prev = now;
			 s.pop_back();
		}//그룹단어인지 체크
		if (s.empty()) ans++;
	}
	cout << ans;
}