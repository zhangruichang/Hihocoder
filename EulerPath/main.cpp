/*
Author: richard
Contact: zhangruichang112@gmail.com
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
typedef long long LL;
typedef unsigned long long ULL;
//int, -2^31~2^31-1    -2.1*10^9~2.1*10^9 (-2147483648-2147483647)
//unsigned int, 0~2^32-1  0~4.2*10^9
//long long  -2^63~2^63-1 -9*10^18~9*10^18
//unsigned long long 0~2^64-1  0~1.8*10^19
typedef pair<int, int> pii;
typedef vector<int> vi;
#define fi first
#define se second
#define iOS  ios_base::sync_with_stdio(false)
int getint(){
	int t = 0, flag = 1; char c = getchar();
	while (c<'0' || c>'9' || c == '-')
	{
		if (c == '-')
			flag = -1;
		c = getchar();
	}
	while (c >= '0'&&c <= '9')
		t = t * 10 + c - '0', c = getchar();
	return t*flag;
}
int GCD(int m, int n)
{
    return !m ? n : GCD(n%m, m);
}
template <typename T>
string to_string(T value)
{
  //create an output string stream
  ostringstream os ;

  //throw the value into the string stream
  os << value ;

  //convert the string stream into a string and return
  return os.str() ;
}
LL MultMod(LL a,LL b,LL MOD)
{
    a %= MOD;
    b %= MOD;
    LL ret = 0;
    while(b){
        if (b & 1){
            ret += a;
            if(ret >= MOD) ret -= MOD;
        }
        a = a << 1;
        if (a >= MOD) a -= MOD;
        b = b >> 1;
    }
    return ret;
}
int n, t, m, cnt;
int deg[10000+10];
bool v[10000+10];
vector<int> Edge[10000+10];

int dfs(int i)
{
    if(v[i]) return 0;
    v[i]=1;
    int cnt=0;
    for(auto e: Edge[i])
        cnt+=dfs(e);
    return cnt;
}
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    while(~scanf("%d%d", &n, &m))
    {
        memset(deg, 0 ,sizeof deg);
        for(int i=1;i<=n;i++) Edge[i].clear();
        for(int i=0;i<m;i++)
        {
            int u, v;
            u=getint(), v=getint();
            Edge[u].push_back(v);
            Edge[v].push_back(u);
            deg[u]++, deg[v]++;
        }
        int oddnum=0;
        for(int i=1;i<=n;i++)
        {
            if(deg[i]&1) oddnum++;
        }
        memset(v, 0 ,sizeof v);
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(dfs(i)>1) cnt++;
        }
        puts( cnt<=1 && (oddnum==2 || !oddnum) ? "Full" : "Part");
    }
	return 0;
}