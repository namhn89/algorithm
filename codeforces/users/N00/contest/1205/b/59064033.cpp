using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MAXN = 1e5 + 1;
const int MAXM = 200 + 1;
const int inf = 1e9;
long long a[MAXN];
int d[MAXM][MAXM];
vector <int> b[MAXN];

int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    for (int i = n ; i >= 1; --i){
        if (a[i] == 0) {
            n--;
        }
        else break;
    }
    // for (int i = 1; i <= n ;++i) cout << a[i] << " "; cout << endl;

    for (int i = 0; i <= 60; ++i) {
        for (int j = 1; j <= n; ++j){
            if ((a[j] >> i) & 1) b[i].push_back(j);
        }
    }
    for (int i = 0; i <= 60; ++i) {
        if (b[i].size() >= 3){
            cout << 3 << endl;
            return 0;
        }
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) d[i][j] = inf ;
    for (int i = 0; i <= 60; ++i){
        if (b[i].size() == 2){
            int u = b[i][0], v = b[i][1];
            d[u][v] = 1;
            d[v][u] = 1;
        }
    }
    for (int i = 1; i <= n; ++i) d[i][i] = 0;
    int ans = inf ;
    for (int k = 1; k <= n; ++k){
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= n; ++j){
                if (i != k && j != k && i != j){
                    if((a[i] & a[k]) && (a[k] & a[j])){
                        ans = min(ans , d[i][j] + 2);
                    }
                }
            }
        }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

        }
    }
    if (ans > n) ans = -1;
    cout << ans ;

    return 0;
}
