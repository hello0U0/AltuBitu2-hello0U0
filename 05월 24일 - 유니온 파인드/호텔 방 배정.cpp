//level4 호텔 방 배정
#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<long long, long long> room;

long long findParent(long long node) {
    if (room[node] == 0) return node;
    return room[node] = findParent(room[node]);
}


vector<long long> solution(long long k, vector<long long> room_number) {
    int size = room_number.size();
    vector<long long> answer(size);
    for (int i = 0; i < size; i++) {
        long long now = room_number[i];
        long long result = findParent(now);
        room[result] = findParent(result + 1);
        answer[i] = result;
    }
    return answer;
}