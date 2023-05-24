#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {
	int N, M, K, X;
	cin >> N >> M >> K >> X;

	unordered_map<int, vector<int>> graph;

	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;
		graph[s].push_back(e);
	}

	queue<int> q;
	vector<int> dist(N + 1, -1);

	// ��� ���ñ����� �Ÿ��� 0���� ����
	dist[X] = 0;

	// �ʺ� �켱 Ž��(BFS) ����
	queue<int> q;
	q.push(X);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		// ���� ���ÿ��� �̵��� �� �ִ� ��� ���ø� Ȯ��
		for (int i = 0; i < graph[now].size(); i++) {
			int nextNode = graph[now][i];
			// ���� �湮���� ���� ���ö��
			if (dist[nextNode] == -1) {
				// �ִ� �Ÿ� ����
				dist[nextNode] = dist[now] + 1;
				q.push(nextNode);
			}
		}
	}

	// �ִ� �Ÿ��� K�� ��� ������ ��ȣ�� ������������ ���
	bool check = false;
	for (int i = 1; i <= N; i++) {
	    if (dist[i] == K) {
	        cout << i << '\n';
	        check = true;
	    }
	}
	
	// ���ٸ� -1 ���
	if (!check) cout << -1 << '\n';
}