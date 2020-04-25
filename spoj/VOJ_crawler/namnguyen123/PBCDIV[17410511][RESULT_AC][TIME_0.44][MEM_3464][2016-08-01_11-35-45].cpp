using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<int,II> III;
typedef pair<ll,ll> LL;
const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    //ios_base::sync_with_stdio(false);
   // cin.tie(NULL);
    int T ;
    cin >> T ;
    ll A, B ;
    while(T--)
    {
        cin >> A >> B ;
        ll res1 = B/12 - (A-1)/12 ;
        ll res2 = B/30 - (A-1)/30 ;
        ll res3 = B/60 - (A-1)/60 ;
        cout << res1 + res2 - 2*res3 << endl;

    }


    return 0;
}
