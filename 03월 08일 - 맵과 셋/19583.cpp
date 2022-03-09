#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() {
	string start_time, end_time, close_time;
	int count = 0;
	map<string, int> name_check;

	cin >> start_time >> end_time >> close_time;
	while (!cin.eof()) {
		string time, name;
		cin >> time >> name;
		//시작전에 채팅친 학생은 map에 기록
		if (time <= start_time) {
			name_check[name] = 0;
		}// 총회가 끝난 때부터 스트리밍 종료되기전까지
		else if (time >= end_time && time <= close_time) {
			// 채팅하면 map에 기록되어있을경우에만 체크
			if (name_check.find(name) != name_check.end()) {
				name_check[name] = 1;
			}
		}
	}//map에서 체크된 사람들만 계산
	for (auto iter : name_check) {
		if (iter.second ) count++;
	}

	cout << count;
	return 0;
}