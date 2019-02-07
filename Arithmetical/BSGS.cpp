#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long Int64;
class Hash
{
    static const int HASHMOD = 7679977;
    int top,hash[HASHMOD+100],value[HASHMOD+100],stack[1<<16];
    int locate(const int x) const{
        int h = x % HASHMOD;
        while(hash[h]!=-1 && hash[h]!=x)
            ++h;
        return h;
    }
public:
    Hash():top(0){memset(hash,0xFF,sizeof(hash));}
    void insert(const int x,const int v){
        const int h = locate(x);
        if(hash[h]==-1){
            hash[h]=x;
            value[h]=v;
            stack[++top]=h;
        }
    }
    int get(const int x) const{
        const int h = locate(x);
        return hash[h]==x?value[h]:-1;
    }
    void clear(){
        while(top){
            hash[stack[top--]]=-1;
        }
    }
}hash;
struct Triple{
    Int64 x,y,z;
    Triple(const Int64 a,const Int64 b,const Int64 c):
        x(a),y(b),z(c){}
};

Triple ExtendedGCD(const Int64 a,const Int64 b){
    if(b==0)
        return Triple(1,0,a);
    const Triple last = ExtendedGCD(b,a%b);
    return Triple(last.y,last.x-a/b*last.y,last.z);
}
int A,B,C;
Int64 BabyStep(Int64 A,Int64 B,Int64 C){
    const int sqrtn = static_cast<int>(std::ceil(std::sqrt(C)));
    Int64 base = 1;
    hash.clear();
    for(int i=0;i<sqrtn;i++){
        hash.insert(base,i);
        base = base * A % C;
    }
    Int64 i=0,j=-1,D=1;
    for(;i<sqrtn;++i){
        Triple res = ExtendedGCD(D,C);
        const int c = C / res.z;
        res.x=(res.x*B/res.z % c+c)%c;
        j=hash.get(res.x);
        if(j!=-1)
            return i*sqrtn+j;
        D = D*base%C;
    }
    return -1;
}
int main()
{
    C=12345701;A=2;B=1111111;
    const Int64 ans = BabyStep(A,B,C);
    if(ans==-1){
        std::cout<<"no solution\n";
    }else{
        printf("%I64d\n",ans);
    }
    return 0;
}