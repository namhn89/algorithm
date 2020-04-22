using namespace std;
#include<bits/stdc++.h>
#define TR(c, it) for(typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define FOR(i, a, b) for(long i = a, _b = (b) ; i <= _b ; i++)
#define FORD(i, a, b) for(long i = a, _b = (b) ; i >= _b ; i--)
#define REP(i, a) FOR(i, 0, a - 1)
#define DEB(X) cout << #X << ": " << X << endl ;
#define long long long
#define pb push_back
#define mp make_pair
const long N = 2e5 + 5;
const long mod = 1e9 + 7;
long power(long a, long p, long mod) {
    long res = 1;
    while (p) {
        if (p&1) res = (res * a) % mod;
        a = (1ll * a * a) % mod;
        p /= 2;
    }
    return res;
}
long fact[N];
long ins[N];
map <long , long> s;
long C(long n, long k) {
    return (((fact[n] * ins[n-k]) % mod) * ins[k]) % mod;
}
int main() {
    long n, k;
    long ans = 0;
    cin >> n >> k;
    /// init
    fact[0] = ins[0] = 1;
    FOR(i, 1, n) fact[i] = (1ll * fact[i-1] * i) % mod, ins[i] = power(fact[i], mod-2, mod);

    FOR(i, 1, n) {
        long a, b;
        cin >> a >> b;
        ++s[a] ; --s[b+1];
    }
    long last = s.begin() -> first;
    long curr_cover = 0;
    TR(s, i) {
        pair<long, long> it = *i;
        long dist = it.first - last;
        if (curr_cover >= k) ans += (1ll * C(curr_cover, k) * dist) % mod;
        while(ans >= mod) ans -= mod;
        curr_cover += it.second;
        last = it.first;
    }
    return cout << ans << '\n',0;
}