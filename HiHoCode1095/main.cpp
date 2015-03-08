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
//#include <unordered_set>
//#include <unordered_map>
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
int a[maxn];
int n, k;
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    while(cin>>n>>k)
    {
        for(int i=1;i<=n;i++) scanf("%d", &a[i]);
        int low=1, high=k+1, ans;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int his=0,hos=0, how=0;
            for(int i=1;i<=n;i++)
            {
                how+=mid;
                if(how<=a[i]) his++, how=0;
                else hos++, how-=a[i];//how>0
            }
            if(hos>his)
            {
                if(low==high)
                {
                    ans=low;break;
                }
                high=mid;
            }
            else
            {
                low=mid+1;
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}
