#include<set>
#include<map>
#include<list>
#include<cmath>
#include<queue>
#include<stack>
#include<ctime>
#include<cstdio>
#include<string>
#include<vector>
#include<climits>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1e3 + 10;
typedef long long LL;
typedef unsigned long long ULL;
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair
#define pb push_back
#define CLR(a,x) memset(a,x,sizeof(a))

int n, bw;
int need[maxn], value[maxn];
int lastdp[100000+10], curdp[100000+10];
int Solve()
{
    //int**dp=new int[2];
    //dp=Dp;
    //for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int j=0;j<=bw;j++) lastdp[j]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=bw;j++)
        {
            curdp[j]=lastdp[j];
            for(int k=1;k<=j/need[i-1];k++)
            {
                curdp[j]=max(curdp[j], lastdp[j-k*need[i-1]]+k*value[i-1]);
            }
        }
        for(int j=0;j<=bw;j++) lastdp[j]=curdp[j];
    }
    return curdp[bw];
}

int main()
{
    while(cin>>n>>bw)
    {
        for(int i=0;i<n;i++) cin>>need[i]>>value[i];
        cout<<Solve()<<endl;
    }

	return 0;
}
