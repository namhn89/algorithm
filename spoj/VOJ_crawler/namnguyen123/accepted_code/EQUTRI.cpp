using namespace std;
#include<bits/stdc++.h>
#define BASE 1000000000
typedef long long ll ;
struct bigint
{
    vector < ll > digit ;
    void clear()
    {
        digit.clear();
    }
    void refine()
    {
        digit.push_back(0);
        for(int i = 0 ; i < digit.size() - 1 ; ++i )
        {
            digit[i + 1] += digit[i] / BASE ;
            digit[i] = digit[i] % BASE ;
            if(digit[i] < 0 )
            {
                digit[i] += BASE ;
                digit[i + 1] -- ;
            }
        }
        while(digit.size() >= 2 && digit.back() == 0 ) digit.pop_back();
    }
    bigint operator * (ll x)
    {
        bigint res ;
        res.digit.resize(digit.size() + 1);
        for(int  i = 0 ; i < digit.size() ; ++i )
        {
            res.digit[i] = digit[i] * x ;
        }
        res.refine();
        return res ;
    }
    void divide(ll x , bigint &q , ll &r)
    {
        q.clear();
        r = 0 ;
        for(ll i = digit.size() - 1 ; i >= 0 ; --i )
        {
            r = r * BASE + digit[i] ;
            q.digit.push_back(r / x);
            r = r % x ;
        }
        reverse(q.digit.begin(),q.digit.end());
        q.refine();
    }
    bigint operator / (ll x)
    {
        bigint q ;
        ll r ;
        divide(x , q , r);
        return q ;
    }
    void COUT()
    {
        refine();
        printf("%lld" , digit.back());
        if(digit.size() >= 2 )
        {
            for(ll i = digit.size() - 2 ; i >= 0 ; --i )
            {
                printf("%09lld",digit[i]);
            }
        }
        printf("\n");
    }
};
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    bigint ans ;
    ans.digit.push_back(1);
    ll N,a,b,c;
    cin >> N >> a >> b >> c ;
    // ll ans = (N + 1)*(N + 2)*(a+b+c)/6;
    ans = ans * (N+1) ;
    ans = ans * (N+2) ;
    ans = ans * (a+b+c) ;
    ans = ans / 6 ;
    ans.COUT();

    return 0;
}
