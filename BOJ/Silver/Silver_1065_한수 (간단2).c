#include <stdio.h>

int main(void) {
    int n, a, b, c, result = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        a = i % 10; //1���ڸ���
        b = ((i % 100) - a) / 10;//10�� �ڸ���
        c = i / 100; //100�� �ڸ���
        if (c == 0 || (c - b) == (b - a)) {
            result++;
        }
    }
    printf("%d", result);
    return 0;
}