#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> v = {1,7,8,2,3,4,9,123,45,908,324,768,34};

	partial_sort(v.begin(), v.begin() + 4, v.end());

	for_each(v.begin(), v.end(), [](int a) {cout << a << ' '; });
}