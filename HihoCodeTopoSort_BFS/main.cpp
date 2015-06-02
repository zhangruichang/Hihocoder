/*
Author: richard
Contact: zhangruichang112@gmail.com
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
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
int a[maxn], n, t, m, x, y;
vector<int> Edge[maxn];

int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    cin>>t;
    for(int ti=1;ti<=t;ti++)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++) Edge[i].clear();
        for(int i=0;i<m;i++)
        {
            cin>>x>>y;
            Edge[x].push_back(y);
        }
        int InDegree[n+1];
        memset(InDegree, 0, sizeof InDegree);
        for(int i=1;i<=n;i++)
        {
            for(auto e: Edge[i]) InDegree[e]++;
        }
        queue<int> q;
        for(int i=1;i<=n;i++) if(!InDegree[i]) q.push(i);
        int cnt=0;bool ok=1;
        bool v[n+1];
        //memset(v, 0 ,sizeof v);

        while(!q.empty())
        {
            auto cur=q.front();q.pop();cnt++;
            //InDegree[cur]=-1;
            for(auto e: Edge[cur])
            {
                InDegree[e]--;
                if(!InDegree[e]) q.push(e);
            }
            //cout<<cur<<" ";
            //if(v[cur]) {ok=0; break;}
            //v[cur]=1;
            //for(int i=1;i<=n;i++)
        }
        puts( cnt==n ? "Correct" : "Wrong");
    }
	return 0;
}
