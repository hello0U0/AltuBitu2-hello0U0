#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a, b;	//구간 [a,b]
	vector<int> arr(21);
	for (int i = 1; i < 21; i++) arr[i] = i;	//{X, 1,2,3......,19,20}

	for (int i = 0; i < 10; i++) {
		cin >> a >> b;	//1-20 사이의 구간 입력
		int mid = (a + b) / 2;		//a~b 중간값
		// a ~ b값을 그 중간값을 기준으로 대칭적으로 교환 
		for (int j = 0; j <= mid - a; j++) {
			swap(arr[a + j], arr[b - j]);
		}
	}

	for (int i = 1; i < 21; i++) cout << arr[i] << " ";
	return 0;
}