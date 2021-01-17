#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int idx = 0, count = 0;
	char str[2501], find[51];

	scanf("%[^\n]s", str);
	scanf(" %[^\n]s", find);	// '\n'을 공백처리하고 입력받음[띄어쓰기]
	const string S_str(str), S_find(find);

	idx = S_str.find(S_find);	// 찾은 단어의 처음 인덱스
	for (auto i = 0; i < S_str.length(); i++) {
		if (idx == string::npos) break;
		else count++;
		idx = S_str.find(S_find, idx + S_find.length());	// 찾은 단어의 다음 인덱스부터 탐색
	}
	cout << count << endl;
	return 0;
}