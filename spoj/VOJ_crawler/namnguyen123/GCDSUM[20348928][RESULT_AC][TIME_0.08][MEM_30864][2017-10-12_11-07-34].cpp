using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e6 + 5 ;
const int N = 1e6 + 1;
long long f[MAXN] , phi[MAXN] ;
void sieve () {
    for(int i = 1 ; i <= N ; ++i ) phi[i] = i ;
    for(int i = 2 ; i <= N ; ++i ) {
        if (phi[i] == i) {
            for(int j = i ; j <= N ; j += i) phi[j] -= phi[j] / i ;
        }
    }
    for(int i = 1 ; i <= N ; ++i )
        for(int j = 2 ; i * j <= N ; ++j ) f[i * j] += phi[j] * i ;
    for(int i = 2 ; i <= N ; ++i ) f[i] += f[i - 1] ;
}

int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    sieve() ;
    int n ;
    while(~scanf("%d", &n )) {
        if (n == 0) return 0 ;
        printf("%lld\n", f[n]);
    }


    return 0;
}
