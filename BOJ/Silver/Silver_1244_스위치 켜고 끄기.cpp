#include <iostream>
#include <vector>
using namespace std;

enum gender { MALE = 1, FEMALE = 2 };	// FEMALE�� �ڵ������� 2 ������ �������

int main(void)
{
	vector<pair<int, int>> studentList;
	int nSwitch, nStudent;
	bool state[101] = { false, };

	cin >> nSwitch;							// ����ġ ����
	for (auto i = 1; i <= nSwitch; i++)		// 1������ �ֱ�
		cin >> state[i];
	cin >> nStudent;						// �л� ��
	for (auto i = 0; i < nStudent; i++) {
		pair<int, int> temp;				// first : ����, second : ���� ��
		cin >> temp.first >> temp.second;
		studentList.push_back(temp);
	}

	for (auto& i : studentList) {
		switch (i.first) {	// ������ ���� 
		case MALE:			// ���� -> n�� ����̸� ���¹ٲ�
			for (auto j = 1; j <= nSwitch; j++)
				if (!(j % i.second)) state[j] = !state[j];	// ���� ����
			break;
		case FEMALE:		// ���� -> �¿��Ī ���¹ٲ�
			for (auto j = i.second, k = 0; (j - k >= 1) && (j + k <= nSwitch); k++) {	// �߰��� �������� ���� Ž��
				// ������ n�� ����ġ(k == 0�� ���)�� ���� ��ȯ
				if (!k) state[j] = !state[j];
				else if (state[j - k] == state[j + k]) {	// �¿� ��Ī�� ��� ���� �ٲ�
					state[j - k] = !state[j - k];
					state[j + k] = !state[j + k];
				}
				else break;									// ���Ī�� ��� ����
			}
			break;
		}
	}

	for (auto i = 1; i <= nSwitch; i++) {
		cout << state[i] << ' ';
		if (!(i % 20)) 	cout << endl;	// �� �ٿ� 20���� -> 20 * n ��° ���� ����
	}
	return 0;
}