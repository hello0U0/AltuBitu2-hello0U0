#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	string n;
	bool isok = false;
	int sum = 0;
	cin >> n;
	for (int i = 0; i < n.size();i++) {
		int now = n[i] - '0';
		if (now == 0) isok = true;		//0이 있는지 판단
		sum += now;						//각 자리의 합을 구한다.
	}
	//0이 없으면 10의 배수가 아니다. 각 자리의 합이 3의 배수가 아니면 n은 3의 배수가 아니다.
	if (!isok||sum%3!=0){
		cout << -1;
		return 0;
	}
	//숫자를 내림차순으로 정렬한다.
	sort(n.begin(), n.end(),greater<>());
	cout << n;
	return 0;
}