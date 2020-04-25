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
int n, q ;
ll F[]= {1ll,1ll,2ll,6ll,24ll,120ll,720ll,5040ll,40320ll,362880ll,3628800ll,39916800ll,479001600ll,6227020800ll,87178291200ll,20922789888000ll,355687428096000ll,6402373705728000ll,121645100408832000ll,2432902008176640000ll};
void Change(ll x[],int n,int m,long long k)
{
    if(n==0) return;
    ll p = k/F[n-1];
    ll i,d=0;
    for(i=1; i<=m; i++)
        if(x[i]==0)
        {
            d++;
            if(d == p + 1 ) break;
        }
    x[i] = 1 ;
    cout << i << " ";
    Change(x,n-1,m,k%F[n-1]);
}
ll Reverse(ll x[],int n)
{
    ll y[21];
    memset(y, 0, sizeof y) ;
    ll res = 0 ;
    FORE(i, 1, n )
    {
        ll d = 0;
        for(int j = 1 ; j <= x[i] ; j++ )
            if(y[j]==0) d++;
        res += (d-1)*F[n-i];
        y[x[i]]=1;
    }
    res ++ ;
    return res ;
}
int main()
{
    // freopen("SHHV.inp","r",stdin);
   //  freopen("SHHV.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x[21];
    ll t ;
    n = 0 ;
    while(cin >> t ){
        n++;
        x[n] = t ;
    }
    ll A = x[n];
    n--;
    //FORE(i , 1 , n ) cout << x[i] << " ";
    //cout << endl;
    //cout << A << endl;
    cout << Reverse(x,n) << endl;
    memset(x , 0 , sizeof x ) ;
    Change(x, n, n, A - 1);
    return 0;
}
