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
    if(!m) return n;
    return GCD(n%m, m);//yushu and chushu
}
int a[maxn], n;
int Partition(int a[], int low, int high)
{
    int i=low, j=high, pivot=a[low];
    while(i<j)
    {
        while(i<j && a[j]>=pivot) j--;
        while(i<j && a[i]<=pivot) i++;
        if(i<j)
            swap(a[i], a[j]);
        else break;
    }
    swap(a[low], a[i]);
    return i;
}
int QS(int a[], int low, int high, int k)
{
    if(low==high) return a[low];
    int mid=Partition(a, low, high);
    int order=mid-low+1;
    if(order==k) return a[mid];
    else if(order>k)return QS(a, low, mid-1, k);
    else return QS(a, mid+1, high, k-order);
}
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    int k;
    while(cin>>n>>k)
    {
        for(int i=0;i<n;i++) cin>>a[i];
        if(k>n || k<=0) cout<<-1<<endl;
        else cout<<QS(a, 0, n-1, k)<<endl;;
    }
	return 0;
}
