#include <iostream>
#include <cstring>
#include <cmath>

int main(void)
{
	int n, sum = 0;
	char str[10] = { 0, };
	for (int i = 0; i < 8; i++) {
		scanf("%d", &n);
		sum += pow(10, 7 - i) * n;
	}
	sprintf(str, "%d", sum);
	if (!strcmp(str, "12345678"))		puts("ascending");
	else if (!strcmp(str, "87654321")) puts("descending");
	else								puts("mixed");
	return 0;
}