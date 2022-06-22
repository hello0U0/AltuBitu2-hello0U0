//4195 친구 네트워크
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
unordered_map<string, string> parent;

//해당 노드의 루트노드 찾기
string findParent(string node) {
	if (parent[node].empty()) {	//처음 등장하면
		parent[node] = "-1";		//초기화
		return node;
	}
	if (parent[node][0]=='-') {	//결과값이 음수면 루트
		return node;
	}
	return parent[node] = findParent(parent[node]);
}
void unionInput(string x, string y) {
	string xp = findParent(x);
	string yp = findParent(y);
	//이미 같은 집합이면 끝
	if (xp == yp) return;
	int ixp = stoi(parent[xp]);
	int iyp = stoi(parent[yp]);
	int sum = ixp + iyp;
	//xp의 자식이 더 많으면 xp 밑으로 yp가 들어간다.
	if (ixp<iyp) {
		parent[xp] = to_string(sum);
		parent[yp] = xp;
	}//아니면 yp밑으로 xp가 들어간다.
	else {
		parent[yp] = to_string(sum);
		parent[xp] = yp;
	}
	return;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc--) {
		parent.clear();
		int f;
		cin >> f;
		while(f--) {
			string a;
			string b;
			cin >> a >> b;
			unionInput(a, b);
			int ans = stoi(parent[findParent(a)]);
			cout << -ans<<"\n";
		}
	}
	return 0;
}