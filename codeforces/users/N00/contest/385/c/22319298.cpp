using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e7 + 5 ;
const int MAXM = 1e5 + 10 ;
int n_prime = 0 ;
int f[MAXN], prime[MAXN], vis[MAXN], a[MAXM] ;
long long cnt[MAXN] ;
int n, ma = 0 ;
void SangNguyenTo( int n )
{
    int i, j;
    for(i = 2; i <= n; i++)
    {
        if (f[i] == 0) f[i] = prime[++n_prime] = i;
        j = 0;
        while (j < n_prime && prime[j] < f[i] && prime[j+1]*i <= n)
            f[prime[j+1]*i] = prime[j+1], j++;
    }
}
int main()
{
    // freopen("TASK.inp","r",stdin);
    // freopen("TASK.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(cnt , 0 , sizeof (cnt) ) ;
    memset(vis , 0 , sizeof (vis) ) ;
    cin >> n ;
    FORE(i, 1, n )
    {
        int x ;
        cin >> x ;
        ma = max(ma , x) ;
        vis[x] ++;
    }
    SangNguyenTo(ma) ;
    FORE(i, 1, n_prime )
    {
        for( int j = prime[i] ; j <= ma ; j += prime[i] ) if (vis[j]) cnt[prime[i]] += vis[j] ;
    }
    //FORE(i, 1, n_prime ) cout << prime[i] << " " << cnt[prime[i]] << endl;
    FORE(i, 1, ma ) cnt[i] += cnt[i - 1] ;
    int Q ;
    cin >> Q ;
    while(Q--)
    {
        int l, r ;
        cin >> l >> r ;
        if (l > ma ) cout << 0 << endl;
        else
        {
            if (r > ma ) r = ma ;
            cout << cnt[r] - cnt[l - 1] << endl;
        }
    }



    return 0;
}
