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
const int MAXN = 3e4 + 5 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
vector <int> b ;
int f[MAXN];
int t[MAXN];
int t2[MAXN];
int n, p ;
void sang(int n)
{
    FORE(i, 2, sqrt(n))
    {
        if (!f[i])
        {
            for(int j = 2*i ; j <= n; j += i )
            {
                f[j] = 1 ;
            }
        }
    }
    FORE(i, 2, n ) if (!f[i]) b.push_back(i);
}
int get(int p, int n)
{
    int res = 0 ;
    while(n)
    {
        res+=n/p;
        n/=p;
    }
    return res ;
}
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    b.push_back(0);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> p ;
    sang(n);
    int nd = b.size() - 1 ;
    int k = p ;
    FORE(i, 1, nd )
    {
        if (k == 1)break;
        if (k % b[i] == 0  )
        {
            while(k % b[i] == 0)
            {
                k/=b[i];
                t[i]++;
            }
        }
    }
    FORE(i, 1, nd)
    {
        if (b[i] > p )break;
        else t2[i] = get(b[i], n );
    }
    int x = 0 ;
    FORE(i, 1, nd )
    {
        if (b[i] > p )break;
        if (t[i])
        {
            x = max(x,t2[i]/t[i]);
        }
    }
    cout << x << endl;



    return 0;
}
