#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

const int N = 110;

vector<int> e[N];
bool v[N];
int p[N];

bool dfs(int x, pii &q)
{
    v[x] = true;
    vector<pii> V;
    //for (int y : e[x])
    for(int yi=0; yi<e[x].size(); yi++)
    {
        int y=e[x][yi];
        if (!v[y])
        {
            pii g;
            if (!dfs(y, g)) return false;
            if (~g.first) V.push_back(g);
        }
    }
    sort(V.begin(), V.end());
    q = make_pair(p[x], p[x]);
    //for (pii g : V) {
    for(int vi=0; vi<V.size(); vi++)
    {
        pii g=V[vi];
        if (!~q.first)
            q = g;
        else if (q.second + 1 == g.first)
            q.second = g.second;
        else
            return false;
    }
    return true;
}

bool solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) e[i].clear();
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    fill(p, p + N, -1);
    fill(v, v + N, false);
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int t;
        scanf("%d", &t);
        p[t] = i;
    }
    pii g;
    return dfs(1, g);
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        puts(solve() ? "YES" : "NO");
    }
    return 0;
}
