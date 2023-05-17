//น้มุ
#include <iostream>

using namespace std;

int main()
{
	while (true)
	{
		string s;
		cin >> s;

		int cnt0 = 0;
		int cnt1 = 0;
		bool cmp = (bool)(s[0] - '0') ^ 1;

		for (auto& c : s)
		{
			bool num = c - '0';
			if (cmp != num)
			{
				cmp ^= 1;
				num == 0 ? ++cnt0 : ++cnt1;
			}
		}

		cout << min(cnt0, cnt1) << '\n';
	}
}
