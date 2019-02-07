// a^b mod c
#include <iostream>
using namespace std;
int a,b,c;
//二进制算法
int Binary_mod(int m,int n,int k)
{
    int ans=1;
    for(;n;n>>=1,m=(long long)m * m % k)
    {
        if(n&1)
        {
            ans = (long long)ans * m % k;
        }
    }
    return ans;
}
int main()
{
    a=2;b=10;c=9;
    cout<<Binary_mod(a,b,c)<<endl;
    return 0;
}