using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
int a[MAXN] ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n ;
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i] ;
    map<int, long long> res;
    map<int, int> divisors;
    map<int, int> nextDivisors;
    for (int i = 1 ; i <= n ; i++)
    {
        nextDivisors.clear();
        for (auto &p : divisors) nextDivisors[__gcd(p.first, a[i])] += p.second;

        nextDivisors[a[i]]++;

        swap(nextDivisors, divisors);

        for (auto &p : divisors)
            res[p.first] += p.second;
    }

    int q;
    cin >> q;
    while (q --)
    {
        int x;
        cin >> x;
        cout << res[x] << endl;
    }

    return 0;
}
