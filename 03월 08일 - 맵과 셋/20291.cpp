#include<iostream>
#include<map>
using namespace std;

int main() {
	int n;
	string s;
	map<string, int> ext_count;		//확장자 - 파일 개수
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;

		//파일명에서 확장자만 추출
		size_t dot_i = s.find(".");
		s = s.substr(dot_i + 1, s.size());
		//기존에 받았으면 해당 확장자 개수 증가, 새로우면 확장자 개수 초기화
		ext_count[s]++;
	}
	for (auto iter : ext_count) {
		cout << iter.first << " " << iter.second << '\n';
	}
}