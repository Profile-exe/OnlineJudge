#include <iostream>
#include <string>

using namespace std;

int main()
{
	string word, answer;
	auto length = 0ULL;

	while (true)
	{
		const char ch = getchar();

		if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || ch == '-')
		{
			word += ch;
			if (word == "E-N-D") break;
		} else {
			if (length < word.length())	{
				answer = word;
				length = word.length();
			}
			word.clear();
		}
	}

	for (auto i : answer) {
		if ('A' <= i && i <= 'Z')
			std::cout << static_cast<char>(i + 32);
		else std::cout << i;
	}
}