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
const int maxn=1001;
const int maxk=51;
const int minf=-1e9;
int n,k;
int a[maxn];
int f[maxn][maxk];

void Init()
{
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        a[i]%=k;
    }
}

int Mod(int x, int j)
{
    if(x>j)
        return j+k-x;
    else
        return j-x;
}

void Solve()
{
    for(int i=1; i<=k; i++)    f[0][i]=minf;
    f[0][0]=0;
    for(int i=1; i<=n; i++)
        for (int j=0; j<k; j++)
            f[i][j]=max(f[i-1][j],f[i-1][Mod(a[i],j)]+1);
    cout<<f[n][0];
}
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Init();
    Solve();

    return 0;
}
