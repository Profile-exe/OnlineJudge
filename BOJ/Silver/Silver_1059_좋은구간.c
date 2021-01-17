#include <stdio.h>

int main(void)
{
	int L, n, size, count = 0;
	int min = 1000, max = 0;	// S�� ��Ҵ� 1�̻� 1000����. �ִ��� �־ �ּڰ��� ���Ѵ�.
	int S[50] = { 0, };

	scanf("%d", &L);
	for (int i = 0; i < L; i++) {
		scanf("%d", &S[i]);
		if (max < S[i]) max = S[i]; // 1 <= n <= max
		if (min > S[i]) min = S[i];	// n�� �ΰ��� ��� 1. n <= min 2. n�� [min, max] ���̿� ���� ��
	}
	scanf("%d", &n);

	// ������ ���ϱ� ���� ����
	for (int i = 0; i < L - 1; i++) {
		for (int j = 0; j < L - 1; j++) {
			if (S[j] > S[j + 1]) {
				int tmp = S[j];
				S[j] = S[j + 1];
				S[j + 1] = tmp;
			}
		}
	}
	// n�� ��ġ�� �ΰ��� ���� ���� �� ����.
	if (n < min) {	// �� �� ���� ū ������ [0, min]
		int l = n - 1, r = min - n - 1;
		int size = l + r;
		for (int s = 1; s <= size; s++) {
			// n�� ��ġ�� ���ʺ��� count
			for (int move = 0; move <= s; move++) {
				if (n - l <= n - s + move && n - s + move <= n + r - s) count++;
			}
		}
		printf("%d\n", count);	// l�� r�� 0�� ���, �� ������ [n, n]�� ��츦 ����
		return 0;
	}
	else {			// n�� [min, max] ���̿� �ִ� ��� 
		// ���� n�� ���� ����� �� �� S�� ��Ҹ� ���ؾ� �Ѵ�.
		int index = 0;	// n�� �����ִ� ����� ���� �ε����� ���Ѵ�.
		for (int i = 0; i < L; i++) {
			if (S[i] == n) {	// n�� S�� ��ҿ� ��ġ�� ��� ������ �������� �����Ƿ� 0�� ��� �� ����
				puts("0");
				return 0;
			}
			if (S[i] < n && n < S[i + 1]) {
				index = i;
				break;
			}
		}
		int l = n - S[index] - 1, r = S[index + 1] - n - 1;
		size = r + l; // ������ �ִ� ũ��
		for (int s = 1; s <= size; s++) {	// ������ ũ��� 1 �̻�
			// n�� ��ġ�� ���ʺ��� count
			for (int move = 0; move <= s; move++) {
				if (n - l <= n - s + move && n - s + move <= n + r - s) count++;
			}
		}
		printf("%d\n", count);
		return 0;
	}
	return 0;
}