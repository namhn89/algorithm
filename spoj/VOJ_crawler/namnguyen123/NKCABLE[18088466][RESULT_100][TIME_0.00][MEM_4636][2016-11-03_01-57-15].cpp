using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
#define TASK test

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<int,II> III;
typedef pair<ll,ll> LL;
typedef vector<int> VI ;
typedef vector<II> VII;
typedef vector< VI> VVI;

inline void read (int &x) {
    register char c = getchar();
    x = 0;
    bool neg = 0;
    for(;((c < '0' || c > '9') && c != '-'); c = getchar());
    if (c == '-') {
        neg = 1;
        c = getchar();
    }
    for(;c >= '0' && c <= '9'; c=getchar())
        x = (x << 1) + (x << 3) + (c - '0');
    if(neg)
        x = -x;
}

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
const int BASE = 31 ;

int n ;
long long F[MAXN];
int a[MAXN] ;
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen("TASK.inp","r",stdin);
    // freopen("TASK.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n ;
    FORE(i , 1 , n - 1) cin >> a[i] ;
    F[1] = 0 ;
    F[2] = a[1] ;
    F[3] = a[1] + a[2] ;
    FORE(i , 4 , n) F[i] = min(F[i-1],F[i-2]) + a[i-1] ;
    cout << F[n] << endl;
    return 0;
}