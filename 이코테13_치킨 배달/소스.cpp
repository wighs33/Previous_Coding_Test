#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[50][50];
vector<pair<int, int> > chicken;
vector<pair<int, int> > house;

// ġŲ �Ÿ��� ���� ����ϴ� �Լ�
int getSum(vector<pair<int, int> > candidates) {
    int result = 0;
    // ��� ���� ���Ͽ�
    for (int i = 0; i < house.size(); i++) {
        int hx = house[i].first;
        int hy = house[i].second;
        // ���� ����� ġŲ ���� ã��
        int temp = 1e9;
        for (int j = 0; j < candidates.size(); j++) {
            int cx = candidates[j].first;
            int cy = candidates[j].second;
            temp = min(temp, abs(hx - cx) + abs(hy - cy));
        }
        // ���� ����� ġŲ �������� �Ÿ��� ���ϱ�
        result += temp;
    }
    // ġŲ �Ÿ��� �� ��ȯ
    return result;
}

int main(void) {
    cin >> n >> m;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            cin >> arr[r][c];
            if (arr[r][c] == 1) house.push_back({ r, c }); // �Ϲ� ��
            else if (arr[r][c] == 2) chicken.push_back({ r, c }); // ġŲ��
        }
    }

    // ��� ġŲ �� �߿��� m���� ġŲ ���� �̴� ���� ���
    vector<bool> binary(chicken.size());
    fill(binary.end() - m, binary.end(), true);

    // ġŲ �Ÿ��� ���� �ּҸ� ã�� ���
    int result = 1e9;

    do {
        vector<pair<int, int> > now;
        for (int i = 0; i < chicken.size(); i++) {
            if (binary[i]) {
                int cx = chicken[i].first;
                int cy = chicken[i].second;
                now.push_back({ cx, cy });
            }
        }
        result = min(result, getSum(now));
    } while (next_permutation(binary.begin(), binary.end()));

    cout << result << '\n';
}