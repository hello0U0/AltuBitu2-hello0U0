//2503 숫자야구
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//각 글자에 대해 볼과 스트라이크를 계산한다.
void findString(const string s, const string &ans, int &ball,int &strike) {
	for (int j = 0; j < 3; j++) {
		size_t found = s.find(ans[j]);
		if (found != string::npos) {
			found == j ? strike++ : ball++;
		}
	}
}

int cal(const vector<string> num, const vector<pair<int, int>> num_ans, string ans) {
	int count = 0;
	do {
		bool isok = true;
		//전체 질문에 대해
		for (int i = 0; i < num.size(); i++) {
			int ball = 0, strike = 0;
			findString(num[i], ans, ball, strike);
			//볼이나 스트라이크 수가 다르면 탈락
			if (ball != num_ans[i].second || strike != num_ans[i].first) {
				isok = false;
				break;
			}
		}
		if (isok) {
			count++;
		}
	} while (next_permutation(ans.begin() , ans.end()));
	return count;
}

int main() {
	int n;
	cin >> n;
	vector<string> num(n);				//민혁의 답
	vector<pair<int, int>> num_ans(n);	//(strike,ball)
	for (int i = 0; i < n; i++) {
		cin >> num[i] >> num_ans[i].first >> num_ans[i].second;
	}

	string ans = "123";
	int sum = 0;
	for (ans[0] = '1'; ans[0] <= '7'; ans[0]++) {
		for (ans[1] = ans[0]+1; ans[1] <= '8'; ans[1]++) {
			for (ans[2] = ans[1]+1; ans[2] <= '9'; ans[2]++) {
				//3개의 숫자를 뽑아 순열에서 가능한 개수를 찾는다.
				sum += cal(num, num_ans, ans);
			}
		}
	}
	cout << sum;
}