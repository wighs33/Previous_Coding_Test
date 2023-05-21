#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

template<typename T>
void e(T t) { cout << t << endl; }
template<typename T>
void s(T t) { cout << t << ' '; }

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	const int key_s = key.size();
	const int lock_s = lock.size();

	vector<int> v(key_s * 2 + lock_s);
	vector<vector<int>> field(key_s * 2 + lock_s, v);

	for (int i = 0; i < lock_s; i++)
	{
		for (int j = 0; j < lock_s; j++)
		{
			field[key_s + i][key_s + j] = lock[i][j];
		}
	}

	queue<pair<int, int>> key_list;
	queue<pair<int, int>> lock_list;

	for (int i = 0; i < key_s; i++)
		for (int j = 0; j < key_s; j++)
			if (key[i][j] == 1) {
				key_list.push({ i,j });
			}

	for (int i = 0; i < lock_s; i++)
		for (int j = 0; j < lock_s; j++)
			if (lock[i][j] == 0) {
				lock_list.push({ i,j });
			}
	if (lock_list.empty()) return false;

	auto key_i = key_list.front();
	key_list.pop();
	int lock_cnt = 0;
	while (!key_list.empty())
	{
		auto lock_i = lock_list.front();
		lock_list.pop();
		lock_list.push(lock_i);
		++lock_cnt;

		if (lock_cnt == lock_list.size()) {
			lock_cnt = 0;
			key_i = key_list.front();
			key_list.pop();
		}

		for (int cnt = 0; cnt < 4; cnt++)
		{
			auto tmp_field = field;

			for (int i = 0; i < key_s; i++)
			{
				for (int j = 0; j < key_s; j++)
				{
					tmp_field[key_s + lock_i.first - key_i.first + i][key_s + lock_i.second - key_i.second + j] += key[i][j];
				}
			}

			bool b = false;
			for (int i = 0; i < lock_s; i++)
			{
				for (int j = 0; j < lock_s; j++)
				{
					int _ = tmp_field[key_s + i][key_s + j];
					if (_ == 2 or _ == 0) {
						b = true;
						break;
					}
				}
				if (b) break;
			}

			//e("피벗");
			//s(key_i.first); e(key_i.second);
			//s(lock_i.first); e(lock_i.second);
			//e("");

			//e("자물쇠");
			//for (int i = 0; i < lock_s; i++)
			//{
			//	for (int j = 0; j < lock_s; j++)
			//	{
			//		s(lock[i][j]);
			//	}
			//	e("");
			//}
			//e("");

			//e("합체");
			//for (int i = 0; i < lock_s; i++)
			//{
			//	for (int j = 0; j < lock_s; j++)
			//	{
			//		s(tmp_field[key_s + i][key_s + j]);
			//	}
			//	e("");
			//}
			//e("");


			if (!b) return true;
			b = false;

			//90도 회전
			//e("키");
			auto tmp_key = key;
			for (int i = 0; i < key_s; i++)
			{
				for (int j = 0; j < key_s; j++)
				{
					tmp_key[i][j] = key[key_s - 1 - j][i];
					//s(tmp_key[i][j]);
				}
				//e("");
			}
			//e("");

			key = tmp_key;

			int _ = key_i.first;
			key_i.first = key_i.second;
			key_i.second = key_s - 1 - _;
		}
	}

	return false;
}

int main() {
	cout << solution({ {0, 0, 0}, {1, 0, 0}, {0, 1, 1} }, { {1,0,1,1}, {1,1, 1, 1}, {1,1, 1, 0}, {1,1, 0, 1} }) << endl;
}