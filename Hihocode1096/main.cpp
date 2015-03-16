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
#include<fstream>
#include<iostream>
#include<algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;
const int maxn = 1e6 + 10;
typedef long long LL;
typedef unsigned long long ULL;
//int, -2^31~2^31-1    -2.1*10^9~2.1*10^9 (-2147483648-2147483647)
//unsigned int, 0~2^32-1  0~4.2*10^9
//long long  -2^63~2^63-1 -9*10^18~9*10^18
//unsigned long long 0~2^64-1  0~1.8*10^19
typedef pair<int, int> pii;
#define f first
#define s second
int getint(){
	int t = 0, flag = 1;
	char c = getchar();
	while (c<'0' || c>'9' || c == '-')
	{
		if (c == '-')
			flag = -1;
		c = getchar();
	}
	while (c >= '0'&&c <= '9')
	{
		t = t * 10 + c - '0';
		c = getchar();
	}
	return t*flag;
}
int n,m;
unordered_map<int, int> hash1;
int dfs(int i, int cur, int sum)
{
    if(sum>n) return 0;
    if(sum==n) return hash1.empty();
    int cnt=0;
    unordered_map<int, int> tmp=hash1;
    for(int j=cur+1;j<=n;j++)
    {
        for(unordered_map<int, int>::iterator it=hash1.begin();it!=hash1.end();)
        {
            if(j%(it->f)==0 && (it->s)>=1)
            {
                it->s--;
                if(it->s==0)
                {
                    it=hash1.erase(it);
                    continue;
                }
            }
            it++;
        }
        cnt+=dfs(i+1, j, sum+j);
        hash1=tmp;
    }
    return cnt;
}
int prime[16]={2,3,5,7,9,11,13,17,19,23,29,31,37,41,43,47};
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    while(cin>>n>>m)
    {
        hash1.clear();

        for(int i=0;i<16;i++)
        {
            while(m>1)
            {
                if(m%prime[i]==0)
                    m/=prime[i], hash1[prime[i]]++;
                else break;
            }
            if(m==1) break;
        }
        cout<<dfs(0, 0, 0)<<endl;
    }
	return 0;
}
