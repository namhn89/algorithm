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
ll cntx[MAXN], cnty[MAXN];
pair<ll, ll> point[MAXN];
int n;
int main(){
    cin >> n;
    FORE(i, 1, n){
        int x, y;
        cin >> x >> y;
        point[i].first = x;
        point[i].second = y;
        cntx[x]++; cnty[y]++;
    }
    ll res = 0;
    FORE(i, 1, n){
        res += (cntx[point[i].first] - 1) * (cnty[point[i].second] - 1);
    }
    cout << res;
}
