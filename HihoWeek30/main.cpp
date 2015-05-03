/*
Author: richard
Contact: zhangruichang112@gmail.com
*/
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
typedef vector<int> vi;
#define fi first
#define se second
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
int a[maxn], n, t, m;
int x[maxn], x1[maxn];
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
        vector<int> v, v1;
        cin>>n;for(int i=0;i<n;i++) cin>>a[i];
        fill_n(x, n, -1);fill_n(x1, n, -1);
        if(n==1)
        {
            if(a[0]==0) cout<<"0\n1 1\n";
            else cout<<"1 1\n0\n";
            continue;
        }
        if(a[0]==0 || a[0]==2)
        {
            if(!a[0]) x[0]=x[1]=0;
            else x[0]=x[1]=1;
            for(int i=2;i<n;i++)
            {
                x[i]=a[i-1]-x[i-1]-x[i-2];
            }
            for(int i=0;i<n;i++)
            {
                if(x[i]) v.push_back(i+1);
                else v1.push_back(i+1);
            }
        }
        else
        {
            x[0]=0,x[1]=1;bool f1=1;
            for(int i=2;i<n;i++)
            {
                x[i]=a[i-1]-x[i-1]-x[i-2];
                if(x[i]!=0 && x[i]!=1 || (i==n-1 &&x[n-2]+x[n-1]!=a[n-1]) ) {f1=0;break;}
            }
            x1[0]=1,x1[1]=0;bool f2=1;
            for(int i=2;i<n;i++)
            {
                x1[i]=a[i-1]-x1[i-1]-x1[i-2];
                if(x1[i]!=0 && x1[i]!=1 || (i==n-1 &&x1[n-2]+x1[n-1]!=a[n-1])) {f2=0;break;}
            }
            if(f1 && f2)
                for(int i=0;i<n;i++)
                {
                    if(x[i] && x1[i]) v.push_back(i+1);//cnt1++;
                    if(!x[i] && !x1[i]) v1.push_back(i+1);
                }
            else if(f1)
            {
                for(int i=0;i<n;i++)
                {
                    if(x[i]) v.push_back(i+1);//cnt1++;
                    if(!x[i]) v1.push_back(i+1);
                }
            }
            else
            {
                for(int i=0;i<n;i++)
                {
                    if(x1[i]) v.push_back(i+1);//cnt1++;
                    if(!x1[i]) v1.push_back(i+1);
                }
            }
        }
        cout<<v.size();
        for(auto e: v) cout<<" "<<e;
        cout<<endl<<v1.size();
        for(auto e: v1) cout<<" "<<e;
        cout<<endl;
    }
	return 0;
}
