
#include<set>
#include<map>
#include<cmath>
#include<ctime>
#include<queue>
#include<cstdio>
#include<vector>
#include<string>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define rep(i, m) for (int i = 0; i < (int)(m); i++)
#define rep2(i, n, m) for (int i = n; i < (int)(m); i++)
typedef long long LL;
typedef pair<int, int> pii;

const int oo = (int) 1e9;
const double PI = 2 * acos(0);
const double eps = 1e-9;

constexpr int MAX_N = 100010;

int p[MAX_N], cc;
bool vis[MAX_N];

void init() {
    memset(vis, false, sizeof(vis));
    cc = 0;
    for (int i = 2; i*i <= MAX_N; ++i) if (!vis[i]) {
        p[cc++] = i;
        for (int j = i+i; j <= MAX_N; j += i) vis[j] = true;
    }
}

LL check(LL n) {
    LL ans = 1;
    for (int i = 0; i < cc && p[i] <= n; ++i) if (n % p[i] == 0) {
        int cnt = 1;
        while (n % p[i] == 0) {
            n /= p[i];
            ++cnt;
        }
        ans *= cnt;
    }

    if (n > 1) ans <<= 1;
    return ans;
}

pii c[MAX_N];
#define F first
#define S second

bool vis2[MAX_N];
int main(void) {
    init();
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &c[i].S);
            c[i].F = check(c[i].S);
        }
        sort(c, c + n);
        int maxx=1;
        for(int i=0;i<n;i++) maxx=max(maxx, c[i].F);
        cout<<maxx<<endl;
        LL ans = 0;
        if (n <= 500) {
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                ans = max(ans, check((LL)c[i].S * c[j].S));
            }
        }
        } else {
            for (int i = n-1; i >= n-500; --i) for (int j = i; j >= n-500; --j)
                ans = max(ans, check((LL)c[i].S * c[j].S));
        }

        printf("%lld\n", ans);
    }

    return 0;
}
