#include <stdio.h>

int main()
{
    int x, y, big, small, gcm, lcm, rest;

    scanf("%d %d", &x, &y);

    if (x > y) {
        big = x;
        small = y;
    }
    else {
        big = y;
        small = x;
    }

    do {
        rest = big % small;
        big = small;
        small = rest;
    } while (small != 0);
    printf("%d\n%d", big, (x * y) / big);

    return 0;
}