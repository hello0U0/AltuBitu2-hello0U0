#include<iostream>
#include<stack>
#include<deque>
using namespace std;

int main() {
	int n,x;
	stack<int> nstack;
	deque<int> answers;
	cin >> n;
	while (n) {
		cin >> x;
		nstack.push(x);
		n--;
	}

	while (!nstack.empty()) {
		n++;
		switch (nstack.top()) {
		case 2:
			x = answers.back();
			answers.pop_back();
			answers.push_back(n);
			answers.push_back(x);
			break;
		case 3:
			answers.push_front(n);
			break;
		default:
			answers.push_back(n);
			break;
		}
		nstack.pop();
	}
	while (!answers.empty()) {
		cout << answers.back() << " ";
		answers.pop_back();
	}
}