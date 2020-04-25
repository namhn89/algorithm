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
const int MAXN = 3e2 + 5 ;
bool palind [MAXN][MAXN];
char s [MAXN];
int dp [MAXN];
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    scanf ("%s", s);
    int n = strlen (s);
    for (int j = 0; j < n; ++j)
        for (int i = j; i >= 0; i--)
            if (s [i] == s [j])
                if (j - i == 0 || j - i == 1) palind [i][j] = true;
                else palind [i][j] = palind [i + 1][j - 1];

    for (int j = 0; j < n; ++j)
    {
        if (palind [0][j]) dp [j] = 1;
        else dp [j] = INT_MAX;
        for (int i = 0; i < j; ++i)
            if (palind [i + 1][j])
                dp [j] = min (dp [j], dp [i] + 1);
    }
    printf ("%d\n", dp [n - 1]);
    return 0;


    return 0;
}
