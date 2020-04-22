using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
long long a[] = {0, 1, 2, 4, 6, 12, 16, 18, 30, 60, 88, 106, 126, 520, 606, 1278,
                 2202, 2280, 3216, 4252, 4422, 9688, 9940, 11212, 19936, 21700,
                 23208, 44496, 86242, 110502, 132048, 216090, 756838, 859432,
                 1257786, 1398268, 2976220, 3021376, 6972592, 13466916, 20996010
                };
long long power (long long a, long long n)
{
    long long res = 1 ;
    while(n)
    {
        if (n & 1) res = (res * a) % MOD ;
        a = (a * a) % MOD ;
        n >>= 1 ;
    }
    return res ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    int n ;
    cin >> n ;
    cout << power (2 , a[n] ) - 1  << endl;

    return 0;
}
