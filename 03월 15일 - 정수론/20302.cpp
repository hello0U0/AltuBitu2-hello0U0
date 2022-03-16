#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//소수를 찾고 소수가 아닌 것들은 어떤 (가장작은) 소수의 배수인지 구한다.
vector<int> calPrime() {
	vector<int> prime(100001, 1);
	for (int i = 2; i * i <= 100000; i++) {
		if (prime[i] != 1) continue;
		for (int j = i * i; j < 100001; j += i) {
			if (prime[j] == 1) prime[j] = i;
		}
	}
	return prime;
}

void calNummap(unordered_map<int, int> &nummap,const vector<int> &prime,char &cal,int &num) {
	if (num < 0) num = -num;
	//곱셈일때 수를 소인수 분해하여 각 소수들의 개수만큼 더한다.
	if (cal == '*') {
		while (prime[num] != 1) {
			nummap[prime[num]]++;
			num /= prime[num];
		}
		nummap[num]++;
		return;
	}//나눗셈일때 수를 소인수 분해하여 각 소수들의 개수만큼 뺀다.
	while (prime[num] != 1) {
		nummap[prime[num]]--;
		num /= prime[num];
	}
	nummap[num]--;
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
	calNummap(nummap, prime, cal, num);
	for (int i = 1; i < n; i++) {
		cin >>cal>> num;
		if (num == 0)isok = true;
		if (isok) continue;
		calNummap(nummap, prime, cal, num);
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