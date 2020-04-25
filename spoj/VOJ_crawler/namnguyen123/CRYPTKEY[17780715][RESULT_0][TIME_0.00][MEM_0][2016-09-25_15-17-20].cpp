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
typedef vector<int> VI ;
typedef vector<II> VII;
const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
ll a[MAXN];
int n ;
ll k ;
int main()
{
    //freopen("CRYPTKEY.inp","r",stdin);
   // freopen("CRYPTKEY.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> n)
    {
        map<ll,int> f ;
        FORE(i, 1, n )
        {
            cin >> a[i] ;
            f[a[i]] = 1 ;
        }
        cin >> k ;
        FORE(i, 1, n )
        {
            FORE(j, 1, n )
            {
                if (i != j )
                {
                    ll gcd = __gcd(a[i],a[j]);
                    ll lcm = a[i]*a[j]/ gcd ;
                    f[gcd] = 1 ;
                    f[lcm] = 1 ;
                }
            }
        }
        if(f[k]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}

