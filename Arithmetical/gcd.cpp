#include <iostream>
using namespace std;

// 辗转相除法  欧几里得算法
// 原理：gcd(x,y)=gcd(x,y-x)
int gcd(int x, int y)
{
    return y == 0 ? x : gcd(y, x%y);
}

// 二进制算法
inline int GCD(int x, int y)
{
    int i, j;
    if(x == 0) return y;
    if(y == 0) return x;
    for(i = 0; 0 == (x&1); i++) x>>=1; // 去掉所有的2
    for(j = 0; 0 == (y&1); j++) y>>=1; // 去掉所有的2
    if(j < i) i = j;
    while(1){
        if(x < y){
            x^=y; y^=x; x^=y; // 交换x,y
        }
        if(0 == (x -= y)) return y << i; 
        // 如果x==y,gcd==x==y(就是在辗转减，while(1)控制 )
        while(0==(x&1)) x>>=1; // 去掉所有的2
    }
}
int main()
{
    int a, b;
    a = 123; b = 87;
    cout << gcd(a,b) << endl; // 辗转相除法  欧几里得算法
    cout << GCD(a,b) << endl; // 二进制算法
    return 0;
}