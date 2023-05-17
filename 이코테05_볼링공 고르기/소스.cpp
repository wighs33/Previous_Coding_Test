#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sol(int n, int m, vector<int> v)
{
	sort(v.begin(), v.end());

	int res = v.size() * (v.size() - 1) / 2;

	for (int i = 1; i <= m; i++)
	{
		auto start_ = lower_bound(v.begin(), v.end(), i);
		auto end_ = upper_bound(v.begin(), v.end(), i);
		int _ = distance(start_, end_);
		res -= _ * (_ - 1) / 2;
	}

	return res;
}

int main() {
	cout << sol(5, 3, { 1,3,2,3,2 }) << endl;
	cout << sol(8, 5, { 1,5,4,3,2,4,5,2 }) << endl;
}