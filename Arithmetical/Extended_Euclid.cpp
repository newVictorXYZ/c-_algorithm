// 求解（p,q） 使 p*a + q*b = gcd(a,b)
#include <iostream>
using namespace std;
int extended_gcd(int a,int b,int &x,int &y)
{
    int ret,tmp;
    if(!b)
    {
        x=1;
        y=0;
        return a;
    }
    ret = extended_gcd(b,a%b,x,y);
    tmp = x;
    x = y;
    y = tmp - a/b*y;
    return ret;
}
int main()
{
    int a,b,x,y,z;
    a=4;b=6;
    z=extended_gcd(a,b,x,y);
    // z=gcd(a,b);
    // x=p;
    // y=q;
    cout<<z<<" "<<x<<" "<<y<<endl;
    return 0;
}