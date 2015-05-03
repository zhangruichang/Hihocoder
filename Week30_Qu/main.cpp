#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
int x[maxn][2],a[maxn];
#define chose(num) num==0?first:second
void test(int r,int n)
{
	x[1][r] = r;
	bool flag = false;
	if(a[1]==2)x[1][r] = 1;
	for(int i=1;i<=n;i++) {
		x[i+1][r] = a[i] - (x[i][r]+x[i-1][r]);
		if(x[i+1][r]<0||x[i+1][r]>1){
			flag = true;
			break;
		}
	}
	if(flag||x[n+1][r]!=0){
		x[1][r]^=1;
		for(int i=1;i<=n;i++)
			x[i+1][r] = a[i] - (x[i][r]+x[i-1][r]);
	}
}
pair<vector<int>,vector<int> > find_vec(int n)
{
	test(0,n);
	test(1,n);
	pair<vector<int>,vector<int> > res;
	for(int i = 1; i <= n; ++i) {
		if(x[i][0]==x[i][1]) {
			if(x[i][0])res.second.push_back(i);
			else res.first.push_back(i);
		}
	}
	return res;
}
void debug(int n)
{
	for(int i = 1; i <= n; ++i){
		printf("(%d,%d) ",x[i][0],x[i][1]);
	}
	printf("\n");
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);
		for(int i = 1; i <= n;++i) {
			x[i][0] = -1;
			x[i][1] = -1;
		}
		x[0][0] = x[0][1] = 0;
		x[n+1][0] = x[n+1][1] = 0;
		for(int i=1;i<=n;++i){
			scanf("%d",a+i);
		}
		pair<vector<int>,vector<int> > res = find_vec(n);
		vector<int> & v1 = res.first;
		vector<int> & v2 = res.second;
		//debug(n);
		//printf("\n");
		printf("%u", v2.size());
		int sz = v2.size();
		for(int i = 0; i < sz; ++i) {
			printf(" %d", v2[i]);
		}
		printf("\n");
		printf("%u", v1.size());
		sz = v1.size();
		for(int i = 0; i < sz; ++i) {
			printf(" %d", v1[i]);
		}
		printf("\n");
	}
    return 0;
}
