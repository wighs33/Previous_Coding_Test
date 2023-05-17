#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

using pqii = priority_queue<pair<int, int>>;

int solution(vector<int> food_times, long long k) {
	pqii pq;
	int size_ = food_times.size();

	for (size_t i = 0; i < size_; i++)
	{
		pq.push({ -food_times[i], i + 1 });
	}

	int eat = 0;

	while (k >= (long long)(-pq.top().first - eat) * size_)
	{
		k -=(long long)(-pq.top().first - eat) * size_;
		int _ = -pq.top().first;
		pq.pop();
		if (pq.empty()) return -1;
		if (eat >= _) {
			--size_;
			continue;
		}
		eat = _;
		--size_;
	}
	
	vector<int> vec_;
	while (!pq.empty())
	{
		vec_.push_back(pq.top().second);
		pq.pop();
	}
	sort(vec_.begin(), vec_.end());
	return vec_[k%size_];
}

int main() {
	cout << solution({ 8,6,4 }, 15) << endl;
	cout << solution({ 2, 1, 1,3,1,1,1,2 }, 10) << endl;
	cout << solution({ 3,1,2 }, 5) << endl;
	cout << solution({ 4,2,3,6,7,1,5,8 }, 16) << endl;
	cout << solution({ 4,2,3,6,7,1,5,8 }, 27) << endl;
	cout << solution({ 3,1,1,1,2,4,3 }, 12) << endl;
	cout << solution({ 1,1,1,1 }, 4) << endl;
}