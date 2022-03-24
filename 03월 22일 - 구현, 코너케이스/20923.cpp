//20923 숫자 할리갈리 게임
#include<iostream>
#include<deque>
#include<vector>
using namespace std;

//카드 빼기
int popCard(deque<int>& card) {
	int x = card.back();
	card.pop_back();
	return x;
}
//pop_card의 맨 뒷장을 push_card의 맨 앞으로 넣는다.
void pushCard(deque<int>& push_card, deque<int>& pop_card) {
	while (!pop_card.empty()) {
		push_card.push_front(popCard(pop_card));
	}
	return;
}

int main() {
	int n, m;
	vector<deque<int>> dosu_card(2), dosu_gcard(2);	//도 = 0, 수 = 1
	cin >> n >> m;
	while (n--) {
		int do_now, su_now;
		cin >> do_now >> su_now;
		dosu_card[0].push_back(do_now);
		dosu_card[1].push_back(su_now);
	}
	for (int i = 0; i < m; i++) {
		//순서대로 카드를 빼서 그라운드에 둔다.그라운드에 둔 카드는 그라운드 카드덱을 뒤집었을때 맨 앞이다.
		dosu_gcard[i % 2].push_front(popCard(dosu_card[i % 2]));
		//cout << i << " ";
		//한명의 카드덱이 비면 끝난다.
		if (dosu_card[0].empty() || dosu_card[1].empty()) break;

		//5카드가 있으면 do가 이긴다.
		if (dosu_gcard[i % 2].front() == 5) {
			pushCard(dosu_card[0], dosu_gcard[1]);
			pushCard(dosu_card[0], dosu_gcard[0]);
		}
		//그라운드에 카드가 각각 최소 1개씩은 있어야 된다.
		if (dosu_gcard[0].empty() || dosu_gcard[1].empty()) continue;
		//두 카드의 합이 5면 su가 이긴다.
		if (dosu_gcard[0].front() + dosu_gcard[1].front() == 5) {
			pushCard(dosu_card[1], dosu_gcard[0]);
			pushCard(dosu_card[1], dosu_gcard[1]);
		}
	}
	//카드양이 많은 사람이 이긴다. 카드수가 같으면 dosu를 출력한다.
	n = dosu_card[0].size() - dosu_card[1].size();
	if (n >= 0) cout << "do";
	if (n <= 0) cout << "su";

	return 0;
}