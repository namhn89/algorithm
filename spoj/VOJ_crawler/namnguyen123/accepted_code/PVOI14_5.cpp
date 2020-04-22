using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e6 + 5 ;
vector <int> g[MAXN];
int n ;
long long power (long long a , long long n) {
   long long res = 1 ;
   for(int i = 1 ; i <= n ; ++i) res = (res * a) ;
   return res ;
}
int main()
{
    // freopen("TASK.inp","r",stdin);
    // freopen("TASK.out","w",stdout);
    scanf("%d",&n) ;
    int Max = 0 ;
    FORE(i, 1, n )
    {
        int x ;
        scanf("%d",&x) ;
        Max = max(Max , x);
        for(int i = 2 ; i * i <= x ; ++i )
        {
            if( x % i == 0 )
            {
                int d = 0 ;
                while (x % i == 0)
                {
                    x /= i ;
                    d++;
                }
                if (d != 0 ) g[i].push_back(d) ;
            }
        }
        if (x != 0 ) g[x].push_back(1) ;
    }
    long long ans = 0 ;
    long long val = 1;
    FORE(i , 2 , Max )
    {
        if (g[i].size())
        {
            sort(g[i].begin() , g[i].end());
            int pos = (n + 1) / 2 ;
            int cnt0 = n - g[i].size();
            int median;
            if (cnt0 >= pos) median = 0;
            else median = g[i][pos - cnt0 - 1];
            ans += cnt0 * median ;
            val = val * power(i , median) ;
            TR(g[i] , it) ans += abs(*it - median);
        }
    }
    cout << ans << " " << val << endl;
    return 0;
}
