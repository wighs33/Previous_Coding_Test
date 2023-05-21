#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
void e(T t) { cout << t << endl; }
template<typename T>
void sp(T t) { cout << t << ' '; }

int solution(string s) {
	string newstr;
	int min_size = s.size();

	string _;
	for (int i = s.size() / 2; i > 0; --i)
	{
		_ = s.substr(0, i);
		//sp(_);
		int cnt = 1;
		int j = 2;
		for (; i * j <= s.size(); j++)
		{
			string cmp = s.substr(i * (j - 1), i);
			//sp(cmp);
			if (_ == cmp) ++cnt;
			else {
				newstr += cnt == 1 ? _ : to_string(cnt) + _;
				_ = cmp;
				cnt = 1;
			}
			//sp(cnt);
		}
		newstr += cnt == 1 ? _ : to_string(cnt) + _;
		newstr += s.substr(i * (j - 1), s.size() - i * (j - 1));
		//sp("newstr:");
		//e(newstr);

		min_size = min(min_size, (int)newstr.size());
		newstr.clear();
	}

	return min_size;
}

int main() {
	cout << solution("aabbaccc") << endl;
	cout << solution("ababcdcdababcdcd") << endl;
	cout << solution("abcabcdede") << endl;
	cout << solution("abcabcabcabcdededededede") << endl;
	cout << solution("xababcdcdababcdcd") << endl;
}