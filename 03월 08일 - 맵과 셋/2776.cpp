#include<iostream>
#include<set>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int test_case = 0; test_case < t; test_case++) {
		int n,m;
		set<int> note;
		set<int>::iterator iter;
		//수첩 1 입력
		cin >> n;
		while(n--) {
			cin >> m;
			note.insert(m);
		}
		//수첩 2 입력 및 출력
		cin >> n;
		while(n--) {
			cin >> m;
			set<int>::iterator iter = note.find(m);
			cout << (iter != note.end()) << '\n';
		}
	}
	return 0;
}