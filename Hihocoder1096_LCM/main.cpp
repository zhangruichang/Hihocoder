#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#include <time.h>
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define eps 1e-7
using namespace std;

#ifdef __int64
    typedef __int64 LL;
#else
    typedef long long LL;
#endif

LL mod = 1000000007;
int n,m;
int solve(int now_pos,int lft,int lcm){
    if(lft == 0){
        if(lcm == m)return 1;
        return 0;
    }
    int cnt=0;
    for(int i=now_pos;i<=lft;i++){
        cnt+=solve(i+1,lft-i,__gcd(lcm*i,m));
    }
    return cnt;
}
bool F(int a[], int i, int lcm, int m, int n)
{
    if(i==n) return lcm==m;
    return F(a, i+1, __gcd(lcm*a[i], m), m, n);
}

int main()
{
    //int a[]={2,9,2,3}, m=8, n=sizeof(a)/sizeof(int);
    //cout<<F(a, 0, 1, m, n)<<endl;
    srand(time(NULL));
    //for(int i=0;i<10;i++) cout<<rand()%RAND_MAX<<" ";;
    while(scanf("%d%d",&n,&m)!=EOF)
        printf("%d\n",solve(1,n,1));
    return 0;
}
