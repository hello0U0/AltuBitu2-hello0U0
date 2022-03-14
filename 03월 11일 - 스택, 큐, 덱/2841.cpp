#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main() {
	int n, p;
	int count = 0;
	vector<stack<int>> guitar(7);	//1~6 사용
	cin >> n >> p;
	while (n--) {
		int nowr, nowp;
		cin >> nowr >> nowp;
		while (!guitar[nowr].empty()&&guitar[nowr].top() > nowp) {
			guitar[nowr].pop();
			count++;
		}
		if (guitar[nowr].empty()||guitar[nowr].top() != nowp) {
			guitar[nowr].push(nowp);
			count++;
		}
	}
	cout << count;
}