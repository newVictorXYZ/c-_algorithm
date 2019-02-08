// 斐波那契数列
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n;
double m, k, ans;

inline double F(double a, int b)
{
    if (b == 0)
        return 1;
    double k = F(a, b/2);
    if (b % 2 == 0)
        return k * k;
    else
        return k * k * a;
}
int main()
{
    n = 1000;
    m = (1 + sqrt(5)) / 2;
    k = (1 - sqrt(5)) / 2;
    ans = (F(k, n) * (1 - m) - F(m, n) * (1 - k)) / (k - m);
    printf("%.0lf",ans);
    return 0;
}