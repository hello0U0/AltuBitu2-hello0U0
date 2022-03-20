#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#define MAX 1e5+1
using namespace std;

//소수를 찾고 소수가 아닌 것들은 어떤 (가장작은) 소수의 배수인지 구한다.
vector<int> calPrime() {
	vector<int> prime(MAX, 1);
	for (int i = 2; i * i < MAX; i++) {
		if (prime[i] != 1) continue;
		for (int j = i * i; j < MAX; j += i) {
			if (prime[j] == 1) prime[j] = i;
		}
	}
	return prime;
}

void calNummap(unordered_map<int, int> &nummap,const vector<int> &prime,char &cal,int num) {
	//곱셈일때 수를 소인수 분해하여 각 소수들의 개수만큼 더한다.
	int x = cal == '*' ? 1:-1;
	while (prime[num] != 1) {
		nummap[prime[num]] += x;
		num /= prime[num];
	}
	nummap[num] += x;
	return;
}

int main() {
	int n, result, num;
	char cal='*';
	bool isok = false;
	unordered_map<int, int> nummap;		//소수와 소수의 개수를 저장
	vector<int> prime = calPrime();		

	cin >> n;
	//첫번째 수는 cal='*'라고 설정
	cin >> num;
	if (num == 0)isok = true;
	calNummap(nummap, prime, cal, abs(num));
	for (int i = 1; i < n; i++) {
		cin >>cal>> num;
		if (num == 0)isok = true;
		if (isok) continue;
		calNummap(nummap, prime, cal, abs(num));
	}

	//0이 있다면 무조건 정수다.
	if (isok) {
		cout << "mint chocolate";
		return 0;
	}
	//1에 대해선 상관하지 않는다.
	if(nummap[1]<0)nummap[1] = 0;
	for (auto iter : nummap) {
		if (iter.second < 0) {
			cout << "toothpaste";
			return 0;
		}
	}
	cout << "mint chocolate";
	return 0;
}