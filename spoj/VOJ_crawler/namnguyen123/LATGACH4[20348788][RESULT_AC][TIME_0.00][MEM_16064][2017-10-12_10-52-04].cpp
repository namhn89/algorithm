using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 111539786 ;
const int MAXN = 1e5 + 5 ;
map < long long  , long long > F ;
long long fib (long long n) {
    if (F.count(n)) return F[n] ;
    long long k = n / 2 ;
    if (n % 2 == 1) {
        return F[n] = (fib(k) * fib(k + 1) + fib(k) * fib(k - 1)) % MOD ;
    }
    else return F[n] = (fib(k) * fib(k) + fib(k - 1) * fib(k - 1) ) % MOD ;
}


int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    F[0] = 1 ;
    F[1] = 1 ;
    int T ;
    cin >> T ;
    while(T--){
        long long n ;
        cin >> n ;
        cout << fib(n) << endl ;

    }

    return 0;
}
