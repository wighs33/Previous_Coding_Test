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

	// 출발 도시까지의 거리는 0으로 설정
	dist[X] = 0;

	// 너비 우선 탐색(BFS) 수행
	queue<int> q;
	q.push(X);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		// 현재 도시에서 이동할 수 있는 모든 도시를 확인
		for (int i = 0; i < graph[now].size(); i++) {
			int nextNode = graph[now][i];
			// 아직 방문하지 않은 도시라면
			if (dist[nextNode] == -1) {
				// 최단 거리 갱신
				dist[nextNode] = dist[now] + 1;
				q.push(nextNode);
			}
		}
	}

	// 최단 거리가 K인 모든 도시의 번호를 오름차순으로 출력
	bool check = false;
	for (int i = 1; i <= N; i++) {
	    if (dist[i] == K) {
	        cout << i << '\n';
	        check = true;
	    }
	}
	
	// 없다면 -1 출력
	if (!check) cout << -1 << '\n';
}