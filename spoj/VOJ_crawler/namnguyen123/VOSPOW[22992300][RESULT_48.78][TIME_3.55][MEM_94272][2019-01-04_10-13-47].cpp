#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
const int N = 1e7 + 5;

ll n, k, t, base, muli, seed, a[N], bitSet[4096], phii[20], id = 0, ele[20], bitSet2[4096], maxPow = 0, check = 0;
ii p[20];

ll add(ll a, ll b, ll MOD) {
    return (a + b) % MOD;
}

ll sub(ll a, ll b, ll MOD) {
    return (((a - b) % MOD) + MOD) % MOD;
}

ll mul(ll a, ll b, ll MOD) {
    long long x = 1e6;
    long long b1 = b / x, b2 = b % x;
    return (((a * b1) % MOD) * x + a * b2) % MOD;
}

ll power(ll a, ll b, ll MOD) {
    if (b == 0) return 1;
    ll x = power(a, b / 2, MOD);
    if (b % 2 == 0) {
        return mul(x, x, MOD);
    }
    return mul(a, mul(x, x, MOD), MOD);
}


ll calc(ll u, ll basei) {
    ll UCLN = __gcd(u, basei);
    ll n2 = 0;
    for (int i = 0; i < id; i++) {
        if (UCLN % p[i].first == 0) n2 += (1 << i);
    }
    ll n1 = ((1 << id) - 1) ^ n2;
    ll du1, du2;
    ll powi = power(k, t, bitSet[n1]);
    du1 = power(u, powi, bitSet2[n1]);
    if (check) du2 = 0;
    else {
        du2 = power(u, power(k, t, 10000), bitSet2[n2]);
    }
    ll p1 = bitSet2[n1];
    ll p2 = bitSet2[n2];
    ll res = power(p2, bitSet[n1] - 1, p1);
    res = mul(res, sub(du1, du2, p1), p1);
    res = res * p2;
    res = add(res, du2, basei);
    return res;
    // A chia p1 du du1, chia p2 du du2. Tim so du khi chia cho p1p2
    // (A- du2)= kp2 dong du voi du1-du2 mod p1
    // (du1-du2)*rev(p2)*p2 + du2
}

int main(){
    cin >> n >> k >> t >> base >> muli >> seed;
    ll basei = base;
    a[0] = seed; ll maxC = power(2, 20, 1000000000);
    for (int i = 1; i <= n; i++){
        a[i] = add(seed, mul(a[i-1], muli, maxC), maxC);
    }
    for (int i = 2; i * i <= base; i++) {
        if (base % i) continue;
        p[id] = make_pair(i, 0);
        ele[id] = 1;
        while (base % i == 0) {
            p[id].second++;
            base /= i;
            ele[id] *= i;
        }
        phii[id] = ele[id] - ele[id] / i;
        maxPow = max(maxPow, 1LL*p[id].second);
        id++;
    }
    if (base != 1) {
        p[id] = make_pair(base, 1);
        phii[id] = base - 1;
        ele[id] = base;
        id++;
    }
    ll kt = 1;
    for (int i = 1; i <= t; i++){
        if (k == 1) {
            break;
        }
        kt = kt*k;
        if (kt > 100) {
            check = 1;
            break;
        }
    }
    maxC = 1 << id;
    for (int i = 0; i < maxC; i++){
        bitSet[i] = 1;
        bitSet2[i] = 1;
        ll ii = i;
        int it1 = 0;
        while (ii != 0) {
            if (ii % 2 == 0) {
                it1++;
                ii /= 2;
                continue;
            }
            bitSet[i] = mul(bitSet[i], phii[it1], 10000000000000);
            bitSet2[i] = mul(bitSet2[i], ele[it1], 10000000000000);
            it1++;
            ii /= 2;
        }
    }
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        res = add(res, calc(a[i], basei), basei);
    }
    cout << res;
}
