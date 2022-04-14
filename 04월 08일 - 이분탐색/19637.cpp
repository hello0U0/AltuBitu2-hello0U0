//19637 IF문 좀 대신 써줘
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int, string> pis;

string binarySearch(int left, int right, const int &target, const vector<pis> &max_title) {
	while (left <= right) {
		int mid = (left + right + 1) / 2;	// mid가 0이 나오는 경우 방지
		//타겟이 상한값 범위에 있다면 해당 타이틀을 리턴
		if (max_title[mid - 1].first < target && target <= max_title[mid].first) {
			return max_title[mid].second;
		}//타깃이 중간값보다 작다면
		if (target < max_title[mid].first) {
			right = mid - 1;
		}//타깃이 중간값보다 크다면
		else {
			left = mid + 1;
		}
	}
	return "";
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<pis> max_title;	//상한값 - 칭호
	max_title.push_back({ -1,""});
	for (int i = 0; i < n; i++) {
		int xi;
		string xs;
		cin >> xs >> xi;
		if (xi > max_title.back().first) {
			max_title.push_back({ xi,xs });
		}
	}
	n = max_title.size()-1;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		cout << binarySearch(0, n, x, max_title)<<'\n';
	}
	return 0;
}