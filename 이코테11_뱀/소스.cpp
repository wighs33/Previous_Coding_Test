#include <iostream>
#include <string>
#include <queue>
//#include <windows.h>

using namespace std;

//template<typename T>
//void e(T t) { cout << t << endl; }
//template<typename T>
//void s(T t) { cout << t << ' '; }

enum data
{
	EMPTY,
	APPLE,
	SNAKE
};

enum direction
{
	RIGHT,
	UP,
	LEFT,
	DOWN
};

int main() {
	int N; cin >> N;

	vector<int> v(N);
	vector<vector<int>> board(N, v);
	queue<pair<int, int>> snake_q;
	pair<int, int> snake_head = { 0,0 };
	snake_q.push(snake_head);
	board[0][0] = SNAKE;
	int snake_dir_degree = 0;


	int K; cin >> K;
	for (size_t i = 0; i < K; i++)
	{
		int h, w;
		cin >> h >> w;
		board[h - 1][w - 1] = APPLE;
	}
	int L; cin >> L;
	queue<pair<int, int>> move_dir_q;
	for (size_t i = 0; i < L; i++)
	{
		int move;
		char dir;
		cin >> move >> dir;
		move_dir_q.push({ move,dir });
	}
	auto move_limit = move_dir_q.front();
	move_dir_q.pop();

	int cnt = 0;
	vector<pair<int, int>> dir_basis(4);
	dir_basis[RIGHT] = { 0,1 };
	dir_basis[UP] = { -1,0 };
	dir_basis[LEFT] = { 0,-1 };
	dir_basis[DOWN] = { 1,0 };

	while (true)
	{
		//뱀 이동
		snake_head.first += dir_basis[snake_dir_degree / 90].first;
		snake_head.second += dir_basis[snake_dir_degree / 90].second;

		//벽체크
		if (snake_head.first <= -1 || snake_head.first >= N || snake_head.second <= -1 || snake_head.second >= N) {
			cout << ++cnt << endl;
			return 0;
		}

		//몸체크
		if (board[snake_head.first][snake_head.second] == SNAKE) {
			cout << ++cnt << endl;
			return 0;
		}

		//사과체크
		if (board[snake_head.first][snake_head.second] != APPLE) {
			//꼬리지우기
			board[snake_q.front().first][snake_q.front().second] = EMPTY;
			snake_q.pop();
		}

		//머리그리기
		board[snake_head.first][snake_head.second] = SNAKE;
		snake_q.push(snake_head);

		//시간초 계산
		++cnt;
		//e(cnt);
		if (move_limit.first - cnt == 0) {
			if (move_limit.second == 'L') snake_dir_degree += 90;
			else snake_dir_degree -= 90;

			if (snake_dir_degree == -90) snake_dir_degree = 270;
			else if (snake_dir_degree == 360) snake_dir_degree = 0;

			if (move_dir_q.empty()) {
				move_limit.first = N;
			}
			else
			{
				move_limit = move_dir_q.front();
				move_dir_q.pop();
			}
		}

		////출력
		//for (int i = 0; i < N; i++) {
		//	for (int j = 0; j < N; j++) s(board[i][j]); e("");
		//}e("");

		//Sleep(1000);
	}
}