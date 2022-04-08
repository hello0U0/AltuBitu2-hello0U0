//2075 N번째 큰 수
#include<iostream>
#include<queue>
using namespace std;


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	//가장 작은수가 top
	priority_queue<int,vector<int>,greater<>> ans;
	for (int i = 0; i < n * n; i++) {
		int x;
		cin >> x;
		if (ans.size() >= n) {	//n번째 수 이상이 등장하면
			if (x <= ans.top()) continue; //n번째 수보다 작거나 같으면 무시
			else ans.pop();	//n번째수보다 크면 제일 작은수를 빼고 x를 넣는다.
		}
		ans.emplace(x);
	}
	cout << ans.top();
}