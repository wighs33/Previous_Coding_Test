#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// 현재 설치된 구조물이 '가능한' 구조물인지 확인하는 함수
bool possible(set<vector<int> > answer) {
    for (auto v : answer) {
        int x = v[0];
        int y = v[1];
        if (v[2] == 0) { // 설치된 것이 '기둥'인 경우
            bool check = false;
            // '바닥 위'라면 정상
            if (y == 0) check = true;
            // '보의 한 쪽 끝 부분 위' 혹은 '다른 기둥 위'라면 정상
            if (answer.find({ x - 1, y, 1 }) != answer.end()) check = true;
            if (answer.find({ x, y, 1 }) != answer.end()) check = true;
            if (answer.find({ x, y - 1, 0 }) != answer.end()) check = true;
            if (!check) return false; // 아니라면 거짓(False) 반환
        }
        else if (v[2] == 1) { // 설치된 것이 '보'인 경우
            bool check = false;
            bool left = false;
            bool right = false;
            // '한쪽 끝부분이 기둥 위' 혹은 '양쪽 끝부분이 다른 보와 동시에 연결'이라면 정상

            if (answer.find({ x, y - 1, 0 }) != answer.end()) check = true;
            if (answer.find({ x + 1, y - 1, 0 }) != answer.end()) check = true;
            if (answer.find({ x - 1, y, 1 }) != answer.end()) left = true;
            if (answer.find({ x + 1, y, 1 }) != answer.end()) right = true;
            if (left && right) check = true;
            if (!check) return false; // 아니라면 거짓(False) 반환
        }
    }
    return true;
}

vector<vector<int> > solution(int n, vector<vector<int> > build_frame) {
    set<vector<int> > answer;
    // 작업(frame)의 개수는 최대 1,000개
    for (int i = 0; i < build_frame.size(); i++) {
        auto _ = { build_frame[i][0],build_frame[i][1],build_frame[i][2] };
        if (build_frame[i][3] == 0) { // 삭제하는 경우
            // 일단 삭제를 해 본 뒤에
            answer.erase(_);
            if (!possible(answer)) { // 가능한 구조물인지 확인
                answer.insert(_); // 가능한 구조물이 아니라면 다시 설치
            }
        }
        if (build_frame[i][3] == 1) { // 설치하는 경우
            // 일단 설치를 해 본 뒤에
            answer.insert(_);
            if (!possible(answer)) { // 가능한 구조물인지 확인
                answer.erase(_); // 가능한 구조물이 아니라면 다시 제거
            }
        }
    }
    // 정렬된 결과를 반환
    vector<vector<int>> res(answer.begin(), answer.end());
    return res;
}