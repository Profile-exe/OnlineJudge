#include <stdio.h>
#include <stdbool.h>

void Pnumber(int n);
bool arr[10001] = { 0, };

int main(void)
{
	int i, dic, inc, t, n;
	scanf("%d", &t);
	Pnumber(10000);	// �����佺�׳׽��� ü
	for (i = 0; i < t; i++) {
		scanf("%d", &n);
		dic = 0;
		inc = 0;
		while (arr[n / 2 - dic] != false || arr[n / 2 + inc] != false) {	// �Ҽ��� ¦���� 1/2�� �������� ���� ��Ī
			dic++;
			inc++;
		}
		printf("%d %d\n", n / 2 - dic, n / 2 + inc);
	}
	return 0;
}

void Pnumber(int n)
{
	arr[0] = arr[1] = true;
	for (int i = 2; i <= n; i++) {
		if (!arr[i]) {	// arr[i] = 0 �� arr[i]�� �������� ���� ��[�Ҽ�]�� ��
			for (int j = 2 * i; j <= n; j += i) {	// �Ҽ� i�� �������� i�� �����ŭ ����
				arr[j] = true;
			}
		}
	}
}