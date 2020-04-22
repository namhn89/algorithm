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
const ull num[] = { 2, 7, 61 };

ull pmod(ull a, ull n, const ull& m)
{
    ull res = 1;
    while (n)
    {
        if (n & 1)
        {
            res *= a;
            res %= m;
        }
        a *= a;
        a %= m;
        n >>= 1;
    }
    return res;
}

bool test(const ull& a, const ull& d, int s, const ull& n)
{
    ull res = pmod(a, d, n);
    if (res == 1 || res == n - 1)
    {
        return 1;
    }
    else
    {
        for (int r = 1; r < s; ++r)
        {
            res *= res;
            res %= n;
            if (res == n - 1) return 1;
        }
    }
    return 0;
}

bool solve(ull& n)
{
    ull d = n - 1;
    int s = 0;
    while (!(d & 1))
    {
        d >>= 1;
        ++s;
    }
    bool ans = 1;
    for (int i = 0; i < 3 && ans && num[i] < n; ++i)
        ans = test(num[i], d, s, n);
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //std::ios::sync_with_stdio(0);
    //std::cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        ull n;
        scanf("%llu", &n);
        while (1)
        {
            --n;
            if (solve(n))
            {
                printf("%llu\n", n);
                break;
            }
        }
    }
}
