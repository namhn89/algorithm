using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;

long long BIT[MAXN] ;

long long n , m ;
void update (int u , int value)
{
    for(int node = u ; node <= n ; node += node & (-node) ) BIT[node] += value ;
}
long long get (int u)
{
    long long res = 0 ;
    for(int node = u ; node > 0 ; node -= node & (-node) ) res += BIT[node] ;
    return res ;
}
int find_element (long long x) {
    int l = 1 , r = n , ans = -1 ;
    while(l <= r) {
        int mid = (l + r) / 2 ;
        if (get(mid) > x) r = mid - 1 ;
        else l = mid + 1 ;
    }
    return l ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    while(~scanf("%lld %lld", &n , &m)) {
        if(n == -1 && m == -1) return 0 ;
        memset(BIT , 0 , sizeof(BIT))  ;
        for(int i = 1 ; i <= n ; ++i) update(i , 1) ;
        long long pos = n ;
        for(int i = 1 ; i <= n ; ++i) {
            long long cnt = m - (pos - 1) * (pos - 2) / 2 ;
            if (cnt < 0) cnt = 0 ;
            pos-- ; m -= cnt ;
            int ans = find_element (cnt) ;
            printf("%d ", ans) ;
            update(ans , -1) ;
        }
        printf("\n");
    }
    return 0;
}
