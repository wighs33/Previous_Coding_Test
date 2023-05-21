#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// ���� ��ġ�� �������� '������' ���������� Ȯ���ϴ� �Լ�
bool possible(set<vector<int> > answer) {
    for (auto v : answer) {
        int x = v[0];
        int y = v[1];
        if (v[2] == 0) { // ��ġ�� ���� '���'�� ���
            bool check = false;
            // '�ٴ� ��'��� ����
            if (y == 0) check = true;
            // '���� �� �� �� �κ� ��' Ȥ�� '�ٸ� ��� ��'��� ����
            if (answer.find({ x - 1, y, 1 }) != answer.end()) check = true;
            if (answer.find({ x, y, 1 }) != answer.end()) check = true;
            if (answer.find({ x, y - 1, 0 }) != answer.end()) check = true;
            if (!check) return false; // �ƴ϶�� ����(False) ��ȯ
        }
        else if (v[2] == 1) { // ��ġ�� ���� '��'�� ���
            bool check = false;
            bool left = false;
            bool right = false;
            // '���� ���κ��� ��� ��' Ȥ�� '���� ���κ��� �ٸ� ���� ���ÿ� ����'�̶�� ����

            if (answer.find({ x, y - 1, 0 }) != answer.end()) check = true;
            if (answer.find({ x + 1, y - 1, 0 }) != answer.end()) check = true;
            if (answer.find({ x - 1, y, 1 }) != answer.end()) left = true;
            if (answer.find({ x + 1, y, 1 }) != answer.end()) right = true;
            if (left && right) check = true;
            if (!check) return false; // �ƴ϶�� ����(False) ��ȯ
        }
    }
    return true;
}

vector<vector<int> > solution(int n, vector<vector<int> > build_frame) {
    set<vector<int> > answer;
    // �۾�(frame)�� ������ �ִ� 1,000��
    for (int i = 0; i < build_frame.size(); i++) {
        auto _ = { build_frame[i][0],build_frame[i][1],build_frame[i][2] };
        if (build_frame[i][3] == 0) { // �����ϴ� ���
            // �ϴ� ������ �� �� �ڿ�
            answer.erase(_);
            if (!possible(answer)) { // ������ ���������� Ȯ��
                answer.insert(_); // ������ �������� �ƴ϶�� �ٽ� ��ġ
            }
        }
        if (build_frame[i][3] == 1) { // ��ġ�ϴ� ���
            // �ϴ� ��ġ�� �� �� �ڿ�
            answer.insert(_);
            if (!possible(answer)) { // ������ ���������� Ȯ��
                answer.erase(_); // ������ �������� �ƴ϶�� �ٽ� ����
            }
        }
    }
    // ���ĵ� ����� ��ȯ
    vector<vector<int>> res(answer.begin(), answer.end());
    return res;
}