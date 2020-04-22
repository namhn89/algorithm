using namespace std;
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
const int MAXN=1e2+1;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int m, n, h[MAXN][MAXN], w[MAXN][MAXN];
vector<II> g[1005];

bool isBorder(int x, int y)
{
    FORE(i, 0 ,3)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (w[nx][ny] >= 0) return true;
    }
    return false;
}

void dfs(int x, int y, int height)
{
  //  cout << "dfs " << x << " " << y << " " << height << endl;
    FORE(i, 0 ,3)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (w[nx][ny] == -1 && h[nx][ny] <= height)
        {
            w[nx][ny] = height;
            dfs(nx, ny, height);
        }
    }
}

int main()
{

   // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);

    int maxH = 0;
    cin >> m >> n;
    FORE(i, 1, m)
    FORE(j, 1, n)
    {
        cin >> h[i][j] ;
        g[h[i][j]].push_back(make_pair(i, j));
        if (h[i][j] > maxH) maxH = h[i][j];
    }

    FORE(i, 1, m)
    {
        FORE(j, 1, n)
        {
            w[i][j] = -1;
        }
    }
    FORE(i, 1, maxH)
    {
        FORE(j, 0 , g[i].size()-1)
        {
            int x = g[i][j].first, y = g[i][j].second;
            if (w[x][y] == -1 && isBorder(x, y))
            {
                w[x][y] = i;
                dfs(x, y, i);
            }
        }
    }
    int res = 0;
  /*  FORE(i, 1, m)
    {
        FORE(j, 1, n)
        {
            cout<<w[i][j]<<" ";
        }
        cout<<endl;
    }*/
    FORE(i, 1, m)
    FORE(j, 1, n) res += w[i][j] - h[i][j];
    cout << res << endl;
}
