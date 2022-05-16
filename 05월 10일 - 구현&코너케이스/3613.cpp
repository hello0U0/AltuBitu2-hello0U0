//3613 Java vs C++
#include<iostream>
using namespace std;
const int diff = 'a' - 'A';

string cal(const string& s) {
	string ans;
	int kind = 0;	// 1 : java, 2 : c++
	//소문자로 시작하지 않으면 끝
	if (s[0] < 'a' || s[0]>'z') {
		ans = "Error!";
		return ans;
	}
	int max_size = s.size();
	for (int i = 0; i < max_size; i++) {
		//대문자가 나오면 자바다
		if (s[i] >= 'A' && s[i] <= 'Z') {
			//형식이 안맞으면 에러
			if (kind == 2) {
				ans = "Error!";
				return ans;
			}
			kind = 1;
			ans.push_back('_');
			ans.push_back(s[i] + diff);
		}//언더바가 나오면 C++이다.
		else if (s[i] == '_') {
			//형식이 안맞으면 에러
			i++;
			if (kind == 1 || i >= max_size||s[i] < 'a' || s[i] > 'z') {
				ans = "Error!";
				return ans;
			}
			kind = 2;
			ans.push_back(s[i] - diff);
		}//소문자면 그대로 넣기
		else ans.push_back(s[i]);
	}
	return ans;
}

int main() {
	string s;
	cin >> s;
	cout << cal(s);
	return 0;
}