#include<stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x1, y1, r1, x2, y2, r2;
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

		double d = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);

		if (d == 0) {
			if (r1 == r2) {
				printf("-1");
			}
			else {
				printf("0");
			}
		}
		else {
			if (d < (r2 - r1)*(r2 - r1)) {
				printf("0");
			}
			else if (d == (r2 - r1)*(r2 - r1)) {
				printf("1");
			}

			else if(d>(r2-r1)*(r2-r1)&&d<(r1+r2)*(r1+r2)){
					printf("2");
			}
			else if (d == (r1 + r2)*(r1 + r2)) {
					printf("1");
			}
			else if(d>(r1+r2)*(r1+r2)) {
					printf("0");
				}
			}
        printf("\n");
		}
	return 0;
}