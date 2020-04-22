using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MAXN = 2e7 + 5 ;
int f[MAXN * 2];
int prime[MAXN] ;
int n_prime = 0 ;
int x , y , mod ;
int get (int p , int n) {
    int res = 0 ;
    while(n){
        res += n / p ;
        n /= p ;
    }
    return res ;
}
void SangNguyenTo( int n )
{
    int i, j;
    for(i = 2; i <= n; i++)
    {
        if (f[i] == 0) f[i] = prime[++n_prime] = i;
        j = 0;
        while (j < n_prime && prime[j] < f[i] && prime[j+1] * i <= n)
            f[prime[j+1]*i] = prime[j+1], j++;
    }
}
long long power(long long a, long long n )
{
    long long res = 1 ;
    while(n)
    {
        if (n & 1) res = (res * a) % mod ;
        a = (a * a) % mod ;
        n >>= 1 ;
    }
    return res ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%d %d %d", &x, &y, &mod) ;
    int N = x + y - 1 ;
    int R = y - 1 ;
    if (N < R)
    {
        printf("0\n");
    }
    else
    {
        SangNguyenTo(N) ;
        long long ans = 1;
        for(int i = 1 ; i <= n_prime ; ++ i )
        {
            int x = get(prime[i] , N) - get(prime[i] , N - R) - get(prime[i] , R) ;
            ans = (ans * power(prime[i] , x)) % mod ;
        }
        printf("%lld\n", ans) ;
    }
    return 0;
}
