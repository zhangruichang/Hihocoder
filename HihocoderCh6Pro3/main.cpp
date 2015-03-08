//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
//#include <unordered_set>
//#include <unordered_map>
#define  RD(x)      scanf("%d", &x)
#define  REP(i, n)  for (int i=0; i<int(n); i++)
#define  FOR(i, n)  for (int i=1; i<=int(n); i++)
#define  pii        pair<int, int>
#define  mp         make_pair
#define  pb         push_back
inline   int read(){int ret; scanf("%d", &ret); return ret;}
int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx4[4] = {1, 0, -1, 0};
int dy4[4] = {0, 1, 0, -1};

using namespace std;
#define  N   123456
#define  eps 1e-8
#define  pi  acos(-1.0)
#define  inf 0XFFFFFFFFFFFFFFFll
#define  mod 1000000007ll
#define  LL  long long
#define  ULL unsigned long long

const ULL magic = 173;

char sa[N], sb[N];
ULL ha[N], hb[N];

ULL p[N];

ULL get(ULL h[N], int l, int r) {
	return h[r] - h[l] * p[r-l];
}

int Main() {
  //  freopen("cf.txt", "r", stdin);
//    freopen("outTX.txt", "w", stdout);
//    ios_base::sync_with_stdio(0);


    p[0] = 1;
    FOR(i, N-1)
    	p[i] = p[i-1] * magic;

    while (scanf("%s", sa+1) != EOF) {
    	scanf("%s", sb+1);

    	int la = strlen(sa + 1);
    	FOR(i, la)
    		ha[i] = ha[i-1] * magic + sa[i] - 'a';

    	int lb = strlen(sb + 1);
    	FOR(i, lb)
    		hb[i] = hb[i-1] * magic + sb[i] - 'a';


    	int K;
    	RD(K);

    	int ans = 0;

    	for (int i = lb; i <= la; i++) {

    		int za = i;
    		int zb = lb;
    		int cnt = 0;
    		while (zb != 0) {
    			int l = 0, r = zb;
    			while (l != r) {
    				int mid = (l + r + 1) / 2;
    				if (get(ha, za - mid, za) == get(hb, zb - mid, zb))
    					l = mid;
    				else
    					r = mid - 1;
    			}
    			if (l == zb)
    				break;
    			za -= l + 1;
    			zb -= l + 1;
    			cnt++;
    			if (cnt > K)
    				break;
    		}
    		if (cnt <= K)
    			ans++;

    	}

    	printf("%d\n", ans);

    }

    return 0;
}


int main() {
    return Main();
}
