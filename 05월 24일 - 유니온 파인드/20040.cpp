//20040 사이클 게임
#include<iostream>
#include<vector>
using namespace std;
vector<int> parent;
int findParent(int node) {
	if (parent[node] < 0) return node;
	return parent[node] = findParent(parent[node]);
}
bool unionInput(int x, int y) {
	int xp = findParent(x);
	int yp = findParent(y);
	if (xp == yp) {
		return true;
	}
	if (xp < yp) {
		parent[xp] += parent[yp];
		parent[yp] = xp;
	}
	else {
		parent[yp] += parent[xp];
		parent[xp] = yp;
	}
	return false;
}
int main() {
	int n, m;
	cin >> n >> m;
	parent.assign(n, -1);
	int ans = 1;
	for (ans = 1; ans <= m; ans++) {
		int x, y;
		cin >> x >> y;
		if (unionInput(x, y)) break;
	}
	if (ans > m) ans = 0;
	cout << ans;
	return 0;
}