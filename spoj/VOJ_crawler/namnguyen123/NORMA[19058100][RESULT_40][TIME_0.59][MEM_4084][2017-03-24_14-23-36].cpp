#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

const int N = 10000;
const int MOD = 1e9;

int a[N], b[15][N], c[15][N] , n ;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        b[0][i] = c[0][i] = a[i];
    }
    for (int j = 1; 1 << j <= n; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
        {
            b[j][i] = max(b[j - 1][i], b[j - 1][i + (1 << (j - 1))]);
            c[j][i] = min(c[j - 1][i], c[j - 1][i + (1 << (j - 1))]);
        }
    int ans = 0;
    for (int l = 1; l <= n; ++l)
    {
        int k = __lg(l);
        for (int i = 1; i + l - 1 <= n; ++i)
        {
            int bb = max(b[k][i], b[k][i + l - (1 << (k))]);
            int cc = min(c[k][i], c[k][i + l - (1 << (k))]);
            int val = 1LL * bb * cc % MOD * l % MOD;
            ans = (ans + val) % MOD;
        }
    }
    cout << ans ;
}
