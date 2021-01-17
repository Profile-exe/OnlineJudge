#include <stdio.h>

int get_count1(int x);
int get_count2(int x);
int get_count3(int x);

int main(void)
{
	int n, result = 0;
	
	scanf("%d", &n);

	if (n < 10)
		result = get_count1(n);
	else if (n < 100)
		result = get_count2(n);
	else if (n <= 1000)
		result = get_count3(n);

	printf("%d", result);
	return 0;
}

int get_count1(int x)
{
	return x; // ���ڸ��� -> ������ d = 0 -> ��� ��������
}

int get_count2(int x)
{
	return x; // ���ڸ��� -> ���� �ѹ��� ���� -> ��� ��������
}

int get_count3(int x)
{
	int i, j, ignore = 0, number, count = 0;
	for (i = 1; i <= 7; i++) { // d > 0�� �� d = 1 �̾ �ִ� 789 -> �����ڸ�(i) �ִ� 7
		if (i > x / 100) break;
		for (j = 1; j <= 4; j++) { // 159 -> ����(d) �ִ� 4
			number = 100 * i + 10 * (i + j) + (i + 2 * j);
			if (i + 2 * j > 9) { // �����ڸ����� 10 �̻��̸� ���� �ʴ´�
				j -= 1;
				break;
			}
			if (number > x) { // x���� Ŀ���� ���� �ʴ´�
				j -= 1;
				break;
			}
		}
		if (j > 4) j -= 1;
		count += j;
		if (number > x)	break;
	}

	for (i = 2; i <= 9; i++) { // d < 0�� �� d = -1 �̾ �ּڰ� 210 -> �����ڸ� �ּ� 2
		if (i > x / 100) break;
		ignore = 0;
		for (j = 1; j < i; j++) { // 951 -> ����(d) �ִ� -4
			number = 100 * i + 10 * (i - j) + (i - 2 * j);
			if (number > x) { // number���� ũ�ٸ� ��츦 ����ߵ� -> ignore++;
				ignore++;
				continue;
			}
			if (i - 2 * j < 0) {
				j -= 1;
				break;
			}
		}		
		if (j >= i) j -= 1;
		count = count + j - ignore; // ignore ���ֱ�
		if (i - 2 * j < 0)	break;
	}

	for (i = 1; i <= x / 100; i++) { // d = 0�� ��
		number = 100 * i + 10 * i + i;
		if (number > x) {
			i -= 1;
			break;
		}
	}
	if (i > x / 100) i -= 1;
	count += i;
	return 99 + count;
}