//11559 Puyo Puyo
#include<iostream>
#include<vector>
using namespace std;

const int ROW = 12, CAL = 6;
vector<vector<char>> field;				//계산용 필드
vector<pair<int, int>> chain;			//한번에 지우는 뿌요들 위치
										// 'x'는 문자를 지웠음을 의미

//뿌요들 내리기
bool downPoyo(vector<vector<char>> &nowfield) {
	for (int i = 0; i < CAL; i++) {
		vector<char> now;
		int xcnt = 0;
		int j;
		//세로줄에 대해
		for (j = 0; j <ROW; j++) {
			switch (nowfield[j][i]) {
			case 'x':
				xcnt++;
			case '.':
				break;
			default:
				now.push_back(nowfield[j][i]);
				break;
			}
		}//'x'가 없으면 넘어가고
		if (xcnt == 0) continue;
		//'x'가 있으면 아래서부터 문자를 채우고 'x'개수만큼 '.'을 채운다.
		j = ROW - 1;
		while (!now.empty()) {
			nowfield[j--][i] = now.back();
			now.pop_back();
		}
		for (int k = 0; k < xcnt; k++) nowfield[j--][i] = '.';
	}
	return true;
}


//뿌요를 지운다
bool deletePoyo(vector<vector<char>> &nowfield) {
	while (!chain.empty()) {
		int x = chain.back().first, y = chain.back().second;
		nowfield[x][y] = 'x';
		chain.pop_back();
	}
	return true;
}

//현재위치의 문자를 지우고 함께 지울 뿌요 위치를 chain에 기록. 지우는 뿌요 수를 반환한다.
int calDelete(int &chain_i) {
	int count = 0;
	vector<pair<int,int>> calnum = { {-1,0},{1,0},{0,-1},{0,1} };	//상하좌우 인덱스 계산용
	int x = chain[chain_i].first, y = chain[chain_i].second;
	
	//이미 계산 했거나 뿌요가 아니면 넘어간다.
	if (field[x][y] == 'x' || field[x][y] == '.') return 0;
	//현재 위치의 상하좌우에 대해
	for (int i = 0; i < 4; i++) {
		int nowx = x + calnum[i].first, nowy = y + calnum[i].second;
		//필드 범위 밖이면 넘어가기
		if (nowx >= ROW || nowx < 0 || nowy >= CAL || nowy < 0) continue;
		//지워야할 문자와 같은 문자면 chain에 넣는다.
		if (field[nowx][nowy] == field[x][y]) chain.push_back({ nowx, nowy });
	}
	//현재 위치의 문자를 지운다.
	field[x][y] = 'x';
	count++;
	//다음 뿌요를 지운다. 다음 뿌요가 없으면 지운 뿌요 수를 반환한다.
	if (++chain_i < chain.size()) count += calDelete(chain_i);
	return count;
}

//연쇄가 몇번 일어나는지 계산
int calChainReact(vector<vector<char>> &poyoField) {
	int chainCnt = 0;
	bool isDeletePoyo = false;
	do {
		isDeletePoyo = false;
		field = poyoField;	//뿌요 사본을 만들어 계산
		//지울 수 있는 뿌요들은 지우기
		for (int i = ROW - 1; i > 0; i--) {
			bool isEnd = true;	//더이상 계산할 뿌요가 없는지(가로줄이 모두 .인지) 확인
			for (int j = 0; j < CAL; j++) {
				char nowpoyo = field[i][j];
				//뿌요가 없으면 넘어가기
				if (nowpoyo == '.') continue;
				isEnd = false;
				if (nowpoyo == 'x') continue;
				//뿌요가 있으면 연쇄작용이 가능한지 체크. 지울 수 있으면 지운다.
				chain.clear();
				chain.push_back({ i,j });
				int chain_i = 0;
				//원본 뿌요를 지울 수 있으면 지운다.
				if (calDelete(chain_i) >= 4) isDeletePoyo = deletePoyo(poyoField);
			}//더이상 계산이 필요하지 않으면 멈추기
			if (isEnd) break;
		}
		//지운 뿌요가 있으면 빈 자리에 뿌요를 내리고 없으면 멈춘다.
		if (isDeletePoyo) chainCnt += downPoyo(poyoField);
	} while (isDeletePoyo);

	return chainCnt;
}


int main() {
	vector<vector<char>> poyoField(ROW, vector<char>(CAL));
	//필드 입력받기
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < CAL; j++) {
			cin >> poyoField[i][j];
		}
	}
	//연산 및 출력
	cout << calChainReact(poyoField);
}