#include <stdio.h>
void HAN(int N);

int main()
{
    int n;
    scanf("%d", &n);
    HAN(n);
}

void HAN(int N)
{

    if (N < 100)
        printf("%d", N);
    else
    {
        int i;
        int cnt;
        int A, B, C; //A�� 100���ڸ� B�� 10���ڸ� C�� 1���ڸ�
        cnt = 99;
        for (i = 100; i <= N; i++)
        {
            A = i / 100;
            B = i / 10 % 10;
            C = i % 10;

            if ((C - B) == (B - A))
                cnt++;
        }
        printf("%d", cnt);
    }
}
