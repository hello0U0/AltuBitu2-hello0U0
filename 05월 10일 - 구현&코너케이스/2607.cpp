//2607 비슷한 단어
#include<iostream>
#include<map>
#include<cmath>
using namespace std;

//단어의 알파벳 개수들을 반환
map<char, int> calAlpha(const string &s) {
	map<char, int> alpha;
	for (int i = 0; i < s.size(); i++) alpha[s[i]]++;
	return alpha;
}

int cal(const string& s, map<char,int> &first_alpha) {
	int ans = 0;	//하나빼기 -1, 하나 넣기 1, 바꾸기 3
	map<char, int> now_alpha = calAlpha(s);
	for (char i = 'A'; i <= 'Z'; i++) {
		int nowdiff = first_alpha[i] - now_alpha[i];	//알파벳 i의 개수차
		if (nowdiff == 0) continue;						//차이가 없으면 넘어가기
		//2개이상 차이나면 비슷하지 않음, 바꾸기 불가면 끝
		if (abs(nowdiff) != 1 || (ans != 0 && nowdiff + ans != 0)) return 0;
		ans = (ans == 0 ? nowdiff : 3);		//하나 빼기는 -1, 하나 넣기는 1, 바꾸기는 2
	}
	return 1;
}

int main() {
	int n, ans = 0;
	string s;
	cin >> n;
	//첫번째 단어
	cin >> s;
	map<char, int> first_alpha = calAlpha(s);
	while (--n) {
		cin >> s;
		ans += cal(s, first_alpha);
	}
	cout << ans;
}