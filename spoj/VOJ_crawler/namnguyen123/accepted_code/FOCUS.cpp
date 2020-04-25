using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 5e5 + 5 ;
long long BIT[MAXN] ;
int N ;
map < int, int > f ;
set <int> a ;
int b[MAXN] ;
int n ;
void update (int u , int value)
{
    for(int node = u ; node <= N ; node += node & (-node) ) BIT[node] += value ;
}
long long get (int u)
{
    long long res = 0 ;
    for(int node = u ; node > 0 ; node -= node & (-node) ) res += BIT[node] ;
    return res ;
}
void compress ()
{
    n = 0;
    vector <int> res ;
    for(set <int> :: iterator it = a.begin() ; it != a.end() ; ++it) b[++n] = *it ;
    for(int i = 1 ; i <= n ; ++i ) res.push_back(b[i]) ;
    sort(res.begin(), res.end()) ;
    for(int i = 1 ; i <= n ; ++i ) f[b[i]] = lower_bound(res.begin(), res.end(), b[i] ) - res.begin() + 1 ;
}
struct Query
{
    int type ;
    vector <int> x;
};
Query T[MAXN] ;
int main()
{
#define TASK "FOCUS"
     //freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(BIT , 0 , sizeof (BIT)) ;
    cin >> N ;
    for(int i = 1 ; i <= N ; ++i )
    {
        char c ;
        cin >> c ;
        if (c == '+')
        {
            int u ;
            cin >> u ;
            a.insert(u) ;
            T[i].type = 1 ;
            T[i].x.push_back(u) ;
        }
        if (c == '-')
        {
            int u ;
            cin >> u ;
            a.insert(u) ;
            T[i].type = 2 ;
            T[i].x.push_back(u) ;
        }
        if (c == '?')
        {
            int k, u, v ;
            cin >> k >> u >> v ;
            a.insert(u) ;
            a.insert(v) ;
            T[i].type = 3 ;
            T[i].x.push_back(k) ;
            T[i].x.push_back(u) ;
            T[i].x.push_back(v) ;
        }
    }
    compress() ;
    for(int i = 1 ; i <= N ; ++i )
    {
        int type = T[i].type ;
        if (type == 1)
        {
            int u = T[i].x[0] ;
            update(f[u] , 1) ;
        }
        if (type == 2)
        {
            int u = T[i].x[0] ;
            update(f[u] , -1) ;
        }
        if (type == 3)
        {
            int k = T[i].x[0] ;
            int u = T[i].x[1] ;
            int v = T[i].x[2] ;
            int L = f[u] , R = f[v] , ans = -1 ;
            int A = L ;
            int B = R ;
            //cout << A << " " << get(A) << endl;
            //cout << B << " " << get(B) << endl;
            while(L <= R) {
                int mid = (L + R) / 2 ;
                if (get(mid) - get(A - 1) >= k ) ans = mid , R = mid - 1 ;
                else L = mid + 1 ;
            }
            if (ans == -1) cout << 0 << endl;
            else cout << b[ans] << endl;
        }
    }

    return 0;
}
