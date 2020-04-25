using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define BG begin()
#define ED end()
#define SZ size()
#define PB push_back
#define PF push_front
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
#define NAME TASK
#define openfile freopen("TASK.inp","r",stdin);freopen("TASK.out","w",stdout);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<int,II> III;
typedef pair<ll,ll> LL;
const int MOD=1e9+7;
const int MAXN=5e2+1;
int f[MAXN], b[MAXN];
vector<int> a[MAXN];
int n, m, u, v;
bool cmp(int u, int v) {return u > v;}
void dfs(int u)
{
    int m = a[u].size();
    if (m == 0)
    {
        f[u] = 1;
        return ;
    }
    for (int i=0; i<m; i++) dfs(a[u][i]);
    for (int i=0; i<m; i++) b[i] = f[a[u][i]];
    sort(b, b+m, cmp);
    int ans = 0, now = 0;
    for (int i=0; i<m; i++)
    {
        if (now < b[i])
        {
            ans += b[i]-now;
            now = b[i]-1;
        }
        else
        {
            now--;
        }
    }

    f[u] = ans;

}
int main()
{
   //  freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    cin >> n;
    while ( scanf("%d",&u) == 1)
    {
        cin >> m;
        FORE(i, 1, m)
        {
            cin >> v;
            a[u].push_back (v);
        }
    }
    dfs(1);
    cout << f[1] << endl;


    return 0;
}
