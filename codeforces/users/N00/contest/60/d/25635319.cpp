using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 2e7 + 5 ;
int a[MAXN] , nscc , par[MAXN] , n ;
int Max = 0 ;
int findSet(int p)
{
    if (par[p] == p) return p ;
    else return par[p] = findSet(par[p]) ;
}
void Union (int u, int v)
{
    if (par[u] == -1 || par[v] == -1) return ;
    int x = findSet(u), y = findSet(v) ;
    if (x != y)
    {
        nscc-- ;
        par[x] = y ;
    }
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(par , -1 , sizeof(par)) ;
    cin >> n ;
    nscc = n ;
    for(int i = 1 ; i <= n ; ++i )
    {
        cin >> a[i] ;
        par[a[i]] = a[i] ;
        Max = max(a[i] , Max) ;
    }
    Max = Max * 2 ;
    for(long long i = 1 ; i < Max ; ++i )
    {
        for(long long j = i + 1 ; 2 * i * j < Max && j * j - i * i < Max ; j += 2)
        {
            if (__gcd(i , j) != 1) continue ;
            Union(j * j - i * i, 2 * i * j) ;
            if (j * j + i * i < Max)
            {
                Union(j * j + i * i , j * j - i * i) ;
                Union(j * j + i * i , 2 * i * j ) ;
            }
        }
    }
    cout << nscc << endl;
    return 0;
}
