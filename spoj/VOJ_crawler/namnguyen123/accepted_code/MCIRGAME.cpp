#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define BASE 1000000000
struct bigint
{
    vector < ll > digit ;
    void clear()
    {
        digit.clear();
    }
    void refine ()
    {
        digit.push_back(0);
        for(int i = 0 ; i < digit.size() - 1 ; ++i )
        {
            digit[i + 1] += digit[i] / BASE ;
            digit[i] = digit[i] % BASE ;
            if(digit[i] < 0)
            {
                digit[i] += BASE ;
                digit[i + 1] -- ;
            }
        }
        while(digit.size() >= 2 && digit.back() == 0) digit.pop_back();
    }
    bigint operator * (ll x)
    {
        bigint res ;
        res.digit.resize(digit.size() + 1);
        for(int i = 0 ; i < digit.size() ; ++i )
        {
            res.digit[i] = digit[i] * x ;
        }
        res.refine();
        return res ;
    }
    void COUT()
    {
        refine();
        printf("%lld",digit.back());
        if(digit.size() >= 2)
        {
            for(int i = digit.size() - 2 ; i >= 0 ; --i )
            {
                printf("%09lld",digit[i]);
            }

            printf("\n");
        }
    }
};
const int MAXN = 1e5 + 1 ;
int vis[MAXN];
int fA[MAXN],fB[MAXN],fAB[MAXN];
vector <int> prime ;
void sang()
{
    for(int i = 2 ; i <= 100000 ; ++i ) vis[i] = 1 ;
    for(int i = 2 ; i <= sqrt(100000) ; ++i )
    {
        if(vis[i])
        {
            for(int j = 2 ; j * i <= 100000 ; ++j ) vis[i*j] = 0 ;
        }
    }
    for(int i = 2 ; i <= 100000 ; ++i ) if (vis[i]) prime.push_back(i);
}
int main ()
{
    //freopen("CATALAN.inp","r",stdin);
    //freopen("CATALAN.out","w",stdout);
    sang();
    int n ;
    while(cin >> n)
    {
        if(n == -1) break ;
        memset(fA, 0, sizeof(fA) );
        memset(fB, 0, sizeof(fB) );
        for(int i = n + 2 ; i <= 2 * n ; ++i )
        {
            int FACT = i ;
            int j = 0 ;
            while(FACT != 1 || j == prime.size() - 1)
            {
                while(FACT % prime[j] == 0)
                {
                    FACT /= prime[j] ;
                    fA[prime[j]]++;
                }
                j++;
            }
            if(FACT != 1 ) fA[FACT]++;
        }
        for(int i = 2 ; i <= n ; ++i )
        {
            int FACT = i ;
            int j = 0 ;
            while(FACT != 1 || j == prime.size() - 1)
            {
                while(FACT % prime[j] == 0)
                {
                    FACT /= prime[j] ;
                    fB[prime[j]]++;
                }
                j++;
            }
            if(FACT != 1 ) fB[FACT]++;
        }
        bigint ans ;
        ans.digit.push_back(1);
        for(int i = 2 ; i <= 2 * n ; ++ i ) fAB[i] = fA[i] - fB[i] ;
        for(int i = 2 ; i <= 2 * n ; ++ i )
        {
            if(fAB[i])
            {
                while(fAB[i]--) ans = ans * i ;
            }
        }
        ans.COUT();
        printf("\n");
    }
}
