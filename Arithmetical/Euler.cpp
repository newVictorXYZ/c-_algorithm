#include <iostream>
#include <cstdio>
const int N=40000;
using namespace std;
int n;
int phi[N+10],prime[N+10],tot,ans;
bool mark[N+10];

void getphi(){
    int i,j;
    phi[1]=1;
    for(i=1;i<=N;i++){
        if(!mark[i]){
            prime[++tot]=i;
            phi[i]=i-1;
        }
        for(j=1;j<=tot;j++){
            if(i*prime[j]>N)
                break;
            mark[i*prime[j]]=1;
            if(i%prime[j]==0){
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }
            else{
                phi[i*prime[j]]=phi[i]*(prime[j]-1);
            }
        }
    }
}
int main()
{
    getphi();
    return 0;
}