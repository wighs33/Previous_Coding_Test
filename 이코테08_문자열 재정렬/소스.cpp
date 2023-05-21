#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string sol(string s)
{
	sort(s.begin(), s.end());
	int i = 0;
	int sum = 0;
	for (; i < s.size(); i++)
	{
		if (isalpha(s[i])) break;
		sum += s[i] - '0';
	}

	return s.substr(i, s.size()) + to_string(sum);
}

int main() {
	cout << sol("K1KA5CB7") << endl;
	cout << sol("AJKDLSI412K4JSJ9D") << endl;
}