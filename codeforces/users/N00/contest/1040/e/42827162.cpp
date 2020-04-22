using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 5e5 + 5 ;
const double eps = 1e-8 ;

int par[MAXN] ;
long long N , M , K ;
long long a[MAXN] ;

pair <int , int> Edege[MAXN] ;
map < long long , vector <int> > F ;
long long pw[MAXN] ;

int findSet (int p) {
    if (par[p] == p) return par[p] ;
    else return par[p] = findSet(par[p]) ;
}
bool Union (int u , int v) {
    int x = findSet(u) ;
    int y = findSet(v) ;
    if (x == y) return true ;
    par[y] = x ;
    return false ;
}

long long solve (vector <int> id) {
     int ans = N ;
     vector <int> choose ;
     TR(id , it) {
         int u = *it ;
         choose.push_back(Edege[u].st) ;
         choose.push_back(Edege[u].nd) ;
     }
     TR(id , it) {
         int u = *it ;
         int x = Edege[u].st ;
         int y = Edege[u].nd ;
         if (Union(x , y) == false) {
            ans-- ;
         }
     }
     for (int i = 0 ; i < choose.size() ; ++i) par[choose[i]] = choose[i] ;
     return pw[ans] ;
}
int main()
{
#define TASK "test"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    scanf("%lld %lld %lld", &N , &M , &K) ;
    pw[0] = 1LL ;
    for (int i = 1 ; i <= N ; ++i ) pw[i] = (pw[i - 1] * 2) % MOD ;
    for (int i = 1 ; i <= N ; ++i ) par[i] = i ;
    for (int i = 1 ; i <= N ; ++i ) scanf("%lld", &a[i]) ;
    set <long long> myset ;
    for (int i = 1 ; i <= M ; ++i ) {
        int u , v ;
        scanf("%d %d", &u , &v) ;
        Edege[i].st = u , Edege[i].nd = v  ;
        long long cur = a[u] ^ a[v] ;
        myset.insert(cur) ;
        F[cur].push_back(i) ;
    }
    long long ans = 0 ;
    TR(F , it) {
        ans += solve(it -> nd) ;
        ans %= MOD ;
    }
    long long cur = ( (1LL << K) - myset.size()) % MOD ;
    cur = (cur * pw[N]) % MOD ;
    ans = (ans + cur) % MOD ;
    cout << ans ;
    return 0;
}
