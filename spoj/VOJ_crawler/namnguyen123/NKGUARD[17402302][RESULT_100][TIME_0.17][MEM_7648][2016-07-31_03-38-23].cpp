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
#define TR(c, it) for(typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
#define NAME TASK
#define openfile freopen("TASK.inp","r",stdin);freopen("TASK.out","w",stdout);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<int,II> III;
typedef pair<ll,ll> LL;
const ll INF=1e9+7;
const int maxn=1001;
int n,m,res;
int a[maxn][maxn];
bool d[maxn][maxn];
int dx[]= {-1,-1,-1,0,0,1,1,1};
int dy[]= {-1,0,1,-1,1,-1,0,1};
bool OK;
void Init()
{
    scanf("%d%d",&n,&m);
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            scanf("%d",&a[i][j]);
}

void Try(int i, int j)
{
    if(d[i][j])
    {
        OK=false;
        return;
    }
    d[i][j]=true;
    for (int k=0; k<8; k++)
    {
        int x=i+dx[k];
        int y=j+dy[k];
        if(x>0 && x<=n  && y>0 && y<=m)
        {
            if(OK && a[x][y]>a[i][j])    OK=false;
            if(!d[x][y] && a[x][y]==a[i][j])
                Try(x,y);
        }
    }

}
void Solve()
{
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            OK=true;
            Try(i,j);
            if(OK) res++;
        }
    printf("%d",res);
}

int main()
{
    Init();
    Solve();
}
