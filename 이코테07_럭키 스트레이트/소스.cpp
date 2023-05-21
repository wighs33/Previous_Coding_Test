#include <iostream>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;

	string s = to_string(N);
	int sum = 0;
	for (int i = 0; i < s.size() / 2; i++)
	{
		sum += s[i] - '0';
	}
	int cmp = 0;
	for (int i = s.size() / 2; i < s.size(); i++)
	{
		cmp += s[i] - '0';
	}
	sum == cmp ? cout << "LUCKY" : cout << "READY";
	cout << '\n';
}