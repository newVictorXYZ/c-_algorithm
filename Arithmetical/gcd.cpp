#include<iostream>
using namespace std;
// 辗转相除法
int gcd(int x,int y)
{
    return y==0?x:gcd(y,x%y);
}
// 二进制算法
inline int GCD(int x,int y)
{
    int i,j;
    if(x==0)
        return y;
    if(y==0)
        return x;
    for(i=0;0==(x&1);i++)
        x>>=1;
    for(j=0;0==(y&1);j++)
        y>>=1;
    if(j<i)
        i=j;
    while(1){
        if(x<y){
            x^=y;
            y^=x;
            x^=y;
        }
        if(0==(x-=y))
            return y<<i;
        while(0==(x&1))
            x>>=1;
    }
}
int main()
{
    int a,b;
    a=123;b=87;
    cout<<gcd(a,b)<<endl;
    cout<<GCD(a,b)<<endl;
    return 0;
}