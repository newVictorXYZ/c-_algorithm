#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
const int Times = 10;
const int N = 5500;
typedef long long LL;
LL ct,cnt;
LL fac[N],num[N];

LL gcd(LL a,LL b)
{
    return b?gcd(b,a%b):a;
}
LL multi(LL a,LL b,LL m)
{
    LL ans=0;
    a%=m;
    while(b){
        if(b&1){
            ans=(ans+a)%m;
            b--;
        }
        b>>=1;
        a=(a+a)%m;
    }
    return ans;
}
LL quick_mod(LL a,LL b,LL m)
{
    LL ans = 1;
    a%=m;
    while(b){
        if(b&1){
            ans=multi(ans,a,m);
            b--;
        }
        b>>=1;
        a=multi(a,a,m);
    }
    return ans;
}
bool Miller_Rabin(LL n)
{
    if(n==2)
        return true;
    if(n<2 || !(n&1))
        return false;
    LL m=n-1;
    int k=0;
    while((m&1)==0){
        k++;
        m>>=1;
    }
    for(int i=0;i<Times;i++){
        LL a=rand()%(n-1)+1;
        LL x=quick_mod(a,m,n);
        LL y=0;
        for(int j=0;j<k;j++){
            y=multi(x,x,n);
            if(y==1 && x!=1 && x!=n-1)
                return false;
            x=y;
        }
        if(y!=1)
            return false;
    }
    return true;
}
LL pollard_rho(LL n,LL c)
{
    LL i=1,k=2;
    LL x=rand()%(n-1)+1;
    LL y=x;
    while(true){
        i++;
        x=(multi(x,x,n)+c)%n;
        LL d=gcd((y-x+n)%n,n);
        if(1<d && d<n)
            return d;
        if(y==x)
            return n;
        if(i==k)
        {
            y=x;
            k<<=1;
        }
    }
}
void find(LL n,int c)
{
    if(n==1)
        return;
    if(Miller_Rabin(n))
    {
        fac[ct++]=n;
        return;
    }
    LL p=n;
    LL k=c;
    while(p>=n)
        p=pollard_rho(p,c--);
    find(p,k);
    find(n/p,k);
}
int main()
{
    LL n=1531513166168;
    ct=0;
    find(n,120);
    sort(fac,fac+ct);
    num[0]=1;
    int k=1;
    for(int i=1;i<ct;i++){
        if(fac[i]==fac[i-1]){
            ++num[k-1];
        }else{
            num[k]=1;
            fac[k++]=fac[i];
        }
    }
    cnt=k;
    for(int i=0;i<cnt;i++)
        cout<<fac[i]<<"^"<<num[i]<<" ";
    cout<<endl;
    return 0;
}   