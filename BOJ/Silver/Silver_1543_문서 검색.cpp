#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int idx = 0, count = 0;
	char str[2501], find[51];

	scanf("%[^\n]s", str);
	scanf(" %[^\n]s", find);	// '\n'�� ����ó���ϰ� �Է¹���[����]
	const string S_str(str), S_find(find);

	idx = S_str.find(S_find);	// ã�� �ܾ��� ó�� �ε���
	for (auto i = 0; i < S_str.length(); i++) {
		if (idx == string::npos) break;
		else count++;
		idx = S_str.find(S_find, idx + S_find.length());	// ã�� �ܾ��� ���� �ε������� Ž��
	}
	cout << count << endl;
	return 0;
}