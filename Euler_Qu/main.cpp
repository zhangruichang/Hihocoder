#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define foreach(it,v) for(__typeof(v.begin()) it = v.begin(); it != v.end(); ++it)
using namespace std;
typedef long long ll;
const int maxn = 10000 + 10;
int p[maxn],d[maxn];
int findx(int x)
{
	return p[x] < 0 ? x : p[x] = findx(p[x]);
}
bool merge(int x,int y)
{
	x = findx(x), y = findx(y);
	if(x==y)return false;
	if(p[x] < p[y]) swap(x,y);
	p[y] += p[x];
	p[x] = y;
	return true;
}
int main(int argc, char const *argv[])
{
	int n,m;
	while(~scanf("%d%d",&n,&m)) {
		for(int i = 1; i <= n; i++) p[i] = -1;
		for(int i = 1; i <= n; i++) d[i] = 0;
		int scc = n,tot = 0;
		while(m--) {
			int u,v; scanf("%d%d",&u,&v);
			if(u==v)continue;
			if(d[u]&1)tot--;
			else tot++;
			if(d[v]&1)tot--;
			else tot++;
			d[u]++,d[v]++;
			scc -= merge(u,v);
		}
		if(scc > 1||tot==1||tot>2)puts("Part");
		else puts("Full");
	}
	return 0;
}
