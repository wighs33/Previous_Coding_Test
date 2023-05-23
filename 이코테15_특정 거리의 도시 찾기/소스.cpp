#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <queue>

using namespace std;

template<typename T>
void e(T t) { cout << t << endl; }
template<typename T>
void s(T t) { cout << t << ' '; }

int main(void) {
	int N, M, K, X;
	cin >> N >> M >> K >> X;

	unordered_map<int, vector<int>> graph;

	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;
		graph[s].push_back(e);
	}

	queue<int> bq;
	vector<bool> visited(N);

	int cnt = 0;
	bq.push(1);
	while (cnt<3)
	{
		int _ = bq.front();
		bq.pop();
		visited[_] = true;

		for (int i = 0; i < graph[_].size(); i++)
		{
			bq.push(graph[_][i]);
		}

		++cnt;
	}
}