#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
void e(T t) { cout << t << endl; }
template<typename T>
void s(T t) { cout << t << ' '; }

int solution(int n, vector<int> weak, vector<int> dist) {
    // 길이를 2배로 늘려서 '원형'을 일자 형태로 변경
    int length = weak.size();
    for (int i = 0; i < length; i++) {
        weak.push_back(weak[i] + n);
    }
    int answer = dist.size() + 1;
    for (int start = 0; start < length; start++) {
        do {
            s(weak[start]);
            int cnt = 1;
            int position = weak[start] + dist[cnt - 1];
            for (int index = start; index < start + length; index++) {
                if (position < weak[index]) {
                    cnt += 1;
                    if (cnt > dist.size()) {
                        break;
                    }
                    position = weak[index] + dist[cnt - 1];
                    s(weak[index]);
                }
            }
            e("");
            answer = min(answer, cnt);
        } while (next_permutation(dist.begin(), dist.end()));
    }
    if (answer > dist.size()) {
        return -1;
    }
    return answer;
}

int main()
{
    //e(solution(12, { 1, 5, 6, 10 }, { 1, 2, 3, 4 }));
    e(solution(12, { 1, 3, 4, 9, 10 }, { 3, 5, 7 }));
}