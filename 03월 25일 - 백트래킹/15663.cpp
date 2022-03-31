//15663 N과 M (9)
#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;

vector<int> num;
vector<int> ans;
vector <bool> use;
int n, m;
void baTr(int time) {
	//m개 수를 뽑으면 정렬
	if (time == m) {
		for (int i = 0; i < m; i++) {
			cout << ans[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		//이미 가진 숫자면 넘어가기
		if (use[i]) continue;
		//중복 숫자는 맨 첫 숫자부터 연속으로만 넣고 나머지는 넘어가기
		if (i > 0 && num[i] == num[i - 1] && !use[i - 1]) continue;
		//숫자 저장
		use[i] = 1;
		ans[time] = num[i];
		baTr(time + 1);
		use[i] = 0;
	}
	return;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	num.resize(n);
	ans.resize(m);
	use.resize(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	//작은수부터 정렬
	sort(num.begin(), num.end());
	baTr(0);
}