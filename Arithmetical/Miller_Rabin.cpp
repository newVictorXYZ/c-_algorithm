#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <iostream>
using namespace std;
const int count = 10;
int modular_exp(int a,int m,int n)
{
    if(m==0){
        return 1;
    }
    if(m==1){
        return (a%n);
    }
    long long w=modular_exp(a,m/2,n);
    w=w*w%n;
    if(m&1)
    {
        w=w*a%n;
    }
    return w;
}

bool Miller_Rabin(int n)
{
    if(n==2){
        return true;
    }
    for(int i=0;i<count;i++)
    {
        int a=rand()%(n-2)+2;
        if(modular_exp(a,n,n)!=a)
            return false;
    }
    return true;
}

int main()
{
    srand(time(NULL));
    long long n=191439145771;
    if(Miller_Rabin(n))
        cout<<"Probably a prime\n";
    else
        cout<<"a composite\n";
    return 0;
}