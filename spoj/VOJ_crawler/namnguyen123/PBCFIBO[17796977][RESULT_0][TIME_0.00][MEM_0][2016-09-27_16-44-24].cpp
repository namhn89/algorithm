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
const int MAXN = 1e5 + 5 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
int f[MAXN] ;
map<int,int> F ;
int main()
{
    int n , MOD , s ;
    cin >> n >> MOD >> s ;
    f[1] = 1 % MOD ;
    f[2] = 2 % MOD ;
    int i ;
    for(i = 3 ; i <= min(n,1000000) ; i++ )
    {
        f[i] = ( f[i-1] + f[i-2] )% MOD ;
        if (f[i-1] == f[1] && f[i] == f[2] ){
            break ;
        }
    }
    vector <int> ans ;
    for (int j = 1 ; j <= i ; j ++ ){
        if (!F[f[j]]){
            ans.push_back(f[j]);
            F[f[j]] = 1 ;
        }
    }
    sort(ans.begin(),ans.end());
    //FOR(i , 0 , ans.size()) cout << ans[i] << " ";
    if (s > ans.size()) cout << ans[ans.size()-1] << endl ;

    return 0 ;
}
