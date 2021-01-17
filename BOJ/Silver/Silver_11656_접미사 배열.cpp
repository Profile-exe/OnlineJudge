#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<string> v;
	string s;

	cin >> s;

	for (auto i = 0; i < s.length(); i++)
	{
		string temp;
		for (auto j = i; j < s.length(); j++)
			temp += s[j];
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	for (auto i : v)
		cout << i << '\n';
}