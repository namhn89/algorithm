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
const int MOD = 1e9 + 7 ;
const int MAXN = 1e2 + 5 ;
int     n,x[MAXN],dd[MAXN];
bool    yes[MAXN][MAXN];
int     res[MAXN] = {0, 0, 2, 2, 4, 96, 1024, 2880, 81024, 770144};
int     ans = 0;

bool kt(int x)
{
    if (x <= 1) return false;
    for (int i=2; i*i<=x; i++)
        if (x % i == 0) return false;
    return true;
}

void dq(int t)
{
    if (t == n+1)
    {
        if (not yes[x[1]][x[n]]) return;
        ans++;
        for (int i=1; i<=n; i++) printf("%d ",x[i]);
        printf("\n");
        return;
    }
    for (int i=1; i<=n; i++)
        if (dd[i] == 0 && yes[x[t-1]][i])
        {
            x[t] = i;
            dd[i] = 1;
            dq(t+1);
            if (ans == 10000) return;
            dd[i] = 0;
        }
}

int main()
{
    scanf("%d",&n);
    printf("%d\n",res[n]);

    n *= 2;
    for (int i=1; i<=n; i++)
        for (int j=i; j<=n; j++)
        {
            yes[i][j] = kt(i+j);
            yes[j][i] = yes[i][j];
        }

    x[1] = 1;
    dd[1] = 1;
    dq(2);

    return 0;
}
