// 求A^B的所有约数（即因子）之和，并对其取模9901输出
#include <iostream>
using namespace std;
const int mod = 9901;
int A,B;
int p[10001],n[10001];

long long power(long long p,long long n)
{
    long long sq = 1;
    while(n)
    {
        if(n&1)
        {
            sq = (sq*p)%mod;
        }
        n>>=1;
        p=p*p%mod;
    }
    return sq;
}

long long sum(long long p,long long n)
{
    if(n==0)
    {
        return 1;
    }
    if(n%2)
    {
        return (sum(p,n/2))*(1+power(p,n/2+1))%mod;
    }
    else
    {
        return (sum(p,n/2-1)*(1+power(p,n/2+1))+power(p,n/2))%mod;
    }
}
int main()
{
    A=2;
    B=3;
    int k=0;
    for(int i=2;i*i<=A;)
    {
        if(A%i==0)
        {
            p[++k]=i;
            n[k]=0;
            while(!(A%i))
            {
                n[k]++;
                A/=i;
            }
        }
        if(i==2)
        {
            i++;
        }
        else
        {
            i+=2;
        }
    }
    if(A!=1)
    {
        p[++k]=A;
        n[k]=1;
    }
    int ans=1;
    for(int i=1;i<=k;i++)
    {
        ans = (ans*(sum(p[i],n[i]*B)%mod))%mod;
    }
    cout<<ans<<endl;
    return 0;
}