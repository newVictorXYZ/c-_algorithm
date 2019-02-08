// 求A^B的所有约数（即因子）之和，并对其取模9901输出
#include <iostream>
using namespace std;
const int mod = 9901;
int A,B;
int p[10001],n[10001];

long long power(long long p,long long n) // 反复平方法求 (p^n)%mod
{
    long long sq = 1;
    while (n) {
        if (n & 1) {
            sq = (sq*p)%mod;
        }
        n >>= 1;
        p = p * p % mod;
    }
    return sq;
}

long long sum(long long p,long long n)
{
    // 递归二分求 (1+p+p^2+p^3+...+p^n) % mod
    // 奇数二分式 (1+p+p^2+...+p^(n/2))*(1+p^(n/2+1))
    // 偶数二分式 (1+p+p^2+...+p^(n/2-1))*(1+p^2(n/2+1))+p^(n/2)
    if (n == 0) return 1;
    if (n % 2) // n 为奇数
        return (sum(p, n/2)) * (1 + power(p, n/2+1)) % mod;
    else  // n为偶数
        return (sum(p, n/2-1) * (1 + power(p, n/2+1)) + power(p, n/2)) % mod;
}
int main()
{
    A=2;
    B=3;
    int k=0; // 指针，常规做法：分解整数A（A为非质数）
    for(int i = 2; i * i <= A;) { // 根号法+递归法
        if (A % i == 0) {
            p[++k] = i;
            n[k] = 0;
            while(!(A % i))
            {
                n[k]++;
                A /= i;
            }
        }
        if (i == 2) // 奇偶法
            i++;
        else
            i += 2;
    }
    if (A != 1) // 特殊判定：分解整数A（A为质数）
    {
        p[++k] = A;
        n[k] = 1;
    }
    int ans=1; // 约数和
    for(int i = 1; i <= k; i++)
    {
        ans = (ans * (sum(p[i], n[i] * B) % mod)) % mod;
    }
    // n[i] * B 可能会超过int，因此用long long 
    cout << ans << endl;
    return 0;
}