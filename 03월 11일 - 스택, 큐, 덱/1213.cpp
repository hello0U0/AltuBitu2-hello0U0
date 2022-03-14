#include<iostream>
#include<map>
#include<string>
using namespace std;

int main() {
	string name;
	map<char, int> name_map;
	cin >> name;
	for (int i = 0; i < name.size();i++) {
		name_map[name[i]]++;
	}

	string start = "", end = "";
	int odd = 0;
	char odd_char=0;
	for (auto iter:name_map) {			//알파벳 순서대로
		if (iter.second % 2 == 1) {		//알파벳 개수가 홀수일때
			odd++;
			if (odd > 1) break;			//홀수개인 알파벳은 한개까진 괜찮다.
			odd_char = iter.first;		//홀수인 알파벳 글자를 저장
		}
		//절반 글자는 사전순으로, 절반글자는 거꾸로 저장
		string now(iter.second / 2,iter.first);	
		start += now;	
		end = now + end;
	}
	if (odd == 1) start += odd_char;	//홀수개인 알파벳을 가운데 저장

	cout << (odd > 1 ? "I'm Sorry Hansoo" : start + end) << '\n';
}