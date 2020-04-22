using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
long long power (long long a, long long n)
{
    long long res = 1 ;
    while(n)
    {
        if (n & 1) res = (res * a) % MOD ;
        a = (a * a) % MOD ;
        n >>= 1 ;
    }
    return res ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int p , k ;
    cin >> p >> k ;
    if (k == 0) {cout << power(p , p - 1) << endl; }
    else if (k == 1 ) {cout << power (p , p ) << endl; }
    else if (k >= 2 ) {
         int m = 1 ;
         long long cur = k ;
         for (; cur != 1 ; m++){
            cur = (cur * k) % p ;
         }
         cout << power (p , (p - 1)/ m ) << endl;
    }


    return 0;
}
