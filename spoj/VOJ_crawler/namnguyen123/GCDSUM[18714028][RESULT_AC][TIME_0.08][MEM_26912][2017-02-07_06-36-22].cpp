using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e6 + 5 ;
const int N = 1e6 ;
long long phi[MAXN] ;
long long lp[MAXN];
vector <int> pr;
long long f[MAXN] ;
void calc_sieve()
{
    phi[1] = 1;
    for (int i = 2; i <= N; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            phi[i] = i - 1;
            pr.push_back(i);
        }
        else
        {
            //Calculating phi
            if (lp[i] == lp[i / lp[i]])
                phi[i] = phi[i / lp[i]] * lp[i];
            else
                phi[i] = phi[i / lp[i]] * (lp[i] - 1);
        }
        for (int j = 0 ; j < pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
    phi[1] = 0 ;
    for (int i = 1 ; i <= N ; ++i)
        for (int j = 1 ; i * j <= N ; ++j ) { f[i * j] += phi[j] * i ;}
    for(int i = 2 ; i <= N ; ++ i ) f[i] += f[i - 1] ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    calc_sieve() ;
    int n ;
    while(~scanf("%d",&n))
    {
        if (n == 0) break ;
        printf("%lld\n", f[n]) ;
    }
    return 0;
}
