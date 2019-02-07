#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long Int64;
class Hash
{
    static const int HASHMOD = 3894229;
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
    Triple(){}
    Triple(const Int64 a,const Int64 b,const Int64 c):
        x(a),y(b),z(c){}
};

Triple ExtendedGCD(const int a,const int b){
    if(b==0)
        return Triple(1,0,a);
    const Triple last = ExtendedGCD(b,a%b);
    return Triple(last.y,last.x-a/b*last.y,last.z);
}

int ExtendedBabyStep(int A,int B,int C){
    Int64 tmp=1,cnt = 0,D=1;
    for(int i=0;i<32;i++){
        if(tmp==B)
            return i;
        tmp = tmp *A %C;
    }
    for(Triple res;(res=ExtendedGCD(A,C)).z!=1;++cnt){
        if(B%res.z)
            return -1;
        B/=res.z;
        C/=res.z;
        D=D*A/res.z %C;
    }
    const int sqrtn = static_cast<int>(std::ceil(std::sqrt(C)));
    hash.clear();
    Int64 base = 1;
    for(int i=0;i<sqrtn;++i){
        hash.insert(base,i);
        base = base * A % C;
    }
    Int64 j=-1,i;
    for(i=0;i<sqrtn;++i){
        Triple res = ExtendedGCD(D,C);
        const int c = C/res.z;
        res.x = (res.x*B/res.z%c+c)%c;
        j=hash.get(res.x);
        if(j!=-1){
            return i*sqrtn+j+cnt;
        }
        D=D*base%C;
    }
    return -1;
}
int main()
{
    int a,b,c;
    a=5;c=4;b=4;
    b%=c;
    const int ans = ExtendedBabyStep(a,b,c);
    if(ans==-1){
        std::cout<<"no solution\n";
    }else{
        printf("%d\n",ans);
    }
    return 0;
}