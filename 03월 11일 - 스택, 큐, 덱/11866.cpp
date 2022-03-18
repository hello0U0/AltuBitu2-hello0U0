#include<iostream>
#include<queue>
using namespace std;

int main() {
	int n, k;
	queue<int> q;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) q.push(i);
	cout << '<';
	while (n>1) {
		int now = (k % n) != 0 ? k % n : k; // k==n이면 k번째를 빼지만 k%n=0이기 때문에 따로 처리 
		for (int i = 1; i < now;i++){
			q.push(q.front());
			q.pop();
		}
		cout << q.front() << ", ";
		q.pop();
		n--;
	}
	cout << q.front() << '>';
}