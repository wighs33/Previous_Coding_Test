#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int sol(int n, vector<int> v)
{
	//초기화
	sort(v.begin(), v.end());
	set<int> num_list;
	num_list.insert(v[0]);
	int save = 1;

	for (size_t i = 1; i < v.size(); i++)
	{
		//set에 추가
		set<int> _ = num_list;
		for (auto& d : num_list)
		{
			_.insert(d + v[i]);
		}
		num_list = _;
		num_list.insert(v[i]);

		//최소 금액 확인
		for (int j = save; j <= num_list.size(); j++)
		{
			if (num_list.find(j) == num_list.end())
				return j;
		}
		save = num_list.size() + 1;
	}

	return save;
}

int main() {
	cout << sol(5, { 3,2,1,1,9 }) << endl;
}