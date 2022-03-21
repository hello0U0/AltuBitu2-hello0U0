#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int r, b;
	cin >> r >> b;
	/*이차방정식 근의 공식을 사용
	(x-2) * (y-2)=b;
	2*(x+y-2)=r -> y-2= r/2 - x
	(x-2) * (y-2) = (x-2)*(r/2-x) = -x^2 (2+r/2)x + -r = b -> x^2 -(2+r/2) + (b+r) = 0;
	근의 공식 (-b +-루트(b^2 - 4ac))/2 */
	int ans_b = 2 + r / 2;
	int ans_root = sqrt(pow(ans_b, 2) - 4 * (b + r));
	int x = (ans_b + ans_root)/2;
	int y = (ans_b - ans_root)/2;
	cout << x << " " << y;
}