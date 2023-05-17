#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sol(int m, vector<int> v)
{
	sort(v.begin(), v.end(), greater<>());
	int s = 0;
	int cnt = 0;

	while (s < m)
	{
		s += v[s];
		++cnt;
	}

	return cnt;
}

int main()
{
	cout << sol(5, { 2,3,1,2,2 }) << endl;
}
