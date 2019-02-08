//
#include <iostream>
#include <cstdio>
using namespace std;
int f[2][1001][801];
void pluss(int *a, int *b, int *c)
{
    a[0] = max(b[0], c[0]);
    a[1] = 0;
    for(int i = 1; i <= a[0]; i++)
    {
        a[i + 1] = (b[i] + c[i]) / 1e9;
        a[i] += b[i] + c[i] - (a[i + 1]) * 1e9;
    }
    if (a[a[0] + 1])
        a[0]++;
}
void print(int *x)
{
    printf("%d", x[x[0]]);
    for(int i = x[0] - 1; i >= 1; i--)
        printf("%09d", x[i]);
    printf("\n");
}
int main()
{
    int n=100;
    f[0][0][0] = f[0][0][1] = 1;
    f[1][0][0] = f[1][0][1] = 1;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            pluss(f[i & 1][j], f[(i - 1) & 1][j], f[i & 1][j - 1]);
        }
    }
    print(f[n&1][n]);
    return 0;
}