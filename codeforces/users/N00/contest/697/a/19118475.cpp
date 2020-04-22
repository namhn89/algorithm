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
    // freopen(".out","w",stdout);'
    int t,x, s ;
    cin >> t >> s >> x ;
    if (x < t )
    {
        cout << "NO" ;
        return 0;
    }
    if (x - t == 1 && s != 1){
        cout << "NO";
        return 0 ;
    }
    if ( (x-1-t)%s == 0 || (x-t)%s == 0)
    {
        cout <<"YES" << endl;
    }
    else
    {
        cout << "NO";
    }




    return 0;
}
