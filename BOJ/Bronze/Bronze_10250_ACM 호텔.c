#include <stdio.h>

int main(void)
{
	int t, h, w, n;
	int i, j, k, count;

	scanf("%d", &t);

	for (i = 0; i < t; i++) {
		scanf("%d %d %d", &h, &w, &n);
		count = 0;
		for (j = 1; j <= w; j++) {		// �� ���� ���� ������
			for (k = 1; k <= h; k++) {	// ������ ������
				if (count == n) break;
				count++;
			}
			if (count == n) break;
		}
		if (j < 10) printf("%d0%d\n", k - 1, j);  // ���ȣ = �� + ��
		if (j > 9) printf("%d%d\n", k - 1, j);
	}

	return 0;
}