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
const int maxn = 1e5 + 10;
typedef long long LL;
typedef unsigned long long ULL;
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair
#define pb push_back
#define CLR(a,x) memset(a,x,sizeof(a))

struct Node{
    int x;
    Node(int x_):x(x_){}
    bool operator<(Node d) const
    {
        return x<d.x;
    }
};
int main()
{
    //freopen("in.txt","r",stdin);
    int n;
    while(cin>>n)
    {
        priority_queue<Node> pq;
        for(int i=0;i<n;i++)
        {
            char ch;int x;
            cin>>ch;
            if(ch=='A') cin>>x, pq.push({x});
            else
            {
                cout<<pq.top().x<<endl;
                pq.pop();
            }
        }
    }
	return 0;
}
