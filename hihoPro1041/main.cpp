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
#include <unordered_set>
#include <unordered_map>
using namespace std;
const int maxn = 1e2 + 10;
typedef long long LL;
typedef unsigned long long ULL;
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair
#define pb push_back
#define CLR(a,x) memset(a,x,sizeof(a))

bool A[maxn][maxn];
bool v[maxn];
unordered_map<int, int> ha;
int n, m;
bool ok;
void dfs(int cur, int c)
{
    if(c==m+1) {ok=1; return ;}
    if(ha.find(cur)!=ha.end())
    {
        if(ha[cur]!=c) return ;
        c++;
    }
    if(v[cur]) return ;
    v[cur]=1;cout<<endl<<cur;
    while(1)
    {
        int i;
        for(i=1;i<=n;i++)
        {
            if(A[cur][i] && !v[i]) break;
        }
        if(i>n) break;
        for(int i=1;i<=n;i++)
        {
            if(A[cur][i]) dfs(i, c);
        }
    }

    //v[cur]=0;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(A, 0, sizeof(A)); ha.clear();
        memset(v, 0, sizeof v);
        int a, b;
        for(int i=1;i<n;i++)
            cin>>a>>b, A[a][b]=1, A[b][a]=1;
        cin>>m;
        int x;
        for(int i=1;i<=m;i++)
            cin>>x, ha[x]=i;
        ok=0;dfs(1,1);
        puts(ok?"YES":"NO");
    }
	return 0;
}
