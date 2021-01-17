#include <stdio.h>

int main(void)
{
	int L, n, size, count = 0;
	int min = 1000, max = 0;	// S의 요소는 1이상 1000이하. 최댓값을 넣어서 최솟값을 구한다.
	int S[50] = { 0, };

	scanf("%d", &L);
	for (int i = 0; i < L; i++) {
		scanf("%d", &S[i]);
		if (max < S[i]) max = S[i]; // 1 <= n <= max
		if (min > S[i]) min = S[i];	// n은 두가지 경우 1. n <= min 2. n이 [min, max] 사이에 있을 때
	}
	scanf("%d", &n);

	// 구간을 구하기 위해 정렬
	for (int i = 0; i < L - 1; i++) {
		for (int j = 0; j < L - 1; j++) {
			if (S[j] > S[j + 1]) {
				int tmp = S[j];
				S[j] = S[j + 1];
				S[j + 1] = tmp;
			}
		}
	}
	// n의 위치를 두가지 경우로 나눌 수 있음.
	if (n < min) {	// 이 때 가장 큰 구간은 [0, min]
		int l = n - 1, r = min - n - 1;
		int size = l + r;
		for (int s = 1; s <= size; s++) {
			// n을 걸치고 왼쪽부터 count
			for (int move = 0; move <= s; move++) {
				if (n - l <= n - s + move && n - s + move <= n + r - s) count++;
			}
		}
		printf("%d\n", count);	// l과 r이 0인 경우, 즉 구간이 [n, n]인 경우를 제거
		return 0;
	}
	else {			// n이 [min, max] 사이에 있는 경우 
		// 먼저 n과 가장 가까운 양 옆 S의 요소를 구해야 한다.
		int index = 0;	// n이 속해있는 요소의 왼쪽 인덱스를 구한다.
		for (int i = 0; i < L; i++) {
			if (S[i] == n) {	// n이 S의 요소와 겹치는 경우 구간이 존재하지 않으므로 0을 출력 후 종료
				puts("0");
				return 0;
			}
			if (S[i] < n && n < S[i + 1]) {
				index = i;
				break;
			}
		}
		int l = n - S[index] - 1, r = S[index + 1] - n - 1;
		size = r + l; // 구간의 최대 크기
		for (int s = 1; s <= size; s++) {	// 구간의 크기는 1 이상
			// n을 걸치고 왼쪽부터 count
			for (int move = 0; move <= s; move++) {
				if (n - l <= n - s + move && n - s + move <= n + r - s) count++;
			}
		}
		printf("%d\n", count);
		return 0;
	}
	return 0;
}