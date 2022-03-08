#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

struct coord {
	int x, y;
};

bool cmp(const coord& a, const coord& b) {
	if (a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}

int main() {
	int n, x, y;
	scanf_s("%d", &n);
	vector<coord> arr(n);
	for (int i = 0; i < n; i++)  scanf_s("%d %d",&arr[i].x,&arr[i].y);

	sort(arr.begin(), arr.end(), cmp);
	
	for (int i = 0; i < n; i++)  printf_s("%d %d\n", arr[i].x, arr[i].y);
	return 0;
}