#include <iostream>
#include <vector>
using namespace std ;
#define fo(i,a,b) for(int i=a;i<=b;i++)
const int MAXN = 100009 ;
const int MOD  = 142857 ;
vector<int> e[MAXN] ;
int N , M , K , A[MAXN] , deg[MAXN] , x , y , ans = 0 ;
void Init()
{
	cin >> N >> M >> K ;
	for(int i=1;i<=N;i++) A[i] = 0 , e[i].clear() , deg[i] = 0 ;
	for(int i=1;i<=K;i++) { cin >> x ; A[x] ++ ; }
	for(int i=1;i<=M;i++) { cin >> x >> y ; e[x].push_back(y) ; deg[y] ++ ; }
}
void DFS(int x)
{
	deg[x] = -1 ;
    for(auto ex: e[x])
    {
        deg[ex] --;
        A[ex] = (A[ex] + A[x]) % MOD ;
    }
    for(auto ex: e[x])
    {
        if ( !deg[ex] )
            DFS(ex) ;
    }
}
void Solve()
{
	for(int i=1;i<=N;i++)
	{
		if ( !deg[i])
			DFS(i) ;
	}
	for(int i=1;i<=N;i++)
		ans = (ans + A[i]) % MOD ;
	cout << ans << "\n" ;
}
int main()
{
    Init() ;
    Solve() ;
}
