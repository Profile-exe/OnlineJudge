#include <iostream>
#include <vector>
using namespace std;

enum gender { MALE = 1, FEMALE = 2 };	// FEMALE은 자동적으로 2 이지만 명시했음

int main(void)
{
	vector<pair<int, int>> studentList;
	int nSwitch, nStudent;
	bool state[101] = { false, };

	cin >> nSwitch;							// 스위치 개수
	for (auto i = 1; i <= nSwitch; i++)		// 1번부터 넣기
		cin >> state[i];
	cin >> nStudent;						// 학생 수
	for (auto i = 0; i < nStudent; i++) {
		pair<int, int> temp;				// first : 성별, second : 받은 수
		cin >> temp.first >> temp.second;
		studentList.push_back(temp);
	}

	for (auto& i : studentList) {
		switch (i.first) {	// 성별에 따라 
		case MALE:			// 남자 -> n의 배수이면 상태바꿈
			for (auto j = 1; j <= nSwitch; j++)
				if (!(j % i.second)) state[j] = !state[j];	// 상태 반전
			break;
		case FEMALE:		// 여자 -> 좌우대칭 상태바꿈
			for (auto j = i.second, k = 0; (j - k >= 1) && (j + k <= nSwitch); k++) {	// 중간을 기준으로 양쪽 탐색
				// 무조건 n번 스위치(k == 0인 경우)는 상태 변환
				if (!k) state[j] = !state[j];
				else if (state[j - k] == state[j + k]) {	// 좌우 대칭인 경우 상태 바꿈
					state[j - k] = !state[j - k];
					state[j + k] = !state[j + k];
				}
				else break;									// 비대칭인 경우 종료
			}
			break;
		}
	}

	for (auto i = 1; i <= nSwitch; i++) {
		cout << state[i] << ' ';
		if (!(i % 20)) 	cout << endl;	// 한 줄에 20개씩 -> 20 * n 번째 마다 개행
	}
	return 0;
}