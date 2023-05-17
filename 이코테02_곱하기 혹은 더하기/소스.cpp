#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sol(string s)
{
	sort(s.begin(), s.end(), greater<>());

	int start = s[0] - '0';

	for (size_t i = 1; i < s.size(); ++i){
		int num = s[i] - '0';
		if (num == 0)
			start += num;
		else
			start *= num;
	}

	return start;
}

int main()
{
	cout << sol("02984") << endl;
	cout << sol("567") << endl;
}
