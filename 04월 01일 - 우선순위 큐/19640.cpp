//19640 화장실의 규칙
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

const int MAX = 1e5;

struct person {
	int d;
	int h;
	int pm;
	bool isdeka;
};
struct cmp {
	bool operator()(const person& x1, const person& x2) {
		if (x1.d != x2.d) return x2.d > x1.d;
		if (x1.h != x2.h) return x2.h > x1.h;
		return x2.pm < x1.pm;
	}
};
int calTime(vector<queue<person>> &m_person) {
	int time = 0;	//몇번째 사람까지 들어갔는가
	//선두 중 우선순위 구하기
	priority_queue<person, vector<person>, cmp> ans;
	//선두들 초기화
	for (int i = 0; i < m_person.size(); i++) {
		if (m_person[i].empty()) continue;
		ans.push(m_person[i].front());
		m_person[i].pop();
	}
	while (!ans.empty()) {
		//한사람 들어감
		person now = ans.top();
		ans.pop();
		//들어간 사람이 데카면 멈춘다.
		if (now.isdeka) break;
		time++;
		//들어간 사람 줄의 다음 사람이 선두로 들어온다.
		if (m_person[now.pm].empty()) continue;
		ans.push(m_person[now.pm].front());
		m_person[now.pm].pop();
	}
	return time;
}
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<queue<person>> m_person(m);//m개의 줄
	person deka;
	//i번째 사람이 i%m번째 줄에 선다.
	for (int i = 0; i < n; i++) {
		int d, h;
		cin >> d >> h;
		person x = {d,h,i%m,0};
		if (i == k) x.isdeka = 1;
		m_person[i%m].push(x);
	}
	cout << calTime(m_person);
}