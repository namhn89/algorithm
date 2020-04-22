using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;

bool IsPrime (int n )
{
    for(int i = 2 ; i * i <= n ; ++i )
    {
        if (n % i == 0 ) return false ;

    }
    return true ;
}

int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n ;
    cin >> n ;
    if ( IsPrime(n) ) cout << 1 << endl;
    else if (n % 2 == 0 || IsPrime(n - 2) )
    {
        cout << 2 << endl;
    }
    else
    {
        cout << 3 << endl;
    }

    return 0;
}
